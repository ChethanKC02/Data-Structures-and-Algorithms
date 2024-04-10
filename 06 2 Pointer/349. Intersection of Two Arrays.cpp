class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int p1 = 0, n1 = nums1.size(), p2 = 0, n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(p1<n1 && p2<n2){
            if(nums1[p1] == nums2[p2]){
                v.push_back(nums1[p1]);
                int a = nums1[p1];
                while( p1<n1 && nums1[p1] == a) p1++;
                while( p2<n2 && nums2[p2] == a) p2++;
            }
            else if(nums1[p1]<nums2[p2]){
                p1++;
            }
            else{
                p2++;
            }
        }
        return v; 
    }
};