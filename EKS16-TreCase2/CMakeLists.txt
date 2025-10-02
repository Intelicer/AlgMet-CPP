add_executable (EKS16-TreCase2 "src/core/Main.cpp"  "include/TreCase.h"  "src/module/TreCase.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS16-TreCase2 PROPERTY CXX_STANDARD 20)
endif()



