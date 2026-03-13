cmake_minimum_required(VERSION 3.26)
project(15-puzzle VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(apply_compile_flags target)
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
            -fsanitize=address,undefined,leak,pointer-compare,pointer-subtract
            >
            # Release
            $<$<CONFIG:Release>:
            -march=native
            -flto
            -fstack-protector-strong
            -D_FORTIFY_SOURCE=3
            -fno-omit-frame-pointer
            >
            # RelWithDebInfo
            $<$<CONFIG:RelWithDebInfo>:
            -march=native
            -flto
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
    )

    target_link_options(
        ${target}
        PRIVATE
            $<$<CONFIG:Debug>:
            -fsanitize=address,undefined,leak,pointer-compare,pointer-subtract
            >
            $<$<CONFIG:Release>:
            -flto
            >
            $<$<CONFIG:RelWithDebInfo>:
            -flto
            >
            $<$<CONFIG:MinSizeRel>:
            -Wl,--gc-sections
            >
    )
endfunction()

add_subdirectory(include)
add_subdirectory(src)
