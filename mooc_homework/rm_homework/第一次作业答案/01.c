#include <stdio.h>
#include <math.h>
int start, min;
int tran2min, time;
int end;
int main(){
    scanf("%d%d", &start, &min);
    tran2min = start / 100 * 60 + start % 100;
    //���ŵ�ʱ���Ƿ�����,����ʼʱ��ת���ɷ�����ͳһ�������,��ת��������ʱ��
    time = tran2min + min;
    end = time / 60 * 100 + time % 60;
    printf("%d", end);
    return 0;
}
