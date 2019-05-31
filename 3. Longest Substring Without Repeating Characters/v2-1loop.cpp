//https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1737/C%2B%2B-code-in-9-lines.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1) {
            return len;
        }
        
        char * data = &(s[0]);
        int start = 0;        
        int idx = 0;        
        int maxSub = 0;
        int subLen = 0;
        std::vector<int> occur(128, -1);
        while (idx < len) {
            int ch = data[idx];
            if (occur[ch] >= start) {
                subLen = idx - start;
                if (subLen > maxSub) {
                    maxSub = subLen;
                }                
                start = occur[ch] + 1;
            }
            occur[ch] = idx;             
            ++idx;
        }
        subLen = idx - start;
        if (subLen > maxSub) {
            maxSub = subLen;
        }         
            
        
        return maxSub;
    }
};
