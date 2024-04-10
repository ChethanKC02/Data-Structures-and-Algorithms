#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    
    void print_v(vector<int> &v){
        cout<<endl;
        for(int i:v) cout<<i<<" ";
    }

    void ins_sort(vector<int> &v){
        int n = v.size();
        for(int i=0;i<n;i++){
            int j = i;
            while(j>0 && v[j] < v[j-1] ){
                swap(v[j],v[j-1]);  
                j--;
            } 
        }
    }
};


int main(){
    vector<int> v = { 64, 34, 25, 12, 22, -100, 11, 90, -10, 0,};
    cout<<"Before Sorting";
    Solution s;
    s.print_v(v);
    s.ins_sort(v); 
    cout<<"\nAfter Sorting";
    s.print_v(v);
    return 0;
}