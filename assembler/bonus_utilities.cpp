#include "bonus_utilities.hpp"
#include "stack.hpp"
#include "../string/string.hpp"
#include <fstream>

String infixToPrefix(const String& str){
   
    std::vector<String> result = str.split(' ');

    stack<String> S; 
    String prefixExpression;
    int token = result.size() - 1;
    String lhs, op, rhs;
    std::cout<<str<<std::endl;
    while (token>= 0) { 
        if (result[token] == '(') { 
            lhs = S.pop(); 
            op = S.pop();
            rhs = S.pop();   
            S.push( op +" "+ rhs +" "+ lhs );    
        } else if (result[token] != ')') { 
            S.push(result[token]);    
        }
        --token;
    }
    if(result[token] == "" || result[token] == "\n" || result[token] == "\r"){
        return String{};
    }
    return S.pop();
}

String to_string(int x) {
    String s;
    bool negative = false;

    if (x == 0) {
        s = "0";
        return s;
    }

    if (x < 0) {
        negative = true;
        x = -x;
    }

    while (x > 0) {
        char digit = '0' + (x % 10);
        s = digit + s;  // Prepend the digit to the string
        x /= 10;        // Move to the next digit
    }

    if (negative)
        s = "-" + s;    // Add negative sign if the number was negative

    return s;
}

String evaluate(int& tempVar, const String& left, const String& op, const String& right, std::ostream& out) {

    
    out<< "   LD     " + left<<std::endl;
    if(op == "+"){
        out<< "   AD     " + right+ "\n";
    }else if(op == "-"){
        out<< "   SB     " + right + "\n";
    }else if(op == "*"){
        out<< "   MU     " + right + "\n";
    }else if(op == "/"){
        out<< "   DV     " + right + "\n";
    }

    ++tempVar;
    out<<"   ST     TMP"<<tempVar<<std::endl;
    return  "TMP" + to_string(tempVar) ;

}


void PrefixtoAl(const String& postfixExpression, std::ostream& out){
    stack<String> S;
    std::vector<String> tokens = postfixExpression.split(' ');
    //int index = 0;
    int tempVarCount = 0;
    size_t index = tokens.size()-1;
    while(index < tokens.size() && tokens[index] != ";"){
        if (tokens[index] == "+" || tokens[index] == "-"|| tokens[index] == "*" || tokens[index] == "/" ){
            String left = S.pop();
            String right = S.pop();
            String result = evaluate(tempVarCount, left, tokens[index], right, out);
            S.push(result);
        }else{
            S.push(tokens[index]);
        }
        --index;
    }

}
