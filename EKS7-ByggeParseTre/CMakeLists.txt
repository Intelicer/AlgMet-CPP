add_executable (EKS7-ByggeParseTre "src/core/Main.cpp" "include/ParseTree.h" "src/module/ParseTree.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS7-ByggeParseTre PROPERTY CXX_STANDARD 20)
endif()



