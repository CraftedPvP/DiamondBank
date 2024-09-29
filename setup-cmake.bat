@echo off
title "CMake Setup"

set buildDir=build
set cmakeDir=CMake
set keepFile=CMakeLists.txt
set buildExecutableDebug=.\build\DiamondBank\bin\Debug

@REM Skip function definition so they won't get called
goto :main

@REM Function definition for all actions

:Build
    @REM Creates the build files for the current platform
    echo === Creating project with CMake
    if not exist "%cmakeDir%" (mkdir "%cmakeDir%")
    cd CMake
    cmake ..
    
    @REM Compiles the executable for the current platform
    echo === Building project
    cmake --build .
    cd ..

    echo === Building complete
    printf "\n"
exit /b

:Run
    if not exist %buildExecutableDebug%\DiamondBank.exe (
        echo === Error: Executable not found in "%buildExecutableDebug%\DiamondBank.exe". Try building it first...
        printf "\n"
        exit /b 0
    )
    echo === Running Executable
    %buildExecutableDebug%\DiamondBank.exe
    
    printf "\n"
exit /b

:Clean
    @REM Delete the entire build folder
    echo === Cleaning CMake build directory...
    echo Deleting %buildDir%
    rm -rf %buildDir%

    @REM Delete the cmake cache folders and cache files while leaving the CMakeLists.txt intact
    echo === Cleaning CMake cache directory...
    echo Deleting %cmakeDir%
    rm -rf %cmakeDir%
    
    echo === Cleaning complete
    printf "\n"
exit /b

@REM Main logic start
:main

printf "\n"

@REM If no arguments are passed, it means we will build and run the program
if "%1" == "" (
    call :Build
    call :Run
    exit /b 0
)

if "%1" == "build" (
    call :Build
    exit /b 0
)

if "%1" == "run" (
    call :Run
    exit /b 0
)

if "%1" == "clean" (
    call :Clean
    exit /b 0
)

echo Error: Invalid arguments. Please use 'build', 'run', or 'clean'.