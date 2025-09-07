add_executable (EKS3-QueueAlgMet "src/core/Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS3-QueueAlgMet PROPERTY CXX_STANDARD 20)
endif()



