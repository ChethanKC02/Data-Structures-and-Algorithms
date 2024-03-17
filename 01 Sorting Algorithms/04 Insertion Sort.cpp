#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v){
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void insertionSort(vector<int> &arr, int n)
{
    for(int i=1;i<n;i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main()
{
    vector<int> v = {5, 9, -1, 6, 1, 100, 0, -50};
    cout<<"Before Sorting: ";
    print(v);
    insertionSort(v,v.size());
    cout<<"After Sorting: ";
    print(v);
    return 0;
}
