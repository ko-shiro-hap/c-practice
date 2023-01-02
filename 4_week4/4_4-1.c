// 単純挿入ソートを作る

// InsertionSort

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

void InsertionSort(int a[], int n){
	//ここを書く
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
    InsertionSort(v,n);
    printA(v,n);
    free(v);
    return 0;
}
