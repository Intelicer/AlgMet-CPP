add_executable (Oblig2 "src/core/Main.cpp" "include/Oblig2.h" "src/module/Oblig2.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Oblig2 PROPERTY CXX_STANDARD 20)
endif()



