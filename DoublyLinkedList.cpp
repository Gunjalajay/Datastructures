//Function insertAtTail,InsertAtHead,deletenode,deleteAtHead,sortedInsert,deletenode,reverse.
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
void sortedInsert(node* head, int data) {
node* x=new node(data);
//LL -> 1-> 2->   <-4->5
node*temp=head;
    if(temp->data > x->data )
    {
        x->next=temp;
        temp->prev=x;
        head=x;
    }
    if(head==NULL)
    {
        head=x;
    }
    
    while(temp->next->data < x->data )
    {
        temp=temp->next;
        if(temp->next==NULL)
        {
            break;
        }
    }
    if(temp->next!=NULL)
    {
        x->next=temp->next;
    temp->next->prev=x;
    }
    temp->next=x;
    x->prev=temp;
    
  //  cout<<temp->data;
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
void reverse(node* &head)
{
    // 1->2->3->4
    // 4->3->2->1
    if(head==NULL)
    {return ;}
    if(head->next==NULL)
    {
        head->next=head->prev;
        head->prev=NULL;
        return;
    }
    node*curr=head;
    node*prev1=curr->prev;
    
    curr->prev=curr->next;
    curr->next=prev1;
    
    prev1=curr;
    curr=curr->prev;
    
    head=curr;
    reverse(head);
    
}

int main()
{
   node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);
    display(head);
    sortedInsert(head,6);
    display(head);
    deletenode(head,4);
    display(head);
    reverse(head);
    display(head);
    
   return 0;
}
