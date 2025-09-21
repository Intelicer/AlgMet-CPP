add_executable (EKS5-InfixTilPostfix "src/core/Main.cpp"  "include/InfixTilPostfix.h" "src/modules/InfixTilPostfix.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS5-InfixTilPostfix PROPERTY CXX_STANDARD 20)
endif()



