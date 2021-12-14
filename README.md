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
./Snake
```

## From `code` (VSCode)

![Build_Run_CMake](./img/vscode_cmake.png)

## Lib

- [SFML](https://www.sfml-dev.org/index-fr.php)

## Biblio

- [code (vscode)](https://code.visualstudio.com/docs/cpp/CMake-linux)
- [cmake tutorial](http://sirien.metz.supelec.fr/depot/SIR/TutorielCMake/index.html)
- [cmake org](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#)