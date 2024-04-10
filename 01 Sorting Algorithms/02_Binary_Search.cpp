#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int bs(vector<int> &v, int k){
        int low = 0, high = v.size();
        int mid;
        while(low < high){
            mid = low + (high - low) /2;
            if(v[mid] == k){
                return mid;
            }
            else if(v[mid] <k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    int rec_bs(vector<int> &v, int low, int high, int k){
        if(low > high){
            return -1;
        }
        int mid = low + (high - low) / 2;
        if(v[mid] == k){
            return mid;
        }
        else if(v[mid] < k){
            return rec_bs(v,mid+1,high,k);
        }
        else{
            return rec_bs(v,low,high-1,k);
        }
    }
};

int main(){
    vector<int> v= {1,2,3,4,5,6,7,8,9,10};
    Solution s;
    cout<<s.bs(v,10)<<endl;
    cout<<s.bs(v,11)<<endl;
    cout<<"------"<<endl;
    cout<<s.rec_bs(v,0,10,8)<<endl;
    cout<<s.rec_bs(v,0,10,12)<<endl;
    return 0;
}

/*
Time Complexity: 
    Best Case: O(1)
    Average Case: O(log N)
    Worst Case: O(log N)
Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).

Advantages of Binary Search:
- Binary search is faster than linear search, especially for large arrays.
- More efficient than other searching algorithms with a similar time complexity, such as interpolation search or exponential search.
- Binary search is well-suited for searching large datasets that are stored in external memory, such as on a hard drive or in the cloud.
*/
