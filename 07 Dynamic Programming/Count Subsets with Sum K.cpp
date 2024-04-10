long long ans = 0;
vector<vector<long long>> dp;
int n;


// Meoization
int solve(int i, vector<int> &v, int sum){
	if(i==n && sum == 0) return 1;
	if(i == n || sum<0){
		return 0;
	}
	if(sum == 0){
		return 1;
	}
	if(dp[i][sum] != -1){
		return dp[i][sum];
	}

	return dp[i][sum] = solve(i+1,v,sum-v[i]) + solve(i+1,v,sum);
}

//Tabulation
int mod = 1e9+7;
int findWays(vector<int>& arr, int k){
	n = arr.size();
	dp.assign(n,vector<long long>(k+1,0));
	// return solve(0,arr,k) % mod;
	for(int i=0;i<n;i++){
		dp[i][0] = 1;
	}
	if(arr[0]<=k){
		dp[0][arr[0]] = 1;
	}

	for(int i=1;i<n;i++){
		for(int target = 1;target <= k;target++){
			long long not_taken = dp[i-1][target];
			long long taken = 0;
			if(arr[i]<=target) 
				taken += dp[i-1][target-arr[i]];
			dp[i][target] = (taken+not_taken)%mod;
		}
	}
	return dp[n-1][k] % mod;
}
