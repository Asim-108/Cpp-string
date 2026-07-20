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
    myString(const myString& other){
        this->len = other->len;
        this->str = new char[len + 1];
        std::strcpy(this->str, other->str);
    }
}