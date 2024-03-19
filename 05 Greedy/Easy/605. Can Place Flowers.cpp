//https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0 ; i<flowerbed.size() ;i+=2 ){
            if(flowerbed[i]==0){
                int prev = (i == 0)?0:flowerbed[i-1];
                int next = ( i== flowerbed.size()-1)?0:flowerbed[i+1];
                if(prev==0 && next==0){
                    count++;
                    i++;
                }
            }
        }
        cout<<count;
        return count>=n;
    }
};