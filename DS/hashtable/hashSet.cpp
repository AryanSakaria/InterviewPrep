#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    Node *next;
    Node *prev;
    int key;
    // int value;
    Node()
    {
        next = nullptr;
        prev = nullptr;
        key = -1;
        // value = -1;
    }
    
    Node(int k)
    {
        next = nullptr;
        prev = nullptr;
        key = k;
        // value = val;
    }
    ~Node()
    {

    }
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    Node **hashTable;
    int m;
    MyHashSet() {
        m = 10000;
            
        hashTable = new Node*[m];
        for(int i = 0; i < m; i++)
        {
            hashTable[i] = new Node;
            // cout << (hashTable[i]->next == nullptr) << " ";
        }
        
    }
    
    void add(int key) 
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
            // temp->value = value;
        }
        else
        {
            // cout << "Key doesn't exist so we do this" << endl;
            // cout << "Inserting key:" << key << endl;
            Node *newNode = new Node(key);
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nullptr;
        }   
    }
    
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
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
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
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */
}