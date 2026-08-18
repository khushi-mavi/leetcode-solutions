class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(n == 1 && m == 1 && haystack[0] == needle[0]){
            return 0;
        }
        for(int i = 0; i<=n-m; i++){
            bool match = true;
            for(int j = 0; j <m; j++){
                if(haystack[i+j] != needle[j]){
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }
        return -1;
        
    }
};