#include <iostream>
#include <cstring>
#include <algorithm>

class myString{
private:
    char* str;
    size_t len;

public:
    // default constructor with no arguments
    myString(){
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }
    // standard constructor with string argument
    myString(const char* s){
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    // destructor
    ~myString(){
        delete[] str;
    }
    // copy constructor (deep copy)
    // necessary to pass by reference (&)
    // if we don't pass by reference, program must make a copy of that object, calling the copy constructor again and again, infinite recursion
    myString(const myString& other){
        len = other.len;
        str = new char[len + 1];
        std::strcpy(str, other.str);
    }
    // copy assignment operator
    myString& operator=(const myString& other){
        // self assignment protection
        if (this = &other){
            return *this;
        }
        // undefined delete protection
        if (str != nullptr){
            delete[] str;
        }
        len = other.len;
        str = new char[len + 1];
        std::strcpy(str, other.str);

        return *this;
    }
}