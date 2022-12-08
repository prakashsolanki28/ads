#include<stdio.h>
#include<conio.h>
int size = 0;
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
node *createNode(data){
     node *newnode;
     newnode = (node*)malloc(sizeof(node));
     newnode->data = data;
     size++;
     return newnode;
}
node *endNode(){

    node *ptr;
    ptr = head;
    while(ptr->next != NULL){
       ptr = ptr->next;
    }
    return ptr;
}
void insertFirst(int data)
{
     node *num;
     num = createNode(data);
     num->next = head;
     head = num;
}
// Insert Data on Last index of Link list
void insertLast(int data){

    if(head==NULL){
	insertFirst(data);
	return;
    }
    else{
	node *num,*ptr;
	num = createNode(data);
	num->next = NULL;
	ptr = endNode();
	ptr->next = num;
    }
}
// Insert on Index
void insertAt(int data,int index)
{
    int count = 0;
    if(index > size || index < 0){
       printf("Index is Out of Range...\n");
    }
    else if(index==0){
       insertFirst(data);
    }
    else if(index == size){
       insertLast(data);
    }
    else{
	node *num;
	node *ptr;
	node *pre;
	num = createNode(data);
	ptr = head;
	while(count < index){
	     pre = ptr;
	     ptr = ptr->next;
	     count++;
	}
	num->next = ptr;
	pre->next = num;
    }
}
// Update First
void updateFirst(int data){
    head->data = data;
}
void updateLast(int data){
    node *ptr;
    ptr = endNode();
    ptr->data = data;
}
int updateAt(int data,int index)
{
    int count = 0;
    node *ptr;
    if(head == NULL){
       printf("List is empty...\n");
       return 0;
    }
    if(index > size){
       printf("Out of Range...\n");
       return 0;
    }
    ptr = head;
    while(ptr != NULL){
	if(count == index){
	   ptr->data = data;
	   return 0;
	}
	ptr = ptr->next;
	count++;
    }
    return 0;
}
// Remove First
void removeFirst()
{
   node *ptr;
   ptr = head->next;
   free(head);
   head = ptr;
   size--;
}
void removeLast(){

   if(head == NULL){
      printf("List is already Empty...\n");
   }
   else if(size==0){
      removeFirst();
   }
   else{
      node *ptr,*pre;
      ptr = head;
      while(ptr->next != NULL){
	  pre = ptr;
	  ptr = ptr->next;
      }
      pre->next = NULL;
      free(ptr);
      size--;
   }
}
void removeAt(int index)
{
     int count = 0;
     if(head==NULL){
	 printf("Listis Empty...\n");
     }
     else if(index==0)
     {
	 removeFirst();
     }
     else if(index==size){
	 removeLast();
     }
     else{
	node *ptr,*pre;
	ptr = head;
	while(count < index){
	   pre = ptr;
	   ptr = ptr->next;
	   count++;
	}
	pre->next = ptr->next;
	free(ptr);
	size--;
     }
}

void getFirst(){
    if(head == NULL){
       printf("Data Not Found in list\n");
    }
    else{
       printf("First Data of List -: %d\n",head->data);
    }
}

void getLast(){

    if(head == NULL){
       printf("Data not found in list\n");
    }
    else{
	node *ptr;
	ptr = endNode();
	printf("Last Data of Liast -: %d\n",ptr->data);
    }
}

void getAt(int index){
   if(head == NULL){
      printf("Data Not found in List\n");
   }
   else if(index > size || index < 0){
      printf("Out of Range Index...\n");
   }
   else if(index==0){
      getFirst();
   }
   else if(index == size){
      getLast();
   }
   else
   {
       int count = 0;
       node *ptr;
       ptr = head;
       while(count < index){
	   ptr = ptr->next;
	   count++;
       }
       printf("Data of index %d -: %d\n",index,ptr->data);
   }
}


// Get All Node Of link list
int getAll()
{
    int i;
    node *ptr;
    if(head == NULL){
       printf("List is Empty..\n");
       return 0;
    }
    ptr = head;
    printf("List is -: ");
    while(ptr != NULL){
	printf(" %d | ",ptr->data);
	ptr = ptr->next;
    }
    printf("\n");
    return 0;
}

void options(){
    clrscr();
    printf("Select Option\n");
    printf("0. Show Option\t1. Clear Screen\t2. Exit\n");
    printf("11. Insert First\t 12. Insert Last\t13. Insert At\n");
    printf("21. Update First\t 22. Update Last\t23. Update At\n");
    printf("31. Remove First\t 32. Remove Last\t33. Remove At\n");
    printf("41. Select First\t 42. Select Last\t43. Select At\t44. Select All\n");
}

int getData(){
    int data;
    printf("Enter a Data -: ");
    scanf("%d",&data);
    return data;
}

int getIndex(){
   int index;
   printf("Enter a Index -: ");
   scanf("%d",&index);
   return index;
}

int search(int data){

     int index=0;
     node *ptr;
     ptr = head;
     if(head==NULL){
	printf("List Is Empty...\n");
	return 0;
     }

     while(ptr->next != NULL){
	if(ptr->data == data){
	   printf("Data found Successfully. on index : %d\n",index);
	   return 0;
	}
	index++;
	ptr = ptr->next;
     }

     printf("Data Not found..\n");
     return 0;
}
void main()
{
	int option,data,index;
	clrscr();
	options();
	while(1){
	   printf("Enter a Option -: ");
	   scanf("%d",&option);
	   switch(option){
		case 0:
		options();
		break;
		case 1:
		clrscr();
		options();
		break;
		case 2:
		exit(0);
		break;
		case 3:
		search(getData());
		case 11:
		insertFirst(getData());
		break;
		case 12:
		insertLast(getData());
		break;
		case 13:
		insertAt(getData(),getIndex());
		break;
		case 21:
		updateFirst(getData());
		break;
		case 22:
		updateLast(getData());
		break;
		case 23:
		updateAt(getData(),getIndex());
		break;
		case 31:
		removeFirst();
		break;
		case 32:
		removeLast();
		break;
		case 33:
		removeAt(getIndex());
		break;
		case 41:
		getFirst();
		break;
		case 42:
		getLast();
		break;
		case 43:
		getAt(getIndex());
		break;
		case 44:
		getAll();
		break;
		default:
		printf("Invalid Option...\n");
		break;
	   }
	}
}