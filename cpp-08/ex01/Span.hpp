#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span{
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;
    private:
        unsigned int max_size;
        std::vector<int> _nums;
};


#endif