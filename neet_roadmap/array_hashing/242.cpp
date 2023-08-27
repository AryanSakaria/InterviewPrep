#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		unordered_map<char, int> count;
		for(int i = 0; i < s.size(); i++)
		{
			count[s[i]]++;
		}
		for(int i = 0; i < t.size(); i++)
		{
			count[t[i]]--;
		}
		for(auto i = count.begin(); i!= count.end(); i++)
		{
			cout << "count val for " << i->first << " is:";
			cout << i->second << endl;
			if(i->second != 0) return false;
		}

		return true;
	}
};

int main()
{
	string s, t;
	getline(cin,s);
	getline(cin,t);
	cout << "string 1 is " << s << endl;
	cout << "string 2 is " << t << endl;
	Solution tester;
	cout << tester.isAnagram(s, t) << endl;
}
