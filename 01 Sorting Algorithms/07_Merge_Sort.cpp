#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    
    void print_v(vector<int> &v){
        cout<<endl;
        for(int i:v) cout<<i<<" ";
    }

    vector<int> sort(vector<int> &v, int n){
        if(n >= 2){
            vector<int> v1(v.begin(),v.begin()+n/2);
            v1 =  sort(v1, v.size());
            vector<int> v2(v.begin()+n/2, v.end());
            v2 =  sort(v2, v2.size());
            return this->merge(v1, v2);
        }
        return v;
    }

    vector<int> merge(vector<int>& v1,vector<int>& v2){
        vector<int> v;
        int i = 0 ,j = 0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<=v2[j]){
                v.push_back(v1[i++]);
            }
            else{
                v.push_back(v2[j++]);
            }
        } 
        while(i<v1.size()){
            v.push_back(v1[i++]);
        }
        while(j<v2.size()){
            v.push_back(v2[j++]);
        }
        return v;
    }
};


int main(){
    vector<int> v = { 64, 34, 25, 12, 22, -100, 11, 90, -10, 0,};
    cout<<"Before Sorting";
    Solution s;
    s.print_v(v);
    vector<int> ans = s.sort(v,v.size()); 
    cout<<"\nAfter Sorting";
    s.print_v(ans);
    return 0;
}