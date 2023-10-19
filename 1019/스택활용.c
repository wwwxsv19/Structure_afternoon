#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
	char data[MAX];
	int top;
} Stack;

void initStack(Stack* s){
	s->top = -1;
}
int isFull(Stack* s){
	return s->top == MAX -1;
}
int isEmpty(Stack* s){
	return s->top == -1;
}

void push(Stack* s, char data){
	if(isFull(s)){
		return;
	}
	s->data[++s->top] = data;
}

void pop(Stack* s){
	if(isEmpty(s)){
		return ;
	}
	else{
		printf("%c", s->data[s->top--]);
	}
}

int main(){
	int i, n;
	char str[MAX];
	Stack s;
	
	initStack(&s);
	
	printf("문자열 입력 : ");
	scanf("%s", str);
	
	for(i=0; str[i]!='\0'; i++){
		push(&s, str[i]);
	}
	
	while(!isEmpty(&s)){
		pop(&s);
	}
	
	return 0;
}
