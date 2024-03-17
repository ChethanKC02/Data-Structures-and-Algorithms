#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int mid, int h){
    int left = l;
    int right = mid+1;
    int newarr[h+1], i = 0;
    while(left<=mid && right<=h){
        if(arr[left]<arr[right]){
            newarr[i++]=arr[left++];
        }
        else{
            newarr[i++]=arr[right++];
        }
    }
    while(left<=mid){
        newarr[i++]=arr[left++];
    }
    
    while(right<=h){
        newarr[i++]=arr[right++];
    }
    int ind = 0;
    for (int i = l; i <=h; i++) {
        arr[i] = newarr[ind++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r){
        return;
    }
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void print(int arr[],int n){
    for(int i=0;i< n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[8] = {5, 9, -1, 6, 1, 100, 0, -50};
    cout<<"Before Sorting: ";
    print(arr,8);
    mergeSort(arr,0,7);
    cout<<"After Sorting: ";
    print(arr,8);
    return 0;
}
