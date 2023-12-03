# CMakeList.txt : CMake project for kalkulacka_ved, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (kalkulacka_ved "kalkulacka_ved.cpp" "kalkulacka_ved.h" "operace.h" "operace.cpp" "interakce_s_uzivatelem.h" "interakce_s_uzivatelem.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET kalkulacka_ved PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
