#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> q;
    int top;
    MyQueue() 
    {
        top = -1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!q.empty())
        {
            s.push(q.top());
            q.pop();
        }
    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
         top = s.top();  
        s.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() 
    {
        top = s.top();
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
	/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
}