#include <stdio.h>
#include <math.h>
int start, min;
int tran2min, time;
int end;
int main(){
    scanf("%d%d", &start, &min);
    tran2min = start / 100 * 60 + start % 100;
    //流逝的时间是分钟数,将起始时间转化成分钟数统一后加起来,再转化成正常时间
    time = tran2min + min;
    end = time / 60 * 100 + time % 60;
    printf("%d", end);
    return 0;
}
