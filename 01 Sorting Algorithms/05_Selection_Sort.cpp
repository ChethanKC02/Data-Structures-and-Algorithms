#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    
    void print_v(vector<int> &v){
        cout<<endl;
        for(int i:v) cout<<i<<" ";
    }

    void sel_sort(vector<int> &v){
        int n = v.size();
        for(int i=0;i<n-1;i++){
            int ind = i;
            for(int j=i+1;j<n;j++ ){
                if(v[j]<v[ind]){
                    ind = j;
                }
            }
            swap(v[ind],v[i]);
        }
    }
};


int main(){
    vector<int> v = { 64, 34, 25, 12, 22, -100, 11, 90, -10, 0,};
    cout<<"Before Sorting";
    Solution s;
    s.print_v(v);
    s.sel_sort(v); 
    cout<<"\nAfter Sorting";
    s.print_v(v);
    return 0;
}