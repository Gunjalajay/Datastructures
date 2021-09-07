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

void print(Node* head,Node* last)
{
    Node*temp=head;
    if(head==last)
    {
        cout<<head->data<<endl;
        return;
    }
    
    while(temp->next!=last)
    {
        temp=temp->next;
    }
    cout<<temp->next->data<<endl;
    print(head , temp);
}
void reversePrint(Node* head)
{
    cout<<endl;
    Node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    Node* last=temp;
  
    print(head,last);
    
}

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
void getNode(Node* head, int pos_from_tail) {
    Node* temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    // cout<<count<<endl;
    
    Node* temp1=head;
    int count1=1;
    while((count1+pos_from_tail)!=count)
    {
        temp1=temp1->next;
        count1++;
    }
    cout<<temp1->data;
    
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
    reversePrint(head);
    getNode(head,2);
}
