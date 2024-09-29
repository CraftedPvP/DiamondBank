# 💎 Diamond Bank 💎

The 💎 Diamond Bank 💎 is a C++17 concept project compiled with make. It is a console program designed to simulate a bank interface.

❗ Do not use this in a real production scenario ❗

## Setup
1. Clone the repo or download it as a `.zip`
2. Open the cloned repo or extracted folder in your command prompt/terminal
3. Type in `make` in the root folder to compile using make.
4. Type `make run` to run the program

## Available commands
```
# compiles the project
make

# runs the program
make run

# cleans the output files
make clean
```

## Features

1. Account Login, Logout, and Registration
2. Account Deposit, Withdrawal, Deletion, and Closing
3. Use of `std::variant` and `std::function` for menu and form usage

## F.A.Q.

1. What if I don't have `make`?
   - You can follow instructions for installing MinGW [here](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain)
2. It says I can't connect to the database?
   - It must mean that you tried running the `build/DiamondBank.exe` outside of it's folder.
   - This won't work as the executable will attempt to search for files relative to the current working directory.
   - You have two options:
     - You can use `make run` to run the program in any directory.
     - You can navigate to the `build` folder and run the `DiamondBank.exe` from there.

---
Made with 🍹