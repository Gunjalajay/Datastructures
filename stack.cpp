#include<iostream>
using namespace std;
class stack
{
int top=-1;
int arr[5]={0,0,0,0,0};
public:
bool isEmpty()
{
    if(top==-1)
    return true;

return false;

}
bool isFull()
{
    if(top==4)
    return true;

return false;

}
int push(int value)
{
    if(isFull())
    {
        cout<<"stack overflow"<<endl;
        return 0;
    }
    else{
        top++;
        arr[top]=value;
    }
}
int pop()
{
    if(isEmpty())
    {
        cout<<"stack underflow"<<endl;
    }
    else{
        cout<<"element popped is "<<arr[top]<<endl;
        arr[top]=0;
        top--;
        
    }
}
void display()
{
    cout<<"stack elements are : "<<endl;
    for(int i=0;i<5;i++)
    cout<<arr[i]<<endl;
}

};
int main()
{
    stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    s.display();
return 0;

}
