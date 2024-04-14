#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
    node(){}
    node(int x){
        val=x;
        next=NULL;
    }
};

struct Queue{
    node *front,*rear;
    Queue();
    ~Queue();
    void enqueue(int x);
    void dequeue();
    void peek();
    void display();
};

Queue::Queue(){
    cout<<"Queue is starting!\n";
    front=rear=NULL;
}

Queue::~Queue(){
    cout<<"Oh! You killed me.\n";
}

void Queue::enqueue(int x){
    node *newnode= new node(x);
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
        cout<<x<<" has been enqueued(first node)\n";
    }
    else{
        rear->next=newnode;
        rear=newnode;
        cout<<x<<" has been enqueued!\n";
    }
    return;
}

void Queue::dequeue(){
    node *temp=front;
    int y;
    if(front==NULL && rear==NULL)
    {
        cout<<"Underflow!\n";
    }
    else if(front==rear)
    {
        y=temp->val;
        front=rear=NULL;
        delete temp;
        cout<<y<<" has been dequeued(at head)\n";
    }
    else{
        y=temp->val;
        front=front->next;
        delete temp;
        cout<<y<<" has been dequeued!\n";
    }
    return;
}

void Queue::peek(){
    if(front==NULL && rear==NULL)
    {
        cout<<"There is no front node in the queue\n";
    }
    else{
        cout<<"The front of the queue is "<< front->val<<endl;
    }
    return;
}

void Queue::display(){
    node *temp=front;
    cout<<"Start\n";
    if(front==NULL && rear==NULL)
    {
        cout<<"There is no node in the queue!\n";
    }
    else{
        while(temp!=NULL)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
    cout<<"End\n";
    return;
}

int main()
{
    Queue q;
    q.dequeue();q.display();
    q.enqueue(10);q.display();
    q.enqueue(11);q.display();
    q.enqueue(12);q.display();
    q.enqueue(13);q.display();
    q.enqueue(14);q.display();
    q.enqueue(15);q.display();
    q.peek();

    q.dequeue();q.display();
    q.dequeue();q.display();
    q.dequeue();q.display();
    q.peek();
    q.dequeue();q.display();
    q.dequeue();q.display();
    q.dequeue();q.display();
    q.dequeue();q.display();

}