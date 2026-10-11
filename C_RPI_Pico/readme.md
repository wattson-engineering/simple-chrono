Add to CMakeLists.txt file:

```
# Add this block
add_subdirectory(lib/simple_chrono)

# In this block,
target_link_libraries(test 
        hardware_pio
        hardware_timer
        # Add this vvv
        simple_chrono
        )
```