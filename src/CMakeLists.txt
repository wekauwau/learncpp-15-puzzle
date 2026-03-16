add_library(core)
target_sources(
    core
    PRIVATE Board.cpp
    PUBLIC FILE_SET HEADERS BASE_DIRS ${PROJECT_SOURCE_DIR}/src
)
apply_compile_flags(core)
target_link_libraries(core PRIVATE wekauwau)

add_executable(main)
target_sources(main PRIVATE main.cpp)
apply_compile_flags(main)
apply_sanitizer_flags(main)
target_link_libraries(main PRIVATE core)
