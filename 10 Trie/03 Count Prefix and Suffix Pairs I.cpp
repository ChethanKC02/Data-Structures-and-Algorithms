class Solution {
private:
    bool is(string s1, string s2){
        int size = s2.size();
        int s = s1.size()-1;
        int i = 0;
        int p1 = 0, p2 = size-1;
        while(i<s1.size() && i < size){
            if(s1[p1] != s2[p1++] || s1[s-i]!=s2[p2--]){
                return false;
            }
            i++;
        }
        return (i == s1.size() )?true:false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].size() <= words[j].size()) count += is(words[i], words[j]);                    
            }
        }
        return count;
    }
};