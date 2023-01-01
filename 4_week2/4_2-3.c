// ｎ体のモンスターを持つ配列を動的に確保

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //乱数の生成のため

typedef struct {
    char na[64];
    int stts[6];
} Monster;

Monster creMonster(){
    int i,k;
    Monster tmp;
    k = rand()%8+4;
    int a = 'a' + rand()%26;
    for(i=0;i<k;i++) tmp.na[i] = 'a' + rand()%26;
    tmp.na[k] = '\0';
    for(i=0;i<6;i++) tmp.stts[i] = rand()%255+1;
    return tmp;
}

void priMonster(Monster m){
    printf("%12s  : ",m.na);
    for(int i=0;i<6;i++)
        printf("%3d ",m.stts[i]);
    printf("\n");
}

int main(){
    srand((unsigned)time(NULL)); //乱数を生成する時のおまじない
    int i, n;
    Monster *monsters;
    scanf("%d",&n);
    //ここに１行で monstersにn体のモンスターの領域を確保する
    monsters = (Monster*)malloc(sizeof(Monster)*n);
    //以下はいじらなくてＯＫ
    if(monsters == NULL){
        printf("ERROR\n");
        return 0;
    }
    for(i=0;i<n;i++){
        monsters[i] = creMonster();
        printf("%03d  ",i+1);
        priMonster(monsters[i]);
    }
    free(monsters);
    return 0;
}
