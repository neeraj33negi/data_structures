#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
	int data;
	node* left;
	node* right;
};
int lca(node*,int,int);
void insertNode(node**,int);
node *createTree(void);
void preorder(node *);
int main(){
	int a,b;
	node *tree = NULL;
	tree = createTree();
	printf("Enter value of two nodes: ");
	scanf("%d%d",&a,&b);
	printf("LCA of %d and %d is %d\n",a,b,lca(tree,a,b));
	preorder(tree);
	printf("\n");
	return 0;
}
void preorder(node *tree){
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
void insertNode(node **tree,int data){
	if(!(*tree)){
		node *newNode = (node *)malloc(sizeof(node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		*tree = newNode;
		return;
	}
	else{
		if(data>(*tree)->data){
			insertNode(&(*tree)->right,data);
		}else{
			insertNode(&(*tree)->left,data);
		}
	}
}
node *createTree(){
	int n,data;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	node *tree = NULL;
	while(n--){
		printf("Enter node data: ");
		scanf("%d",&data);
		insertNode(&tree,data);
	}
	return tree;
}
int lca(node *tree,int a, int b){
	if((a==tree->data) || (b==tree->data)){
		return tree->data;
	}
	if((a>tree->data && b<tree->data) || (b>tree->data && a<tree->data)){
		return tree->data;
	}
	else if(a>tree->data){
		return lca(tree->right,a,b);
	}else{
		return lca(tree->left,a,b);
	}
}
