class Solution:
    """
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
    """
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not len(s):
            return 0
        output = 0
        start = 0
        seen = {}
        for r in range(len(s)):
            if s[r] in seen.keys():
                if start <= seen[s[r]]:
                    start = seen[s[r]] + 1
            seen[s[r]] = r
            output = max(output, r - start + 1)
        return output   

if __name__ == '__main__':
    test = Solution()
    str_test = "aab"
    test.lengthOfLongestSubstring(str_test)