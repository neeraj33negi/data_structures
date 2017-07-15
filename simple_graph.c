#include<stdio.h>
#include<stdlib.h>

//node structure for linked representation
typedef struct linkNode{
	int data;
	struct linkNode *next;
}node;
void readGraph(node *[],int);
void printGraph(node *[],int);
int main(){
	int num;
	printf("Enter number of nodes: ");
	scanf("%d",&num);
	node *graph[num];
	readGraph(graph,num);
	printGraph(graph,num);
	return 0;
}
void readGraph(node *nodes[],int num){
	int i,j,val,k;
	node *prev=NULL;
	//newNode->next = NULL;
	for(i=0;i<num;i++){
		nodes[i]=NULL;
	}
	for(i=0;i<num;i++){
		printf("\nEnter the number of neigbours of node %d: ",i+1);
		scanf("%d",&k);
		for(j=0;j<k;j++){
			node *newNode = (node *)malloc(sizeof(node));
			printf("Enter the neigbour %d of node %d: ",j+1,i+1);
			scanf("%d",&val);
			newNode->data = val;
			newNode->next = NULL;
			if(!nodes[i])
				nodes[i] = newNode;
			else
				prev->next = newNode;
			prev = newNode;
		}
	}
}
void printGraph(node *nodes[], int num){
	int i,j;
	node *temp;
	for(i=0;i<num;i++){
		temp = nodes[i];
		printf("\nNeigbours of node %d are: ",i+1);
		while(temp->next){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);
	}
	printf("\n");
}
