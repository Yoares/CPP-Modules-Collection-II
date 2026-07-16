#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    if (this != &other){
        this->max_size = other.max_size;
        this->_nums = other._nums;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n){
    if (_nums.size() >= max_size)
        throw std::runtime_error("Span is full");
    _nums.push_back(n);
}

int Span::shortestSpan() const{
    if (_nums.size() < 2)
        throw std::runtime_error("not enough numbers");
    
    std::vector<int> tmp = _nums;
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (int i = 0; i < _nums.size() - 1; i++)
    {
        int span = tmp[i + 1] - tmp[i];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan() const{
    int min = *std::min_element(_nums.begin(), _nums.end());
    int max = *std::max_element(_nums.begin(), _nums.end());
    return max - min;
}