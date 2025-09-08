add_executable (EKS4-ListAlgMet "src/core/Main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS4-ListAlgMet PROPERTY CXX_STANDARD 20)
endif()



