# 💎 Diamond Bank 💎

The 💎 Diamond Bank 💎 is a C++17 concept project compiled with make. It is a console program designed to simulate a bank interface.

❗ Do not use this in a real production scenario ❗

## Setup

### Via make

1. Clone the repo or download it as a `.zip`
2. Open the cloned repo or extracted folder in your command prompt/terminal
3. Type in `make` in the root folder to compile using make.
4. Type `make run` to run the program

### Via CMake

1. Clone the repo or download it as a `.zip`
2. Open the cloned repo or extracted folder in your command prompt/terminal
3. Call `cmake-setup.bat` to build and run the program.

## Available commands
```
## The make way ##
# compiles the project
make

# runs the program
make run

# cleans the output files
make clean

--

## The CMake way ##
# Build and run 
cmake-setup.bat

# Build only
cmake-setup.bat build

# Run only
cmake-setup.bat run

# Clean only
cmake-setup.bat clean
```

## Features

1. Account Login, Logout, and Registration
2. Account Deposit, Withdrawal, Deletion, and Closing
3. Use of `std::variant` and `std::function` for menu and form usage

## F.A.Q.

1. What if I don't have `make`?
   - You can follow instructions for installing MinGW [here](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain)
2. What if I don't have `cmake`?
   - You can install cmake [here](https://cmake.org/download/)
3. What if I don't have `msbuild`?
   - You can install Visual Studio Build Tools [here](https://visualstudio.microsoft.com/downloads/?q=build+tools)
4. It says I can't connect to the database?
   - It means that the `DiamondBank.exe` cannot find the database which is `database.txt`.
   - At the moment, the executable will attempt to search for files relative to the folder where it was called from.
   - You have two options:
     - Locate the executable within the `build` folder and create a `database.txt` beside it. Running the program will work normally.
     - You can use compile the program with `-DEVHELP` compiler definition to run the program in any directory.

---
Made with 🍹