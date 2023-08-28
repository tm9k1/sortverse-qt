add_executable(${PROJECT_NAME})
target_sources(  
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

if (WIN32)
    add_subdirectory(dlfcn-win32)
    set(CMAKE_DL_LIBS dl)
endif(WIN32)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} sortverse-core ${CMAKE_DL_LIBS})
add_subdirectory(plugins)
add_subdirectory(core)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME ${PROJECT_NAME}
  COMMAND $<TARGET_FILE:${PROJECT_NAME}>
  )