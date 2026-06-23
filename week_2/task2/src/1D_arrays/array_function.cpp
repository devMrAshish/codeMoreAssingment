#include <iostream>
using namespace std;
void swap(int& a,int& b){
    int temp =a;
    a=b;
     b=temp;
    
}
void inputArray(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int sumArray(int arr[], int size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int findLargest(int arr[], int size)
{
    int largest = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int findSmallest(int arr[], int size)
{
    int smallest = arr[0];
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int searchElement(int arr[], int size, int key)
{
    for (size_t i = 0; i < size; i++)
    {
       if (arr[i]==key)
       {
        return i;
       }
       
        
    }
    return -1;
}
void reverseArray(int arr[], int size)
{
    for (size_t i = 0; i < size/2; i++)
    {
        swap(arr[i],arr[size-i-1]);
    }
    
}
int countEven(int arr[],int size){
    int count=0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            count++;
        }
        
    }
    return count;
}
int countOdd(int arr[],int size){
    int count=0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i]%2!=0)
        {
            count++;
        }
        
    }
    return count;
}