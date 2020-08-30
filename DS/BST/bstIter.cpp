#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode()
	{
		val = 0;
		left = nullptr;
		right = nullptr;
	}

	TreeNode(int x)
	{
		val = x;
		left = nullptr;
		right = nullptr;
	}

	TreeNode(int x, TreeNode* left, TreeNode* right)
	{
		val = x;
		this->left = left;
		this->right = right;
	}
};



class BSTIterator {
	public:
	stack<TreeNode*> tree_stack;

    BSTIterator(TreeNode* root) 
    {
        TreeNode* temp = root;
        while(temp!=nullptr)
        {
        	tree_stack.push(temp);
        	temp = temp->left;
        }
    }
    
    /** @return the next smallest number */
    int next() 
    {
      	TreeNode* ret = tree_stack.top();

      	TreeNode* temp = ret->right;

      	tree_stack.pop();
      	while(temp!=nullptr)
      	{
      		tree_stack.push(temp);
      		temp = temp->left;
      	}

      	return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        if(tree_stack.empty())
        {
        	return false;
        }
        return true;
    }
};

int main()
{
	TreeNode* leaf = new TreeNode(3);
	TreeNode* leaf2 = new TreeNode(9);
	TreeNode* leaf3 = new TreeNode(20);

	TreeNode* node = new TreeNode(15, leaf2, leaf3);

	TreeNode* root = new TreeNode(7, leaf, node);

	BSTIterator *iterator = new BSTIterator(root);
	cout << iterator->next() << endl;
	cout << iterator->next() << endl;
	cout << iterator->hasNext() << endl;
	cout << iterator->next() << endl;
	cout << iterator->hasNext() << endl;
	cout << iterator->next() << endl;
	cout << iterator->hasNext() << endl;
	cout << iterator->next() << endl;
	cout << iterator->hasNext() << endl;
	

}