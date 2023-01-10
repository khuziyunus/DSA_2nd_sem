#include<iostream>
using namespace std;




struct Node
{
	int data,length;
	Node* next;
};

struct Edge
{
	int start_ver,end_ver,length;
};

class DirectedGraph{

	int No_Nodes;
	Node* getNode(int dat,int length,Node*head)
	{
		Node * newNode = new Node;
		newNode->data = dat;
		newNode->length = length;
		newNode->next = head;
		return newNode;
	}

public:

	Node**head;
	
	DirectedGraph(Edge Edges[], int No_Edges , int No_Nodes)
	{
		head = new Node *[No_Nodes]();
		this->No_Nodes = No_Nodes;
		for (int i = 0; i < No_Edges; i++)
		{
			int star_ver = Edges[i].start_ver;
			int end_ver = Edges[i].end_ver;
			int length = Edges[i].length;
			 
			 Node *newNode = getNode(end_ver,length,head[star_ver]);
			 head[star_ver] = newNode;
		}
		
	}


    
};

void Display(Node*ptr,int i)
{
	while (ptr != NULL)
	{
		cout<<"(" << i <<","<<ptr->data<<","<<ptr->length<<")"<<endl;
		ptr = ptr->next;
		
	}
}

int main()
{
	Edge edges[] = { 
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
	int No_Nodes = 6;
	int n = sizeof(edges)/sizeof(edges[0]);
	DirectedGraph DirectedGraph(edges,n,No_Nodes);
	for (int i = 0; i < No_Nodes; i++)
    {
        // display adjacent vertices of vertex i
        Display(DirectedGraph.head[i], i);
    }

}
