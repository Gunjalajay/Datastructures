// Circular Linked List with insertion and deletion operations
#include <iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node(int val)
  {
      data=val;
      next=NULL;
  }
};
void insertAtHead(node* &head,int val){
    node* x=new node(val);
    if(head==NULL)
    {
        x->next=x;
        head=x;
        return;
    }
    node* temp=head;
    
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=x;
    x->next=head;
    head=x;
}

void insertAtTail(node* &head,int val)
{
    
    if(head==NULL)
    {
        insertAtHead(head,val);
     return;   
    }
    node* x=new node(val);
    node* temp=head;
    
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=x;
    x->next=head;
    
}

void deleteAtHead(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node*temp =head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* x=temp->next;
    temp->next=head->next;
    head=temp->next;;
    delete x;
    
    
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
    
    while(count != pos-1)
    {
        temp=temp->next;
        count++;
    }
    
    node* x=temp->next;
    temp->next=x->next;
    delete x;
    
    
}
void display(node* head)
{
    node* temp=head;
    
    do
    {
        cout<<temp->data<<"=>";
        temp=temp->next;
    }while(temp!=head);
    
     cout<<endl;
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
    deleteAtHead(head);
    display(head);
   
   return 0;
}
