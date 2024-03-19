//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0, n = nums.size();
        for( i;i<n;i++){
            if(nums[i]<0 && k>0){
                nums[i]*=-1;
                k--;
            }
            else{
                break;
            }
        }
        k%=2;
        if(k == 1){
            sort(nums.begin(),nums.end());
            nums[0] *= -1;
        }
        
        int sum = 0;
        for(int i:nums){
            sum+=i;
            cout<<i<<" ";
        }
        return sum;
    }
};