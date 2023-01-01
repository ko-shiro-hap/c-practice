# include <stdio.h>

int myStrlen(char s[]){
  int i=0;
  while(s[i] != '\0') {
    i++;
  }
  return i;
}

int main(){
    int len;
    char s[100];
    scanf("%s",s);
    len = myStrlen(s);
    printf("%s -> %d\n",s,len);
    return 0;
}
