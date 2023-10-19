#include <stdio.h>

#define MAX 10

typedef struct s{
	int data[MAX];
	int* top;
} Stack;

void initStack(Stack* s){
	s->top = -1;
}

void isEmpty(Stack* s){
	return s->top == -1;
}
void isFull(Stack* s){
	return s->top == MAX-1;
}

void push(Stack* s, int data){
	if(isFull(s)){
		printf("Full\n");
		return ;
	}
	s->data[++s->top] = data;
}

int pop(Stack* s){
	if(isEmpty(s)){
		printf("Empty\n");
		return 0;
	}
	return s->data[s->top--];
}

int main(){
	int menu, data;
	Stack s;
	initStack(&s);
	
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("데이터 입력 : ");
				scanf("%d", &data);
				push(&s, data);
				break;
			case 2 :
				data = pop(&s);
				if(data) printf("pop 데이터 : %d\n", data);
				break;
			case 0 :
				break;
			default :
				printf("잘못된 입력 입니다. \n");
				break;
		}
	}while(menu);
	
	return 0;
}
