cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AlgMet")

# Include sub-projects.
add_subdirectory ("EKS1-VectorAlgMet")
add_subdirectory ("EKS2-StackAlgMet")
add_subdirectory ("EKS3-QueueAlgMet")
add_subdirectory ("EKS4-ListAlgMet")
add_subdirectory ("EKS5-InfixTilPostfix")
add_subdirectory ("EKS6-PostfixToResult")
add_subdirectory ("EKS7-ByggeParseTre")
add_subdirectory ("EKS8-TreTraversering")
add_subdirectory ("EKS9-EnkelRekursjon")
add_subdirectory ("EKS10-3xRecursion")
add_subdirectory ("Oblig2")