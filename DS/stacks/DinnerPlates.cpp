#include<bits/stdc++.h>
using namespace std;

class DinnerPlates {
public:
    priority_queue <int, vector<int>, greater<int> > min_heap;
    vector<int> check;
    int max_cap;
    int top;


    vector <vector<int> > table;

    DinnerPlates(int capacity) 
    {
         max_cap = capacity;
         top = -1;
    }
    
    void push(int val) 
    {
        if(min_heap.empty())
        {
            vector<int> v;
            v.push_back(val);
            table.push_back(v);
            top++;
            // case 1
            min_heap.push(top);
            check.push_back(1);

            if(max_cap == table[top].size())
            {
                min_heap.pop();
                check[top] = 0;
            }

        }
        else
        {
            int idx = min_heap.top();
            table[idx].push_back(val);
            
            if(table[idx].size()==max_cap)
            {
                min_heap.pop();
                check[idx] = 0;
            }
        }
    }
    
    int pop() 
    {
        //always do at top;
        if(top >= 0)
        {
            if(table[top].size() > 0)
            {
                int ret = table[top].back();
                table[top].pop_back();

                int prev_top = top;
                while(table[top].size()==0 && top >=0)
                {
                    top--;
                    if(top < 0)
                    {
                        break;
                    }
                    table.pop_back();
                }

                if(top!=prev_top)
                {
                    vector<int> v;
                    while(!min_heap.empty())
                    {
                        v.push_back(min_heap.top());
                        min_heap.pop();
                    }
                    for (int i = 0; i < v.size(); ++i)
                    {
                        if(v[i] <= top)
                        {
                            min_heap.push(v[i]);
                        }
                        /* code */
                    }
                }

                

                return ret;
            }
        }
        return -1;
    }
    
    int popAtStack(int index) 
    {
        if(index < top)
        {
            if(table[index].size()!=0)
            {
                int ret = table[index].back();
                // if not already added to queue,
                // add to queue
                if(check[index]==0)
                {
                    min_heap.push(index);
                    check[index] = 1;
                }
                table[index].pop_back();
                return ret;
            }
            else
            {
                return -1;
            }
        }  

        else if(index == top)
        {
            return pop();
        }
        else
        {
            return -1;
        }

    }

    void displayStack()
    {

        for (int i = 0; i < table.size(); ++i)
        {
            cout << "Level " << i << " : " ;
            for (int j = 0; j < table[i].size(); ++j)
            {
                cout << table[i][j] << " ";
                /* code */
            }
            cout << endl;
            /* code */
        }

        cout << "queue status : ";

        vector<int> temp_queue;
        while(!min_heap.empty())
        {
            temp_queue.push_back(min_heap.top());
            min_heap.pop();
        }

        for (int i = 0; i < temp_queue.size(); ++i)
        {
            cout << temp_queue[i] << " ";
            min_heap.push(temp_queue[i]);
            /* code */
        }
        cout << endl;
        cout << "Top :" << top << endl;
    }
};


int main()
{
    DinnerPlates *obj = new DinnerPlates(2);
    obj->push(472);
    obj->push(106);
    obj->push(497);
    obj->push(498);
    obj->push(73);
    obj->push(115);
    obj->push(437);
    obj->push(461);
    cout << "checkpoint 1" << endl;
    obj->displayStack();
    obj->popAtStack(3);
    obj->popAtStack(3);
    obj->popAtStack(1);
    obj->popAtStack(3);
    obj->popAtStack(0);
    obj->popAtStack(2);
    obj->popAtStack(2);
    obj->popAtStack(1);
    obj->popAtStack(1);
    obj->popAtStack(3);
    cout << "checkpoint 2" << endl;
    obj->displayStack();

    obj->push(197);
    obj->push(239);
    obj->push(129);
    obj->push(449);
    obj->push(460);
    obj->push(240);
    obj->push(386);
    obj->push(343);
    cout << "checkpoint 3" << endl;
    obj->displayStack();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
}