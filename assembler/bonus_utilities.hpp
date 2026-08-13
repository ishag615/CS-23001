#ifndef BONUS_UTILITIES_HPP
#define BONUS_UTILITIES_HPP

#include "stack.hpp"
#include "../string/string.hpp"


//String infixToPrefix(std::istream&, std::ostream&);
String infixToPrefix(const String&);

String to_string(int);

void PrefixtoAl(const String&, std::ostream& );

String evaluate(int&, const String&, const String&, const String&, std::ostream&);

#endif 
