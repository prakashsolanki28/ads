#include<stdio.h>
#include<conio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
// for Create Node
node* createNode(data){
     // malloc -> memory allocate for new Node
     node *newnode = (node *)malloc(sizeof(node));
     newnode->data = data;
     // set left or right child Null in Newnode
     newnode->left = NULL;
     newnode->right = NULL;
     return newnode;
}
/*
    in pree Order Root node exist before left and Right
    ---  Root Node : L Child : R Child  ---
*/
void preorderTra(node *root){
    if(root==NULL) return;  //if Root is Null then return from function
    printf("%d -> ",root->data);
    preorderTra(root->left);
    preorderTra(root->right);
}
/*
    in in Order Root node exist between left and Right
    ---  L Child : RootNode : R Child  ---
*/
void inorderTra(node *root){
    if(root==NULL) return;  //if Root is Null then return from function
    inorderTra(root->left);
    printf("%d -> ",root->data);
    inorderTra(root->right);
}
/*
    in Post Order Rote node exist after left and Right
    ---  L Child : R Child : RootNode  ---
*/
void postorderTra(node *root){
    if(root==NULL) return;
    postorderTra(root->left);
    postorderTra(root->right);
    printf("%d -> ",root->data);
}

// for New Create Tree
node *treeInput(int where){
   node *root,*leftTree,*rightTree;
   int data;
   // When Create New Node then show
   if(where==0){ printf("Root Node is -: "); }
   // When Create left child of Node then show
   if(where==1){ printf("Left Child Node of %d -: ",root->data);}
   // when Create Right child of Node then show
   if(where==2){ printf("Right Child Node of %d -: ",root->data);}
   scanf("%d",&data);
    // if User enter -1 means root node is last leaf node
   if( data == -1){ return NULL; }
   root = createNode(data);  //  create node
   leftTree = treeInput(1);  //  create left child
   rightTree = treeInput(2); // create Right child
   root->left = leftTree;
   root->right = rightTree;
   return root;   // return root for data print
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
void options(){
   printf("Options -: \n");
   printf("1. Create Tree\t2. Print Tree \n3. Preorder Tree\t4. Postorder Tree.\t Innserorder Tree\n");

}
void main(){

   node *root = NULL;
   int option;
   clrscr();
   options();
   while(1){
       printf("\nSelect a Option -: ");
       scanf("%d",&option);
       if(option != 1){
	  if(root != NULL){
	   //  clrscr();
	    // options();
	     printf("\nTree  is -:\n ");
	  }
	  else{
	      printf("List is Empty..\n");
	  }
       }
       switch(option){
	   case 1:
	   root = treeInput(0);
	   break;
	   case 2:
	   printTree(root);
	   break;
	   case 3:
	   preorderTra(root);
	   break;
	   case 4:
	   postorderTra(root);
	   break;
	   case 5:
	   inorderTra(root);
	   break;
	   default:
	   exit(0);
       }
   }
}