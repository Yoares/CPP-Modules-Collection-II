#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP 

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <cmath> 
#include <limits>
#include <stdexcept>
#include <climits>
#include <cstdlib>

class ScalarConverte { 
    private: 
        std::string _input; 
        ScalarConverte(); 
        ScalarConverte(const std::string &copy); 
        ScalarConverte(const ScalarConverte &copy); 
        ScalarConverte &operator=(const ScalarConverte &copy); 
        ~ScalarConverte();
    public: 
        static void convert(const std::string& str);      
}; 
#endif