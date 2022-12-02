#include<stdio.h>
#include<conio.h>
#define size 5
int top = -1,stack[size];
void push(){

     int element;
     if(top== size - 1){
	 printf("Overflow...\n");
     }
     else{
	  printf("Enter A Element -: ");
	  scanf("%d",&element);
	  top = top + 1;
	  stack[top] = element;
     }
}

void pop(){

    if(top == -1){
       printf("Underflow...\n");
    }
    else{
       printf("Popped Element -: %d",stack[top]);
       top = top - 1;
    }
}

void show(){

    if(top == -1){
       printf("Underflow...\n");
    }
    else{
       int i;
       printf("Elements of Stack -: \n");
       for(i=top;i>=0;--i){
	  printf("%d\n",stack[i]);
       }
    }
}

void main(){

	int option;
	clrscr();
	printf("Operations -:\n");
	printf("1. Push\t2. Pop\t3. Show\t0. Exit\n");
	while(1){
	    printf("\nSelect a Operation -: ");
	    scanf("%d",&option);
	    switch(option){
		case 1:
		push();
		break;
		case 2:
		pop();
		break;
		case 3:
		show();
		break;
		case 0:
		exit();
		default:
		printf("Invalid Operation...\n");
	    }
	}
}