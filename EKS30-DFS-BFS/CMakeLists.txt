add_executable (EKS30-DFS-BFS "src/core/Main.cpp"  "include/DFS-BFS.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS30-DFS-BFS PROPERTY CXX_STANDARD 20)
endif()



