# *This project has been created as part of the 42 curriculum*

# CPP Module 07 - C++ Templates

## 📖 Overview

CPP Module 07 introduces one of the most powerful features of C++: **Templates**.

Templates allow us to write generic code that works with multiple data types without duplicating logic. Instead of writing the same function or class for `int`, `double`, `char`, or `std::string`, we write a single template and let the compiler generate the appropriate implementation.

This module focuses on:

* Function Templates
* Class Templates
* Template Instantiation
* Generic Programming
* Function Pointers with Templates
* Operator Overloading in Template Classes
* Dynamic Memory Management
* Exception Handling

---

# 📚 Concepts Learned

## What is a Template?

A template is a **blueprint** used by the compiler to generate functions or classes for different types.

Example:

```cpp
template<typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}
```

The compiler automatically creates:

```cpp
int max(int, int);
double max(double, double);
std::string max(std::string, std::string);
```

depending on how the function is used.

---

## Function Templates

Function templates eliminate duplicated code.

Instead of writing:

```cpp
swap(int&, int&);
swap(double&, double&);
swap(char&, char&);
```

we write only one function:

```cpp
template<typename T>
void swap(T& a, T& b);
```

---

## Class Templates

Templates are not limited to functions.

Entire classes can be generic.

Example:

```cpp
template<typename T>
class Array
{
    T* _data;
};
```

The compiler creates:

```cpp
Array<int>
Array<double>
Array<std::string>
```

automatically.

---

## Template Instantiation

Templates are **not compiled immediately**.

Compilation happens only when the template is used.

Example:

```cpp
max(10, 20);
```

The compiler generates:

```cpp
int max(int, int);
```

This process is called **Template Instantiation**.

---

## Why Templates Are Implemented Inside Header Files

Unlike normal functions, templates must have their implementation visible to every translation unit.

This is because the compiler generates code only when it knows the concrete type.

For this reason template implementations usually remain inside:

* `.hpp`
* `.tpp` included from the header

instead of `.cpp` files.

---

# 📂 Exercises

---

# Exercise 00 — Templates

### Goal

Implement three generic functions:

* `swap()`
* `min()`
* `max()`

### Concepts

* Function Templates
* References
* Comparison Operators
* Generic Algorithms

### Notes

The functions must work with any type supporting the required operators.

Example:

```cpp
swap(a, b);
min(a, b);
max(a, b);
```

---

# Exercise 01 — iter

### Goal

Implement a generic function named `iter()` that applies a function to every element of an array.

Example:

```cpp
iter(array, size, print);
```

### Concepts

* Function Templates
* Function Pointers
* Generic Algorithms
* Array Traversal

### How it works

```
Array
    │
    ▼
Element 0
    │
call function
    ▼
Element 1
    │
call function
    ▼
...
```

The important idea is that `iter()` does **not** know what operation it performs.

Its only responsibility is visiting every element and calling the provided function.

---

# Exercise 02 — Array

### Goal

Implement a generic dynamic array class.

Example:

```cpp
Array<int> numbers(10);
Array<std::string> words(5);
```

### Concepts

* Class Templates
* Dynamic Memory
* Orthodox Canonical Form
* Deep Copy
* Operator Overloading
* Exception Handling

### Features

* Empty constructor
* Constructor with size
* Deep Copy
* Assignment operator
* Destructor
* `operator[]`
* Bounds checking
* `size()`

---

# 🧠 Important Concepts to Remember

## Generic Programming

Write algorithms independently from the type they manipulate.

---

## Template Type Deduction

The compiler automatically determines the template type.

Example:

```cpp
max(5, 10);
```

becomes

```cpp
max<int>(5, 10);
```

---

## Function Pointer

Exercise 01 introduces function pointers.

Example:

```cpp
void print(int&);

iter(array, size, print);
```

Notice:

```cpp
print
```

passes the function.

Whereas

```cpp
print()
```

calls the function immediately.

---

## Deep Copy

Each `Array<T>` object must own its own memory.

Incorrect:

```
Array A ----+
            |
            ▼
          Memory
            ▲
            |
Array B ----+
```

Correct:

```
Array A ---> Memory A

Array B ---> Memory B
```

---

## Exception Safety

Accessing an invalid index should throw an exception instead of producing undefined behavior.

Example:

```cpp
array[100];
```

should throw.

---

# ⚙️ Compilation

Example:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp
```

---

# 📁 Project Structure

```
cpp07/
│
├── ex00/
│   ├── whatever.hpp
│   └── main.cpp
│
├── ex01/
│   ├── iter.hpp
│   └── main.cpp
│
└── ex02/
    ├── Array.hpp
    ├── Array.tpp (optional)
    └── main.cpp
```

---

# 🎯 Evaluation Questions

* What is a template?
* Why use templates?
* Difference between a function template and a normal function?
* What is template instantiation?
* Why are template implementations placed in header files?
* What is generic programming?
* How does template type deduction work?
* Difference between `print` and `print()`?
* What is a function pointer?
* Why must `Array` implement a deep copy?
* Why does `operator[]` return a reference?
* Why should `operator[]` throw an exception?
* Why do we overload both const and non-const versions of `operator[]`?

---

# 🏁 Conclusion

CPP07 introduces generic programming through templates and demonstrates how C++ can generate type-safe code automatically for multiple data types.

The module teaches how templates eliminate duplicated code while remaining efficient at compile time. It also reinforces dynamic memory management, copy semantics, operator overloading, and exception handling through the implementation of a generic array class.

Understanding this module is essential before moving to **CPP08**, where templates are combined with STL containers, iterators, and algorithms.
