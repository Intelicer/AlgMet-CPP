add_executable (Testing "Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Testing PROPERTY CXX_STANDARD 20)
endif()



