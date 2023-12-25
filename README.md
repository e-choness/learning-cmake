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

## :bookmark_tabs: Add Subdirectory

- One thing that came up with `add_subdirectory` to organize the projects is always trying to include headers. `target_include_directory` can help locate library header files. VS Code still mark inline errors for including headers. If CMake compiles and builds the project without problem, it's safe to ignore IDE errors.

- `target_compile_definition` is a way to specify the library properties such as library version and others to help define specific complication actions. The definition can be captured in the C++ program as well. Setting it to `PUBLIC`, the definitions will be accessible to source code outside of the library, `PRIVATE` on the other hand, will not propagate to code inside the library. `INTERFACE` does the exact opposite to `PRIVATE`. These are powerful features of CMake, will help a great deal for build automation.

- Don't set compile definitions to something like `1.0.0`, it does not parse well in code.

## :wrench: Scripting in CMake

- Literally every variable data in CMake is a string, with the simplicity of scripting it might take more effort for developers to process.
- `command_name(<list of arguments>)` outputs commands that feeds into the executable.
- `message()` outputs the contents to the console when configuring and compiling in CMake.
- Variables are interpreted using `${}` syntax.

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

## :fork_and_knife: VS Code Shortcuts

| Shortcut | Description |
|---|---|
| `Ctrl+Shift+P`| Summon command palette, where commands like `cmake:configure` can be called here. |
| `Ctrl+P` | Quick search on the files in the project. |
