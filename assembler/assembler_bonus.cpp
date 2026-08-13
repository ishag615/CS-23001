#include "stack.hpp"
#include "../string/string.hpp"
#include "bonus_utilities.hpp"
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "No input file present" << std::endl;
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file: " << argv[1] << std::endl;
        return 1;
    }

    if (argc == 3){
        std::ofstream outputFile(argv[2]);

        if (!outputFile) {
            std::cerr << "Error: Unable to open output file: " << argv[2] << std::endl;
            return 1;
        }
        char ch;
        String str;

        while(inputFile.get(ch)){
            if(ch != ';' && ch != '\n'){
                str += ch;
            }
            if (ch == ';'){
                str += ch;
                outputFile<<"Infix Expression: "<<str<<std::endl;
                String prefix = infixToPrefix(str);
                outputFile<< "Prefix Expression: "<<prefix<<std::endl;
                outputFile<<"Generating Assembly:"<<std::endl;
                //String x = infixToPostfix(str);
                PrefixtoAl(prefix, outputFile);
                str = String();
            }
        }
    outputFile.close();

    }else{
        char ch;
        String str;
        
        while(inputFile.get(ch)){
            if(ch != ';' && ch != '\n'){
                str += ch;
            }
            if (ch == ';'){
                str += ch;
                std::cout<<"Infix Expression: "<<str<<std::endl;
                String postfix = infixToPrefix(str);
                std::cout<< "Prefix Expression: "<<postfix<<std::endl;
                std::cout<<"Generating Assembly:"<<std::endl;
                //String x = infixToPostfix(str);
                PrefixtoAl(postfix, std::cout);
                str = String();
            }
        }
    }

    inputFile.close();
    
    return 0;
}

