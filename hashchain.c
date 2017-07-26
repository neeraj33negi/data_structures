#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int id;
	char name[100];
	struct node *next;
}node;
void search(node**,int,int);
void createHashTable(node**,int);
void insertData(node**,int);
int main(){
	int size,n;
	printf("Enter the size of the hash-table: ");
	scanf("%d",&size);
	node *table[size];
	createHashTable(table,size);
//	printf("%s\n",table[25%size]->name);
//	printf("%s\n",table[25%size]->next->name);
	printf("Enter the ID of the item you want to search: ");
	scanf("%d",&n);
	search(table,n,size);
	return 0;
}
void insertData(node** table, int size){
	int num,id;
	char name[100];
	node **temp;
	printf("How many data items you want to enter?\n");
	scanf("%d",&num);
	while(num--){
		node *newNode = (node *)malloc(sizeof(node));
		newNode->next=NULL;
		printf("Enter the ID: ");
		scanf("%d",&id);
		printf("Enter the name: ");
		scanf("%s",name);
		newNode->id=id;
		strcpy(newNode->name,name);
		temp=&table[id%size];
		if(!(*temp)){
			printf("\nin\n");
			*temp = newNode;
		}else{
			printf("ein\n");
			while((*temp)->next){
				printf("win\n");
				(*temp)=(*temp)->next;
			}
			(*temp)->next=newNode;
		}

	}
}
void createHashTable(node** table, int size){
	for(int i=0;i<size;i++)	table[i]=NULL;
	insertData(table,size);
}
void search(node **table, int id, int size){
	node *temp = table[id%size];
	printf("%d\n",id%size);
	if(!temp){
		printf("INDEX EMPTY\n");
		return;
	}
	while(temp->next){
		printf("Item#%d found with name %s.\n",id,temp->name);
		temp=temp->next;
	}

}

















