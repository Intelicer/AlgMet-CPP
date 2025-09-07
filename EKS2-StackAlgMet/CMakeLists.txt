add_executable (EKS2-StackAlgMet "src/core/Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS2-StackAlgMet PROPERTY CXX_STANDARD 20)
endif()



