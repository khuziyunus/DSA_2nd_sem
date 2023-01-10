#include<iostream>
using namespace std;

void print(string s)
{ 
    cout<<"Hello "<<s<<endl;
}

int main()
{
   
    string input[3];
    system("cls");
    for (int  i = 0; i < 3; i++)
    {
        cin>>input[i];
        //print(input);
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"Hello "<<input[i]<<endl;
    }
    
}