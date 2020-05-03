![](logo.png)
# EZ Tabletop Library

##### Jump To
 * [FAQ](#faq)
 * [Requirements](#requirements)
 * [Compiling](#compiling)
 * [Using](#using)

## FAQ
#### What is LIBEZTP?
LIBEZTP is a C++ library aimed at create an easy to use library for tabletop game adaptations made in C++.
It has the necessary features to make and manage characters, items, and races in an easy format.
This is mostly because I plan on making some DM tools and one universal library would be pretty slick.

#### Where did the code for LIBEZTP come from?
I tried to make a Server-Client D&D application in mostly headers.
I failed miserably and rebranded it as a D&D framework, but a lot of the code was actually decent.
I'm using this to fix the mistakes I made and make it an actual usable library.

However, a lot of the code that is soon to come will be all fresh!

## Requirements
 * C++17 capable compiler (gcc, clang, msvc)
 * CMake 3.10 or above 

## Compiling
 1. Clone the git repo
 2. In the cloned repo root directory, type
 
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    make install
    ```
    
    This will create a new directory called `build` that will hold all your build files.
    It will them use cmake to compile the files and create the library file.
    With this done, it will install the library files and headers into their respective spots.
    
 3. If you wish to verify that the files worked, in build you may type
    
    ```bash
    cd test
    ./test
    ```
    
    This will navigate into the directory that has test, and run the Catch2 tests.
    It should very plainly tell you which tests succeeded and failed.
    If any failed, please make an issue request on the GitHub.

## Using
As this project (quite recently) is attempting to use modern C++, the only way to use this project aside from moving all source files into your project is with `find_package` on CMake.
To use, install as shown above, and then add the following to your `CMakeLists.txt`

```cmake
find_package(LibEZTP)

#All the fun stuff with your executable

target_link_libraries(YourExecutable PRIVATE LibEZTP::LibEZTP)
```

If you installed properly, it's as simple as that.
Only two lines you need to add!