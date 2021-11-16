# Set the minimum version of CMake required.
cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

# Set the project name and version.
project(Takanashi_compiler VERSION 1.0 LANGUAGES CXX)

# C++ standard settings.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Yacc and lex settings.
find_package(BISON)
find_package(FLEX)
set(YACC_SRC "${PROJECT_SOURCE_DIR}/src/frontend/parser/parser.ypp")
set(FLEX_SRC "${PROJECT_SOURCE_DIR}/src/frontend/parser/lexer.l")

# Check the compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(SUPPRESS_WARN_FLAGS "${SUPPRESS_WARN_FLAGS} -Wno-sign-compare \
                                                     -Wno-unused-parameter \
                                                     -Wno-nullability-completeness \
                                                     -Wno-register")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(SUPPRESS_WARN_FLAGS "${SUPPRESS_WARN_FLAGS} -Wno-sign-compare -Wno-unused-parameter")

endif ()

if ("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message("In-source builds are not allowed.")
endif ()

# Output yacc and lex files.
BISON_TARGET(yacc ${YACC_SRC} ${PROJECT_SOURCE_DIR}/src/frontend/parser/parser.cc)
FLEX_TARGET(flex ${FLEX_SRC} ${PROJECT_SOURCE_DIR}/src/frontend/parser/lexer.cc)
ADD_FLEX_BISON_DEPENDENCY(flex yacc)

add_custom_target(
    header
    COMMAND mv ${PROJECT_SOURCE_DIR}/src/frontend/parser/parser.hh ${PROJECT_SOURCE_DIR}/include/frontend/parser
    DEPENDS ${PROJECT_SOURCE_DIR}/src/frontend/parser/parser.cc ${PROJECT_SOURCE_DIR}/src/frontend/parser/lexer.cc
)

# Add library sysy
file(GLOB_RECURSE SYSY RELATIVE ${PROJECT_SOURCE_DIR} 
    "src/sylib.cc"
)

file(GLOB_RECURSE UTILS RELATIVE ${PROJECT_SOURCE_DIR} 
    "src/common/*.cc"
)

add_library(sysy SHARED ${SYSY})
set_target_properties(sysy PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(sysy PRIVATE include)
add_library(utils SHARED ${UTILS})
set_target_properties(utils PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(utils PRIVATE include)

# Add all files.
file(GLOB_RECURSE COMPILER_SRC RELATIVE ${PROJECT_SOURCE_DIR} 
    "src/frontend/**/*.cc"
    "src/frontend/**/*.c"
    "src/backend/**/*.cc"
    "src/backend/**/*.c"
    "src/runtime/*.cc"
    "src/runtime/*.c"
    "src/ir/*.c"
    "src/ir/*.cc"
    "src/main.cc"
)

install(FILES ${PROJECT_BINARY_DIR}/Takanashi_compiler DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# Project configurations
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_executable(${PROJECT_NAME} ${COMPILER_SRC} ${BISON_yacc_OUTPUTS} ${FLEX_flex_OUTPUTS})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} l utils sysy)

add_dependencies(${PROJECT_NAME} utils sysy header)

# Run the test
enable_testing()
add_test(
    test
    ./${PROJECT_NAME} -t -s ../test/functional_tes
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
