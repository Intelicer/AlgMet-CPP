add_executable (EKS24-QuickSort "src/core/Main.cpp"  "include/QuickSort.h" "src/module/QuickSort.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS24-QuickSort PROPERTY CXX_STANDARD 20)
endif()



