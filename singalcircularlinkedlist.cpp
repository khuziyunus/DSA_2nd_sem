#include<bits/stdc++.h>

struct node
{
    int data;
    struct  node*   next;
};

struct node*    circularSingly(int data)
{
    struct node* temp =(struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next  = temp;
    return temp;
}



int main()
{



}