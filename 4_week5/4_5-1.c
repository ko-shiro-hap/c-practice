// 特定の値のノードを削除する関数 void delX(int x) を実装

// sennkei list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}Node;

Node *head = NULL;

Node* createN(int x){
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

void initL(int n){
    int x,i;
    Node *p;
    scanf("%d",&x);
    head = createN(x);
    p = head;
    for(i=1;i<n;i++){
        scanf("%d",&x);
        p->next = createN(x);
        p = p->next;
    }
}

void freeL(){
    Node *p;
    while(head!=NULL){
        p = head->next;
        free(head);
        head = p;
    }
}

void printN(Node *a){
    if(a == NULL) printf("NULL\n");
    else printf("%d\n",a->val);
}

void printL(){
    Node *p = head;
    while(p != NULL){
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}

Node* getN(int n){
    int i;
    Node *p;
    p = head;
    for(i=1;i<n;i++) p = p->next;
    return p;
}

int countL(){
    int ret = 0;
    Node *p = head;
    while(p!=NULL){
        p = p->next;
        ret++;
    }
    return ret;
}

Node* searchX(int x){
    Node *p;
    for(p=head; p!=NULL; p=p->next){
        if(p->val == x) break;
    }
    return p;
}

void insHead(int x){
    Node *p;        //１
    p = createN(x); //１
    p->next = head; //２
    head = p;       //３
}

void insMiddle(int n, int x){
    int i;
    Node *p,*q;
    p = head;           //１
    for(i=1;i<n;i++){   //２
        p = p->next;    //２
    }
    q = createN(x);     //３
    q->next = p->next;  //４
    p->next = q;        //５
}

void insTail(int x){
    Node *p;
    p = head;               //１
    if(p==NULL){
        head = createN(x);
        return;
    }
    while(p->next != NULL){ //２
        p = p->next;        //２
    }
    p->next = createN(x);   //３
}

void delHead(){
    Node *p;
    p = head;           //１
    head = head->next;  //２
    free(p);            //３
}

void delMiddle(int n){
    int i;
    Node *p,*q;
    p = head;           //１
    for(i=1;i<n-1;i++){ //２
        p = p->next;    //２
    }
    q = p->next;        //３
    p->next = q->next;  //４
    free(q);            //５
}

void delTail(){
    Node *p;
    p = head;                       //１
    while(p->next->next != NULL){   //２
        p = p->next;                //２
    }
    free(p->next);                  //３
    p->next = NULL;                 //４
}

void delX(int x){
	//ここを書く
  int i = 1;
  Node *p;
  for(p=head; p!=NULL; p=p->next) {
    if(x == p->val) break;
    i++;
  }
  if(p==NULL) return;
  else if(i==1) delHead();
  else if(i==countL()) delTail();
  else delMiddle(i);
}

int main(void){
    int i,n,x;
    scanf("%d",&n);
    initL(n);
    scanf("%d",&x);
    delX(x);
    printL();
    freeL();
    return 0;
}

