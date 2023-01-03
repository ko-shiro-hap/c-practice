// heap-ki

#include <stdio.h>
#include <stdlib.h>

#define height 4
#define MAX (1<<height)  //ビットシフト演算 2^height と同じ

int t[MAX+1]; //配列外アクセス防止のためのダミーで＋１
int sz = 0;

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void initTree(int n){
    int i;
    for(i=0;i<MAX;i++){
        t[i] = -1;
    }
}

void printA(){
    int i;
    for(i=1;i<=sz;i++) printf("%d ",t[i]);
    printf("\n");
}

void printT(int i){
    int x = i;
    while(x/2!=0){
        printf("  ");
        x/=2;
    }
    printf("%d\n",t[i]);
}

int goP(int i){
    if(i/2 == 0) return 0;
    else return i/2;
}

int goL(int i){
    if(2*i >= MAX) return 0;
    else return 2*i;
}

int goR(int i){
    if(2*i+1 >= MAX) return 0;
    else return 2*i+1;
}

void preOrder(int i){
    if(t[i] == -1) return;
    printT(i);
    preOrder(goL(i));
    preOrder(goR(i));
}

void inOrder(int i){
    if(t[i] == -1) return;
    inOrder(goL(i));
    printT(i);
    inOrder(goR(i));
}

void postOrder(int i){
    if(t[i] == -1) return;
    postOrder(goL(i));
    postOrder(goR(i));
    printT(i);
}

void insBT(int x){
    int k,i = 1;
    for(k=0;k<height;k++){
        if(t[i]==-1){
            t[i] = x;
            sz++;
            return;
        }
        if(x < t[i]) i = goL(i);
        else i = goR(i);
    }
    printf("Error : too high -> %d\n",x);
}

//先頭の要素を取り出す
//ダウンヒープ
int popHeap(){
// 取り出して
// 末尾の要素を根に持ってきて
// 子のうちの大きい方と比較
// 子の方が大きかったら交換
// をHeapが完成するまで繰り返す
// 事前学習資料のP.56～60
  int i = 1;
  int l, r, ma;
  int ret = t[i];
  t[i] = t[sz];
  t[sz] = -1;
  sz--;

  while(i*2 <= sz) {
    l = goL(i);
    r = goR(i);

    if(t[l] < t[r]) {
      ma = r;
    } else {
      ma = l;
    }

    if(t[i] > t[ma]) break;
    swap(&t[i], &t[ma]);
    i = ma;
  }
  return ret;
}

//末尾に要素を追加する
//アップヒープ
void pushHeap(int x){
// 末尾に追加
// 親と比較して、子の方が大きかったら交換
// をHeapが完成するまで繰り返す
  sz++;
  int i = sz;
  int p;

  if(i > MAX-1) {
    printf("Error : out size < %d -> %d\n", MAX-1, i);
    t[sz] = -1;
    sz--;
    return;
  }

  t[sz] = x;
  while(1<i) {
    p = goP(i);
    if(t[i] <= t[p]) return;
    else swap(&t[i], &t[p]);
    i = p;
  }
}

int main(void){
    int i,x,n;
    scanf("%d",&n);
    // 木の初期化
    initTree(n);
    for(i=0;i<n;i++){
        scanf("%d",&t[i+1]);
    }
    sz = n;
    // 中間順で表示
	inOrder(1);

	// pop
	int a=popHeap();
	printf("pop : %d\n",a);
	inOrder(1);

	a = popHeap();
	printf("pop : %d\n",a);
	inOrder(1);

	printf("push : 100\n");
	pushHeap(100);
	inOrder(1);

	printf("push : 30\n");
	pushHeap(30);
	inOrder(1);
    return 0;
}
