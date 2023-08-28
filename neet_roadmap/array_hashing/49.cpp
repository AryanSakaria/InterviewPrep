#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs)
		{
			int n = strs.size();
			unordered_map<string, vector<string>> hash_map;
			for(auto x: strs)
			{
				string word = x;
				sort(word.begin(), word.end());
				hash_map[word].push_back(x);
			}
			vector<vector<string>> ans;
			for(auto x: hash_map)
			{
				ans.push_back(x.second);
			}
			return ans;
		}

};

int main()
{
	Solution tester;
	int n;
	cout << "Enter number of strs" << endl;
	cin >> n;
	vector<string> strs;
	for(int i=0; i < n; i++)
	{
		string word;
		cin >> word;
		strs.push_back(word);
	}
	vector<vector<string>> ans = tester.groupAnagrams(strs);
	for(auto x: ans)
	{
		for(auto y: x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
	
}
