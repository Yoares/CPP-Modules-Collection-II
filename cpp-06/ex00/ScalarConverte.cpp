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
    return false;
}

bool isChar(std::string& s){
    return false;
}

bool isFloat(std::string& s){
    return false;
}

bool isInt(std::string& s){
    bool plus = false;
    bool minus = false;

    return false;
}

bool isDouble(std::string& s){
    return false;
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
}