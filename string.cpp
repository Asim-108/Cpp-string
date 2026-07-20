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
        // copy constructor of nullptr
        if(other.str == nullptr){
            len = 0;
            str = nullptr;
            return;
        }
        len = other.len;
        str = new char[len + 1];
        std::strcpy(str, other.str);
    }
    // move constructor
    // parameter is && since this is rvalue, temporary object
    myString(myString&& other) noexcept{
        // just stealing the data, not copying it
        len = other.len;
        str = other.str;

        // leaving the old object in a valid state
        other.len = 0;
        other.str = nullptr;
    }

    // copy assignment operator
    myString& operator=(const myString& other){
        // self assignment protection
        if (this == &other){
            return *this;
        }
        // copy assignment operator of nullptr
        if(other.str == nullptr){
            len = 0;
            delete[] str;
            str = nullptr;
            return *this;
        }
        // undefined delete protection
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        std::strcpy(str, other.str);

        return *this;
    }

    // move assignment operator
    myString& operator=(myString&& other) noexcept{
        if (this == &other){
            return *this;
        }
        
        // undefined delete protection
        delete[] str;

        // steal the data
        len = other.len;
        str = other.str;

        // leave the old object in a valid state
        other.len = 0;
        other.str = nullptr;

        return *this;
    }

    // operator + overload for concatenation of strings
    myString operator+(const myString& other) const{
        if (str == nullptr || other.str == nullptr){
            throw std::runtime_error("Cannot concatenate strings: one or both strings are null");
        }

        // create a temporary object to store the result
        myString result;
        // this is necessary because the default constructor allocates memory (1 char, still memory leak)
        delete[] result.str;
        result.len = this->len + other.len;
        result.str = new char[result.len + 1];
        std::strcpy(result.str, this->str);
        std::strcat(result.str, other.str);

        return result;
    }

    // print operator
    void print() const {
        if(str){
            std::cout << str << std::endl;
        }else{
            std::cout << "nullptr" << std::endl;
        }
    }
};

int main(){
    myString s1;
    myString s2 = "hello";
    myString s3 = s2;
    myString s4 = s2 + " world";
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    return 0;
}