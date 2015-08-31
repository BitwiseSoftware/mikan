# Usage
Assuming you're using CMake, and want neapolis to be at 'opt/neapolis'.

### Installiation
```Shell
git clone --recursive https://github.com/BitwiseSoftware/mikan.git opt/mikan
```

### CMakeLists.txt
```CMake
add_subdirectory(opt/mikan)
include_directories(opt/mikan/include)
target_link_libraries(YOUR_EXECUTABLE neapolis)
```

# Contributors
### Setup
### Setup
```Shell
$ git clone --recursive https://github.com/BitwiseSoftware/mikan.git
$ cd mikan
$ mkdir build && cd build
$ make
```

# Requirements
* C++11 compatible compiler
* CMake v2.8+
* SFML 2.1+ (apt-get install libsfml-dev)
