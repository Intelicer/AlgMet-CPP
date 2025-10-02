add_executable (EKS15-TreCase1 "src/core/Main.cpp"  "include/TreCase.h"  "src/module/TreCase.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS15-TreCase1 PROPERTY CXX_STANDARD 20)
endif()



