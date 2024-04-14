#include <bits/stdc++.h>
using namespace std;
#define N 5
struct Queue{
    int arr[N],front,rear;
    Queue();
    ~Queue();
    void enqueue(int x);
    void dequeue();
    void peek();
    void display();
};

Queue::Queue(){
    front=rear=-1;
    cout<<"Queue is starting!\n\n";
}

Queue::~Queue(){
    cout<<"\n\nOh! You killed me.\n";
}

void Queue::enqueue(int x){
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=x;
        cout<<x<<" has been enqueued at index(starting) "<<rear<<endl;
    }
    else if((rear+1)%N==front)
    {
        cout<<"Overflow!\n";
    }
    else{
        rear=(rear+1)%N;
        arr[rear]=x;
        cout<<x<<" has been enqueued at index "<<rear<<endl;
    }
    return;
}

void Queue::dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Underflow!\n";
    }
    else if(front==rear)
    {
        front=rear=-1;
        cout<<"Only last element "<<arr[front]<<" has been dequeued!\n";
    }
    else{
        cout<<arr[front]<<" has been dequeued!\n";
        front=(front+1)%N;
    }
    return;
}

void Queue::display(){
    int i=front;
    cout<<"Start:\n";
    if(front==-1 && rear==-1)
    {
        cout<<"The queue is empty\n";
    }
    else{
        while(i!=rear)
        {
            cout<<arr[i]<<endl;
            i=(i+1)%N;
        }
        cout<<arr[i]<<endl;
    }
    cout<<"End.\n";
    return;
}

void Queue::peek(){
    if(front==-1 && rear==-1)
    {
        cout<<"There is no peek in the queue\n";
    }
    else{
        cout<<"The peek of the queue is "<<arr[front]<<endl;
    }
    return;
}

int main(){
    Queue q;
    q.enqueue(6);q.display();
    q.enqueue(7);q.display();
    q.enqueue(8);q.display();
    q.enqueue(9);q.display();
    q.enqueue(10);q.display();
    q.enqueue(11);q.display();
    q.peek();

    q.dequeue();q.display();
    q.dequeue();q.display();
    q.peek();
    q.dequeue();q.display();
    q.dequeue();q.display();
    q.dequeue();q.display();
    q.dequeue();q.display();
    return 0;
}