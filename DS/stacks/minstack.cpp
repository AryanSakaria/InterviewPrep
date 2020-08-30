#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> s_min;

    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
    	if(s_min.empty()||x <= s_min.top())
    	{
    		s_min.push(x);
    	}
        s.push(x);
    }
    
    void pop() 
    {
    	if(s.top()==s_min.top())
    	{
    		s_min.pop();
    	}
    	s.pop();
    }
    
    int top() 
    {
    	int ret;
    	ret = s.top();
    	return ret;    
    }
    
    int getMin() 
    {
        int ret = s_min.top();
        return ret;
    }
};

int main()
{
	MinStack* obj = new MinStack();
	obj->push(0);
	obj->push(1);
	obj->push(0);

	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;
	
	obj->pop();
	return 0;
}