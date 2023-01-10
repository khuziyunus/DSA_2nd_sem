#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
struct cnode{
struct cnode *next;
int data;

};

struct clist {
    struct cnode *start;

};

void print(struct clist *lptr)
{
    if ( lptr == NULL )return;

    if(lptr == NULL)
    {
        cout<<"Circular list is empty";
        return;
    }

    struct cnode *cur = lptr->start->next;
    int i = 1;
    while (cur != lptr->start)
    {
        
        cout<<"\n it "<<i<<", data = " <<cur->data;
        i=i+1;
        cur = cur->next;
    }
    cout<<"\n it "<<i<<", data = " <<cur->data;
        
}

void insert(struct cnode *ptr,int data)
{

}

int main()
{
    struct clist A1;
    A1.start=NULL;
    cout<<&A1;
    struct cnode *ptr1 = (struct cnode *)malloc (sizeof(struct cnode));
    A1.start = ptr1;
    A1.start->next = A1.start;
    A1.start->data = 10;  

    

}