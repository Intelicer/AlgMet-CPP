add_executable (VectorAlgMet-EKS1 "src/core/Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VectorAlgMet-EKS1 PROPERTY CXX_STANDARD 20)
endif()



