	//ここで2次元配列のメモリを動的確保をする

#include <stdio.h>
#include <stdlib.h>

//必要があれば変数などを追加してもOKです

int main(){
    int i,j,k;
    int a,b;
    int **mat;
    scanf("%d %d",&a,&b);

	//ここで2次元配列の動的確保をする
    mat = (int**)malloc(sizeof(int*)*a);

    for(i=0; i<b; i++) {
      mat[i] = (int*)malloc(sizeof(int)*b);
    }

	//ここで2次元配列に数値を代入する
    i = 1;
	  for(j=0; j<a; j++) {
      for(k=0; k<b; k++) {
        mat[j][k] = i;
        i++;
      }
    }

    //以下の部分は表示の部分です
    //いじらなくてOK
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    //さて，最後に忘れずにすることと言えば？
	  for(i=0; i<a; i++) {
      free(mat[i]);
    }
    free(mat);

    return 0;
}
