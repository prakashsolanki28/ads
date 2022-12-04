#include<stdio.h>
#include<conio.h>
int size = 0;
struct node{
   struct node *pre;   // here pre is pervious(Hold 1 back Node Address)
   int data;
   struct node *next;  // Hold Next Node Address
};
typedef struct node node;
node *head = NULL;
int createNode(int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    size++;
    return newnode;
}
int endNode()
{
   node *ptr;
   ptr = head;
   while(ptr->next != NULL){
       ptr = ptr->next;
   }
   return ptr;
}
int nodeAt(int index){
    int count = 0;
    node *ptr;
    ptr = head;
    while(count < index){
       ptr = ptr->next;
       count++;

    }
    return ptr;
}
void insertFirst(int data){
     node *newnode;
     newnode = createNode(data);
     newnode->pre = NULL;
     newnode->next = head;
     head->pre = newnode;
     head = newnode;
}
void insertLast(int data){
     if(head == NULL){
	 insertFirst(data);
     }
     else{
	node *ptr;
	node *newnode;
	ptr = endNode();
	newnode = createNode(data);
	newnode->next = NULL;
	ptr->next = newnode;
	newnode->pre = ptr;
     }
}
void insertAt(int data,int index){
     if(head == NULL || index == 0){
	insertFirst(data);
     }
     else if(index == size){
	insertLast(data);
     }
     else{
	int count = 0;
	node *ptr;
	node *pre;
	node *newnode;
	ptr = head;
	while(count < index){
	   pre = ptr;
	   ptr = ptr->next;
	   count++;
	}
	newnode = createNode(data);
	newnode->pre = pre;
	newnode->next = ptr;
	pre->next = newnode;
	ptr->pre = newnode;
     }
}
void updateFirst(int data){
   if(head == NULL){
      printf("List is Empty...\n");
   }
   else{
      head->data =  data;
   }
}
void updateLast(int data){
   if(head == NULL){
      printf("List is Empty...\n");
   }
   else{
      node *ptr;
      ptr = endNode();
      ptr->data = data;
   }
}
void updateAt(int data,int index){
    if(head == NULL){
       printf("List is Empty...\n");
    }
    else if(index == 0){
       updateFirst(data);
    }
    else if(index == size){
       updateLast(data);
    }
    else{
       node *ptr;
       ptr = nodeAt(index);
       ptr->data = data;
    }
}
void deleteFirst(){
   if(head == NULL){
       printf("List is Empty ...\n");
   }
   else{
       node *next;
       next = head->next;
       free(head);
       next->pre = NULL;
       head = next;
	   size--;
   }
}
void deleteLast(){
   if(head == NULL){
       printf("List is Empty ...\n");
   }
   else{
      node *ptr;
      node *pre;
      ptr = endNode();
      pre = ptr->pre;
      pre->next = NULL;
      free(ptr);
	  size--;
   }
}
void deleteAt(int index){
    if(head == NULL){
       printf("List is Empty ...\n");
    }
	else if(size == 0){
		deleteFirst();
	}
	else if(size == index){
		deleteLast();
	}
    else{
       node *pre;
       node *ptr;
       ptr = nodeAt(index);
       pre = ptr->pre;
       pre->next = ptr->next;
       ptr->next->pre = pre;
       free(ptr);
	   size--;
    }
}
void getAllDesc(){
     node *ptr;
     ptr = head;
     if(ptr == NULL){
	printf("List is Empty...\n");
     }
     else{
	printf("\n------------ -- List -- ---------------\n");
	while(ptr != NULL){
	   printf("| pre - Address of %d | data - %d | next - Address of %d |\n",ptr->pre,ptr->data,ptr->next);
	   ptr = ptr->next;
	}
	printf("\n----------------------------------------\n");
     }
}
void getAll(){
     node *ptr;
     ptr = head;
     if(ptr == NULL){
	printf("List is Empty...\n");
     }
     else{
	printf("\n------------ -- List -- ---------------\n|");
	while(ptr != NULL){
	   printf(" %d |",ptr->data);
	   ptr = ptr->next;
	}
	printf("\n----------------------------------------\n");
     }
}

void search(int data){

	if(head==NULL){
		printf("Link list is Empty....\n");
	}
	else{
		int count=0,index=0;
		node *ptr;
		ptr = head;
		while(ptr != NULL){
			if(data == ptr->data){
				printf("Data %d Found Successfully on Index -: %d",data,index);
				break;
			}
			index ++;
			ptr = ptr->next;
		}
	}
}
void options()
{
     printf("-------- Doubly Linklist --------\n");
     printf("What option perform on List\n");
     printf("1. Insert\n2. Update\n3. Delete\n4. Traversing\n5. Searching\n0. Exit\n");
     printf("---------  --- --- ---  ---------\n");
}
void suboptions(int where)
{
   clrscr();
   if(where == 1){
	printf("----- Doubly Linklist(INSERT) -----\n");
	printf("Where Insert Data in List -: \n");
	printf("1. Insert First\n2. Insert Last\n3. Insert At\n4. Back\n0. Exit\n");
	printf("---------  --- --- ---  ---------\n");
   }
   else if(where == 4){
	printf("----- Doubly Linklist(Traversing) -----\n");
	printf("Select Data from List -: \n");
	printf("1. Get All\n2. Get Data With Full Desc\n3. Back\n0. Exit\n");
	printf("---------  --- --- ---  ---------\n");
   }
   else if(where == 2){
	printf("----- Doubly Linklist(UPDATE) -----\n");
	printf("Where Update Data in List -: \n");
	printf("1. Update First\n2. Update Last\n3. Update At\n4. Back\n0. Exit\n");
	printf("---------  --- --- ---  ---------\n");
   }
   else if(where == 3){
	printf("----- Doubly Linklist(DELETE) -----\n");
	printf("Where Data Delete in List -: \n");
	printf("1. Delete First\n2. Delete Last\n3. Delete At\n4. Back\n0. Exit\n");
	printf("---------  --- --- ---  ---------\n");
   }
}

int getData(){
    int data;
    printf("Enter a Data -: ");
    scanf("%d",&data);
    return data;
}

void welcome(){
    printf("Doubly Linklist\n");
    printf("Doubly Linked list in which a node contains a pointer to the previous as well as the next node in the sequence.\n");
	printf("in a doubly linked list, a node consists of three parts: node data, pointer to the next node in sequence (next pointer) , pointer to the previous node (previous pointer).\n");
	printf("Operations regarding doubly linked list. ");
	printf("--------------------------------------------------\n");
	printf("|\t1. | Insertion at beginning \t\n");
	printf("|\t2. | Insertion at End \t\n");
	printf("|\t3. | Insertion After specified Node \t\n");
	printf("|\t4. | Update at beginning \t\n");
	printf("|\t5. | Update at End \t\n");
	printf("|\t6. | Update After specified Node \t\n");
	printf("|\t7. | Deletion at beginning \t\n");
	printf("|\t8. | Deletion at End \t\n");
	printf("|\t9. | Deletion After specified Node\t\n");
	printf("|\t10. | Traversing\t\n");
	printf("|\t11. | Searching\t\n");
	printf("\n--------------------------------------------------\n");
	printf("Press Enter To Start Program ....");
}

int getIndex(){
    int index;
    printf("Enter a Index -: ");
    scanf("%d",&index);
    if(index > size || index < 0){
       return NULL;
    }
    else{
      return index;
    }
}
void main(){
	int option,suboption;
	clrscr();
	welcome();
	getch();
	clrscr();
	options();
	while(1){
	    printf("\nPlease Enter Your Choice -:");
	    scanf("%d",&option);
	    if(option < 0){
	       printf("Error : Can't use Negative Number..");
	       continue;
	    }
	    suboption = 0;
	    switch(option){
		case 1:
		   suboptions(option);
		   if(head != NULL){ getAll(); }
		   while(1 && suboption != 4){
			printf("\nPlease Enter your Choice -: ");
			scanf("%d",&suboption);
			switch(suboption){
			   case 0:
			   exit(0);
			   case 1:
			   insertFirst(getData());
			   break;
			   case 2:
			   insertLast(getData());
			   break;
			   case 3:
			   insertAt(getData(),getIndex());
			   break;
			   case 4:
			   clrscr();
			   options();
			   break;
			   default:
			   printf("Enter a Valid Option...\n");
			}

			if(suboption !=4){
			   clrscr();
			   suboptions(option);
			   getAll();
			}
		   }
		break;
		case 2:
		   suboptions(option);
		   if(head != NULL) { getAll(); }
		   while(1 && suboption != 4){
			printf("\nPlease Enter your Choice -: ");
			scanf("%d",&suboption);
			switch(suboption){
			   case 0:
			   exit(0);
			   case 1:
			   updateFirst(getData());
			   break;
			   case 2:
			   updateLast(getData());
			   break;
			   case 3:
			   updateAt(getData(),getIndex());
			   break;
			   case 4:
			   clrscr();
			   options();
			   break;
			   default:
			   printf("Enter a Valid Option...\n");
			}
			if(suboption !=4 ){
			   clrscr();
			   suboptions(option);
			   getAll();
			}
		   }
		break;
		case 3:
		suboptions(option);
		   if(head != NULL) { getAll(); }
		   while(1 && suboption != 4){
			printf("\nPlease Enter your Choice -: ");
			scanf("%d",&suboption);
			switch(suboption){
			   case 0:
			   exit(0);
			   case 1:
			   deleteFirst();
			   break;
			   case 2:
			   deleteLast();
			   break;
			   case 3:
			   deleteAt(getIndex());
			   break;
			   case 4:
			   clrscr();
			   options();
			   break;
			   default:
			   printf("Enter a Valid Option...\n");
			}
			if(suboption !=4 ){
			   clrscr();
			   suboptions(option);
			   getAll();
			}
		   }
		break;
		case 4:
		   suboptions(4);
		   while(1 && suboption != 3){
			printf("\nPlease Enter your Choice -: ");
			scanf("%d",&suboption);
			switch(suboption){
			   case 1:
			   getAll();
			   break;
			   case 2:
			   getAllDesc();
			   break;
			   case 3:
			   clrscr();
			   options();
			   break;
			   case 0:
			   exit(0);
			   default:
			   printf("Enter a Valid Option...\n");
			}
		     }
		break;
		case 5:
		search(getData());
		break;
		case 0:
		exit();
		default:
		printf("Invalid option...\n");
	    }
       }
   getch();
}