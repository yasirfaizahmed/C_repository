#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
	if(n > 1000) return 0;
    int arr[n] = {};
    for(int i=0;i<n;i++) cin>>arr[i];

    int temp;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(arr[i + 1] < arr[i]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }



    cout<<arr[n - 2];

    return 0;
}
