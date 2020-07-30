#include "SmartPtr.h"

#include <iostream>

struct Test
{
    int a;
    float b;
};

int main()
{
    const Test TEST_VALUE = {91, 13.37f};

    Test* notSmartPtr = nullptr;
    SmartPtr<Test> smartPtr;

    {
        Test* ptr = new Test(TEST_VALUE);
        std::cout<<"value of ptr is : "<<ptr<<std::endl;
        std::cout<<"pointed value of ptr is : "<<ptr->a<<"\t"<<ptr->b<<std::endl;
        notSmartPtr = ptr;
    }
    std::cout<<"value of ptr is : "<<notSmartPtr<<std::endl;
    std::cout<<"pointed value of ptr is : "<<notSmartPtr->a<<"\t"<<notSmartPtr->b<<std::endl<<std::endl;
    {
        SmartPtr<Test> ptr(TEST_VALUE);
        std::cout<<"value of ptr is : "<<ptr.getPtr()<<std::endl;
        std::cout<<"pointed value of ptr is : "<<ptr.getPtr()->a<<"\t"<<ptr.getPtr()->b<<std::endl;
        smartPtr.setPtr(ptr);
    }
    std::cout<<"value of ptr is : "<<smartPtr.getPtr()<<std::endl;
    std::cout<<"pointed value of ptr is : "<<smartPtr.getPtr()->a<<"\t"<<smartPtr.getPtr()->b<<std::endl;
}
