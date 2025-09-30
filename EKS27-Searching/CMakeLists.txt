add_executable (EKS27-Searching "src/core/Main.cpp"  "include/Searching.h" "src/modules/Searching.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS27-Searching PROPERTY CXX_STANDARD 20)
endif()



