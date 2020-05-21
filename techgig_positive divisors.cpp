#include<iostream>
using namespace std;

int main(){
    int count_ = 0;
    int final_count = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i % j == 0) count_++;
        }
        if(count_ == 4) {
            final_count++;
            count_ = 0;
        }

        count_ = 0;
    }
    cout<<final_count;

    return 0;
}
