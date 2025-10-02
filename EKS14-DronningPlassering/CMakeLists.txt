add_executable (EKS14-DronningPlassering "src/core/Main.cpp"  "include/QueenPlacement.h" "src/module/QueenPlacement.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS14-DronningPlassering PROPERTY CXX_STANDARD 20)
endif()



