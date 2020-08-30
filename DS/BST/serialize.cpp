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

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
    	string s;
    	if(root==nullptr)
    	{
    		s = "";
    		return s;
    	}
    	
    	s = to_string(root->val) + ",";
    	
    	string s_left = serialize(root->left);
    	string s_right = serialize(root->right);
    	s = s + s_left + s_right;
    	return s;


    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
    	string delim = ",";
    	// cout << "Data :" << data << endl;
    	if(data.size()==0)
    	{
    		return nullptr;
    	}
    	// cout << data << " " << data.size() << endl;
    	vector<string> v = split(data, delim);
    	// cout << "Size :" << v.size() << ";Split data:" << endl;
    	// for (auto i : v) cout << i << endl;
    	if(v.size()<=1)
    	{
    		return nullptr;
    	}
    	// cout << v.size() << endl;
    	// return nullptr;
    	string left_tree = "";
    	string right_tree = "";
    	int root = stoi(v[0]);
    	// cout << "root " << root << endl;
    	TreeNode *newNode = new TreeNode(root);
    	// int i = 1;

    	for(int i=1; i < v.size()-1; i++)
    	{
	    	if(stoi(v[i]) < root)
	    	{
	    		// cout << "Adding to left tree:" << v[i] << endl;
	    		left_tree += v[i] + "," ;
	    		// i++;
	    	}
	    	else
	    	{
	    		// cout << "Adding to right tree:" << v[i] << endl;
	    		right_tree += v[i] + ',';

	    	}

    	}
    	// while(i < v.size()-1)
    	// {
    	// 	i++;
    	// }

    	// cout << "left tree:" << left_tree << " " << left_tree.size() << endl;
    	// cout << "right tree:" << right_tree << " " << right_tree.size() << endl;
    	newNode->left  = deserialize(left_tree);
    	newNode->right = deserialize(right_tree);
    	return newNode;

    }
};

int main()
{
	TreeNode* leaf = new TreeNode(3);
	TreeNode* leaf2 = new TreeNode(9);
	TreeNode* leaf3 = new TreeNode(20);

	TreeNode* node = new TreeNode(15, leaf2, leaf3);

	TreeNode* root = new TreeNode(7, leaf, node);
	Codec temp_obj;
	
	cout << 	temp_obj.serialize(root) << endl;
	root = temp_obj.deserialize(temp_obj.serialize(root));
	cout << 	"after deserializing : " << temp_obj.serialize(root) << endl;
	
	// BSTIterator *iterator = new BSTIterator(root);
	// cout << iterator->next() << endl;
	// cout << iterator->next() << endl;
	// cout << iterator->hasNext() << endl;
	// cout << iterator->next() << endl;
	// cout << iterator->hasNext() << endl;
	// cout << iterator->next() << endl;
	// cout << iterator->hasNext() << endl;
	// cout << iterator->next() << endl;
	// cout << iterator->hasNext() << endl;
	

}