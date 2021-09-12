#include<iostream>
using namespace std;

struct Node{
    string data;
    struct Node * next;
};

struct Node *first = NULL;

void CreateLL(string *A, int n){
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void DisplayLL(struct Node *ptr){
    cout<<"The elements are: ";
    while(ptr!=NULL){
        cout<<ptr->data<<" " ;
        ptr = ptr->next;
    }
}

//Recursive Func.
void DisplayLL2(struct Node *ptr){
    if(ptr!=NULL){
        // recursively print all ele. by this call & will print str8 if written it below ptr-> data stmt. 
        DisplayLL2(ptr->next);
        cout<<"The elements in recursive manner are: ";
        cout<<ptr->data<<endl;
    }
}

int main()
{
    string *A;
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    A = new string[n];
    cout<<"Enter the string: ";
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }

    CreateLL(A,n);
    DisplayLL(first);
    //DisplayLL2(first);
    
    return 0;
}