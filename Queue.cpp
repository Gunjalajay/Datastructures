#include<iostream>
using namespace std;
class Queue
{
    int front ,rear;
    int arr[5];
    public:
    Queue()
    {
        front=rear=-1;
        for(int i=0;i<5;i++)
        arr[i]=0;
    }
//   dequeued<--front    enqueued<-- rear
    bool isEmpty()
    {
        if(front==-1 && rear ==-1)
        return true;
    return false;

    }
    bool isFull()
    {
        if(rear==4)
        return true;
    return false;
    }
    int Enque(int val)
    {

        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
            arr[rear]=val;
            
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }
    void Dequeue()
    {
        int x;
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
        }
        else if(front==rear)
        {
            x=arr[front];
            arr[front]=0;
            cout<<"The element Dequeued is "<<x<<endl;
            front=rear=-1;
        }
        else{
            x=arr[front];
            arr[front]=0;
            cout<<"The element Dequeued is "<<x<<endl;
            front++;
        }
    }
    void display()
    {
        for (int i=0;i<5;i++)
        cout<<arr[i]<<endl;
    }
};
int main()
{
 Queue Q;
 Q.Enque(3);
 Q.Enque(4);
 Q.Enque(5);
 Q.Enque(6);
 Q.Enque(7);
 
 Q.Dequeue();
 Q.Dequeue();
 Q.Dequeue();
 Q.Dequeue();
 Q.Dequeue();
 Q.display();
 Q.Dequeue();
 Q.Enque(8);
 Q.display();
    return 0;
}
