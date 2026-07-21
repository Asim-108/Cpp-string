# Custom C++ String Class (`myString`)

A custom, lightweight C++ implementation of a string class written from scratch without using `std::string`. This project demonstrates key C++ memory management concepts, object lifecycles, and class-level mechanisms.

## Core Features Implemented
* **Dynamic Memory Management**: Manages internal heap-allocated character arrays using RAII.
* **The Rule of 5**:
  * Default & parameterized constructors.
  * Deep copy constructor & copy assignment operator (with self-assignment safeguards).
  * Move constructor & move assignment operator (using `&&` rvalue references and `noexcept` to transfer ownership of resources without reallocation).
  * Destructor for clean heap deallocation.
* **Operators & Utilities**:
  * `operator+` member function for safe, non-mutating string concatenation.
  * `print()` utility for console output.

  ## How to Run

1. Compile the code using any C++17 compliant compiler:
   ```bash
   g++ -std=c++17 string.cpp -o program
   ```

2. Run the executable:
   ```bash
   ./program
   ```