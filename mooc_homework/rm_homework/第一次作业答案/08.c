#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int p, r, n, m, temp;

int gcd(int n,int m){//շת�����
    int tt = 0;
    while(m != 0){
        tt = n % m;
        n = m;
        m = tt;
    }
    return n;
}

int main(){

    scanf("%d%d,", &n, &m);
    //����n����ϴ��ֵ
    if (n < m){
        temp = n;
        n = m;
        m = temp;
    }

    p = n * m;
    n = gcd(n,m);

    printf("%d ", n);  //���ǵ����Լ��Ϊ
    printf("%d\n", p / n);  //���ǵ���С������Ϊ
}
