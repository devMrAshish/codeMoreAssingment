#include<iostream>
#include "string_function.h"
void swap(char& a,char& b){
    char temp =a;
    a=b;
     b=temp;
    
}
int stringLength(const std::string& str){
    int length{};
    int i=0;
    while (str[i]!='\0')
    {
        length ++;
        i++;
    }
    return length;
}
bool isVowel(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
           ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
}
bool isAlphabet(char ch){
    return (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z');
}
int countVowel(const std::string& str){
    int count=0;
    int length= stringLength(str);
    for (int i = 0; i < length; i++)
    {
       if (isVowel(str[i]))
       {
        count++;
       }
       
    }
    return count;
}
int countAlphabet(const std::string& str){
    int length=stringLength(str);
    int count=0;
    for (int i = 0; i < length; i++)
    {
        if (isAlphabet(str[i]))
        {
           count++;
        }
        
    }
    

return count;
}
int countConsonant(const std::string& str){    

return countAlphabet(str)-countVowel(str);
}
void reverseString(std::string& str){
    int length=stringLength(str);
     for (int i = 0; i < length/2; i++)
    {
        swap(str[i],str[length-i-1]);
    }
}
bool compareString(const std::string& str1,  const std::string& str2){
    if (stringLength(str1)!=stringLength(str2))
    {
        return false;
     }
     int i=0;
     while (str1[i]!='\0')
    {
        if (str1[i]!=str2[i])
        {
            return false;
        }
        i++;
    }
    
    return true;
}