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

bool isDecimal(const std::string &s, bool requireF)
{

    if (s.empty())
        return false;
    size_t pos = 0;
    if (s[pos] == '-' || s[pos] == '+')
        pos++;

    if (pos == s.length())
        return false;

    size_t end = s.length();

    if (requireF)
    {
        if (s[end - 1] != 'f')
            return false;
        end--;
    }
    else{
        if (s[end - 1] == 'f')
            return false;
    }
    if (pos >= end)
        return false;

    bool found_dot = false;
    bool found_digit = false;
    for(size_t i = pos; i < end; i++){
        if(s[i] == '.')
        {
            if (found_dot)
                return false;
            found_dot = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(s[i]))){
            return false;
        }
        else{
            found_digit = true;
        }
    }
    return found_dot && found_digit;
}

bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

bool isChar(const std::string &s)
{
    return (s.size() == 1 && isprint(s[0]) && !isdigit(s[0]));
}

bool isInt(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isFloat(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    return (isDecimal(s, true));
}

bool isDouble(const std::string &s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;
    return (isDecimal(s, false));
}

Type dectecType(const std::string &str)
{

    std::string s = str;

    if (s.empty())
        return INVALID;

    if (isPseudo(s))
    {
        return PSEUDO;
    }
    if (s.size() == 1 && isChar(s))
    {
        return CHAR;
    }
    if (isInt(s))
    {
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

void ScalarConverte::convert(const std::string &str)
{
    Type type = dectecType(str);
    if (type == INVALID)
    {
        std::cout << "char: impossible\nint: impossible\n"
                  << "float: impossible\ndouble: impossible" << std::endl;
        return;
    }

    if (PSEUDO){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        
        if (str == "nan" || str == "nanf") {
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        } else if (str == "+inf" || str == "+inff") {
            std::cout << "float: +inff\n";
            std::cout << "double: +inf\n";
        } else if (str == "-inf" || str == "-inff") {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        return;
    }
    double value = 0.0;
    if (type == CHAR){
        value = static_cast<double>(str[0]);
    }else{
        value = std::strtod(str.c_str(), NULL);
    }

    std::cout << "char: ";
    if (type == PSEUDO || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()){
       std::cout << "impossible";
    }
    else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "Non displayable";
    }
    else{
        std::cout << static_cast<char>(value);
    }
    std::cout << std::endl;
    std::cout << "int: ";
    if (type == PSEUDO || value < std::numeric_limits<int>::min() ||  value > std::numeric_limits<int>::max()){
        std::cout << "impossible";
    }
    else{
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;
    std::cout << "float: ";
    if (value < -std::numeric_limits<float>::max() ||  value > std::numeric_limits<float>::max()){
        std::cout << "impossible";
    }
    else{
        float fValue =  static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1) << fValue << "f" ;
    }
    std::cout << std::endl;
    std::cout << "double: ";
    if (value < -std::numeric_limits<double>::max() ||  value > std::numeric_limits<double>::max()){
        std::cout << "impossible";
    }
    else{
        std::cout << std::fixed << std::setprecision(1) << value;
    }
    std::cout << std::endl;
}