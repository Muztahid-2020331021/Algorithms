#include <bits/stdc++.h>
using namespace std;

#define N 5

struct Queue
{
    int arr[N];
    int front = -1;
    int rear = -1;
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int peek();
    void display();
};

Queue::Queue()
{
    cout << "Queue is starting!\n";
}

Queue::~Queue()
{
    cout << "Oh! You killed me.\n";
}

void Queue::enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = x;
        cout << x << " has been enqueued at index(first element) " << rear << endl;
    }
    else if (rear == N - 1)
    {
        cout << "Overflow! Can't enqueue anymore.\n";
    }
    else
    {
        rear++;
        arr[rear] = x;
        cout << x << " has been enqueued at index " << rear << endl;
    }
    return;
}

int Queue::dequeue()
{
    int y;

    if (front == -1 && rear == -1)
    {
        cout << "Underflow!\n";
        y = -1;
    }
    else if (front == rear)
    {
        y = arr[front];
        front = rear = -1;
        cout << "The only last element "<<y<<" has been deleted!\n";
    }
    else
    {
        y = arr[front];
        cout << arr[front] << " has been dequeued!\n";
        front++;
    }
    return y;
}

int Queue::peek()
{
    int y;
    if (front == -1 && rear == -1)
    {
        cout << "Underflow condition!\n";
        y = -1;
    }
    else
    {
        cout << "The front value of the queue is " << arr[front] << endl;
        y = arr[front];
    }
    return y;
}

void Queue::display()
{
    int i;
    if (front == -1 && rear == -1)
        cout << "There is no element in the array\n";
    else
        for (i = front; i <= rear; i++)
            cout << arr[i] << endl;
    return;
}

int main()
{
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

}