add_executable(tests Tile_test.cpp Point_test.cpp Board_test.cpp)
target_link_libraries(tests PRIVATE core Catch2::Catch2WithMain)
apply_compile_flags(tests)
apply_sanitizer_flags(tests)

# list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
