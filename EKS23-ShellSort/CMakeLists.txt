add_executable (EKS23-ShellSort "src/core/Main.cpp"  "include/ShellSort.h"  "src/module/ShellSort.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS23-ShellSort PROPERTY CXX_STANDARD 20)
endif()



