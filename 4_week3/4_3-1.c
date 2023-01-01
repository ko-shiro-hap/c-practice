// 探したい数 x の，インデックス（何番目）を返す関数

//第3回 課題１
#include <stdio.h>
#include <stdlib.h>

//この関数を実装する
int binary_search(int a[],int n,int x){
	int ret = -1;
	int lef,mid,rig;
	lef = 0;
	rig = n-1;
	while(lef <= rig){
		mid = (lef + rig) /2;
		printf("%d %d %d :%d\n",lef,mid,rig,a[mid]);
		if(a[mid] == x) {
			ret = mid;
			break;
		}
		if(x < a[mid]) rig = mid-1;
		else lef = mid+1;
	}
	return ret;
}

int main(void) {
	int n,x,i;
	int *a;
	int ans = -1;
	scanf("%d %d",&n,&x);
	a = (int*)malloc(sizeof(int)*n);
	if(a==NULL){
		printf("ERROR\n");
		return -1;
	}
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ans = binary_search(a,n,x);
	if(ans != -1) printf("a[%d] = %d\n",ans,a[ans]);
	else printf("not found\n");
	free(a);
	return 0;
}
