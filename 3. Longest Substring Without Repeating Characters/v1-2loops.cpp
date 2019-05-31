/*
*    关键点：
*         while (start < len - 1) {
            bzero(occur, sizeof(occur));            
            while (end < len) { 
     这里每次都reset dict
     
            start = occurIdx[idx] + 1;
            end = start;     
            
            这里略有加速 而不是++start
            
            该版本问题是 没有充分利用dict 历史信息。 在下个版本中改进
*
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1) {
            return len;
        }
        
        char * data = &(s[0]);
        
        int start = 0 ;
        int end = 0;
        
        int idx = 0;
        unsigned char occur[128];
        int occurIdx[128];
        
        int maxSub = 0;
        int subLen = 0;
        
        while (start < len - 1) {
            bzero(occur, sizeof(occur));            
            while (end < len) {
                idx = data[end];
                //idx = (int)(occur[end]);
                if (occur[idx] > 0) {               
                    break;
                } else {
                    ++occur[idx];
                    occurIdx[idx] = end;
                    ++end;
                }
            }
            subLen = end - start;
            if (subLen > maxSub) {
                maxSub = subLen;
            }
            
            if (end >= len - 1) {
                break;
            }
            
            start = occurIdx[idx] + 1;
            end = start;               
        }
        
        return maxSub;
    }
};
