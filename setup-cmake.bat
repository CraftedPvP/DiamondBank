@echo off
title "CMake Setup"

set buildDir=build
set cmakeDir=CMake
set buildExecutableDebug=.\build\DiamondBank\bin\Debug
set buildExecutableRelease=.\build\DiamondBank\bin\Release
set makeGenerator=MinGW Makefiles
set msbuildGenerator=Visual Studio 17 2022

@REM Skip function definition so they won't get called
goto :main

@REM Function definition for all actions

:Build
    call :BuildMake
    echo.
    echo.
    call :BuildMsbuild
exit /b

:BuildMake
    @REM Compile with Make
    echo === Creating CMake.Make folders
    if NOT exist "%cmakeDir%" mkdir "%cmakeDir%"
    if NOT exist "%cmakeDir%/make" mkdir "%cmakeDir%/make"
    @REM if NOT exist "%buildDir%/make" mkdir "%buildDir%/make"
    cd "%cmakeDir%/make"
    cmake -DDevHelp=ON ../.. -G "%makeGenerator%"
    
    @REM Compiles the executable for the current platform
    echo === Building project
    cmake --build .
    
    cd ../..
exit /b

:BuildMsbuild
    echo === Creating CMake.MSbuild folders
    if NOT exist "%cmakeDir%" mkdir "%cmakeDir%"
    if NOT exist "%cmakeDir%/msbuild" mkdir "%cmakeDir%/msbuild"
    @REM if NOT exist "%buildDir%/msbuild" mkdir "%buildDir%/msbuild"

    echo === Creating project with msbuild
    cd "%cmakeDir%/msbuild"
    cmake -DDevHelp=ON ../.. -G "%msbuildGenerator%"

    echo === Building project
    cmake --build . --config Release

    echo === Exporting executable
    msbuild "DiamondBank.sln" /p:Configuration=Release

    echo === Building complete
    cd ../..
    echo.
exit /b

:Run
    call :RunMake
    call :RunMSBuild
exit /b
:RunMake
    set executable="%buildDir%\%makeGenerator%\bin\DiamondBank.exe"
    if not exist %executable% (
        echo === Error: Executable not found in %executable%. Try building it first...
        echo.
        exit /b 0
    )
    echo === Running Executable
    %executable%
    
    echo.
exit /b

:RunMSBuild
    set executable="%buildDir%\%msbuildGenerator%\bin\Release\DiamondBank.exe"
    if not exist %executable% (
        echo === Error: Executable not found in %executable%. Try building it first...
        echo.
        exit /b 0
    )
    echo === Running Executable
    %executable%
    
    echo.
exit /b
:Clean
    @REM Delete the entire build folder
    if exist %buildDir% (
        echo === Cleaning CMake build directory...
        echo Deleting %buildDir%
        rmdir /S /Q %buildDir%
    )

    @REM Delete the cmake cache folders and cache files while leaving the CMakeLists.txt intact
    if exist %cmakeDir% (
        echo === Cleaning CMake cache directory...
        echo Deleting %cmakeDir%
        rmdir /S /Q %cmakeDir%
    )
    echo === Cleaning complete
    echo.
exit /b

@REM Main logic start
:main

echo.

@REM If no arguments are passed, it means we will build and run the program
if "%1" == "" (
    call :BuildMsbuild
    call :RunMSBuild
    exit /b 0
)

if "%1" == "build" (
    call :Build
    exit /b 0
)

if "%1" == "build-make" (
    call :BuildMake
    exit /b 0
)

if "%1" == "build-msbuild" (
    call :BuildMsbuild
    exit /b 0
)

if "%1" == "run" (
    call :Run
    exit /b 0
)
if "%1" == "run-make" (
    call :RunMake
    exit /b 0
)
if "%1" == "run-msbuild" (
    call :RunMSBuild
    exit /b 0
)

if "%1" == "clean" (
    call :Clean
    exit /b 0
)

echo Error: Invalid arguments.
echo Please use 'build', 'build-make', 'build-msbuild', 'run', 'run-make', 'run-msbuild', or 'clean'.