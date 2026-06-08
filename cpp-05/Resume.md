### 1️⃣ The "Why" of Exceptions
* **The C-Style Problem:** Return codes (`-1`, `NULL`) clutter business logic, cause silent failures if ignored, and create "propagation hell" where errors must be manually passed up the call stack.
* **The Constructor Problem:** Constructors do not have return types. Without exceptions, a failed constructor leaves behind a "zombie" object in an invalid state. 
* **The Exception Solution:** Exceptions separate the "happy path" from the error path. Throwing an exception in a constructor guarantees an invalid object is never born.

### 2️⃣ Core Mechanics & Stack Unwinding
* **The Hidden Buffer:** When you `throw`, the C++ runtime creates the exception object in a dedicated, hidden exception buffer to keep it safe from stack destruction.
* **Stack Unwinding:**  The system halts normal execution and searches down the call stack for a matching `catch` block. As it moves down, it guarantees the destructors of all fully constructed local objects are called.
* **RAII (Scope-Bound Resource Management):** This is why unwinding works perfectly. By allocating resources in a constructor and freeing them in a destructor, stack unwinding automatically cleans up your memory on the way down, preventing leaks without manual intervention.

### 3️⃣ Catching & The Exception Hierarchy
* **The Golden Rule:** Always throw by value (`throw MyException();`) and catch by reference (`catch (std::exception &e)`).
* **Object Slicing:**  If you catch by value (`catch (std::exception e)`), the compiler creates a generic base object, slicing off your custom derived data. You lose polymorphism, and calling `e.what()` will execute the useless base-class version instead of your custom error message.

### 4️⃣ Custom & Nested Exceptions (Module 05)
* **Nested Encapsulation:** We define exceptions inside classes (e.g., `Bureaucrat::GradeTooHighException`) so the error is permanently tied to the domain that owns the rules. It prevents global namespace pollution.
* **Orthodox Canonical Form Exemption:** Exception classes usually carry simple messages and don't manage dynamic memory (`new`). Therefore, compiler-generated shallow copies are perfectly safe, and writing the full Canonical Form for them is unnecessary boilerplate.
* **The `what()` Signature:** `virtual const char* what() const throw();`
    * Returns a C-string instead of `std::string` to guarantee no dynamic memory allocation happens (which could throw a `std::bad_alloc`) while already processing an error.
    * Dynamic binding guarantees this custom message is printed when caught as a `std::exception&`.

### 5️⃣ Object Lifetimes & Memory 
* **Constructors:** If a constructor throws, the object *never officially existed*. Therefore, **its destructor will never be called**.
* **The Manual Memory Trap:** If you use `new` inside a constructor, and a later step in that same constructor throws an exception, you will leak that memory. You must use an internal `try/catch` to `delete` the memory, and then use `throw;` to re-throw the exception and abort the object creation.

### 6️⃣ The 3 Peer Evaluation Traps
1.  **The Destructor Bomb 💣:** Never let an exception escape a destructor. If a destructor throws *during* stack unwinding (meaning an exception was already active), the system faces a double-fault and instantly crashes your program via `std::terminate()`.
2.  **The Pointer Trap 🪤:** Never `throw new MyException();`. This forces the person writing the `catch` block to manually write `delete e;`. If they forget, you get a memory leak, which defeats the entire automatic-safety purpose of exceptions. 
3.  **The Broken Promise 🤥:** The `throw()` at the end of the `what()` signature is a strict promise to the compiler that the function will never throw. If you accidentally write code inside `what()` that throws an exception, the runtime intercepts it, calls `std::unexpected()`, and crashes the program.

---
