add_library(wekauwau INTERFACE)
target_sources(
    wekauwau
    INTERFACE FILE_SET HEADERS BASE_DIRS ${PROJECT_SOURCE_DIR}/include
)
