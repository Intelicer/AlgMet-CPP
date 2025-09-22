add_executable (EKS12-RekursivTreTraversering "src/core/Main.cpp"  "include/RecursiveTreeTraversal.h" "src/module/RecursiveTreeTraversal.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS12-RekursivTreTraversering PROPERTY CXX_STANDARD 20)
endif()



