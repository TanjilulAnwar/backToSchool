#include <stdio.h>
#include <stdlib.h>
struct node
{
  int roll;
	struct node *next;
};


struct  node *root=NULL;

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

void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=(struct node*)malloc(sizeof(struct node)); 
		root->roll=roll;
		root->next=NULL;
	}
	else
	{
		struct node *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
	struct node *newnode = (struct node*)malloc(sizeof(struct node)); //create a new node
		newnode->roll=roll;
		newnode->next=NULL;
		
		current_node->next=newnode; //link the last node with new node
	}
}
void delete_node(int roll)
{
	struct node *current_node=root;
	struct node *previous_node=NULL;
	while(current_node->roll!=roll) //Searching node 
	{
		previous_node=current_node; //Save the previous node
		current_node=current_node->next;
	}
	if(current_node==root) //Delete root
	{
		struct node *temp=root; //save root in temporary variable
		root=root->next; //move root forward
		free(temp); //free memory
	}
	else //delete non-root node
	{
		previous_node->next=current_node->next; //previous node points the current node's next node 
		free(current_node); //free current node
	}
	
}
int main(){

int i ;
	for(i=0; i<1000;i=i+10){
append(i);
  }
    struct node *current_node=root;
		while(current_node!=NULL) //loop until you reach null
		{
			if(((current_node->roll)/10) % 2==0){
        delete_node(current_node->roll);
      }
			current_node=current_node->next;
		}


	print();
    return 0;
}
