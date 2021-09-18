class Solution:
    """
    https://leetcode.com/problems/valid-palindrome/
    """
    def isPalindrome(self, s: str) -> bool:
        lower_a = ord('a')
        upper_a = ord('A') 
        temp_s = ""
        for i in s:
            if ord(i) >= lower_a and ord(i) < lower_a + 26:
                temp_s = temp_s + chr(ord(i) - 32)
            if ord(i) >= upper_a and ord(i) < upper_a + 26:
                temp_s = temp_s + i
            if ord(i) >= ord('0') and ord(i) <= ord('9'):
                temp_s = temp_s + i
        return temp_s == temp_s[::-1]