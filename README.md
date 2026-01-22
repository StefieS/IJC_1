# IJC - Project 1

Prime number finder and C comment remover.

## 📋 What It Does

- **Find primes** - Last 10 prime numbers up to 666 million
- **Remove comments** - Strip C/C++ comments from code

## 📁 Files

```
IJC_1/
├── bitset.h/c        # Bit array library
├── eratosthenes.h/c  # Prime number algorithm
├── primes.c          # Prime finder program
├── error.h/c         # Error handling
├── no-comment.c      # Comment remover
└── Makefile          # Build file
```

## 🔨 How to Build

```bash
make          # Build everything
make run      # Build and run prime finders
make clean    # Remove build files
```

## 🚀 Usage

### Find Primes

```bash
make run
```

This runs both versions (macro and inline) and shows the last 10 primes.

**Output:**
```
665999989
665994041
...
Time=2.34
```

### Remove Comments

```bash
./no-comment < input.c
cat source.c | ./no-comment > clean.c
```

Removes `//` and `/* */` comments from C code.

## 🔧 How It Works

**Bitset Library:**
- Stores bits efficiently (1 bit per number)
- Two versions: macros (fast) and inline functions (safer)

**Sieve of Eratosthenes:**
- Marks non-prime numbers
- Finds primes up to 666 million
- Uses ~79 MB memory

**Comment Remover:**
- Uses finite state machine
- Handles strings and character literals correctly

## 🎓 Course Info

**Course**: IJC (The C Programming Language)  
**School**: FIT VUT Brno  
**Author**: Mikuláš Lešiga (xlesigm00)

## ⚙️ Requirements

- GCC compiler
- Make
- Math library

---

**Note**: Academic project - follow your school's academic integrity policy.
