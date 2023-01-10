#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;

};

void push(Node**head_ref,int data)
{
    Node *ptr1 = new Node();
    
    ptr1->data = data;
    ptr1->next = *head_ref;

    if(*head_ref != NULL)
    {
        Node*temp = *head_ref;
        while (*head_ref != NULL)
            temp =temp->next;
        temp->next = ptr1;
    }
    else
    ptr1->next = ptr1;

    *head_ref=ptr1;
}

void Printlists(Node*head)
{
    Node *temp = head;

    if(head != NULL)
    {
        do
        {
            cout<<temp->data<<" ";
            temp->next;

        } while (temp != head);
        
    }

}
void deleteNode(Node**head,int key)
{
    if((*head)=NULL)
        return;
    if((*head)->next == (*head) && (*head)->data == key)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *last = *head,*d;
    if ((*head)->data == key)
    {
        while (last->next!= (*head))       
            last = last->next;
        last->next = (*head);
        free(*head);
        (*head) = last->next;
        return;
    }

    while((*head)->data != key && (*head)->next != (*head))
    {
        last=last->next;
    }
    
    if(last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
    cout<<"No such key found"<<endl;
}

int main()
{
    int ch;
    int val;
    int del;

    Node* head = NULL;

   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: 
         cout<<"Enter the val   :\n";
         cin>>val;
         push(&head,val);
         break;
         case 2:
         cout<<"Delete the val  :\n";
         cin>>del;
         deleteNode(&head,del);
         break;
         case 3: Printlists(head);
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);

	return 0;
}
