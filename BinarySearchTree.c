#include <stdio.h>
#include <stdlib.h>


struct node
{
	int roll;
	struct node *left, *right;

};


struct node *root;

void insert(int roll)
{
	if(root==NULL) //first node in tree
	{
		root=(struct node*)malloc(sizeof(struct node)); ;
		root->roll=roll;
    root->left = root->right = NULL;
	}
	else
	{
		struct node *current=root,*parent;
		while(current!=NULL)
		{
				if(roll<current->roll)
				{
					parent=current; //keep track of parent node
					current=current->left;
				}
				else
				{
					parent=current;
					current=current->right;
				}
		}
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->roll=roll;
		if(newnode->roll<parent->roll) parent->left=newnode;
		else parent->right=newnode;
	}}

    void print_preorder(struct node *current)
{
	if(current==NULL) return;
	printf("%d\n",current->roll);
	print_preorder(current->left);
	print_preorder(current->right);
	
}
// Inorder Traversal??
void print_inorder(struct node *current)
{
  if (current == NULL) return;
  
    print_inorder(current->left);
    printf("%d\n",current->roll);
    print_inorder(current->right);
  
}


int main(){

int i ;

insert(6);
insert(9);
insert(12);
insert(17);
insert(55);
insert(29);
insert(45);
    printf("Pre-order\n");
	print_preorder(root);

  printf("In-order\n");
	print_inorder(root);
return 0;
}
