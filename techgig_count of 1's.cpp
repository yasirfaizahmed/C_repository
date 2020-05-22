#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    int one = 0;
    int arr[100] = {};
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i] == 1) one++;
        if(arr[i] != 1 && arr[i] != 0 ) break;
    }
    cout<<one;

    return 0;
}

