#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node * next;
};
void insert(node**head,int data)
{
    node*ptr = new node();
    ptr->data = data;
    ptr->next = *head;

    if (*head != NULL)
    {
        node*temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = ptr;
    }
    else
    {
        ptr->next = ptr;
    }
    
*head = ptr;


}
void Delete(node**head,int key)
{
    if (*head = NULL)
        return;
    if ((*head)->data == key && (*head)->next == *head)
        {
            free(*head);
            *head = NULL;
            return;
        }
        node *last = *head,*d;
    if((*head)->data == key)
        {
                while (last->next != *head)
                    last = last->next;
                last->next= (*head)->next;
                free(*head);
                *head = last->next;
                return; 
        }   
    if((*head)->data != key && (*head)->next != (*head))
    {
            last = last->next;
    }
    if(last->next->data == key)
    {
        d=last->next;
        last->next = d->next;
        free(d);
    }
    else
    {
        cout<<"Key not Found"<<endl;
    }
}
void Print(node *head)
{
    node*temp = head;
    if(head != NULL)
        do
        {
            cout<<temp->data<<" ";
                temp = temp->next;
        } while (temp!=head);
        

}

int main()
{

}