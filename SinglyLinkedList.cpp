//Functions= insertAtNode,insertAtTail,Search,Display
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int val)
{
    data=val;
    next=NULL;
}

};

void insertAthead(Node* &head,int val)
{
    Node* n=new Node(val);
    n->next=head;
    head=n;
    
}
bool search(Node* head,int key)
{
    
    while(head!=NULL)
    {
        if(head->data==key)
        return true;


        head=head->next;
    }
    return false;
}
void insertAtTail(Node* &head,int val)
{
    Node* n=new Node(val);
    Node* temp=head;
    if(head==NULL)
    {
        head=n;
    return;
    }
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAthead(head,4);
    display(head);
    cout<<search(head,5);
}
