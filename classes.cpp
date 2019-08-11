#include<iostream>

class main_class
{
public:
    float x;
};

    class sub_class : public main_class
{
public:
    float y;
};


int main()
{
    main_class obj_main;
    obj_main.x = 10.0;
    std::cout<<"from main_class"<<std::endl;

    sub_class obj_sub;
    obj_sub.y = 100.0;
    std::cout<<"from sub_class"<<obj_sub.x<<std::endl;
}

