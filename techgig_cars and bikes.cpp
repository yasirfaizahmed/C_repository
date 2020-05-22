#include<iostream>
using namespace std;

class vehicle{
    public:
    void display(void){
        cout<<"This is a vehicle"<<endl;
    }

};
class car : public vehicle{};
class bike : public vehicle{};
int main(){
    int N;
    cin>>N;
    vehicle v;
    if(N != 2 || N != 4){
        v.display();
    }
    else if(N == 2)

    return 0;
}
