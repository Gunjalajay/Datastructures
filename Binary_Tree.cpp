// insert elements in Tree, Search element in tree 
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
     Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void insert( Node* root,int val)
{
    Node* newNode=new Node(val);
    if(root==NULL)
    {
        root=newNode;
    }
    
    if(val<root->data && root->left!=NULL)
    {
        insert(root->left,val);
    }
    
    if(val<root->data && root->left==NULL)
    {
        root->left=newNode;
    }
    
    if(val>root->data && root->right==NULL)
    {
        root->right=newNode;
    }
    
    if(val>root->data && root->right!=NULL)
    {
        insert(root->right,val);
    }
}

bool search(Node* root,int val)
{
    
    if(root->data == val)
    {
        return true;
    }
    
    if(root==NULL)
    {
        return false;
    }
    
    if(root->left==NULL && root->right == NULL && root->data!=val)
    {
        return false;
    }
    
    if(val < root->data )
    {
        return search(root->left,val);
    }
    
    if(val > root->data )
    {
        return search(root->right,val);
    }
    
    
}


int main()
{
    Node* root=new Node(5);
    insert(root,3);
    insert(root,7);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,8);
    cout<<search(root,20);
    
  return 0;
}
