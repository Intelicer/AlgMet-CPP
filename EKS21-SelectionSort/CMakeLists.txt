add_executable (EKS21-SelectionSort "src/core/Main.cpp"  "include/SelectionSort.h"  "src/module/SelectionSort.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS21-SelectionSort PROPERTY CXX_STANDARD 20)
endif()



