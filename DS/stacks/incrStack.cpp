#include<bits/stdc++.h>


using namespace std;


class CustomStack {
public:
    stack<int> s;
    stack<int> t;
    int len;
    int max_len;
    
    CustomStack(int maxSize) 
    {
        max_len = maxSize;
        len = 0;
    }
    
    void push(int x) 
    {
        if(len!=max_len)
        {
            s.push(x);
            len++;
        }
        
    }
    
    int pop() 
    {
         if(len==0)
         {
             return -1;
         }
        int temp_x = s.top();
        s.pop();
        len--;
        return temp_x;
    }
    
    void increment(int k, int val) 
    {
        for(int i=0; i < len; i++)
        {
            t.push(s.top());
            s.pop();
        }
        
        for(int j = 0; j < len; j++)
        {
            if(j < k)
            s.push(t.top()+val);
            else
            s.push(t.top());
            t.pop();
        }
    }
};