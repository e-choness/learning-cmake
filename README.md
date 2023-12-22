# :fire:Self-Taught CMake Examples

## :+1: Add Executable

- `add_executable(<executable-name> <entry-cpp>)`

## :card_index: Add Library

- `add_library(<library-name> <library-source> <library-header>)`.
- After `<library-name>` we can declare `STATIC`, `SHARED` or `MODULE` as library property. `STATIC` is built by default.
- `target_link_library(<executable-name> <library-name>)` will link the library to the executable. Before `<library-name>` it can be declared as `PUBLIC` OR `PRIVATE`.

## :memo: Useful Commands

### :bell: Basics

Under `<build-directory>`Run `cmake <source-directory>` can build project source files within specified `<build-directory>`.
`cmake --build <build-directory>` do linking, compiling and building executable.

### :floppy_disk: Settings

| Command| Description |
|---|---|
| `ldd <executable>` | List library linking activities. |
| `BUILD_SHARED_LIBS=TRUE` | Set building shared library by default. |
