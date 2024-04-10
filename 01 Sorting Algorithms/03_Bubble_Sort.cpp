#include<bits/stdc++.h>
using namespace std;

void print_v(vector<int> &v){
    cout<<endl;
    for(int i:v) cout<<i<<" ";
}

int main(){
    vector<int> v = { 64, 34, 25, 12, 22, -100, 11, 90, -10, 0,};
    cout<<"Before Sorting";
    print_v(v);

    int n = v.size();
    for(int i=n-1; i>-1; i--){
        for(int j=0; j<i; j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
    cout<<"\nAfter Sorting";
    print_v(v);

    return 0;
}