#include<bits/stdc++.h>
using namespace std;


struct node
{
    struct node * left;
    struct node * right;
    int data;
};

struct node* insert(struct node* head,int data)
{

    if(head == NULL) return Createnode(data);
    if(data <  head->data)     return head->left = Createnode(data);
    if (data> head->data )return head->right = Createnode(data);
    else   
        head->right = insert((head->right),data); 
}
struct node * Createnode(int x)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
}
struct node *search(struct node *head,int data)
{
    struct node* temp = head;
        if (head == NULL)
            return head;
        if(temp->data = data)   
            return temp;
        else
            return temp = search(temp->right,data);//
}
struct node* FindMin(struct node*head)
{
    struct node* tmp = head;

    if(tmp == NULL) return head;
    while (tmp && tmp->left != NULL)
        tmp =tmp->left;
    return tmp;
}
struct node *deletetree(struct node *head)
{
    struct node*tmp = head;
    if(tmp == NULL) return head ;
    delete(tmp->left);
    delete(tmp->right);
    free(tmp);
    return NULL;
}
struct node * deletenode(struct node * head, int data)
{

    if(head == NULL) return head;
    if(data < head->data)return deletenode(head->left,data);
    if(data > head->data)return deletenode(head->right,data);
    else
    {
        if (head->left == NULL && head->right == NULL)
        {
            free(head);
            return NULL;
        }
        
        if(head->left == NULL)
            {
                struct node*tmp = head->right;
                    free(head);
                return tmp;
            }
        if (head->right == NULL)
            {
                struct node* tmp = head->left;
                free(head);
                return tmp;
            }
        else
            {
                struct node*temp = FindMin(head->right);
                head->data = temp->data;
                head->right = deletenode(head->right,head->data);
            }

    return head;
    }


}
void iprint(struct node* head)
{
    if(head == NULL) return;
        iprint(head->left);
            cout<<head->data;
        iprint(head->right);
}
void prprint(struct node*head)
{
    if(head == NULL) return;
    prprint(head->right);
        cout<<head->data;
    prprint(head->left);
}


int main(void)
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
}