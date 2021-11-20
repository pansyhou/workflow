#include <stdio.h>

int infantry = 0, hero = 0; //步兵,英雄的路程
int t1 = 0, total_hero = 0;
int debug = 0; //步兵调试标记量
int T;

int main(){
    scanf("%d", &T);
    total_hero = 3 * T; //英雄跑T时间后的里程
    for (int t = 1; t <= T; t++){
        hero += 3;
        if (debug == 0){
            //步兵不在调试状态
            infantry += 9; //不调试就跑9m
        }
        if (t % 10 == 0){
            //每经过10分钟判断要不要调试
            if (debug == 0 && hero < infantry){//不在调试并且步兵超过了英雄
                debug = 1;
                t1 = t;
            }
        }
        if (t1 + 30 == t){
            //过了半个小时就要解除调试状态
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
