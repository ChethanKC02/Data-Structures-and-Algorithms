//https://leetcode.com/problems/array-partition/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = 0, p1 = 0;
        while(p1<n){
            ans+=nums[p1];
            p1+=2;
        }
        return ans;
    }
};