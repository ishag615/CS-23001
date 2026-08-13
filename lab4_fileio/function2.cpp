#include <iostream>
#include <fstream>

int main(){
std::ifstream file("fileio-data-1.txt");
    if (!file.is_open()){
        std::cout<<"ERROR!!! Unable to open file"<< std::endl;
        return 1;
    }

    int num1, num2;
    char ignore;
   
    //std::cout<<num;
    while (file>>num1){
        //std::cout<<num;
        file>>ignore;
        if (ignore == ';')
            file>>num2;
        int sum = num1+ num2;
        std::cout<<sum<<std::endl;
        file>>ignore;

    }
    /*
    char words;
    while(file>> words){
        std::cout<<words;
    }
*/
    std::cout<<std::endl;
    file.close();
    return 0;
}