add_library(simple_chrono
    simple_chrono.c
)

target_link_libraries(simple_chrono
        pico_stdlib)

target_include_directories(simple_chrono PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)