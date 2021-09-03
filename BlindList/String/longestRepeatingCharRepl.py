class Solution:
    """
    https://leetcode.com/problems/longest-repeating-character-replacement/
    """
    def check_valid(self, s, k, start, r, dict_freq):
        max_freq = 0
        for let in dict_freq:
            max_freq = max(max_freq, dict_freq[let])
        len_s = r - start + 1
        if len_s - max_freq <= k:
            return True
        return False
        
    def characterReplacement(self, s: str, k: int) -> int:
        start = 0
        max_length = 0
        dict_freq = {}
        for i in range(26):
            dict_freq[chr(ord('A') + i)] = 0
            
        for r in range(len(s)):
            dict_freq[s[r]] += 1 
            while(not self.check_valid(s, k, start, r, dict_freq)):
                dict_freq[s[start]] -= 1
                start = start + 1
            max_length = max(max_length, r - start + 1)
            
        return max_length