/*#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int main(){
    bool flag = false;
    string array[10];
    fstream file;
    int loop = 0;
    string line;
    file.open("data.txt");
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, line);
            array[loop] = line;
            loop++;
            if(array[loop] == "this is to test!!") flag = true;
        }
    }
    if(flag == true) cout<<"found"<<endl;
    for(int i=0;i<=loop;i++)
    {
        cout<<array[i]<<endl;
    }
    file.close();
    return 0;
}*/
/*
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int namei = 0;
string name[30];
string number[30];
int room_no[30];

class hotel{
    public:
        void main_menu();
        void book_a_room();
        void costomer_record();
        void rooms_alloted();
        void edit_record();
        void save_exit();
};

void hotel::main_menu(){
    int choice;
    cout<<"-------------------------------HOTEL MANAGEMENT SYSTEM---------------------------"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"           --------------------------MAIN MENU-------------------------             "<<endl;
    cout<<"\t\t\t1.BOOK A ROOM"<<endl;
    cout<<"\t\t\t2.COSTOMER RECORD"<<endl;
    cout<<"\t\t\t3.ROOMS ALLOTED"<<endl;
    cout<<"\t\t\t4.EDIT RECORD"<<endl;
    cout<<"\t\t\t5.EXIT"<<endl;
    cout<<"\t\t\t ENTER YOUR CHOICE:";
    cin>>choice;

    switch(choice){
        case 1:
            book_a_room();
            break;
        case 2:
            costomer_record();
            break;
        case 3:
            rooms_alloted();
            break;
        case 4:
            edit_record();
            break;
        case 5:
            save_exit();
        default:
            cout<<"\n\t\t\t invalid input!!\n\t\t\tENTER YOUR CHOICE AGAIN";
            cout<<"\n\t\t\t press anything to continue"<<endl;
            cin>>choice;
            main_menu();
            break;
    }
}

void hotel::book_a_room(){
    string temp;
    cout<<"\t\tname:";
    cin>>temp;
    name[namei] = temp;
    namei++;
    main_menu();
}

void hotel::save_exit(){
    for(int i=0;i<=namei;i++){
        fstream file_name;
        file_name.open("file_name.txt",ios::app);
        file_name<<name[i];
        file_name<<endl;
        file_name.close();
        for(int i=0;i<=namei;i++)
            if()
    }
    main_menu();
}

void hotel::costomer_record(){

}

void hotel::rooms_alloted(){

}

void hotel::edit_record(){

}

int main(){
    fstream file_name;
    fstream file_number;
    fstream file_room_number;

    hotel lmao;
    lmao.main_menu();
}*/
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

string name, number;
int room_number;

class hotel{
    public:
        void main_menu();
        void book_a_room();
        void costomer_record();
        void rooms_alloted();
        void edit_record();
};


void hotel::main_menu(){
    int choice;
    cout<<"-------------------------------HOTEL MANAGEMENT SYSTEM---------------------------"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"           --------------------------MAIN MENU-------------------------             "<<endl;
    cout<<"\t\t\t1.BOOK A ROOM"<<endl;
    cout<<"\t\t\t2.COSTOMER RECORD"<<endl;
    cout<<"\t\t\t3.ROOMS ALLOTED"<<endl;
    cout<<"\t\t\t4.EDIT RECORD"<<endl;
    cout<<"\t\t\t5.EXIT"<<endl;
    cout<<"\t\t\t ENTER YOUR CHOICE:";
    cin>>choice;

    switch(choice){
        case 1:
            book_a_room();
            break;
        case 2:
            costomer_record();
            break;
        case 3:
            rooms_alloted();
            break;
        case 4:
            edit_record();
            break;
        case 5:
            exit(0);
        default:
            cout<<"\n\t\t\t invalid input!!\n\t\t\tENTER YOUR CHOICE AGAIN";
            cout<<"\n\t\t\t press anything to continue"<<endl;
            cin>>choice;
            main_menu();
            break;
    }
}

void hotel::book_a_room(){
    int len = 0;
    fstream file_names;
    fstream file_phone;
    fstream file_room;

    file_names.open("names.txt",ios::app);
    cout<<"\t\tName:";
    cin>>name;
    file_names<<"\n";
    file_names<<name;
    file_names.close();
    //len = name.size();
    //for(int i=0;i<24-len;i++)file<<" ";

    file_phone.open("phone.txt",ios::app);
    cout<<"\t\tPhone no.:";
    cin>>number;
    file_phone<<"\n";
    file_phone<<number;
    file_phone.close();
    //len = number.size();
    //for(int i=0;i<24-len;i++)file<<" ";

    file_room.open("room.txt",ios::app);
    cout<<"\t\tRoom no.:";
    cin>>room_number;
    file_room<<"\n";
    file_room<<room_number;
    file_room.close();
    cout<<"\t\tSaved!!"<<endl;
    system("CLS");
    main_menu();
}

void hotel::costomer_record(){
    /*string letters;
    string line;
    string token;
    ifstream file_name;
    cout<<"enter search word ";
    cin>>letters;
    file_name.open("names.txt");
    if(file_name.is_open()){
        while (getline(file_name, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
        }
    }
    cout << token << " not found" << endl;
    }*/

    string array[5];
    string line;
    int j = 0;
    int in = 0;
    int in_i = 0;
    int room;
    string name;
    ifstream file_room;  //opooen a file
    ifstream file_name;
    ifstream file_phone;
    file_room.open("phone.txt");  //open a room file
    if(file_room.is_open()){  //untill its closed
        while(!file_room.eof()){
            getline(file_room, line);
            array[j] = line;
            j++;
        }
    }
    else cout<<"no file found!!!"<<endl;
    cout<<"enter the room no."<<endl;
    scanf("%d", &room);
    while(array[in]!=""){
        in++;
        if(room == array[in]){
            cout<<"room already booked by:"<<endl;
            file_name.open("names.txt");
            while(!file_name.eof()){
                in_i++;
                getline(file_name, line);
                if(in==in_i)
                    cout<<line<<endl;
            }
        }
    }
    file_room.close();
}

void hotel::rooms_alloted(){

}

void hotel::edit_record(){

}

int main(){
    hotel you;
    you.main_menu();
    return 0;
}


