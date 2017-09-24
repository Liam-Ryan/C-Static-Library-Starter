# CStaticLibSeed
**A starter project to make it easier to create static libraries with CMake and unit tests.**

Includes CMake setup and sample tests for using the [Check](https://github.com/libcheck/check) 
unit testing library

**Dependencies**

- CMake
- FindPkgConfig
- Check
- pthread( required by check )

**Warning** Seed has only been tested on Linux systems

**Getting started**
1. Install dependencies and clone repo with git or download a zip. Check is available in most Linux distro repositories.
1. Create a build folder in the project directory - mkdir build
1. Navigate to the build folder and run `cmake ..`
1. Hopefully you won't see any errors, if you do you likely have a missing dependency
1. Run `make` in the project directory, if you have errors now it's probably my fault - please raise an issue!
1. If all went well then you can navigate to test folder and run `./testexec` You should see output saying 3 tests of 
3 passed
1. If you wish you can break a test to make sure all is working as it should - go to library.c and change the output 
string in hello(). Re-run make and run the new testexec binary and you should see a failure

**Memory Leaks and debugging**
To run valgrind properly or to debug your unit tests you need to uncomment `srunner_set_fork_status(sr, CK_NOFORK);` 
in test.c. This does prevent check from catching segfaults so be aware of that. After uncommenting and rebuilding the 
testexec binary with make you can then run `valgrind --leak-check=full ./testexec` from the build/test directory.  

**Customisation**
Congratulations, the seed is working! 

In order to create your own library you can rename library.h and library.c, 
make sure to update any references to these files in CmakeLists.txt files. 
Also change the project name in CmakeLists.txt files. You'll need to run cmake again after doing this. 
 
Finally make sure to replace this file with your own Readme.md 


Happy hacking!
