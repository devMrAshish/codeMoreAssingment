#include<iostream>
using namespace std;
// Function to swap two integers using poineter
void swap(int* a, int* b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

int main()
{
    int a{34};    // An intger variable

    cout<< " Originl value : "<<a<<" and memory address of a is "<<&a<<endl;

    int* ptr_1=&a;       // Pointer ptr_1 pointing to address of a

    *ptr_1=21;          // Manipulating the value, by dereferencing

    cout<< " Value of a after change is "<<*ptr_1<<" and memory address of a is "<<ptr_1<<endl;

    // Testing the swap function

    int x=50;
    int y=50;
    cout<<" Before swap: "<<endl;
    cout<<"X = "<<x<<", Y = "<<y<<endl;
    swap(&x,&y);
    cout<<" After swap: "<<endl;
    cout<<" X = "<<x<<", Y = "<<y<<endl;

    
    return 0;
}
