add_executable (EKS28-BinarySearchTree "src/core/Main.cpp"  "include/BST.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS28-BinarySearchTree PROPERTY CXX_STANDARD 20)
endif()



