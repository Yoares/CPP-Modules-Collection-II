# C++ Module 06 - The Art of Casting

Welcome to Module 06 of the 42 School C++ curriculum. 

If previous modules taught you how to build safe, encapsulated, and structured objects, this module teaches you how to bypass those safety nets. Here, you learn that data types are simply "lenses" through which the compiler interprets raw binary data. By mastering **C++ Casts**, you gain the ability to change these lenses at will, manipulating memory, interpreting raw hardware coordinates, and interrogating polymorphic objects at runtime.

---

## 🛠️ Module Overview

This module is broken down into three distinct exercises, each focusing on a specific type of C++ cast and the philosophy behind its use.

### Exercise 00: Conversion of Scalar Types
**The Cast:** `static_cast`
* **Concept:** Parsing a string representation of a C++ literal and converting it to its actual primitive type (`char`, `int`, `float`, `double`), then safely casting that value into the other three primitive types.
* **The Challenge:** Handling overflows, underflows, and non-displayable characters using `<limits>`. 
* **The Edge Cases:** Correctly processing mathematical anomalies known as pseudo-literals (`nan`, `nanf`, `+inf`, `-inff`).
* **Why it matters:** `static_cast` is the workhorse of C++. It handles logical, safe conversions between compatible types while respecting the underlying math and bounds of the data.

### Exercise 01: Serialization
**The Cast:** `reinterpret_cast`
* **Concept:** Taking a complex `Data` object, stripping away its type safety, and converting its memory address into a raw unsigned integer (`uintptr_t`), then safely rebuilding the pointer from that integer.
* **The Challenge:** Proving that memory is just a massive grid of numbered lockers. By converting a pointer to a `uintptr_t`, we treat a memory location purely as a numerical coordinate.
* **Why it matters:** `reinterpret_cast` is the most dangerous and powerful cast. It is essential for systems programming, hardware hacking, and interfacing with legacy C APIs (like threading libraries) that only accept raw memory pointers or integers.

### Exercise 02: Identify Real Type
**The Cast:** `dynamic_cast`
* **Concept:** Randomly generating derived classes (`A`, `B`, or `C`) and returning them hidden behind a polymorphic `Base` pointer. The program must then correctly identify the true type of the object at runtime.
* **The Challenge:** Guessing the object's true identity using only pointers and references, strictly without the use of the `<typeinfo>` header. Handling the distinct ways `dynamic_cast` fails (returning `NULL` for pointers vs. throwing `std::bad_cast` for references).
* **Why it matters:** Unlike other casts that happen at compile-time, `dynamic_cast` happens at **runtime**. It physically inspects the Run-Time Type Information (RTTI) of an object in memory to ensure safe downcasting in complex inheritance hierarchies.

---

## 🚀 Compilation & Usage

This project strictly adheres to the C++98 standard and is compiled using `c++` with the `-Wall -Wextra -Werror` flags.

### Building the Exercises
Navigate to the specific exercise directory (`ex00`, `ex01`, or `ex02`) and use the provided Makefile:

```bash
make        # Compiles the executable
make clean  # Removes object files
make fclean # Removes object files and the executable
make re     # Recompiles the entire project