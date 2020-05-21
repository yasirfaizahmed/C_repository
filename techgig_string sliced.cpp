#include<iostream>
using namespace std;

int main(){
    char str[100];
    cin.getline(str, 99);
    int start, endd;
    cin>>start;
    cin>>endd;
    char new_str[100];
    int i=0;
    for(int i=start;i<sizeof(str)/sizeof(char);i++){
        if(i <= endd)str[i - start] = str[i];
        else str[i - start] = '\0';
    }

    i = 0;
    while(str[i] != '\0') {
        cout<<str[i];
        i++;
    }

    return 0;
}
