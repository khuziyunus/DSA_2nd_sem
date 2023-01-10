       //<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

//using namespace std;


struct tNode {
	struct tNode *left;
	struct tNode *right;
	int data;
};

struct tNode *CreateNewNode (int data){
	struct tNode *temp = (struct tNode *) malloc (sizeof (struct tNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct tNode *insert(struct tNode *root, int data)
{
	if (root == NULL) return CreateNewNode (data);
	if (data <= root->data)  root->left = insert (root->left, data);
	else  root->right = insert (root->right, data);

	int swapped,i;
	struct node* curr;
	struct node* temp = NULL;
	if(root == NULL)
	do
	{
		temp = root;
		swapped =0 ;
		while (temp-> next == cur)
			if(temp.data> temp.next.data)
				swap(tmp.data,temp . next.data)
				swapped+=1
				tmp =tmp.next
				
	} while (swapped);
	

	return root;
}

struct tNode *search (struct tNode *root, int data){
	if (root == NULL) return NULL;
	if (root->data == data) return root;
        else if (root->data > data) return search (root->left, data);
	else return search (root->right, data);
}

struct tNode * findMin (struct tNode *root){
	struct tNode* current = root;
	  
	while (current && current->left != NULL)
            current = current->left;
            
 	return current;

}

struct tNode * deleteTree (struct tNode *root)
{
	if (root == NULL) return NULL;
	root->left = deleteTree (root->left);
	root->right = deleteTree (root->right);
	free (root);
	return NULL;
}

struct tNode *deleteNode (struct tNode *root, int data)
{
	// if tree is empty or node not found
	if (root == NULL) return root;
	// if data is less than root value
	if (data < root->data) root->left = deleteNode (root->left, data);
	// if data is greater than root value
	else if (data > root->data) root->right = deleteNode (root->right, data);
	// if data is equal, which means we can delete the node.
	else { // data is searched....
	       // no child
		if (root->left == NULL && root->right == NULL)
		{
			free (root);
			return NULL;
		}// only right child 
		else if (root->left == NULL)
		{
			struct tNode *temp = root->right;
			free (root);
			return temp;
		} // only left child 
		else if (root->right == NULL)
		{
			struct tNode *temp = root->left;
			free (root);
			return temp;
		} // both children exit
		else{
			// step no. 1
			struct tNode *temp = findMin(root->right);
			// step no. 2 ... copy data
			root->data = temp->data;

			// delete temp->data from right node.
			root->right  = deleteNode (root->right, root->data);
		}
	}
	return root;
}

void iPrint (struct tNode *root)
{
	if (root == NULL) return;
	iPrint (root->left);
	printf ("%d ", root->data);
        iPrint (root->right);	
}

void prPrint (struct tNode *root)
{
	if (root == NULL) return;
        prPrint (root->right);	
	printf ("%d ", root->data);
	prPrint (root->left);
}

/// root = insert (root, 12);
int main (void)

{
	struct tNode *root = CreateNewNode (10);
	struct tNode *left = CreateNewNode (8);
	struct tNode *right = CreateNewNode (12);
	//right->right = CreateNewNode (14);
	root->left = left;
	root->right = right;
	root = insert (root, 7);
    
    findMin(root);
	printf ("Inorder....");
	iPrint (root);
	printf ("\n\nPreOrder...");
	prPrint (root);
	printf ("\n");
	struct tNode *temp = findMin (root);
	if (temp)
		printf ("Minimum value of the tree is %d.\n", temp->data);
	
	temp = search (root, 8);
	if (temp)
		printf ("\n\nSearching 8 is %d...", temp->data);
	root = deleteNode (root, 10);
	printf ("Printing after deletion of 10.\n");
	iPrint (root);

	root = deleteTree (root);
	printf ("\n\nPrinting after deleting the tree...");
	iPrint (root);	
	
	return 0;
}
