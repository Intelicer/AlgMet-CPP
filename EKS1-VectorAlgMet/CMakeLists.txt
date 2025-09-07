add_executable (EKS1-VectorAlgMet "src/core/Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS1-VectorAlgMet PROPERTY CXX_STANDARD 20)
endif()



