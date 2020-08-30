#include<bits/stdc++.h>

using namespace std;
int max_level = 20;
class Node
{
    public:
    int key;
    Node** forward;
    // int node_level;
    int count;
    Node(int, int);
    ~Node()
    {
        delete forward;
    }
};

Node::Node(int key, int level)
{
    this->key = key;
    forward = new Node*[level+1];
    memset(forward, 0, sizeof(Node*)*(level+1));
    count = 1;
};


void seedRandomGenerator(){
	static bool isSeeded = false;
	if (!isSeeded){
		isSeeded = true;
		srand(std::chrono::system_clock::now().time_since_epoch().count());
	}
}


int randomLevel()
{
    int lvl = 0;
    seedRandomGenerator();
    float r = (float)rand()/RAND_MAX;
    while(r < 0.5 && lvl < max_level)
    {
        
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
}

class Skiplist {
public:
    int level;
    Node *header;
    void displayList();
    Skiplist() 
    {
        // maxlevel is 20
        header = new Node(-1, max_level);
        level = 0;
        
    }
    
    bool search(int target) 
    {

        Node *current = header;
        for(int i = level; i >=0; i--)
        {
            while((current->forward[i]!=NULL) 
                && current->forward[i]->key < target)
            {
                current = current->forward[i];
            }
            // update[i] = current;
        }
        
        current = current->forward[0];
        if(current!=NULL)
        {

            if(current->key == target)
            {
                
                return true;
            }
            else
            {
                
                return false;
            }
            
        }
        else
        {
            
            return false;
        }
    }
    
    void add(int num) 
    {
        Node *update[max_level];
        Node *current = header;

        for(int i = level; i >=0; i--)
        {
            while((current->forward[i]!=NULL) 
                && current->forward[i]->key < num)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        current = current->forward[0];

        if(current==NULL||current->key!=num)
        {
            int r_level = randomLevel();
            
            if (r_level > level)
            {
                for(int i = level+1; i <= r_level; i++)
                {
                    update[i] = header;
                }
                level = r_level;
            } 

            Node* n = new Node(num, r_level);

            for(int i = 0; i <= r_level; i++)
            {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;

            }

        }
        else if(current->key == num)
        {
            current->count++;
        }
    }
    
    bool erase(int num) 
    {
        Node *update[max_level];
        Node *current = header;

        for(int i = level; i >=0; i--)
        {
            while((current->forward[i]!=NULL) 
                && current->forward[i]->key < num)
            {
                current = current->forward[i];
            }
            update[i] = current;
        }
        
        current = current->forward[0];



        if(current!=NULL and current->key==num)
        {
            
            if(current->count > 1)
            {
                current->count--;
                return true;
            }
            else
            {
                
                for(int i = 0; i <= level; i++)
                {
                    if(update[i]->forward[i]!=current)
                        break;
                    update[i]->forward[i] = current->forward[i];

                }
               

                // int i = 0;
                // while(update[i]->forward[i]==current)
                // {
                //     update[i]->forward[i] = current->forward[i];
                //     i++;
                // }
                delete current;
                while(header->forward[this->level]==NULL
                    && this->level>0)
                {
                    this->level--;
                }
               
                return true;
            }
        }
        else
        {
            return false;
        }

    }
};

void Skiplist::displayList() 
{ 
    cout<<"\n*****Skip List*****"<<"\n"; 
    for (int i=0;i<=level;i++) 
    { 
        Node *node = header->forward[i]; 
        cout << "Level " << i << ": "; 
        while (node != NULL) 
        { 
            for(int k=0; k < node->count; k++)
                cout << node->key<<" "; 
            node = node->forward[i]; 
        } 
        cout << "\n"; 
    } 
}; 


int main()
{
    // std::cout << randomLevel() << std::endl;
    Skiplist *lst = new Skiplist();
    bool output;
    lst->add(16);
cout << "null,";
lst->add(5);
cout << "null,";
lst->add(14);
cout << "null,";
lst->add(13);
cout << "null,";
lst->add(0);
cout << "null,";
lst->add(3);
cout << "null,";
lst->add(12);
cout << "null,";
lst->add(9);
cout << "null,";
lst->add(12);
cout << "null,";
output = lst->erase(3);
if(output==1){cout << "true,";}else{cout << "false,";}
// lst->displayList();
output = lst->search(6);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(7);
cout << "null,";
output = lst->erase(0);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(1);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(10);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(5);
cout << "null,";
output = lst->search(12);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(7);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(16);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(7);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(0);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(9);
cout << "null,";
lst->add(16);
cout << "null,";
lst->add(3);
cout << "null,";
output = lst->erase(2);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(17);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(2);
cout << "null,";
// lst->displayList();
output = lst->search(17);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(0);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(9);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(14);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(1);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(6);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(1);
cout << "null,";
output = lst->erase(16);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(9);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(10);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(9);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(2);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(3);
cout << "null,";
lst->add(16);
cout << "null,";
output = lst->erase(15);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(12);
if(output==1){cout << "true,";}else{cout << "false,";}
// lst->displayList();
output = lst->erase(7);
if(output==1){cout << "true,";}else{cout << "false,";}
// lst->displayList();
lst->add(4);
cout << "null,";
output = lst->erase(3);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(2);
cout << "null,";
output = lst->erase(1);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(14);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(13);
cout << "null,";
lst->add(12);
cout << "null,";
lst->add(3);
cout << "null,";
output = lst->search(6);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(17);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(2);
cout << "null,";
output = lst->erase(3);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(14);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(11);
cout << "null,";
lst->add(0);
cout << "null,";
output = lst->search(13);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(2);
cout << "null,";
output = lst->search(1);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(10);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(17);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(0);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(5);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(8);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(9);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(8);
cout << "null,";
output = lst->erase(11);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(10);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(11);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(10);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(9);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->erase(8);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(15);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(14);
if(output==1){cout << "true,";}else{cout << "false,";}
lst->add(1);
cout << "null,";
lst->add(6);
cout << "null,";
lst->add(17);
cout << "null,";
lst->add(16);
cout << "null,";
output = lst->search(13);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(4);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(5);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(4);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(17);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(16);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(7);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(14);
if(output==1){cout << "true,";}else{cout << "false,";}
output = lst->search(1);
if(output==1){cout << "true,";}else{cout << "false,";}

    // lst->search(1);
    // lst->add(1);
    // lst->search(1);

    // lst->add(4);
    // lst->add(70);

    // lst->add(13);
    // lst->add(434);
    // lst->add(42);
    // lst->search(13);
    // lst->erase(13);
    // lst->search(13);




    // lst->add(3);
    // lst->displayList();
    // std::cout << lst->level << std::endl;


}