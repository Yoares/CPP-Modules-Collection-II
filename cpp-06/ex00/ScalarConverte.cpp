#include "ScalarConverte.hpp"
#include <cctype>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

ScalarConverte::ScalarConverte()
{
}

ScalarConverte::ScalarConverte(const ScalarConverte &copy)
{
    (void)copy;
}

ScalarConverte &ScalarConverte::operator=(const ScalarConverte &copy)
{
    (void)copy;
    return (*this);
}

ScalarConverte::~ScalarConverte()
{
}

bool isPseudo(std::string& s){
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

bool isChar(std::string& s){
    return (s.size() == 1 && isprint(s[0]) && !isdigit(s[0]));
}

bool isFloat(std::string& s){
    if (s.empty() || s[s.length() - 1] != 'f')  
        return false;
    if (s == "-inff" || s == "+inff" || s == "nanf") 
        return true;
    int = 0;
    bool hasdigit = false;
    bool hasdot = false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (i < (int)s.length() - 1; i++){
        if (isdigit(s[i]))
            hasdigit = true;
        else if (s[i] == '.' && !hasdot)
            hasdot = true;
        else
            return false;
    }
    return hasdigit && hasdot;
}

bool isInt(std::string& s){
    int i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length()) 
        return false;
    for (i < (int)s.size(); i++){
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isDouble(std::string& s){
    if (s == "-inf" || s == "+inf" || s == "nan") return true;

    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;
    if (s[i] == '+' || s[i] == '-') i++;
    for (i < s.length(); i++){
        if (isdigit(s[i])) {   
            hasDigit = true;
        } else if (s[i] == '.' && !hasDot) {
            hasDot = true;
        } else {
            return false;
        }
    }
    return hasDigit && hasDot;
}

Type dectecType(const std::string& str){

    std::string s = str;

    if (s.empty())
        return INVALID;

    if (isPseudo(s)){
        return PSEUDO;
    }
    if (s.size() == 1 && isChar(s)){
        return CHAR;
    }
    if (isInt(s)){
        return INT;
    }
    if (isFloat(s))
    {
        return FLOAT;
    }
    if (isDouble(s))
    {
        return DOUBLE;
    }
    
    return INVALID;
}

void ScalarConverte::convert(const std::string& str)
{
    Type type = dectecType(str);
    if (type == INVALID) {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: impossible\ndouble: impossible" << std::endl;
        return;
    }
    

}