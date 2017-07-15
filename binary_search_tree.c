#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left, *right;
}node;
void insert(node **,int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
int level(node *,int);
int countNodes(node *);
int heightOfTree(node *);
int leavesCount(node *);
node *findMin(node *);
node *findMax(node *);
node *search(node *, int);
node *deleteNode(node *,int);

int main(){
	node *head = NULL;
	int n,data;
	printf("How many items you want to enter?");
	scanf("%d",&n);
	while(n--){
		printf("Enter data: ");
		scanf("%d",&data);
		insert(&head,data);
	}
	printf("\nPREORDER: ");
	preorder(head);
	printf("\nINORDER: ");
	inorder(head);
	printf("\nPOSTORDER: ");
	postorder(head);
	printf("\n");
	printf("Number of nodes in tree is: %d\n",countNodes(head));
	printf("Number of leaves in the tree are:  %d\n", leavesCount(head));
	printf("Height of the tree is: %d.\n",heightOfTree(head));
	//printf("Level of 10 is: %d\n",level(head,10));
	printf("Minimum element is: %d\n", findMin(head)->data);
	printf("Maximum element is: %d\n", findMax(head)->data);
	printf("Enter the item you want to search: ");
	scanf("%d",&data);
	search(head, data);
	printf("Enter the item you want to delete: ");
	scanf("%d",&data);
	head = deleteNode(head, data);
	inorder(head);
	printf("\n");
	return 0;
}
void insert(node **tree, int data){
	if(!(*tree)){
		*tree = (node *)malloc(sizeof(node));
		(*tree)->data = data;
		(*tree)->left=NULL;
		(*tree)->right=NULL;
		return;
	}else{
		if(data<(*tree)->data){
			insert(&(*tree)->left,data);
		}else{
			insert(&(*tree)->right,data);
		}
	}
}
void preorder(node *tree){
	if(tree){
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
void inorder(node *tree){
	if(tree){
		inorder(tree->left);
		printf("%d ",tree->data);
		inorder(tree->right);
	}
}
void postorder(node *tree){
	if(tree){
		postorder(tree->left);
		postorder(tree->right);
		printf("%d ",tree->data);
	}
}
int countNodes(node *tree){
	if(!tree){
		return 0;
	}
	return (1 + countNodes(tree->left) + countNodes(tree->right));
}
int heightOfTree(node *tree){
	if(!tree){
		return 0;
	}
	if(!tree->left && !tree->right){
		return 0;
	}
	int l,r;
	l = heightOfTree(tree->left);
	r = heightOfTree(tree->right);
	return ((l>r)?l:r) + 1;
}
int leavesCount(node *tree){
	if(!tree) return 0;
	if(!(tree->left) && !(tree->right))	return 1;
	return leavesCount(tree->left) + leavesCount(tree->right);
}
int level(node *tree, int item){
	if(!tree){
		printf("\nTREE DOESN't EXIST\n");
		return -1;
	}
	if(item == tree->data){
		return 0;
	}
	if(item<tree->data){
		return 1 + level(tree->left,item);
	}
	if(item>tree->data){
		return 1 + level(tree->right, item);
	}

}
node *findMin(node *tree){
	node *temp = tree;
	while(temp->left)	temp = temp->left;
	return temp;
}
node *findMax(node *tree){
	node *temp = tree;
	while(temp->right) temp=temp->right;
	return temp;
}

node *search(node *tree, int item){
	if(!tree){
		printf("\nITEM NOT FOUND!\n");
		return NULL;
	}
	if(item==tree->data){
		printf("\nITEM FOUND!\n");
		return tree;
	}
	if(item<tree->data){
		return search(tree->left, item);
	}
	if(item>tree->data){
		return search(tree->right, item);
	}
}
node *deleteNode(node *head, int item){
	if(!head){
		return head;
	}
	if(item<head->data){
		head->left = deleteNode(head->left,item);
	}
	else if(item>head->data){
		head->right = deleteNode(head->right,item);
	}else{
		if(!head->left){
			node *temp = head->right;
			free(head);
			return temp;
		}else if(!head->right){
			node *temp = head->left;
			free(head);
			return temp;
		}else{
			node *temp = findMin(head->right);
			head->data = temp->data;
			head->right = deleteNode(head->right,head->data);
		}
	}
	return head;
}




















