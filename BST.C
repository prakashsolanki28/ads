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
    else if(root->data < data){
	   root->right = insertData(root->right,data);
    }
    else{
	   root->left = insertData(root->left,data);
    }
    return root;
}

void search(node *root,int data){
     if(root == NULL) return;
     if(root->data == data){
	printf("Data found Successfully...\n");
	return;
     }
     else if(root->data < data){
	 search(root->right,data);
     }
     else{
	 search(root->left,data);
     }
     return;
}

void preorderTra(node *root){
    if(root==NULL) return;  //if Root is Null then return from function
    printf("%d -> ",root->data);
    preorderTra(root->left);
    preorderTra(root->right);
}

void inorderTra(node *root){
    if(root==NULL) return;  //if Root is Null then return from function
    innerorderTra(root->left);
    printf("%d -> ",root->data);
    innerorderTra(root->right);
}

void postorderTra(node *root){
    if(root==NULL) return;
    postorderTra(root->left);
    postorderTra(root->right);
    printf("%d -> ",root->data);
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
     printf("1. Insert Data\t2. Print Tree\t3. Orders\n4. Search");
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
	    case 3:
	    printf("Preorder is -: ");  preorderTra(root);
	    printf("\nPostorder is -: "); postorderTra(root);
	    printf("\nIn Order -: "); innerorderTra(root);
	    break;
	    case 4:
	    printf("Enter a Data for Search -: ");
	    scanf("%d",&data);
	    search(root,data);
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