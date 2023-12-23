# :fire:Self-Taught CMake Examples

## :pencil2: Notes

- This example is done mainly using CMake command lines and [Visual Studio Code](https://code.visualstudio.com/) with `CMake Tools`/`CMake Tools Extension` and related plugins.
- [CLion](https://www.jetbrains.com/clion/) also does a great job supporting complete configuration and CMake automation.
- [Visual Studio](https://visualstudio.microsoft.com/) also supports CMake, it's just not my first choice of IDE.

## 🐭 Minimum Setup

- `cmake_minimum_required` is the bare minimum required statement for specifying the cmake version the project is build on.
- `project(${PROJECT_NAME} VERSION x.x.x)` is giving a project a name and version to build. `VERSION` has to be upper case, CMake is case sensitive on that regard.

## 🐱 C++ Standard Declarations

- `set(CMAKE_CXX_STANDARD xx)` is to set C++ standard to compile, xx can be 11, 14, 17, 20 and 23. The command is using `CXX` instead of `C++` or `CPP` is because this is easier to parse for the OS file system. I don't know how it came to be but it's a thing that people just generally agreed on.
- `set(CMAKE_CXX_STANDARD_REQUIRED True/False)` is line is not required, but if the project is heavily relying on a specific C++ standard version, forcefully set a C++ standard might not be a bad idea.

## :+1: Add Executable

- `add_executable(<executable-name> <entry-cpp>)`

## :card_index: Add Library

- `add_library(<library-name> <library-source> <library-header>)`.
- After `<library-name>` we can declare `STATIC`, `SHARED` or `MODULE` as library property. `STATIC` is built by default.
- `target_link_library(<executable-name> <library-name>)` will link the library to the executable. Before `<library-name>` it can be declared as `PUBLIC` OR `PRIVATE`.

## :memo: Useful Commands

### :bell: Basics

- Under `<build-directory>` Run `cmake <source-directory>` can build project source files within specified `<build-directory>`.
- `cmake --build <build-directory>` do linking, compiling and building executable.
- `cmake -G Ninja <source-directory>` builds project using Ninja toolchain using source files from `<source directory>`. (In this case it doesn't quite work yet. Need investigation.)

### :floppy_disk: Settings

| Command| Description |
|---|---|
| `set CMAKE_GENERATOR=Ninja` | Set default CMake generator as Ninja. |
| `ldd <executable>` | List library linking activities. |
| `BUILD_SHARED_LIBS=TRUE` | Set building shared library by default. |
| `ls ENV:` | Output environmental variables. Useful when looking for compiler settings and include paths without using any IDEs.  |
| `echo $env:INCLUDE` | Output include paths. |
| `cmake -G Ninja -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl <source-directory>` | Build the program with Ninja generator and clang as compiler. |
