//https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
private:
    bool ispalindrome(string s, int start, int end){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() -1 ;
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                return (ispalindrome(s,l+1,r) || ispalindrome(s,l,r-1));
            }
        }
        return true;
    }
};