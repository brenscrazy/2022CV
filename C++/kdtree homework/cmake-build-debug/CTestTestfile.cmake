# CMake generated Testfile for 
# Source directory: D:/ng/2d-tree-brenscrazy
# Build directory: D:/ng/2d-tree-brenscrazy/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tests "D:/ng/2d-tree-brenscrazy/cmake-build-debug/test/runUnitTests.exe")
set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "D:/ng/2d-tree-brenscrazy/CMakeLists.txt;44;add_test;D:/ng/2d-tree-brenscrazy/CMakeLists.txt;0;")
subdirs("googletest")
subdirs("test")
