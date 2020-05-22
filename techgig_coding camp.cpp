#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n <= 9) cout<<n;

    int cons = 189;

    if(n > 9 && n <= cons){
        int d = -1;
        for(int i=9;i<=n;i++)
            if(n <= cons) if(i % 2 != 0) d++;
        if(n % 2 == 0)cout<<(n - d) / 10;
        else cout<<(n - d) - ((n - d) / 10) * 10;
    }

    int m = 0;
    if(n > cons){
        m = (n - 190) / 3;
        if((n - 190) % 3 == 0) cout<<(m + 100) / 100;
        else if((n - 190) % 3 == 1) cout<<((m + 100) / 10) % 10;
        else if((n - 190) % 3 == 2) cout<<((m + 100) % 100) % 10;
    }

    return 0;
}
