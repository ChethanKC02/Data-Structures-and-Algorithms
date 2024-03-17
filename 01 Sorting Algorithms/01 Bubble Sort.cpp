#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    bool swapped;
    for(int i=n-1;i>-1;i--){
        swapped = false;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!swapped) break;
    }
}

void print(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v = {5, 9, -1, 6, 1, 100, 0, -50};
    cout<<"Before Sorting: ";
    print(v);
    bubbleSort(v,v.size());
    cout<<"After Sorting : ";
    print(v);
    return 0;
}
