//Function insertAtTail,InsertAtHead,deletenode,deleteAtHead
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* x=new node(val);
    x->next=head;
    if(head!=NULL)
    {
    head->prev=x;
    }
    head=x;
}
void insertAtTail(node* &head,int val)
{
    if(head==0)
    {
        insertAtHead(head,val);
        return;
    }
    node* x=new node(val);
    node* temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=x;
    x->prev=temp;
}
void deleteAtHead(node* &head)
{
    node*temp=head;
    head=head->next;
    head->prev=NULL;
    
    delete temp;
}
void deletenode(node* &head,int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    int count=1;
    node* temp=head;
    while(temp->next!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    {
    temp->next->prev=temp->prev;
    }
    delete temp;
    
}
void display(node* head)
{
    node* temp=head;
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<temp->data<<"<=>";
        temp=temp->next;
    }
     cout<<"NULL"<<endl;
}
int main()
{
   node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    display(head);
    deletenode(head,4);
    display(head);
   return 0;
}
