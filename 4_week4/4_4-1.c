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
    int i,j,k,tmp;
	int m; // 最小値を示すデータのインデックス

    for(i=1;i<n;i++){
    	// 未整理部分の最小を探す
    	tmp = a[i];
		for(j=0;j<i;j++){
			if(tmp<a[j]){
				break;
			}
		}
		for(k=i;k>j;k--){
			a[k]=a[k-1];
		}
		a[j]=tmp;
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
    InsertionSort(v,n);
    printA(v,n);
    free(v);
    return 0;
}
