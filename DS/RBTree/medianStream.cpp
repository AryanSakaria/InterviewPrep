#include<bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue <int> left_heap;
    priority_queue <int, vector<int>, greater<int> > right_heap;
    float cur_median; 
    int size;
    
    MedianFinder() 
    {
        cur_median = -1;
        size = 0;
    }
    
    void addNum(int num) 
    {
       	 if(size == 0)
       	 {
       	 	cout << "Adding first element " << num << endl;
       	 	cur_median = num;
       	 	size++;
       	 	left_heap.push(num);
       	 	cout << "left heap :" << left_heap.top() << "; size = " << left_heap.size() << endl;
       	 }
       	 else if(size == 1)
       	 {
       	 	cout << "Adding second element " << num << endl;
       	 	cout << "cur_median " << cur_median << endl;
       	 	if(cur_median <= num)
       	 	{
       	 		cout << "Case median less num" << endl;
       	 		right_heap.push(num);
       	 		cur_median = (num + cur_median)/2.0;
       	 		cout << "cur_median " << cur_median << endl;
       	 		size++;
       	 	}
       	 	else
       	 	{
       	 		cout << "Case median more num" << endl;
       	 		right_heap.push(left_heap.top());
       	 		left_heap.pop();
       	 		left_heap.push(num);
       	 		cur_median = (num + cur_median)/2.0;
       	 		size++;
       	 	}
       	 	cout << "left heap :" << left_heap.top() << "; size = " << left_heap.size() << endl;
       	 	cout << "right heap :" << right_heap.top() << "; size = " << left_heap.size() << endl;

       	 }
       	 else
       	 {
       	 	cout << "case others; num = " << num << endl;
       	 	if(size%2==0)
       	 	{
       	 		cout << "case size even" << endl;
       	 		if(num <= left_heap.top())
       	 		{
       	 			left_heap.push(num);
       	 		}
       	 		else
       	 		{
       	 			right_heap.push(num);
       	 		}

       	 		while(left_heap.size()-1!=right_heap.size())
       	 		{
       	 			if(left_heap.size()-1 < right_heap.size())
	       	 		{	
	       	 			left_heap.push(right_heap.top());
	       	 			right_heap.pop();
	       	 		}
	       	 		else if(right_heap.size() < left_heap.size()-1)
	       	 		{
	       	 			right_heap.push(left_heap.top());
	       	 			left_heap.pop();
	       	 		}
       	 			
       	 		}

       	 		stack<int> temp;
       	 		cout << "Displaying left heap " << endl;
       	 		while(!left_heap.empty())
       	 		{
       	 			temp.push(left_heap.top());
       	 			left_heap.pop();
       	 			cout << temp.top() << " ";
       	 		}

       	 		cout << endl;
       	 		while(!temp.empty())
       	 		{
       	 			left_heap.push(temp.top());
       	 			temp.pop();
       	 		}


       	 		cout << "Displaying right heap " << endl;
       	 		while(!right_heap.empty())
       	 		{
       	 			temp.push(right_heap.top());
       	 			right_heap.pop();
       	 			cout << temp.top() << " ";
       	 		}
       	 		cout << endl;


       	 		while(!temp.empty())
       	 		{
       	 			right_heap.push(temp.top());
       	 			temp.pop();
       	 		}
       	 		cur_median = left_heap.top();
       	 		size++;
       	 	}
       	 	else
       	 	{
       	 		cout << "case size odd" << endl;
       	 		if(num <= left_heap.top())
       	 		{
       	 			cout << " Pushing here" << endl;
       	 			left_heap.push(num);
       	 		}
       	 		else
       	 		{
       	 			cout << " Pushing here2" << endl;

       	 			right_heap.push(num);
       	 		}
       	 		cout << "Sizes :" << right_heap.size() << " " << left_heap.size() << endl;
       	 		while(left_heap.size()!=right_heap.size())
       	 		{
       	 			cout << "Balancing" << endl;
       	 			if(left_heap.size() < right_heap.size())
	       	 		{	
	       	 			left_heap.push(right_heap.top());
	       	 			right_heap.pop();
	       	 		}
	       	 		else if(right_heap.size() < left_heap.size())
	       	 		{
	       	 			right_heap.push(left_heap.top());
	       	 			left_heap.pop();
	       	 		}
       	 		}
       	 		cout << left_heap.top() << " " << right_heap.top() << endl;
       	 		if(left_heap.top()==-3)
       	 		{
       	 			if(right_heap.top()==-2)
       	 			{
       	 				cout << "This case, then why median not" << endl;
       	 				cout << "left heap top :" << left_heap.top() << " " << right_heap.top() << endl;
       	 				// cout << (left_heap.top() + right_heap.top())/2.0.0; 
       	 			}
       	 		}
       	 		cur_median = (left_heap.top() + right_heap.top())/2.0;

       	 		size++;

       	 		stack<int> temp;
       	 		cout << "Displaying left heap " << endl;
       	 		while(!left_heap.empty())
       	 		{
       	 			temp.push(left_heap.top());
       	 			left_heap.pop();
       	 			cout << temp.top() << " ";
       	 		}

       	 		cout << endl;
       	 		while(!temp.empty())
       	 		{
       	 			left_heap.push(temp.top());
       	 			temp.pop();
       	 		}


       	 		cout << "Displaying right heap " << endl;
       	 		while(!right_heap.empty())
       	 		{
       	 			temp.push(right_heap.top());
       	 			right_heap.pop();
       	 			cout << temp.top() << " ";
       	 		}
       	 		cout << endl;


       	 		while(!temp.empty())
       	 		{
       	 			right_heap.push(temp.top());
       	 			temp.pop();
       	 		}

       	 	}
       	 }
       	 		cout << "cur_median " << cur_median << endl;
    }
    
    double findMedian() 
    {
 		return cur_median;       
    }
};

int main()
{

  // Your MedianFinder object will be instantiated and called as such:
  MedianFinder* obj = new MedianFinder();
  obj->addNum(-1);
  cout << "median : " << obj->findMedian() << endl;
  obj->addNum(-2);
  cout << "median : " << obj->findMedian() << endl;
  obj->addNum(-3);
  cout << "median : " << obj->findMedian() << endl;
  obj->addNum(-4);
  cout << "median : " << obj->findMedian() << endl;
  obj->addNum(-5);
  cout << "median : " << obj->findMedian() << endl;
  
  // cout << "median : " << obj->findMedian() << endl;

  // obj->addNum(2);
  // obj->addNum(3);
  // obj->addNum(1);
  // obj->addNum(3);

  // obj->addNum(3);
  // // cout << "median : " << obj->findMedian() << endl;
  // obj->addNum(3);
  // // cout << "median : " << obj->findMedian() << endl;


 
}