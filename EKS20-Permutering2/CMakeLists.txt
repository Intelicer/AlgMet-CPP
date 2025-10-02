add_executable (EKS19-Permutering "src/core/Main.cpp"  "include/Permutering.h"  "src/module/Permutering.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS19-Permutering PROPERTY CXX_STANDARD 20)
endif()



