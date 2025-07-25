# 🧮 CS40 Homework 8 – Stack-Based Calculator (C & μASM)

This repository contains my solution to **Homework 8** for CS40 (_Programming Languages_), a course I completed at Tufts University. The assignment focused on building a stack-based calculator in both:

- **C** – to practice high-level implementation with structured memory and stack handling
- **μASM (Micro Assembly)** – to understand low-level architecture and control flow through a register-based assembly language

---

## 📚 Topics Covered

- Reverse Polish Notation (RPN) calculator
- Stack-based evaluation
- Binary and unary arithmetic operations
- Bitwise manipulation in C and assembly
- Safe division logic (handling zero & signed integers)
- Jump table implementation for command dispatch
- Modular μASM program structure

---

## 📂 Repository Contents

| File           | Description                                |
| -------------- | ------------------------------------------ |
| `calc40.c`     | C implementation of the calculator         |
| `calc40.ums`   | Main μASM file (logic for calculator)      |
| `callmain.ums` | μASM entrypoint: jumps to `main` and halts |
| `printd.ums`   | Helper for printing integers in μASM       |
| `urt0.ums`     | Stack initialization for μASM programs     |
| `Makefile`     | Build file for compiling the C version     |
| `.gitignore`   | Ignore binary files and build artifacts    |
| `README.md`    | This file                                  |

---

## ▶️ Running the C Version

### 🛠 Requirements

- GCC or another C compiler
- `make`
- `seq.h` and `seq.c` (used in the Tufts CS40 stack abstraction)

### 🔧 Build & Run

```bash
make
./calc40
```

**Enter expressions like:**

```bash
12 3 + 5 * d
```

Then press **Enter** to print the stack. Use commands like d (duplicate), s (swap), z (zero/clear), etc.

---

## ▶️ Running the μASM Version

This version is split across multiple .ums files and must be assembled and run using the CS40-provided μASM toolchain:

## 🛠 Requirements

- `umasm` – assembles μASM to UM bytecode
- `um` – virtual machine for executing UM programs

## 🔧 Build & Run

**Assemble the code:**

```bash
umasms calc40.ums callmain.ums printd.ums urt0.ums -o calc40.um
```

**Run the program:**

```bash
um calc40.um
```

**Then type commands (similar to the C version) like:**

```bash
15 3 /
~
+
```

## ⚙️ Supported Commands

| Command   | Description                  |
| --------- | ---------------------------- |
| `+ - * /` | Binary arithmetic            |
| `&`       | `~`                          |
| `c`       | Change sign (unary -)        |
| `d`       | Duplicate top stack value    |
| `s`       | Swap top two stack values    |
| `p`       | Pop/discard top value        |
| `z`       | Zero the stack               |
| `\n`      | Print current stack contents |

---

## 🧠 What I Learned

- Translating high-level logic into low-level control structures
- Building and navigating a manual stack implementation
- Using jump tables for function dispatch
- Handling edge cases (e.g., division by zero) in both C and μASM
- Writing modular assembly code using separate helper files
- Leveraging macros and goto in structured C for control flow

---

## 🏫 About the Course

CS40: Machine Structure and Assembly Language Programming
Tufts University – Fall 2023

---

## 📄 License

This code was written as part of an academic assignment and is shared for educational purposes only.
Please do not plagiarize. Contact me if you'd like to learn from the code or discuss the project.
