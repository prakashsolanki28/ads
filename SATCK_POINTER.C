#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5

// Define Stack Structure
struct 	stack{
   int items[size];
   int top;
};
//typedef struct stack stack;
void push(struct stack *ptr){

     if(ptr->top == size - 1){
	printf("Overflow...\n");
     }
     else{
	int item;
	printf("Enter a Item -: ");
	scanf("%d",&item);
	ptr->top++;
	ptr->items[ptr->top] = item;
     }
}

void pop(struct stack *ptr){
    if(ptr->top == -1){
	printf("Underflow...\n");
    }
    else{
	printf("Item popped : %d",ptr->items[ptr->top]);
	ptr->top--;
    }
}
void show(struct stack *ptr){

     int i;
     printf("Items is -: \n");
     for(i = ptr->top; i>= 0;i--){
	 printf("%d on -: %d\n",i,ptr->items[i]);
     }
}
void main(){

	int option;
	struct stack *ptr;
	ptr->top = -1;
	clrscr();
	while(1){
	     int val;
	     printf("\nEnter a option -: ");
	     scanf("%d",&option);
	     switch(option){
		case 1:
		push(ptr);
		break;
		case 2:
		pop(ptr);
		break;
		case 3:
		show(ptr);
		break;
		case 0:
		exit(0);
		default:
		printf("Invalid Option...\n");
	     }
	}

}