#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//最大値を返す関数
int getMax(int a[], int n){
    int i,ret=0;
    for(i=1;i<n;i++){
        if(a[ret]<a[i]) ret = i;
    }
    return ret;
}

int solve(){
    //初期化や入力
    int ret = 0;
    int n,q,i,x;
    int *d;
    scanf("%d %d",&n,&q);
    d = (int*)malloc(sizeof(int)*n);
    if(d==NULL){
        printf("ERROR\n");
        return -1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    //以下の操作をq回繰り返す
    //モンスターの配列の中から最大値を求め
    //その防御力最大モンスターにボールを投げる
    for(i=0;i<q;i++){
        x = getMax(d,n);
        d[x] /= 2; //d[n-1] = d[n-1]/2;
    }
    //総和を求める
    for(i=0;i<n;i++){
        ret += d[i];
    }
    free(d);
    return ret;
}

//メイン関数はいじらなくて良い
int main(void){
    printf("%d\n",solve());
    return 0;
}
