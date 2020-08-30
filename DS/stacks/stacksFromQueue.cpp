#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue


class MyStack {
public:
    /** Initialize your data structure here. */
    std::queue<int> m_q;
    // std::queue<int> temp;
    int len; 
    
    MyStack() 
    {
        len = 0;
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_q.push (x);
        for(int i = 0; i < len; i++)
        {
            m_q.push(m_q.front());
            m_q.pop();
        }
        len++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int x = m_q.front();
        m_q.pop();
        len--;
        return x;
        
    }
    
    /** Get the top element. */
    int top() 
    {
        int x = m_q.front();
        return x;   
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        if(len==0)
        {
            return true;
        }
        else
        {
            return false;    
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main ()
{
  /*
  Enter driver code
  */

}