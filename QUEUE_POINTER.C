#include<stdio.h>
#include<conio.h>
int size;
struct queue{
    int items[20];
    int front,rear;
};
typedef struct queue queue;
void enqueue(queue *ptr){

     if((ptr->rear == size-1 && ptr->front==0) || (ptr->front == ptr->rear + 1)){
	 printf("Overflow...\n");
     }
     else{
	  int data;
	  if(ptr->front==-1){
	     ptr->front = 0;
	  }
	  printf("Enter a number -: ");
	  scanf("%d",&data);
	  ptr->rear = (ptr->rear + 1) % size;
	  ptr->items[ptr->rear] = data;
     }
}

void dequeue(queue *ptr){
     if(ptr->front == -1 && ptr->rear == -1){
	printf("Underflow...\n");
     }
     else{
       printf("Dequeue -: %d\n",ptr->items[ptr->front]);
     }

     if(ptr->front == ptr->rear){
	 ptr->front = -1;
	 ptr->rear = -1;
     }
     else{
	 ptr->front = (ptr->front + 1) % size;
     }
}

void show(queue *ptr){
    if(ptr->front == -1){
       printf("Empty Queue..\n");
    }
    else{
	int i;
	printf("Queue is -: \n");
	for(i=ptr->front;i!=ptr->rear;i=(i+1)%size){
	    printf("%d\n",ptr->items[i]);
	}
	printf("%d\n",ptr->items[i]);
    }
}
void main(){
      int option;
      queue *ptr;
      clrscr();
      printf("Enter a size -: ");
      scanf("%d",&size);
      ptr->front = -1;
      ptr->rear = -1;
      printf("1. Enqueue\t2. Dequeue\t.3. Display\t 0. Exit\n ");
      while(1){
	 printf("\n Enter a option -: ");
	 scanf("%d",&option);
	 switch(option){
	    case 1:
	    enqueue(ptr);
	    break;
	    case 2:
	    dequeue(ptr);
	    break;
	    case 3:
	    show(ptr);
	    break;
	    case 0:
	    exit(0);
	    default:
	    printf("Invalid option ...\n");
	 }
      }
}