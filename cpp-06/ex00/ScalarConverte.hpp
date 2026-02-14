#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP 
#include <iostream> 
#include <iomanip> 
#include <string> 
#include <cmath> 
#include <limits> 

class ScalarConverte { 
    private: 
        std::string _input; 
        ScalarConverte(); 
        ScalarConverte(const std::string &input); 
        ScalarConverte(const ScalarConverte &other); 
        ScalarConverte &operator=(const ScalarConverte &other); 
        ~ScalarConverte();
    public: 
        static void convert(const std::string& litera); 
}; 
#endif