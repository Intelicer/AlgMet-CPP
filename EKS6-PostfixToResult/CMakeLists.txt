add_executable (EKS6-PostfixToResult "src/core/Main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS6-PostfixToResult PROPERTY CXX_STANDARD 20)
endif()



