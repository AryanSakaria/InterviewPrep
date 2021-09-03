class Solution:
    """
    https://leetcode.com/problems/valid-anagram/
    """
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = {}
        t_dict = {}
        for i in range(26):
            s_dict[chr(ord('a') + i)] = 0
            t_dict[chr(ord('a') + i)] = 0
            
        for i in s:
            s_dict[i] += 1
        for i in t:
            t_dict[i] += 1

        return s_dict == t_dict