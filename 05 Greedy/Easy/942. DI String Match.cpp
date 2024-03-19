//https://leetcode.com/problems/di-string-match/description/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length(), low = 0, high = n;
        vector<int> v;
        for(char c:s){
            if(c == 'I') v.push_back(low++);
            else v.push_back(high--);
        }          
        v.push_back((low - high == -1)?high:low);
        return v;
    }
};