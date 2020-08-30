#include<bits/stdc++.h>
using namespace std;


class MyCircularQueue {
public:
    vector<int> queue;
    int size;
    int head;
    int tail;
    int k;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) 
    {
        size = 0;
        head = -1;
        tail = -1;
        this->k = k;
        for(int i = 0; i < k; i++)
        {
            queue.push_back(-1);
        }
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) 
    {
        if(size==0)
        {
            tail = 0;
            head = 0;
            size++;
            queue[head] = value;
            return true;
        }
        
        if(size==k)
        {
            return false;
        }
            
        head = (head + 1)%k;
        queue[head] = value;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() 
    {
        if(size==0)
        {
            return false;
        }
        if(size==1)
        {
            tail = -1;
            head = -1;
            size--;
            return true;
        }
        
        tail = (tail+1) % k;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() 
    {
        if(tail!=-1)
        {
            return queue[tail];
        }
        else
        {
            return -1;
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() 
    {
        if(head!=-1)
        {
            return queue[head];
        }
        else
        {
            return -1;
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() 
    {
        if(size)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() 
    {
        if(size==k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void disp()
    {
        cout << "head :" << head << "\ntail :" << tail << endl;
        for(int i = 0; i < k; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
      // Your MyCircularQueue object will be instantiated and called as such:
  MyCircularQueue* obj = new MyCircularQueue(3);
  bool param_1 = obj->enQueue(1);
  obj->disp();
  bool param_2 = obj->enQueue(2);
  obj->disp();

  bool param_3 = obj->enQueue(3);
  obj->disp();

  bool param_4 = obj->enQueue(3);
  obj->disp();



  // bool param_2 = obj->deQueue();
  // int param_3 = obj->Front();
  // int param_4 = obj->Rear();
  // bool param_5 = obj->isEmpty();
  // bool param_6 = obj->isFull();

  cout << param_1 << endl;
  cout << param_2 << endl;
  cout << param_3 << endl;
  cout << param_4 << endl;
  // cout << param_5 << endl;
  // cout << param_6 << endl;

}