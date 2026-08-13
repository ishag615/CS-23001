#include <iostream>
#include <fstream>

int main(){
    std::ifstream file("fileio-text.txt");
    if (!file.is_open()){
        std::cout<<"ERROR!!! Unable to open file"<< std::endl;
        return 1;
    }
     char words;
    file.get(words);
    while (!file.eof()){
        std::cout<<words;
        if (words == ' ')
            std::cout<<std::endl;
        file.get(words);
    }
    while(file>> words){
        std::cout<<words;
    }

    std::cout<<std::endl;
    file.close();
    return 0;

}