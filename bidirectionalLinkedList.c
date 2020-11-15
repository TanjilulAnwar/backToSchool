#include <stdio.h>
#include <stdlib.h>
struct node
{
	int roll;
	struct node *next, *prev;
};
struct node *root, *tail;
void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=(struct node*)malloc(sizeof(struct node));;
		root->roll=roll;
		root->next=NULL;
		tail=root;
	}
	else
	{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));;
		newnode->roll=roll;
		newnode->next=NULL;
		tail->next=newnode; //add the new node after tail node
		tail=tail->next; //move tail pointer forward
	}
}


void print()
{
		struct node *current_node=root;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->roll);
      	printf("%p\n",current_node->next);
			current_node=current_node->next;
		}
}

int main(){

int i ;
	for(i=0; i<1000;i=i+10){
append(i);
  }
    
	print();
    return 0;
}
