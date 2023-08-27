#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target)
		{
			int n = nums.size();
			int complement;
			unordered_map<int, int> num_loc;
			for(int i = 0; i < n; i++)
			{
				complement = target - nums[i];
				if(num_loc.count(complement) != 0){
					return {num_loc[complement], i};
				}
				num_loc[nums[i]] = i;
			}
			return {};
		}
};

int main()
{
	vector<int> arr;
	int target;
	cout << "enter target, size, elements of array :" << endl;
	cin >> target;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	Solution tester;
	vector<int> ans = tester.twoSum(arr, target);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}	


}
