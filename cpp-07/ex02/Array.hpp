#ifndef ARRAY_HPP 
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T* data;
        unsigned int _size;
    public:
    // canonical form
        Array() : data(NULL), _size(0) {}
        Array(unsigned int n) : _size(n){
            data = new T[n]();
        }
        Array(Array &copy) : _size(copy._size) {
            data = new T[_size];
            for(unsigned int i = 0; i < _size; i++){
                data[i] = copy.data[i];
            }
        }
        Array &operator=(Array &other){
            if (this != &other)
            {
                delete[] data;
                _size = other._size;
                data = new T[_size];
                for(unsigned int i = 0; i < _size; i++){
                    data[i] = other.data[i];
                }
            }
            return *this;
        }
        ~Array(){ delete[] data;}
        
        unsigned int size() const {return this->_size;}

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error: Index out of bounds.";
                }
        };

        T& operator[](unsigned int index) {
            if (index >= _size) {
                throw OutOfBoundsException();
            }
            return data[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= _size) {
                throw OutOfBoundsException();
            }
            return data[index];
        }
};

#endif