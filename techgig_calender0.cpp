#include <iostream>
using namespace std;
int main()
{
    int month;
    int day_;
    cin>>month;
    cin>>day_;

	int total_days = 0;
	int y[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i = 0;
	while(i<month){
        total_days = total_days + y[i];
        i++;
	}

	bool start = false;
	int week =0;
	int day=day_;
	for(int i=1;i<=total_days/7;i++){
        for(int j=1;j<=7;j++){
            day++;
            if(day == total_days - y[month]) start = true;
        }
        if(start == true) week++;
	}
	cout<<week;

}
