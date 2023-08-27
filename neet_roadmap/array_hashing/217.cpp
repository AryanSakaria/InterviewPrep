#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_set<int> hash_map;
		for(int i = 0; i < nums.size(); i++)
		{
			if (hash_map.find(nums[i]) == hash_map.end())
			{
				hash_map.insert(nums[i]);
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	vector<int> arr;
	Solution tester;
	int n;
	cin >> n;
	int a_i;

	for (int i =0; i < n; i++)
	{
		cin >> a_i;
		arr.push_back(a_i);		
	}
	cout << tester.containsDuplicate(arr) << endl;
}
