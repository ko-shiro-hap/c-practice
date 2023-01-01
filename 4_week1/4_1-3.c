//回文英語の判定

# include <stdio.h>

int isPalindrome(char s[]){
	//関数の中だけを書き換えてください
	//回文になっているとき１を返す
	//回文になっていないとき０を返す
  int i=0, j;

  for(j=0; s[j+1]; j++);
  while(i<=j) {
    if(s[i++]!=s[j--]) return 0;
  }

  return 1;
}

//メイン関数は書き換えなくてよいです
int main(){
    char s[100];
    scanf("%s",s);
    printf("%s -> %d\n",s,isPalindrome(s));
    return 0;
}
