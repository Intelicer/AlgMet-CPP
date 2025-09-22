add_executable (EKS11-GrafikkRekursjon "src/core/Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS11-GrafikkRekursjon PROPERTY CXX_STANDARD 20)
endif()



