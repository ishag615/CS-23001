# CS 23001 — Computer Science II: Data Structures & Abstraction

## About this course

CS 23001 is the second core programming course in Kent State's Computer Science curriculum. It covers advanced object-oriented programming in C++, with a focus on designing and implementing Abstract Data Types (ADTs), dynamic memory management, operator overloading, templates, and fundamental data structures including arrays, linked lists, stacks, and trees.

The course emphasizes building data structures from scratch — without relying on the C++ Standard Library — to develop a deep understanding of how these structures work internally. Every project requires designing a class interface, implementing it with full test coverage, and applying it to a real problem.

---

## Repository structure

```
CS-23001/
├── bigint/               ← Project 1: arbitrary-precision integer ADT
├── string/               ← Project 2: custom string ADT + Apache log parser
├── infix2prefix/         ← Project 3a: infix to postfix conversion (stack)
├── assembler/            ← Project 3b: infix expression to assembly code
├── profiler/             ← Project 4: srcML AST builder and code profiler
├── EVAL/                 ← Evaluation and test infrastructure
├── debug_lab01/          ← Lab: debugging with gdb
├── debug_lab02/          ← Lab: debugging population growth program
├── lab3/                 ← Lab: testing fundamentals
├── lab4_fileio/          ← Lab: file I/O in C++
├── lab 8/                ← Lab: object construction and destruction
├── lab10/                ← Lab: recursion practice
├── object_construction/  ← Lab: constructor/destructor behavior
├── recursion_practice/   ← Lab: recursive algorithm exercises
├── sort_report/          ← Lab: sorting algorithm analysis
├── testing_2/            ← Lab: advanced unit testing
└── my_name_is/           ← Lab 1: course environment setup
```

---

## Projects

### Project 1 — BigInt: Arbitrary-Precision Integer ADT
**Folder:** `bigint/`

The built-in `int` type in C++ is limited to 64-bit values — at most 19 digits. This project builds a `Bigint` ADT that can represent and perform arithmetic on positive integers of arbitrary size (100, 200, 500+ digits).

**The problem it solves:** Computing 100! (a 158-digit number), multiplying RSA-sized integers, or handling any value that overflows standard numeric types.

**Implementation:** The `Bigint` is backed by a fixed-capacity C-array where each element stores one digit (0–9) in reverse order — the 0-index holds the ones place, the 1-index holds the tens place, and so on. This representation makes addition and multiplication algorithms natural to implement.

**Key skills demonstrated:**
- Designing a complete C++ class with specification (`.hpp`) and implementation (`.cpp`) files
- Operator overloading: `+`, `*`, `==`, `>>`, `<<`, `[]`
- Multi-milestone development: constructors and I/O in Milestone 1, addition in Milestone 2, multiplication in Milestone 3
- Unit testing: every method tested in isolation before use
- Algorithm design: grade-school addition and multiplication algorithms adapted for the digit-array representation

**Constraints:** No STL containers (`std::vector`, `std::string`) permitted. Built from raw C-arrays only.

---

### Project 2 — String: Custom Dynamic String ADT + Apache Log Parser
**Folder:** `string/`

The C++ standard `std::string` is not available for this project. Instead, a full string class is designed and implemented from scratch using a dynamically allocated null-terminated character array.

**The problem it solves:** Building a reliable, reusable string abstraction, then applying it to parse real-world Apache web server log files and extract access statistics.

**Implementation:** The `String` class manages its own heap memory with a custom destructor, copy constructor, and assignment operator (the Rule of Three). Concatenation (`+=`) reallocates the internal array to fit the new length. All string operations — comparison, subscript access, substring search — are implemented without any standard library string functions.

**Key skills demonstrated:**
- Dynamic memory management: `new`, `delete`, heap allocation
- Rule of Three: destructor, copy constructor, assignment operator
- Operator overloading: `+=`, `==`, `[]`, `<<`, `>>`
- File I/O: parsing structured log file format
- Separation of ADT design from application logic

---

### Project 3 — Assembler: Infix Expression to Assembly Code
**Folders:** `infix2prefix/`, `assembler/`

This project implements a two-stage compiler component: converting a mathematical infix expression (the way humans write math) into a sequence of assembly instructions for a simple single-register CPU.

**The problem it solves:** Real compilers must transform human-readable expressions like `((A + (B * C)) / (D - E))` into the low-level instruction sequences that CPUs actually execute. This project implements the core of that code-generation phase.

**Stage 1 — Infix to Postfix:** Using the Shunting-Yard algorithm, the program converts a fully parenthesized infix expression into postfix notation using a stack.

**Stage 2 — Postfix to Assembly:** The postfix expression is then evaluated to produce a sequence of LD/ST/AD/SB/MU/DV instructions for a RISC-style CPU with a single register and six instructions.

**Example:**
```
Infix:    ((A + (B * C)) / (D - E))
Postfix:  A B C * + D E - /
Assembly: LD B / MU C / ST TMP1 / LD A / AD TMP1 / ...
```

**Key skills demonstrated:**
- Stack data structure: implemented as a linked list (generic template class)
- Template classes (generics): `Stack<T>` works for any type
- Algorithm implementation: Shunting-Yard infix-to-postfix conversion
- File I/O: reading expressions from input files, writing assembly to output files
- Reuse of prior work: uses the `String` ADT from Project 2

---

### Project 4 — Profiler: Source Code AST Builder and Instrumenter
**Folder:** `profiler/`

The most complex project in the course. Given a C++ source file in srcML format (an XML representation of source code), this project builds an Abstract Syntax Tree (AST) in memory, traverses it, and rewrites the source to inject profiling counters — producing instrumented code that counts how many times each function runs.

**The problem it solves:** Performance profiling requires counting which parts of a program execute and how many times. This project automates the injection of counter code into a C++ source file by treating the source as a tree structure.

**Implementation:** Two classes — `AST` (a tree node) and `token` — work together to read srcML XML input, construct the tree, traverse it, and emit modified source with counters inserted before each function definition.

**Key skills demonstrated:**
- Tree data structures: recursive construction and traversal
- XML parsing: reading structured data from a file into a tree
- Recursive algorithms: tree traversal and transformation
- Object-oriented design: two cooperating classes with well-defined responsibilities
- Real-world application: source code analysis, a foundation for compilers and static analysis tools

---

## Labs

The lab assignments develop specific foundational skills that the projects build upon:

| Lab | Skill |
|---|---|
| `my_name_is` | Development environment setup, file I/O basics |
| `debug_lab01`, `debug_lab02` | Debugging with gdb, fixing logical and runtime errors |
| `lab3`, `testing_2` | Unit testing methodology, writing thorough test cases |
| `lab4_fileio` | File input/output in C++ |
| `lab 8`, `object_construction` | Constructors, destructors, object lifecycle |
| `recursion_practice`, `lab10` | Recursive thinking and implementation |
| `sort_report` | Sorting algorithm analysis and performance comparison |
| `EVAL` | Evaluation infrastructure for project test suites |

---

## Skills developed

**C++ and OOP**
- Class design: header files, implementation files, proper encapsulation
- Operator overloading for natural ADT syntax
- Dynamic memory management: `new`, `delete`, avoiding memory leaks
- Rule of Three: destructor, copy constructor, assignment operator
- Templates and generic programming

**Data Structures (built from scratch)**
- Arrays (fixed and dynamic)
- Linked lists (singly linked, used for the Stack in Project 3)
- Stacks (implemented via linked list template)
- Trees (recursive AST in Project 4)

**Software Engineering**
- Multi-milestone incremental development
- Unit testing before integration
- Makefile-based build systems
- Version control with commit history
- Separation of interface (`.hpp`) from implementation (`.cpp`)

**Problem Solving**
- Representation choices: how data is stored determines how algorithms work (BigInt digit array, dynamic String array)
- Algorithm adaptation: applying grade-school arithmetic to a custom data structure
- Compiler concepts: expression parsing, code generation, AST traversal

---

## How to build and run

Each project folder contains a `Makefile`. From within the project directory:

```bash
make tests      # Build and run all unit tests
make add        # Build and run the BigInt addition demo
make multiply   # Build and run the BigInt multiplication demo
make postfix    # Build and run the infix-to-postfix converter
```

Developed and tested on Linux using `g++` with C++17.
