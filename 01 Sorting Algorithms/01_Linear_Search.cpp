#include<iostream>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int index = -1;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == 8){
            index = i;
            break;
        }
    }
    if(index == -1){
        cout<<"Not found!"<<endl;
    }
    else{
        cout<<"Found at index "<<index<<endl;
    }
    return 0;
}
