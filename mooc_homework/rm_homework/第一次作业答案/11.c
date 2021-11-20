
#include <stdio.h>
#include <math.h>

int n,m;

int divide(int a, int b) {
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;// "^"位运算异或:两个位相同为0，相异为1
    unsigned int ua = abs(a);//绝对值abs() 
    unsigned int ub = abs(b);
    unsigned int res = 0;
    for (int i = 31; i >= 0; i--) {
        if ((ua >> i) >= ub) {// "">>"位运算移位符
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
