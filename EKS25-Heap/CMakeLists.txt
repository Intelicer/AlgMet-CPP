add_executable (EKS25-Heap "src/core/Main.cpp"  "include/Heap.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS25-Heap PROPERTY CXX_STANDARD 20)
endif()



