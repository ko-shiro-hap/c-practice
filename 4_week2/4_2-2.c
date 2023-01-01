// 回文を作る

#include <stdio.h>
#include <stdlib.h>

int myStrlen(char s[]){
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

// 関数の中でtmpに対してmallocして
// そこに回文を代入してreturnで返しましょう
char *setPalindrome(char s[]){
	char *tmp;
	//以下に必要な宣言を含めて書いてください
  int i, size = myStrlen(s);
  tmp = (char*)malloc(sizeof(char)*size*2);
  if(tmp == NULL){
    printf("ERROR\n");
    return NULL;
  }

  for(i=0; i<size; i++) {
    tmp[i] = s[i];
  }
  for(i=0; i<size; i++) {
    tmp[size+i] = s[size-i-1];
  }

  return tmp;
}


//メイン関数はいじる必要はありません
int main(){
    int i;
    char nyuryoku[1024]; //入力
    char *kaibun;   //回文を受け取る
    scanf("%s",nyuryoku);
    kaibun = setPalindrome(nyuryoku);
    printf("%s\n  -> %s\n",nyuryoku,kaibun);
    free(kaibun);
    return 0;
}
