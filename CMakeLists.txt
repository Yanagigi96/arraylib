cmake_minimum_required(VERSION 3.16)
project(arraylib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Динамическая библиотека ---
add_library(arraylib SHARED src/arraylib.cpp)

target_include_directories(arraylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Макрос для экспорта функций (нужен для Windows DLL)
target_compile_definitions(arraylib PRIVATE ARRAYLIB_BUILD)

if (MSVC)
    target_compile_options(arraylib PRIVATE /W4)
else()
    target_compile_options(arraylib PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Чтобы .so искалась рядом с исполняемым файлом
set_target_properties(arraylib PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# --- Прикладная задача (Вариант 20) ---
add_executable(variant_20 examples/variant_20.cpp)
target_link_libraries(variant_20 PRIVATE arraylib)
set_target_properties(variant_20 PROPERTIES BUILD_RPATH "$ORIGIN")

# --- Тесты ---
include(CTest)
if (BUILD_TESTING)
    add_executable(test_unit tests/test_unit.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)
    target_compile_options(test_unit PRIVATE -UNDEBUG)
    add_test(NAME unit COMMAND test_unit)

    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)
    target_compile_options(test_integration PRIVATE -UNDEBUG)
    add_test(NAME integration COMMAND test_integration)
endif()