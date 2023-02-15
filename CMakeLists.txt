cmake_minimum_required(VERSION 3.0.0)

project("Tortilla")

add_executable("Tortilla" main.cpp CHIP8.cpp helpers/rom.cpp helpers/OpCode.cpp helpers/Display.cpp)

find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  # SFML version >= 2.5
  #In SFML Version 2.5 or later, ${SFML_LIBRARIES}, ${SFML_DEPENDENCIES}, ${SFML_INCLUDE_DIR} no longer exist. Specify libraries individually.
  target_link_libraries(${PROJECT_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()