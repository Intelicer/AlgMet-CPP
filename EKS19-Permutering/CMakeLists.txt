add_executable (EKS20-Permutering2 "src/core/Main.cpp"  "include/Permutering.h"  "src/module/Permutering.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS20-Permutering2 PROPERTY CXX_STANDARD 20)
endif()



