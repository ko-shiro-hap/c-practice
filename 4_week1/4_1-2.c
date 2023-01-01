// 大文字と小文字を関係なく比較する

# include <stdio.h>

int fuzzyStrcmp(char s[], char t[]){
	//関数の中だけを書き換えてください
	//同じとき１を返す，異なるとき０を返す
  for(int i=0; s[i]==t[i] || s[i]==t[i]+32 || s[i]==t[i]-32; i++){
    if(s[i]=='\0'){
      return 1;
    }
  }
  return 0;
}

//メイン関数は書き換えなくてできます
int main(){
    int ans;
    char s[100];
    char t[100];
    scanf("%s %s",s,t);
    printf("%s = %s -> ",s,t);
    ans = fuzzyStrcmp(s,t);
    printf("%d\n",ans);
    return 0;
}
