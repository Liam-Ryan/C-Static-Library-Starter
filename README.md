# CStaticLibSeed
A quick and dirty seed to make it easier to create static libraries with CMake

1. Clone repo
2. Rename library.c and library.h to <yourlibrary>. Change all references to library in arguments in CMakeLists to <yourlibrary>
3. If using Clion open the repo as a new project. If not then create an empty build directory in the repo folder and run "cmake .." from there
4. Write any tests you want in test/test.c. 
5. Run 'make' from within the build folder. The library will be output as <yourlibrary>.a and the test executable will be testexec.
   Alternatively CLion users can run "Build All" and specify the testexec as the executable
