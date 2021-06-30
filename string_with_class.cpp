/*
#### READ the instructions carefully. ######
1) First try to understand the given code in the program

2) The code is partially completed. Some string operations are already implemented using functions in this program.

3) Your TASK is to define the remaining functions and complete the code.

4) ASK ME in case of any difficulties.
*/

#include<iostream>
#include<cstring>
using namespace std;

// Defining a class for string properties and functions
class STR
{
    int length;
    int capacity;// Maximum number of elements allowed
    char *s; // Address of first element in the string
    int strLength(const char*);
public:
    //constructor to initialize string properties
    STR(int c=10) // default capacity is 10
    {
        length = 0;
        capacity = c;
        s = new char[c+1];
        s[0] = '\0';
    }

    STR(const char *str) // default
    {
        int len = strLength(str) ;
        cout << "length = "<< len <<endl;
        if(len > capacity)
            cout<<"copy impossible!\n\n";
        else
        {
            capacity = len;
            s = new char[capacity+1];
            for(int i = 0; i < len; i++)s[i]=str[i];
            s[len] = '\0';
            length = len;
        }
    }

    bool isEqual(STR&);
    void print(); // it prints the elements in the string

    // Define a function to reverse a string
      void strReverse ()
    {
        int n = strLength(s);
        int i;
        for (i=0; i< n/2; i++)
            swap(s[i], s[n-1-i]);
          cout << s <<endl;
    }

    // Define a function to check palindrome
      void isPalindrome ()
      {
          int flag=0;
          int n = strLength(s);
        int i;
        for (i=0; i< n/2; i++)
           {
            if(s[i] == s[n-1-i])
            {
            flag=1;
            break; }
           }
      if (flag)
        cout << "Is palindrome" <<endl;
      else
        cout << "Is not palindrome" <<endl;

      }

    // Define a function to check if a string greater

    bool isEmpty();
    bool isFull();
};

int main()
{
    // Declaring an string object of type STR
    STR s1("Mike John");
    STR s2("Mike John");
    STR s3;
    cout << "s3 is empty : " << s3.isEmpty()<<endl;
    s1.print();
    cout << "s1 is full : " << s1.isFull()<<endl;
    cout << "s1 = s2 : " <<s1.isEqual(s2)<<endl;
    s1.strReverse();
    s1.isPalindrome();


    // Use the three functions here which you will define outside the main function

    return 0;
}

bool STR::isEmpty()
{
    return length == 0;
}

bool STR::isFull()
{
    return length == capacity;
}
int STR::strLength(const char *p)
{
    int len=0;
    while(*(p++))
        len++;
    return len;
}
bool STR::isEqual(STR& sObj){
    char *tmp=s, *str = sObj.s;
    while(*tmp && *str){
        if(*(tmp++) != *(str++))return false;
    }
    if(*tmp && !*str)return false;
    if(!*tmp && *str)return false;
    return true;
}

void STR::print()
{
    cout<<"\n"<<s<<"\n";
}
