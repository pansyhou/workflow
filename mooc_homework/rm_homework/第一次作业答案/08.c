#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int p, r, n, m, temp;

int gcd(int n,int m){//辗转相除法
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
    //调整n保存较大的值
    if (n < m){
        temp = n;
        n = m;
        m = temp;
    }

    p = n * m;
    n = gcd(n,m);

    printf("%d ", n);  //它们的最大公约数为
    printf("%d\n", p / n);  //它们的最小公倍数为
}
