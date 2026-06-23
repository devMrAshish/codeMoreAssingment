#include<iostream>
#include "array_function.h"
using namespace std;
int main()
{
    int arr[5];
    int length=size(arr);
    int key;
    cout<<" Enter the value in array : "<<endl;
    inputArray(arr,length);    // Gets input from the user 
    cout<<" Sum of element of array : "<<sumArray(arr,length)<<endl;            // Tells the sum of array
    cout<<" Largest in the array : " <<findLargest(arr,length)<<endl;           //  find largest element of the array
    cout<<" Smallest in the array : " <<findSmallest(arr,length)<<endl;         //  Find smallest element in array   
    cout<<" Count of Even no. in array : "<<countEven(arr,length)<<endl;        // Counts the even no. in array
    cout<<" Count of Odd no. in array : "<<countOdd(arr,length)<<endl;          // Counts the odd no. in array
    cout<<" Enter the key element to find : "<<endl;
    
    cin>>key;         //     Gets the key from user                      
    cout <<" Key is found at index : "<<searchElement(arr,length,key)<<endl;     // Tells the index where the key found. If not found retutn -1.
    reverseArray(arr,length);                   //  Reverses the actual array
    cout<< " Reverse of array : ";
    printArray(arr,length);                     //  Prints the array
    cout<<endl;
    return 0;
}
