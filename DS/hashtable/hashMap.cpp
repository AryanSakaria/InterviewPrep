#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node *next;
    Node *prev;
    int key;
    int value;
    Node()
    {
        next = nullptr;
        prev = nullptr;
        key = -1;
        value = -1;
    }
    
    Node(int k, int val)
    {
        next = nullptr;
        prev = nullptr;
        key = k;
        value = val;
    }
    ~Node()
    {

    }
};

class MyHashMap {
public:
    Node **hashTable;
    int m;
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        m = 10000;
        hashTable = new Node*[m];
        for(int i = 0; i < m; i++)
        {
            hashTable[i] = new Node;
            // cout << (hashTable[i]->next == nullptr) << " ";
        }
        // cout << endl;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        int idx = key % m;
        // cout << "Idx :" << idx << endl;
        Node* temp = hashTable[idx];
        while(temp->next!=nullptr && temp->key!= key)
         {
            // cout << "Searching for key" << endl;
            // cout <<temp->key << " ";
            temp = temp->next;
        }
        // cout << endl;
        if(temp->key == key)
        {
            // cout << "Since key exists we do this" << endl;
            temp->value = value;
        }
        else
        {
            // cout << "Key doesn't exist so we do this" << endl;
            // cout << "Inserting key:" << key << endl;
            Node *newNode = new Node(key, value);
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nullptr;
        }

    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        int idx = key % m;   
        Node* temp = hashTable[idx];
        while(temp->next!=nullptr && temp->key!= key)
        {
            // cout << "Searching for key" << endl;
            // cout <<temp->key << " ";
            temp = temp->next;
        }
        if(temp->key == key)
        {
            // temp->value = value;
            return temp->value;
        }
        else
        {
            return -1;
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        int idx = key % m;   
        Node* temp = hashTable[idx];
        while(temp->next!=nullptr && temp->key!= key)
        {
            // cout << "Searching for key" << endl;
            // cout <<temp->key << " ";
            temp = temp->next;
        }
        if(temp->key == key)
        {

            Node *nextnode = temp->next;
            Node *prevnode = temp->prev;
            //not last key
            if(nextnode!=nullptr)
            {
                prevnode->next = nextnode;
                nextnode->prev = prevnode;
                delete temp;
            }
            else
            {
                prevnode->next = nullptr;
                delete temp;
            }
            // cout << " Successfully removed" << endl;
            // We gotta remove
        }
        else
        {
            // cout << "Didn't find" << endl;
        }
        
    }
};

int main()
{
    MyHashMap* obj = new MyHashMap();
    cout << obj->get(1) << endl;

    obj->put(1, 10);
    cout << obj->get(1) << endl;
    obj->put(1, 12);
    cout << obj->get(1) << endl;
    obj->put(1, 14);
    cout << obj->get(1) << endl;


    obj->put(10001, 123);
    cout << obj->get(10001) << endl;
    obj->remove(20001);
    cout << obj->get(10001) << endl;

    obj->put(20001, 10);
    cout << obj->get(20001) << endl;
    obj->remove(20001);


    Node *temp = obj->hashTable[1];
    cout << "Final output" << endl;
    for (int i = 0; i < 2; ++i)
    {
        temp = temp->next;
        cout << temp->key << " " << temp->value << " ";
        cout << temp <<endl;
        /* code */
    }
    cout << endl;


}