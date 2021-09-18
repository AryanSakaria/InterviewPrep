from collections import deque
class Solution:
    """
    https://leetcode.com/problems/valid-parentheses/
    """
    def isValid(self, s: str) -> bool:
        cur_open = deque()
        dict_opp = {'(' : ')', '{' :'}', '[' :']'}
        for i in s:
            if i in dict_opp.keys():
                cur_open.append(i)
                #opening bracket
            else:
                #closing bracket
                if len(cur_open) == 0:
                    #closing a bracket
                    #when not enough open
                    #brackets
                    return False
                cur_brak = cur_open.pop()
                if i != dict_opp[cur_brak]:
                    return False
        if len(cur_open) != 0:
            return False
        return True