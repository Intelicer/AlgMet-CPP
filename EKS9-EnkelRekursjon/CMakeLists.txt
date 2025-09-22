add_executable (EKS9-EnkelRekursjon "src/core/Main.cpp"  "include/SimpleRecursion.h" "src/module/SimpleRecursion.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS9-EnkelRekursjon PROPERTY CXX_STANDARD 20)
endif()



