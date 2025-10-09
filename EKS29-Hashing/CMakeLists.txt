add_executable (EKS29-Hashing "src/core/Main.cpp"  "include/Hashing.h" "src/module/Hashing.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS29-Hashing PROPERTY CXX_STANDARD 20)
endif()



