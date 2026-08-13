#include "stack.hpp"
#include "../string/string.hpp"
#include "utilities.hpp"
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

    std::ofstream postfix_file("postfix.txt");

   if (!postfix_file) {
		std::cerr << "Output file can't be opened! Please try again!" << std::endl;
		return 1;
	}
    char ch;
    String str;
    while(inputFile.get(ch)){
        if(ch != ';'){
            str += ch;
        }
        if (ch == ';'){
            str += ch;

            postfix_file<< infixToPostfix(str)<<std::endl;
            str = "";
            }
        }
        

    inputFile.close();
    postfix_file.close();

    return 0;
}

