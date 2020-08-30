#include <bits/stdc++.h>

using namespace std;


long long mergeSort(vector<long long> &v, long long l, long long r, long long lower, long long upper)
{
	if(l==r)
	{
		if(v[l]<=upper)
            if(v[l]>=lower)
                return 1;
        return 0;
	}
	long long mid = l + r;
	mid = mid / 2;
	long long count = mergeSort(v, l , mid, lower, upper) + mergeSort(v, mid+1, r, lower, upper);
	long long j, k;
	j = k = mid + 1;

	for(long long i = l; i <= mid; i++)
	{
		while((j <= r)&&(v[j] - v[i] < lower))
		j++;
		while((k <= r)&&(v[k] - v[i] <= upper))
		k++;
		count += (k-j);
	}
	inplace_merge(v.begin() + l, v.begin() + mid + 1, v.begin() + r + 1);
	// merge(v,l,mid,r);
	return count;
}

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
    	vector<long long> pref_sums;
    	pref_sums.push_back(nums[0]);

    	for(int i = 1; i < nums.size(); i++)
    	{
    		pref_sums.push_back(pref_sums[i-1] + nums[i]);
    		// cout << pref_sums[i+1] << " " << endl;
    	}
    	return mergeSort(pref_sums, 0, pref_sums.size()-1, lower, upper);    
    }
};



