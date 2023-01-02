// バケットソートを作る

// BucketSort
#include <stdio.h>
#include <stdlib.h>

void printA(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int  tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

#define MAX 1000000
void BucketSort(int a[], int n){
    int i,t;
    int b[MAX];
    //ここから下を書く
    for(i=0; i<MAX; i++) {
      b[i] = 0;
  }

  for(i=0; i<n; i++) {
    b[a[i]] = 1;
  }

  t = 0;
  for(i=0; i<MAX; i++) {
    if(b[i] == 1) {
      a[t++] = i;
    }
  }
}

int main(void){
    int n,i;
    int *v;
    scanf("%d",&n);
    v = (int*)malloc(sizeof(int)*n);
    if(v==NULL){
        printf("ERROR\n");
        return -1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    BucketSort(v,n);
    printA(v,n);
    free(v);
    return 0;
}
