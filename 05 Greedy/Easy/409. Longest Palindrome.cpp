//https://leetcode.com/problems/longest-palindrome/description/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int odds = 0;
        int flag = 0;
        for(char c:s){
            mp[c]++;
        }
        int evens = 0;
        for(const auto&[ch,freq]:mp){
            if(freq%2 == 0){
                evens += freq;
            }
            else{
                flag = 1;
                odds+=freq-1;
            }
        }
        return odds + flag +evens;
    }

};