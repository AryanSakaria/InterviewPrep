class Solution {
	public:
		    vector<int> topKFrequent(vector<int>& nums, int k) {
			            unordered_map<int, int> mp;
				            int max_int = 0;
					            for(auto x: nums)
							            {
									                mp[x]++;
											            max_int = max(max_int, mp[x]);
												            }
						            cout << "max " << max_int << endl;
							            vector<vector<int>> bucket_list(max_int);
								            vector<int> ans;
									            for(auto x: mp)
											            {
													                cout << "first " << x.first << " second " << x.second << endl;
															            bucket_list[x.second-1].push_back(x.first);
																            }
										            for(int i = bucket_list.size()-1; i >= 0; i--)
												            {
														                for(int j = 0; j < bucket_list[i].size();j++)
																	            {
																			                    ans.push_back(bucket_list[i][j]);
																					                    k--;
																							                    if(k == 0)
																										                    {
																													                        return ans;
																																                }
																									                }
																            
																        }
											            return ans;
												        }
};
