class Solution:
    """
    https://leetcode.com/problems/minimum-window-substring/
    """
    def check_valid(self, dict_freq, t_dict):
        for key in t_dict:
            if not key in dict_freq:
                return False
            if t_dict[key] > dict_freq[key]:
                return False
        return True
        
    
    def minWindow(self, s: str, t: str) -> str:
        start = 0
        min_length = 1000000
        dict_freq = {}
        t_dict = {}
        found_valid = False
        ans_str = s
        
        
        for i in range(len(t)):
            if t[i] in t_dict:
                t_dict[t[i]] += 1
            else:
                t_dict[t[i]] = 1
        
            
        for r in range(len(s)):
            if s[r] in dict_freq:
                dict_freq[s[r]] += 1
            else:
                dict_freq[s[r]] = 1
        
            found_valid = self.check_valid(dict_freq, t_dict) or found_valid
            if not found_valid:
                continue
                
            if found_valid:
                while(self.check_valid(dict_freq, t_dict)):
                    dict_freq[s[start]] -= 1
                    start = start + 1
                if not self.check_valid(dict_freq, t_dict):
                    dict_freq[s[start-1]] += 1
                    start = start -1
                    
                if len(s[start:r+1]) < len(ans_str):
                    # min_length = len(s[start:r+1])
                    ans_str = s[start:r+1]
                    
        if not found_valid:
            return ""
        return ans_str