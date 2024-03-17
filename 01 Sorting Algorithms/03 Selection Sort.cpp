#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr, int n) {
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(arr[min] < arr[i]){
            swap(arr[i],arr[min]);
        }
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
    selectionSort(v,v.size());
    cout<<"After Sorting: ";
    print(v);
    return 0;
}
