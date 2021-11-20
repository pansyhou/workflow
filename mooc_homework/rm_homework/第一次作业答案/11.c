
#include <stdio.h>
#include <math.h>

int n,m;

int divide(int a, int b) {
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;// "^"λ�������:����λ��ͬΪ0������Ϊ1
    unsigned int ua = abs(a);//����ֵabs() 
    unsigned int ub = abs(b);
    unsigned int res = 0;
    for (int i = 31; i >= 0; i--) {
        if ((ua >> i) >= ub) {// "">>"λ������λ��
            ua = ua - (ub << i);
            res += 1 << i;
        }
    }
    return sign == 1 ? res : -res;
}

int main(){
    scanf("%d%d",&n,&m);
    printf("%d",divide(n,m));
    return 0;
}
