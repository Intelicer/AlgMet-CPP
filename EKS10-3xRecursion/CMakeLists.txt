add_executable (EKS10-3xRecursion "src/core/Main.cpp"  "include/TxRecursion.h" "src/module/TxRecursion.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS10-3xRecursion PROPERTY CXX_STANDARD 20)
endif()



