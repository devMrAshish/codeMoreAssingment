#include<iostream>
#include "string_function.h"
int main()
{
    std::string str{"Hello"};
    std::string str1{"World"};
    std::cout<<" Length of string_1 : "<<stringLength(str)<<std::endl;
    std::cout<<" Count of vowel in string_1 : "<<countVowel(str)<<std::endl;
    std::cout<<" Count of Consonant in string_1 : "<<countAlphabet(str)<<std::endl;
    std::cout<<" String1 and String2 is equal : "<<std::boolalpha<<compareString(str,str1)<<std::endl;
    reverseString(str);
    std::cout<<" Reversed string_1 : "<<str<<std::endl;
    std::cout<<" Done!"<<std::endl;
    return 0;
}
