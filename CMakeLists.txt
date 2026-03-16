cmake_minimum_required(VERSION 3.26)
project(15-puzzle VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(apply_compile_flags target)
    set(GCC "$<CXX_COMPILER_ID:GNU>")
    set(CLANG "$<CXX_COMPILER_ID:Clang>")
    set(REL "$<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>>")

    target_compile_options(
        ${target}
        PRIVATE
            # Debug
            $<$<CONFIG:Debug>:
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            -Wconversion
            -Wsign-conversion
            -Wdouble-promotion
            -Wformat=2
            -Wimplicit-fallthrough
            -Wnull-dereference
            -Wold-style-cast
            -Woverloaded-virtual
            -Wnon-virtual-dtor
            -Wduplicated-cond
            -Wduplicated-branches
            -Wlogical-op
            -Wuseless-cast
            -Wmisleading-indentation
            -D_GLIBCXX_DEBUG
            -fno-omit-frame-pointer
            >
            # Release + RelWithDebInfo
            $<$<CONFIG:Release>:
            -march=native
            -fstack-protector-strong
            -D_FORTIFY_SOURCE=3
            -fno-omit-frame-pointer
            >
            $<$<CONFIG:RelWithDebInfo>:
            -march=native
            -fstack-protector-strong
            -D_FORTIFY_SOURCE=3
            -fno-omit-frame-pointer
            >
            # MinSizeRel
            $<$<CONFIG:MinSizeRel>:
            -ffunction-sections
            -fdata-sections
            -fstack-protector-strong
            -D_FORTIFY_SOURCE=3
            >
            # LTO — compiler-specific, release-like configs only
            $<$<AND:${REL},$<CONFIG:Release>>:>
            $<$<AND:${REL},${GCC}>:-flto=auto>
            $<$<AND:${REL},${CLANG}>:-flto=thin>
    )
    target_link_options(
        ${target}
        PRIVATE
            $<$<AND:${REL},${GCC}>:-flto=auto>
            $<$<AND:${REL},${CLANG}>:-flto=thin>
            $<$<CONFIG:MinSizeRel>:
            -Wl,--gc-sections
            >
    )
endfunction()

function(apply_sanitizer_flags target)
    set(GCC "$<CXX_COMPILER_ID:GNU>")

    target_compile_options(
        ${target}
        PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined,leak>
            $<$<AND:$<CONFIG:Debug>,${GCC}>:-fsanitize=pointer-compare,pointer-subtract>
    )
    target_link_options(
        ${target}
        PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=address,undefined,leak>
            $<$<AND:$<CONFIG:Debug>,${GCC}>:-fsanitize=pointer-compare,pointer-subtract>
    )
endfunction()

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.13.0
)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(src)
add_subdirectory(tests)
