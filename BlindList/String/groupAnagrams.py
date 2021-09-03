class Solution:
    """
    https://leetcode.com/problems/group-anagrams/
    """
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans_dict = {}
        for str_i in strs:
            str_sort = sorted(str_i)
            str_sort = "".join(str_sort)
            print(str_sort)
            if not str_sort in ans_dict:
                ans_dict[str_sort] = []
            ans_dict[str_sort].append(str_i)
        ans = []
        for str_i in ans_dict:
            ans.append(ans_dict[str_i])
            
        return ans
