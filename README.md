# Snake

_Game..._

## From the `terminal`
### Compile

_Considering that_ `build` directory _is aside sources_

```bash
.
├── CMakeLists.txt
├── main.cpp
└── README.md
```

```bash
mkdir build && cd build && cmake .. && make
```

> outcomes

```bash
.
├── build
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── CPackConfig.cmake
│   ├── CPackSourceConfig.cmake
│   ├── CTestTestfile.cmake
│   ├── DartConfiguration.tcl
│   ├── Makefile
│   ├── Snake
│   └── Testing
├── CMakeLists.txt
├── main.cpp
└── README.md

3 directories, 11 files
```

### Run

```bash
./snake
```

### Install

_compile first with rigth options_

```bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/doali-snake
make
make install
```

## Doc

`doxygen -g Doxyfile.in`

## Dependencies

```bash
doali doali:~ 
> pkg-config --list-all | grep sfml
sfml-network                     SFML-network - The Simple and Fast Multimedia Library, network module.
sfml-window                      SFML-window - The Simple and Fast Multimedia Library, window module.
sfml-all                         SFML-all - The Simple and Fast Multimedia Library, all modules.
sfml-graphics                    SFML-graphics - The Simple and Fast Multimedia Library, graphics module.
sfml-system                      SFML-system - The Simple and Fast Multimedia Library, system module.
sfml-audio                       SFML-audio - The Simple and Fast Multimedia Library, audio module.
doali doali:~ 
> pkg-config --libs sfml-window
-lsfml-window -lsfml-system
doali doali:~ 
> pkg-config --libs sfml-graphics 
-lsfml-graphics -lsfml-window -lsfml-system
doali doali:~ 
> 
```

> (!) [eliasdaler CMake !!](https://eliasdaler.github.io/using-cmake/)

## From `code` (VSCode)

![Build_Run_CMake](./img/vscode_cmake.png)

## Lib

- [SFML](https://www.sfml-dev.org/index-fr.php)

## Biblio

- [code (vscode)](https://code.visualstudio.com/docs/cpp/CMake-linux)
- [cmake tutorial](http://sirien.metz.supelec.fr/depot/SIR/TutorielCMake/index.html)
- [cmake org](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#)
- [cmake tutoriel](http://sirien.metz.supelec.fr/depot/SIR/TutorielCMake/index.html)
- [cmake to_check](https://en.sfml-dev.org/forums/index.php?topic=27603.0)