#include <I2C.h>
#include <delay.h>

void IIC_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	//RCC->APB2ENR|=1<<4;//先使能外设IO PORTC时钟 
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	
	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	IIC_SCL=0;
	IIC_SDA=0;
	delay_init();
}
void IIC_Start(void)
{
	SDA_OUT();     //sda线输出
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(2);
	IIC_SDA=0;
}
void IIC_Ack(void) //应答
{
	unsigned char i=0;
	SDA_IN();
	IIC_SCL=0;
	delay_us(5);
	while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)&&i<250)i++;
	IIC_SCL=1;
	delay_us(2);
	IIC_SCL=0;
}
void IIC_Stop(void)
{
	SDA_OUT();
	IIC_SCL=0;
	delay_us(2);
	IIC_SDA=0;
	delay_us(2);
	IIC_SCL=1;
	delay_us(2);
	IIC_SDA=1;
	delay_us(2);
}
void IIC_Send_Byte(unsigned char onebyte)
{
	SDA_OUT();
	unsigned char i;
		for(i=0;i<8;i++)
			{
				IIC_SCL=0;
				if(onebyte&0x01)			//低位在前
				{
					IIC_SDA=1;
				}
				else
				{
					IIC_SDA=0;
				}
				delay_us(3);
				onebyte=onebyte>>1;
				IIC_SCL=1;
				delay_us(3);
			}
}
unsigned char ScanKey(void)//读按键
{
	SDA_OUT();
	unsigned char rekey,rkey,i;
	IIC_Start();
	IIC_Send_Byte(0x42); //读按键命令
	IIC_Ack();
	IIC_SDA=0;		//在读按键之前要拉高sda（我也不知道怎么拉高）
	for (i=0;i<8;i++)
	{
		IIC_SCL=0;
		rekey=rekey>>1;
		delay_us(30);
		IIC_SCL=1;
		if(READ_SDA)
		{
			rekey=rekey|0x80;
		}
		else
		{
			rekey=rekey|0x00;
		}
		delay_us(30);
	}
	IIC_Ack();
	IIC_Stop();
	return (rekey);
}

void SmgDisplay(void)//开显示
{
	unsigned char i;
	
	IIC_Start();
	IIC_Send_Byte(0x40);  //自动+1模式
	IIC_Ack();
	IIC_Stop();
	
	IIC_Start();
	IIC_Send_Byte(0xc0);		//设置首地址
	IIC_Ack();
	IIC_Stop();
	
	IIC_Start();
	IIC_Send_Byte(0x8f);		//开显示,最大亮度
	IIC_Ack();
	IIC_Stop();
}
void I2CTest(void)
{
	unsigned char keydate;
	IIC_Init();
	SmgDisplay();
	while (1)
	{
		keydate=ScanKey();   //读按键，读出按键值不做处理
	}
}




#ifndef __I2C_H
#define __I2C_H
#include "sys.h"
#include <stm32f10x.h>

#define SDA_IN()  {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=8<<12;}
#define SDA_OUT() {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=3<<12;}

//IO操作函数	 
#define IIC_SCL    PBout(4) //SCL
#define IIC_SDA    PBout(5) //SDA	 
#define READ_SDA   PBin(5)  //输入SDA 

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
unsigned char ScanKey(void);//读按键
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	 
void SmgDisplay(void); //写显示寄存器
void I2CTest(void);
#endif