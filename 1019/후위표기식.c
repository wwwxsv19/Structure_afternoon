#include <stdio.h>

#define MAX 300

typedef struct{
	int data[MAX];
	int top;
} Stack;

void initStack(Stack* s){
	s->top = -1;
}
int isEmpty(Stack* s){
	return s->top == -1; 
}
int isFull(Stack* s){
	return s->top == MAX-1;
}

void push(Stack* s, int data){
	if(!isFull(s)){
		s->data[++s->top] = data;
	}
}

int pop(Stack* s){
	if(!isEmpty(s)){
		return s->data[s->top--];
	}
}

int main(){
	int n, m;
	char a, expr[MAX];
	Stack s;
	
	initStack(&s);
	
	fgets(expr, MAX, stdin);
	
	for(int i=0; expr[i]!='\0'; i++){
		a = expr[i];
		if(a != ' ' && a >= '1' && a <= '9') push(&s, a-'0'); 
		else if( a == '+' || a == '-' || a == '*'){
			n = pop(&s); 
			m = pop(&s);
			switch(a){
				case '+': push(&s, n+m); break;
				case '-': push(&s, m-n); break;
				case '*': push(&s, n*m); break;
			}
		}
	}
	
	printf("%d", pop(&s));
	
	return 0;
}