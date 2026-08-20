class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        n = len(haystack)
        m = len(needle)
        if m > n:
            return -1
        lps = [0]*m
        self.buildlps(needle,lps)
        j = 0
        for i in range (n):
            while j > 0 and haystack[i] != needle[j]:
                j = lps[j-1]
            if haystack[i] == needle[j]:
                j += 1
            if j == m:
               return i - m + 1
        return -1



    def buildlps(self, needle: str, lps: list)-> None:
       m = len(needle)
       length = 0
       i = 1
       lps[0] = 0
       while i < m:
        if needle[i] == needle[length]:
            length += 1
            lps[i] = length
            i += 1
        else: 
            if length != 0:
                length = lps[length-1]
            else:
                lps[i] = 0
                i += 1