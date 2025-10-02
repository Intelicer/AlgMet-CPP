add_executable (EKS18-TreCase4 "src/core/Main.cpp"  "include/TreCase.h"  "src/module/TreCase.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS18-TreCase4 PROPERTY CXX_STANDARD 20)
endif()



