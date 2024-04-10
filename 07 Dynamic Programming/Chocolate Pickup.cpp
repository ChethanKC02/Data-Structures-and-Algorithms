/*
2
3 4
2 3 1 2
3 4 2 2
5 6 3 5
->21
2 2
1 1
1 2
->5
*/

#include <bits/stdc++.h> 

vector<vector<vector<int>>> dp;
int row, col;


//Memoization
int solve(int i, int j1, int j2, vector<vector<int>> & g){
    if(j1<0 || j1 == col || j2<0 || j2 == col){
        return -1e9;
    }

    if(i == row-1){
        if(j1 == j2){
            return g[i][j1];
        }
        else{
            return g[i][j1] + g[i][j2];
            
        }
    }

    if(dp[i][j1][j2] != -1) 
        return dp[i][j1][j2]; 
    
    int sol = INT_MIN;
    for(int s1 = -1;s1<=1;s1++){       
        for(int s2= -1;s2<=1;s2++){
            int ans;
            if(j1 == j2){
                ans = g[i][j1] + solve(i+1,j1+s1,j2+s2,g);
            }
            else{
                ans = g[i][j1] + g[i][j2] + solve(i+1,j1+s1,j2+s2,g);
            }
            sol = max(sol,ans);
        }
    }

    return dp[i][j1][j2] = sol;
}


//Tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    dp.assign(r,vector<vector<int>>(c,vector<int>(c,-1)));
    // row = r;
    // col =c;
    // return solve(0,0,col-1,grid);
    for(int j1 = 0;j1<c;j1++){
        for(int j2=0;j2<c;j2++){
            if(j1 == j2){
                dp[r-1][j1][j2] = grid[r-1][j1];
            }
            else{
                dp[r-1][j1][j2] = grid[r-1][j2]+grid[r-1][j1];
            }
        }
    }

    for(int i = r-2;i>-1;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2 = 0;j2<c;j2++){
                int ans = INT_MIN;
                for(int s1=-1;s1<2;s1++){
                    for(int s2=-1;s2<2;s2++){
                        int sum;
                        if(j1 == j2){
                            sum = grid[i][j1];
                        }
                        else{
                            sum = grid[i][j1] + grid[i][j2];
                        }

                        if( j1+s1<0 || j1+s1==c || j2+s2<0 || j2+s2==c){
                            sum += -1e9;
                        }
                        else{
                            sum += dp[i+1][j1+s1][j2+s2];
                        }
                        ans = max(ans,sum);
                    }
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][c-1];

}