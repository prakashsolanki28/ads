#include<stdio.h>
#include<conio.h>
int queue[20],size,rear = -1, front = -1;
void enqueue(){

     // for full  (rear + 1) % size == front
     if((rear == size-1 && front==0) || (front == rear + 1)){
	 printf("Overflow...\n");
     }
     else{
	  int data;
	  if(front==-1){
	     front = 0;
	  }
	  printf("Enter a number -: ");
	  scanf("%d",&data);
	  rear = (rear + 1) % size;
	  queue[rear] = data;
     }
}
void dequeue(){

     if(front == -1 && rear == -1){
	printf("Underflow...\n");
     }
     else{
       printf("Dequeue -: %d\n",queue[front]);
     }

     if(front == rear){
	 front = -1;
	 rear = -1;
     }
     else{
	 front = (front + 1) % size;
     }
}

void show(){
    if(front == -1){
       printf("Empty Queue..\n");
    }
    else{
	int i;
	printf("Queue is -: \n");
	for(i=front;i!=rear;i=(i+1)%size){
	    printf("%d\n",queue[i]);
	}
	printf("%d\n",queue[i]);
    }
}
void main(){
      int option;
      clrscr();
      printf("Enter a size -: ");
      scanf("%d",&size);
      printf("1. Enqueue\t2. Dequeue\t.3. Display\t 0. Exit\n ");
      while(1){
	 printf("\n Enter a option -: ");
	 scanf("%d",&option);
	 switch(option){
	    case 1:
	    enqueue();
	    break;
	    case 2:
	    dequeue();
	    break;
	    case 3:
	    show();
	    break;
	    case 0:
	    exit(0);
	    default:
	    printf("Invalid option ...\n");
	 }
      }
}