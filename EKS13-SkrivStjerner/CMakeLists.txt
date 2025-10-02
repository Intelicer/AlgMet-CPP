add_executable (EKS13-SkrivStjerner "src/core/Main.cpp"  "include/PrintStars.h" "src/module/PrintStars.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EKS13-SkrivStjerner PROPERTY CXX_STANDARD 20)
endif()



