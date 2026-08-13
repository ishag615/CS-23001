//string.cpp

#include "string.hpp"
#include <cassert>
#include <vector>
String::String(){
    stringSize = 1;
    str = new char[stringSize];
    str[0]=0;
}
String::String(char ch){
    if (ch == '\0'){
    stringSize = 1;
    str = new char[stringSize];
    str[0] = ch;
    }else{
    stringSize = 2;
    str = new char[stringSize];
    str[0] = ch;
    str[1] = 0;
    }
}                      
String::String(const char s[]){
    int i = 0;
    while (s[i] != 0){
        ++i;
    }
    stringSize = i+1;
    str = new char[stringSize];
    for(int j=0; j<i; ++j){
        str[j] = s[j];
    }
    str[i] = 0;
}
//copy constrctor
String::String(const String& testStr) {
    stringSize = testStr.stringSize;
    str = new char[stringSize];
    
    for (int i = 0; i < stringSize; ++i) {
        str[i] = testStr.str[i];
    }
    str[length()]= 0;
}

//destructor  
String::~String (){
delete [] str;
} 

void String::swap (String& testStr){

 int tempSize = testStr.stringSize;
    testStr.stringSize = stringSize;
    stringSize = tempSize;

char* temp = testStr.str;
    testStr.str = str;
    str = temp;

}
int String::capacity() const{
//return stringSize - 1;
    return stringSize-1;
}
int String::length() const {
    /*
    int result = 0;
    while (str[result] != 0) ++result;
    return result;
    */
   return stringSize - 1;
}

char& String::operator[](int i){
    assert (i>= 0);
    assert (i< length());
    return str[i];
}

char String::operator[](int i) const{
    assert (i>= 0);
    assert (i< length());
    return str[i];
}

String& String::operator=(String rhs){
    swap(rhs);
    return *this;
}

String& String::operator+=(const String& rhs){
    int offset = length();
    int rhsLen = rhs.length();
    int totalLength = offset + rhsLen;

    if(totalLength >= capacity()){
        int newCap = offset +rhsLen +1;
        char *testStr = new char[newCap];
        for (int i = 0; i < offset; ++i) {
            testStr[i] = str[i];
        }  
        for (int i = 0; i < rhsLen; ++i) {
            testStr[offset + i] = rhs.str[i];
        } 
        testStr[totalLength] = 0;
        delete[] str;
        str = testStr;
        stringSize = newCap;
    } else {
        for (int i = 0; i < rhsLen; ++i) {
            str[offset + i] = rhs.str[i];
        }
        str[totalLength] = 0;
    }
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

String String::substr(int start, int end) const{
    if (start < 0) start = 0;
    if (end >= length()) end = length()-1;
    if (start> end) return String();
        
    int substrLen = end - start + 1;

    String result;
    result.str = new char[substrLen + 1];
    result.stringSize = substrLen + 1;
    int i = start;
    while (i <=end){
        result.str[i-start] = str[i];
        ++i;
    }
    result.str[substrLen] = 0;
    return result;
}
int String::findch(int start, char ch)const{
    //String temp = substr(start, length()-1);
    //int first_index = -1;
            
    for (int i = start; i < length(); ++i){
        if (str[i] == ch){
            return  i ;
        }
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
    char buffer[500];
    in >> buffer;
    rhs = String(buffer);
    return in;
}
std::vector<String> String::split(char ch) const {
    std::vector<String> result;
    int start = 0;
    int end = findch(start, ch);
    int Len = length();

    while (end != -1) {
        result.push_back(substr(start,end-1));
        start = end + 1;
        end = findch(start, ch);
        /*
        if (end == -1) {
            end = Len;
            result.push_back(substr(start,end));
        }else if (start== end){
            result.push_back("");

        }else{
            result.push_back(substr(start, end - 1));
        }    
        */
    
    }
    result.push_back(substr(start,Len));
    return result;
}
