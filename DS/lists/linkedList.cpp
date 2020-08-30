#include<iostream>

struct node{
    int val;
    node *next;
};

class MyLinkedList {
public:
	int len;
	node *head;
	node *tail;
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0; 
        head = nullptr;
        tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > len-1)
        {
            return -1;    
        }
        node *temp = head;
        for(int i=0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        node *temp = new node();
        temp->val = val;
        
        if(len==0)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        node *temp = new node();
        temp->val = val;
        
        if(len==0)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        
        len++;
            
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if(index==0)
        {
            addAtHead(val);
            // len++;
        }
        else if(index==len)
        {
            addAtTail(val);
            // len++;
        }
        else if((index > 0) &&(index < len))
        {
            node *prev;
            node *next;
            node *temp = head;
            for(int i=0; i < index-1; i++)
            {
                temp = temp->next;
            }
            
            prev = temp;
            next = temp->next;
            node *newNode = new node();
            newNode->val = val;
            newNode->next = next;
            prev->next = newNode;
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
		if((index < len) && (index >= 0))
		{
			node *temp = head;
            if(index==0)
            {
                head = head->next;
                len--;
                delete temp;
            }
            else if(index == len-1)
            {
                while(temp->next!=tail)
                {
                    temp = temp->next;
                }
                len--;
                tail = temp;
                tail->next = nullptr;
                delete temp->next;
            }
            else
            {
                len--;
                for(int i=0; i < index-1; i++)
                {
                    temp = temp->next;
                }
                node *prev = temp;
                node *del = temp->next;
                node *nextdel = del->next;
                temp->next = nextdel;
                delete del;
            }
		}        
    }
    void display()
    {
    	std::cout << "len :" << len << "\n";
    	std::cout << "head :" << head << "\n";
    	std::cout << "tail :" << tail << "\n";

    	node *temp = head;
    	while(temp!=nullptr)
    	{
    		std::cout << temp->val << std::endl;
    		temp = temp->next;
    	}
    }

};

int main()
{
// "addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex","deleteAtIndex","deleteAtIndex","addAtTail"]
//         [0],       [1,4],        [8],        [5],       [4,3],        [0],        [5],       [6,3],            [7],            [5],       [4]]

	
  // Your MyLinkedList object will be instantiated and called as such:
  MyLinkedList* obj = new MyLinkedList();
  obj->addAtHead(0);
  obj->addAtIndex(1,4);
  obj->addAtTail(8);
  std::cout << "List so far :\n";
  obj->display();

  obj->addAtHead(5);
    std::cout << "List so far :\n";
  obj->display();

  obj->addAtIndex(4,3);
  obj->addAtTail(0);
  std::cout << "List so far :\n";
  obj->display();

  obj->addAtTail(5);
  obj->addAtIndex(6,3);
  std::cout << "List so far :\n";
  obj->display();

  obj->deleteAtIndex(7);
  std::cout << "List so far :\n";
  obj->display();

  obj->deleteAtIndex(5);
    std::cout << "List so far :\n";
  obj->display();
  obj->addAtTail(4);
   std::cout << "List so far :\n";
  obj->display();







  
	return 0;
}
