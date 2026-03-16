add_library(core)
target_sources(
    core
    PRIVATE Board.cpp
    PUBLIC FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_features(core PUBLIC cxx_std_26)
apply_compile_flags(core)

add_executable(main)
target_sources(main PRIVATE main.cpp)
apply_compile_flags(main)
apply_sanitizer_flags(main)
target_link_libraries(main PRIVATE core)
