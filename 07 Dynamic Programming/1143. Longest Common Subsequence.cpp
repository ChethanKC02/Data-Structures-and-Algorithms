class Solution {
private:
// Memoization
    vector<vector<int>> dp;
    int n1 , n2 ;
    int solve_memo(int i, int j, string s1,string s2){
        if( i == n1 || j == n2){
            return 0;
        }
        if(s1[i] == s2[j]){
            return 1 + solve_memo(i+1,j+1,s1,s2);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = max(solve_memo(i+1,j,s1,s2),solve_memo(i,j+1,s1,s2));
    }

//Tabulation 
    int solve_tab(string s1,string s2){
        vector<vector<int>> tab(n1+1,vector<int>(n2+1));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(s1[i] == s2[j]){
                    tab[i+1][j+1] = tab[i][j] +1;
                }
                else{
                    tab[i+1][j+1] = max(tab[i+1][j],tab[i][j+1]);
                }
            }
        }
        return tab[n1][n2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size(), n2 = text2.size();
        dp.assign(n1,vector<int>(n2,-1));
        int ans1 = solve_memo(0,0,text1,text2);
        int ans2 = solve_tab(text1,text2);
        cout<<ans1<<" "<<ans2<<endl;
        return ans2;
    }
};