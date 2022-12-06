#include<conio.h>
#include<stdio.h>
struct node{
     int data;
     struct node *left;
     struct node *right;
};
typedef struct node node;
node *createNode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insertData(node *root,int data){

    if(root == NULL){
       root = createNode(data);
    }
    else
    {
	if(root->data < data){
		root->right = insertData(root->right,data);
	}
	else{
		root->left = insertData(root->left,data);
	}
    }

    return root;
}

void printTree(node *root){
    if(root == NULL) return;
    printf("%d : ",root->data);
    if(root->left != NULL)
	printf("L %d ",root->left->data);
    if(root->right != NULL)
	printf("R %d ",root->right->data);
    if(root->right == NULL && root->left == NULL) printf(" Leaf Node");
    printf("\n");
    printTree(root->left);
    printTree(root->right);
}
void main(){
     node *root = NULL;
     int option,data;
     clrscr();
     printf("1. Insert Data\t2. Print Tree\n");
     while(1){
	printf("\nEnter a option -: ");
	scanf("%d",&option);
	switch(option){
	    case 1:
	    printf("Enter a value -: ");
	    scanf("%d",&data);
	    root = insertData(root,data);
	    break;
	    case 2:
	    printTree(root);
	    break;
	    case 0:
	    exit(0);
	    default:
	    printf("Invalid option ....\n");
	}
     }
    // root = createTree();
     //printTree(root);

     //getch();
}