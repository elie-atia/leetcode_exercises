class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        result = 0
        for i in range(len(s)):
            previous_chars = {}
            result_temp = 0
            for char in s[i:]:
                if(not char in previous_chars):
                    result_temp += 1
                    previous_chars[char] = True
                else:
                    break
            result = max(result, result_temp)

        return result


s = Solution()
lengthOfLongestSubstring = s.lengthOfLongestSubstring('pwwkew')
print(lengthOfLongestSubstring)



