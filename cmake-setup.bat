@echo off
title "CMake Setup"

set buildDir=build
set cmakeDir=CMake
set keepFile=CMakeLists.txt

@REM Skip function definition so they won't get called
goto :main

@REM Function definition for all actions

:Build
    @REM Creates the build files for the current platform
    echo === Creating project with CMake
    cd CMake
    cmake .
    
    @REM Compiles the executable for the current platform
    echo === Building project
    cmake --build .
    cd ..
    echo === Building complete
exit /b

:Run
    if not exist .\build\DiamondBank\bin\Debug\DiamondBank.exe (
        echo === Error: Executable not found. Try building it first...
        exit /b 0
    )
    echo === Running Executable
    .\build\DiamondBank\bin\Debug\DiamondBank.exe
exit /b

:Clean
    @REM Delete the entire build folder
    echo === Cleaning CMake build directory...
    rm -rf %buildDir%

    @REM Delete the cmake cache folders and cache files while leaving the CMakeLists.txt intact
    echo === Cleaning CMake cache directory...
    FOR /d %%a IN ("%cmakeDir%\*") DO RD /S /Q "%%a"
    FOR %%a IN ("%cmakeDir%\*") DO IF /i NOT "%%~nxa"=="%keepFile%" DEL "%%a"
    echo === Cleaning complete
exit /b

@REM Main logic start
:main

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