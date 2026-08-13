#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "stack.hpp"
#include "../string/string.hpp"


//String infixToPrefix(std::istream&, std::ostream&);
String infixToPostfix(const String&);

String to_string(int);

void PostfixtoAl(const String&, std::ostream& );

String evaluate(int&, const String&, const String&, const String&, std::ostream&);

#endif 
