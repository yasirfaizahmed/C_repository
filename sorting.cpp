#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

swaping(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = rand()%1000;
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<endl;

    int i = 0, j = 0;
    while(j<n){
        for(i=0;i<n;i++){
            if(arr[i]>arr[i+1]) swaping(&arr[i], &arr[i+1]);
        }
        j++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
