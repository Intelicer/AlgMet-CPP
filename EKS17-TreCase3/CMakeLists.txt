add_executable (EKS17-TreCase3 "src/core/Main.cpp"  "include/TreCase.h"  "src/module/TreCase.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS17-TreCase3 PROPERTY CXX_STANDARD 20)
endif()



