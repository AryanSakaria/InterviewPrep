#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int value;
    int key;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:
    int len;
    int max_cap;
    unordered_map<int, Node*> mp;
    Node *head;
    Node *tail;
    
    void diplayList()
    {
    	cout << "List so far" << endl;
    	Node *temp = tail;
    	while(temp!=nullptr)
    	{
    		cout << temp->value << " ";
    		temp = temp->next;
    	}
    	cout << endl;
    }
    LRUCache(int capacity) 
    {
        len = 0;
        max_cap = capacity;
        mp.reserve(1024);
        mp.max_load_factor(0.25);
        head = nullptr;
        tail = nullptr;
        
    }
    
    int get(int key) 
    {
        if (mp.find(key) == mp.end()) 
        {
        	cout << "Didn't find key in get" << endl;
            return -1;
        }
        else
        {
        	cout << "Found key in get" << endl;
            Node *temp = mp[key];
            if(temp==head)
            {
            	return temp->value;
        	}
            if(temp==tail)
            {
                Node *t_2 = tail;
                tail = tail->next;
                tail->prev = nullptr;
                t_2->next = nullptr;
                t_2->prev = head;
                head->next = t_2;
                head = t_2;
            }
            else
            {
                Node *t_prev = temp->prev;
                Node *t_next = temp->next;
                t_prev->next = t_next;
                t_next->prev = t_prev;
                head->next = temp;
                temp->prev = head;
                temp->next = nullptr;
                head = temp;
            }
            
            
            return temp->value;
        }
    }
    
    void put(int key, int value) 
    {
        if(get(key)!=-1)
        {
            Node *temp = mp[key];
            temp->value = value;
        }
        else
        {
        	cout << "didn't find key in put" << endl;
        	// cout << "Reached the correct node" << endl;
            Node *new_node = new Node(value);
            new_node->key = key;
            mp[key] = new_node;
            
            if(len==0)
            {
            	cout << "Inserting first node" << endl;
                tail = new_node;
                head = new_node;
                len++;
            }
            
            else if(len < max_cap)
            {
            	cout << "Still less than capacity" << endl;
            	head->next = new_node;
            	new_node->prev = head;
            	new_node->next = nullptr;
            	head = new_node;
                len++;
            }
            else
            {
            	cout << "Reached capacity" << endl;
                
	            head->next = new_node;
	            new_node->prev = head;
	            new_node->next = nullptr;
	            head = new_node;
	            //delete at tail
	            //full capacity
	            int delete_key = tail->key;
	            tail = tail->next;
	            delete tail->prev;
	            tail->prev = nullptr;
	            mp.erase(delete_key);
            }
        }
    }
};


int main()
{
	LRUCache *obj = new LRUCache(3);
	obj->diplayList();

	cout << "putting 1,1 " << endl;
	obj->put(1,1);

	cout << "putting 2,2 " << endl;
	obj->put(2,2);
	obj->diplayList();


	cout << "get 1 " << endl;
	cout << obj->get(1) << endl;



	obj->diplayList();

	cout << "putting 3,3 " << endl;
	obj->put(3,3);
	obj->diplayList();

	cout << "get 2: " << obj->get(2) << endl; 

	cout << "putting 4,4 " << endl;

	obj->put(4,4);
	obj->diplayList();

	cout << "get 1: " << obj->get(1) << endl;	
	cout << "get 3: " << obj->get(3) << endl;	
	cout << "get 4: " << obj->get(4) << endl;	






	// obj->put(2,2);
	// obj->diplayList();
	// obj->get(1);
	// obj->diplayList();
	// obj->put(3,4);
	// obj->diplayList();
	// obj->get(2);
	// obj->diplayList();



}