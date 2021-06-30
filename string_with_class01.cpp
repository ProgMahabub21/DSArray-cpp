/*
#### READ the instructions carefully. ######
1) First try to understand the given code in the program

2) The code is partially completed. Some string operations are already implemented using functions in this program.

3) Your TASK is to define the remaining functions and complete the code.

4) ASK ME in case of any difficulties.
*/

#include<iostream>
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
    void strReverse();

    // Define a function to check palindrome
    bool isPalindrome();

    // Define a function to check if a string greater
    bool isGreater(STR&);

    bool isEmpty();
    bool isFull();
};

int main()
{
    // Declaring an string object of type STR
    STR s1("CMD");
    STR s2("COD");
    STR s3;
    bool t;
    cout << "s3 is empty : " << s3.isEmpty()<<endl;
    s1.print();
    cout << "s1 is full : " << s1.isFull()<<endl;
    cout << "s1 = s2 : " <<s1.isEqual(s2)<<endl;
    cout << "String Reversed:" <<endl;
    s1.strReverse();
    s1.print();
    cout << "Checking Palindrome:" <<endl;
    if (s1.isPalindrome())
        cout << "Palindrome" <<endl;
    else
        cout << "not palindrome" <<endl;
    cout <<  "checking Greater String :\n";
    cout << s1.isGreater(s2);

    // Use the three functions here which you will define outside the main function

    return 0;
}

bool STR::isEqual(STR& sObj){
    if(length != sObj.length) return false;
    for(int i=0; i < length; i++){
        if(s[i] != sObj.s[i])return false;
    }
    return true;
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
    int i=0;
    while(p[i] != '\0')i++;
    return i;
}

void STR::print()
{
    cout<<"\n"<<s<<"\n";
}
void STR :: strReverse()
{
    int i;
    for (i=0; i< length/2; i++)
        swap(s[i], s[length-1-i]);

}
bool STR :: isPalindrome()
{
      int flag=0;
        int i;
        for (i=0; i< length/2; i++)
           {
            if(s[i] != s[length-1-i])
            {
            flag=1;
            break; }
           }
      if (flag)
        return false;
      else
        return true;
}
bool STR:: isGreater(STR& sObj)
{
    for (int i=0; i< length; i++ )
    {
        if (s[i] < sObj.s[i])
        {
         return false;
        }
       else if (sObj.s[i] < s[i])
        {
            return true;
        }

    }
}
