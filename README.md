# C Assertion Demo: Safe Integer Conversion & Ariane 5 Lesson

This repository features a minimal C program demonstrating runtime validation using **assertions** (`assert.h`). 

---

## 🚀 The Ariane 5 Connection (Why This Matters)

This code demonstrates the bug that caused the Ariane 5 crash. The crash occurred because the system tried to fit a 64-bit variable into a 16-bit variable, which caused an arithmetic overflow.
NOTE: The program assumes the double to be 64-bit on your system and a short int to be 16-bit.

On June 4, 1996, the **Ariane 5 rocket** ended in a catastrophic explosion just 37 seconds after launch. 

*   **The Cause:** A software error caused by a **64-bit floating-point number converting into a 16-bit signed integer**. 
*   **The Bug:** The value was greater than `32767` (exactly like the `40000` value in this demo), causing an **integer overflow**.
*   **The Consequence:** The computer generated an operand error, which wasn't caught. The guidance system failed, the rocket veered off course, and self-destructed.
*   **How Assertions Help:** While the rocket lacked proper exception handling for this specific variable, a development-time **assertion** or a safe runtime fallback would have exposed this critical vulnerability during testing. This demo mimics that exact scenario.

---

## 🛠️ Prerequisites

To compile and run this code, you need a C compiler (like `gcc` or `clang`) and `git`.

*   **Linux/Ubuntu:** `sudo apt install build-essential git`
*   **macOS:** `xcode-select --install`
*   **Windows:** MSYS2, MinGW, or Windows Subsystem for Linux (WSL).

---

## 💻 Getting Started

Follow these terminal commands to clone, compile, and run the project locally.

### 1. Clone the Repository
Clone the repository using Git and navigate into the project directory:
```bash
git clone https://github.com/Raiza04/debugging
cd debugging
```

### 2. Compile the Code
Compile the source code using the GCC compiler:
```bash
gcc -o assertion_demo ariane5.c
```
*   `gcc`: The GNU Compiler Collection.
*   `-o assertion_demo`: Specifies the output binary name.
*   `ariane5.c`: The C source file.

### 3. Run the Program
Execute the compiled binary:

**On Linux / macOS:**
```bash
./assertion_demo
```

**On Windows (Command Prompt / PowerShell):**
```cmd
assertion_demo.exe
```

---

## 🔬 Expected Output

Because `x` is set to `40000`, it exceeds the maximum boundary of a signed 16-bit integer (`32767`). 

The built-in assertion halts the program instantly to prevent unsafe execution:
```c
assert(x >= -32768 && x <= 32767);
```

Running the code will yield an intentional crash output:
```text
assertion_demo: ariane5.c:10: convert: Assertion `x >= -32768 && x <= 32767' failed.
Aborted (core dumped)
```
### 🧪 Testing Scenarios

Feel free to comment or uncomment the lines containing `assert()` and `static_assert()` to experiment with different runtime and compile-time scenarios!


### 💡 Disabling Assertions for Production
In production environments, assertions are often disabled to maximize execution speed. You can turn them off by defining the `NDEBUG` (No Debug) macro during compilation:
```bash
gcc -DNDEBUG -o assertion_demo ariane5.c
```
If you run the program now, the check is bypassed, resulting in an unmanaged integer overflow (Output: `y = -25536`).

---
