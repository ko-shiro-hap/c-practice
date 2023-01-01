// 1をIに変える

#include <stdio.h>

int main(void) {
	int i;
	char s[100];
	scanf("%s",s);
	printf("%s\n  -> ",s);
	//ここを編集する
	//何行になってもよいです
  for(i=0; s[i]!='\0'; i++) {
    if(s[i] == '1') {
      s[i] = 'I';
    }
  }
	//
	printf("%s\n",s);
	return 0;
}
