/*
  3. LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS [MEDIUM]
  
  Given a string s, find the length of the longest substring without repeating characters.
  
  Example
  ----------------------
  Input: s = "abcabcbb"
  Output: 3

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1){
            return 0;
        }
        set<char> set;
        int i = 0 ,j = 0;
        int ans = 0;
        while(j<s.size()){
            if(set.find(s[j])==set.end()){
                set.insert(s[j]);
                j++;
            }else{
                ans = max(ans, j-i);
                set.erase(s[i]);
                i++;
            }
        }
        ans = max(ans, j-i);
        return ans;
    }
};
