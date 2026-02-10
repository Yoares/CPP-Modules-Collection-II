# C++ Module 05: Repetition and Exceptions

## 📝 Overview
This project simulates a bureaucratic system to master **C++ Exception Handling** and **Object-Oriented Design Patterns**.

The simulation involves Bureaucrats of varying ranks (1–150) attempting to sign and execute Forms. The system strictly enforces rules using **Exceptions** (`try`, `catch`, `throw`) rather than simple `if/else` checks, ensuring robust error handling and memory safety.

## 🛠 Key Concepts Learned
* **Exception Handling:** Inheriting from `std::exception`, custom error classes (`GradeTooHighException`), and Stack Unwinding.
* **RAII (Resource Acquisition Is Initialization):** Ensuring objects are valid upon creation.
* **Abstract Classes & Interfaces:** Refactoring `Form` into `AForm` to enforce a contract.
* **Polymorphism:** Executing different behaviors (File I/O, Randomness, Output) through a common interface.
* **The Factory Pattern:** Creating objects dynamically based on string input (The Intern).

---

## 📂 Project Structure

### Exercise 00: Mommy, when I grow up, I want to be a Bureaucrat!
**The Basics of Exception Handling.**
* **`Bureaucrat` Class:** Represents a worker with a Name (const) and a Grade (1–150).
* **Logic:** Attempting to instantiate a Bureaucrat with an invalid grade throws an exception immediately.
* **Goal:** Protect the object's integrity from the moment it is born.

### Exercise 01: Form up, maggots!
**Resource Management & Interaction.**
* **`Form` Class:** A passive object that requires a specific grade to be signed.
* **Interaction:** `Bureaucrat::signForm()` attempts to change the Form's status.
* **Logic:** A Bureaucrat cannot sign a form if their grade is too low. The Form throws the exception, and the Bureaucrat catches it to report the error.

### Exercise 02: No, you need form 28B, not 28C...
**Abstract Classes & Polymorphism.**
* **`AForm` (Abstract):** The base class now handles the security checks (Is signed? Is grade high enough?) via the **Template Method Pattern**.
* **Concrete Classes:**
    1.  **`ShrubberyCreationForm`:** Creates a file `<target>_shrubbery` and writes ASCII trees (File I/O).
    2.  **`RobotomyRequestForm`:** 50% chance of success, makes drilling noises (Randomness).
    3.  **`PresidentialPardonForm`:** Pardons a target via Zaphod Beeblebrox (Standard Output).
* **Logic:** The Bureaucrat can now `executeForm()`, triggering these distinct behaviors.

### Exercise 03: At least this beats coffee-making
**The Factory Pattern.**
* **`Intern` Class:** A worker with no rank/name.
* **Functionality:** `makeForm(string name, string target)`.
* **Logic:** Uses an array of function pointers to create the correct Form object based on a string name, avoiding ugly `if/else` chains.

---

## ⚙️ Compilation & Usage

Each exercise has its own Makefile.

### 1. Compiling
Navigate to the specific exercise directory and run:
```bash
make