add_executable (EKS22-InsertionSort "src/core/Main.cpp"  "include/InsertionSort.h"  "src/module/InsertionSort.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS22-InsertionSort PROPERTY CXX_STANDARD 20)
endif()



