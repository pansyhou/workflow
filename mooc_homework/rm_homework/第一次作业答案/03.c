#include <stdio.h>

int infantry = 0, hero = 0; //����,Ӣ�۵�·��
int t1 = 0, total_hero = 0;
int debug = 0; //�������Ա����
int T;

int main(){
    scanf("%d", &T);
    total_hero = 3 * T; //Ӣ����Tʱ�������
    for (int t = 1; t <= T; t++){
        hero += 3;
        if (debug == 0){
            //�������ڵ���״̬
            infantry += 9; //�����Ծ���9m
        }
        if (t % 10 == 0){
            //ÿ����10�����ж�Ҫ��Ҫ����
            if (debug == 0 && hero < infantry){//���ڵ��Բ��Ҳ���������Ӣ��
                debug = 1;
                t1 = t;
            }
        }
        if (t1 + 30 == t){
            //���˰��Сʱ��Ҫ�������״̬
            debug = 0;
        }
    }
    if (infantry > total_hero){
        printf("infantry %d", infantry);
    }
    else if (infantry == total_hero){
        printf("draw %d", infantry);
    }
    else{
        printf("hero %d", total_hero);
    }
    return 0;
}
