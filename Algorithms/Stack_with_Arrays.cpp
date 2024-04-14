#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int cnt = -1, arr[4];
    Stack();
    ~Stack();
    void push(int x);
    int top();
    int pop();
};

Stack::Stack()
{
    cout<<"Stack is starting!\n";
}
Stack::~Stack()
{
    cout<<"Stack has ended!\n";
}

void Stack::push(int x)
{
    if (cnt == 3)
    {
        cout << "Stack Overflow!\n";
        return;
    }
    arr[++cnt] = x;
    cout << x << " has been pushed and the size of stack is " << cnt+1 << endl;
    return;
}

int Stack::top()
{
    if (cnt == -1)
    {
        cout << "Stack is empty!\n";
        return -1;
    }
    cout << "The top of the stack is " << arr[cnt] << " and the size of the stack is " << cnt+1 << endl;
    return arr[cnt];
}

int Stack::pop()
{
    if (cnt == -1)
    {
        cout << "Stack Underflow!\n";
        return -1;
    }
    
    cout << arr[cnt] << " has been popped! and the size of the stack is "<<cnt<<endl;
    int y = arr[cnt--];
    
    return y;
}

int main()
{
    Stack st;

    cout<<"\n\n";
    st.push(6);st.top();
    st.push(7);st.top();
    st.push(8);st.top();
    st.push(9);st.top();
    st.push(10);st.top();
    st.push(11);st.top();
    cout<<"\n";
    st.pop();st.top();
    st.pop();st.top();
    st.pop();st.top();
    st.pop();st.top();
    st.pop();st.top();

    return 0;
}