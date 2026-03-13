add_executable(main)
target_sources(main PRIVATE main.cpp Tile.cpp)
target_compile_features(main PRIVATE cxx_std_26)
apply_compile_flags(main)

# target_link_libraries(main PRIVATE wekauwau)
