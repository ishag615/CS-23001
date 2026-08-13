//string.cpp

#include "string-m1.hpp"
#include <cassert>
String::String(){
    str[0]=0;
}
String::String(char ch){
    str[0] = ch;
    str[1] = 0;
}                      
String::String(const char s[]){
    int i = 0;
    while (s[i] != 0){
        if (i >= capacity()) break;
        str[i] = s[i];
        ++i;
    }
    str[i] = 0;
}       
String& String::operator+=(const String& rhs){
    int offset = length();
    int rhsLen = rhs.length();
    int i =0;
    while (i<rhsLen){
        if(offset+i >= capacity()) break;
        str[offset+i] = rhs.str[i];
        ++i;
    }
    str[offset+i]= 0;
    return *this;
}
String operator+(String lhs, const String& rhs){
    return lhs += rhs;
}
bool operator<(char lhs, const String& rhs){return String(lhs) < rhs;}
bool operator<(const char lhs[], const String& rhs) {return String(lhs) < rhs;}
bool operator==(char lhs, const String& rhs){return String(lhs) == rhs;}
bool operator==(const char lhs[], const String& rhs){return String(lhs) == rhs;}
bool operator !=(const String& lhs, const String& rhs){return !(lhs == rhs);}
bool operator>(const String& lhs, const String& rhs){return rhs < lhs;}
bool operator>=(const String& lhs, const String& rhs){return !(lhs < rhs);}
bool operator<=(const String& lhs, const String& rhs){return !(rhs < lhs);}


bool String::operator==(const String& rhs) const{
    int i =0;
    while ((str[i] != 0) && (rhs.str[i] !=0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];
}
bool String::operator<(const String& rhs) const{
    int i=0;
    while ((str[i] != 0) &&(rhs.str[i] != 0) &&(str[i] == rhs.str[i])) ++i;
    return str[i] <rhs.str[i];
}

char String::operator[](int i) const{
    assert (i>= 0);
    assert (i< length());
    return str[i];
}
char& String::operator[](int i){
    assert (i>= 0);
    assert (i< length());
    return str[i];
}
int String::length() const {
    int result = 0;
    while (str[result] != 0) ++result;
    return result;
}
int String::capacity() const{
return STRING_SIZE -1; 
}

String String::substr(int start, int end) const{
    if (start < 0) start = 0;
    if (end >= length()) end = length()-1;
    if (start> end) return String();
    String result;
    int i = start;
    while (i <=end){
        result.str[i-start] = str[i];
        ++i;
    }
    result.str[i-start] = 0;
    return result;
}
int String::findch(int start, char ch)const{
    String Str=str;
    int length = Str.length();
    if (start<0 || start>= length){
        std::cout<<"ERROR! Invalid starting point"<<std::endl;
        return -1;
    }
    for (int i=start; i<length; ++i){
        if (Str[i] == ch)
        return i;
    }
    return -1;
}

int String::findstr(int start, const String& testStr) const {
    int testLength = testStr.length();
    int strLength = length();

    if (start < 0 || start >= strLength) {
        std::cout << "error!, invalid start position" << std::endl;
        return -1;
    }

    for (int i = start; i <= strLength - testLength; ++i) {
        int j;
        for (j = 0; j < testLength; ++j) {
            if (str[i + j] != testStr.str[j]) {
                break;
            }
        }

        if (j == testLength) {
            return i;
        }
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out <<rhs.str;
    return out;
}
std::istream& operator>>(std::istream& in, String& rhs) {
    char buffer[STRING_SIZE];
    if (!in.eof())
        in>>buffer;
    else
        buffer[0] = 0;
    rhs = String(buffer);
    return in;
}

    