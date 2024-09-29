# 💎 Diamond Bank 💎

The 💎 Diamond Bank 💎 is a C++17 concept project compiled with make. It is a console program designed to simulate a bank interface.

❗ Do not use this in a real production scenario ❗

## Setup

### Via make

1. Clone the repo or download it as a `.zip`
2. Open the cloned repo or extracted folder in your command prompt/terminal
3. Type in `make` in the root folder to compile using make and run the executable.

### Via CMake

1. Clone the repo or download it as a `.zip`
2. Open the cloned repo or extracted folder in your command prompt/terminal
3. Call `setup-cmake.bat` to build using CMake and run the program.

## Available commands
```
## The make way ##
# Builds the project and runs the executable
make

# Builds the project only
make build

# Runs the program
make run

# Cleans the output files
make clean

--

## The CMake way ##
# Builds the project and runs the executable
cmake-setup.bat

# Builds the project only
cmake-setup.bat build

# Run the executable only
cmake-setup.bat run

# Clean the project only
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