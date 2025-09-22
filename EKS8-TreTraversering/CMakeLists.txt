add_executable (EKS8-TreTraversering  "src/core/Main.cpp" "include/TreeTraversal.h" "src/module/TreeTraversal.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS8-TreTraversering PROPERTY CXX_STANDARD 20)
endif()



