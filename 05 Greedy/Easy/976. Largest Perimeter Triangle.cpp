//https://leetcode.com/problems/largest-perimeter-triangle/description/
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        while(i>1){
            if(nums[i-2]+ nums[i-1] >nums[i]){
                return nums[i] + nums[i-1]+nums[i-2];
            }
            i--;
        }
        return 0;
    }
};