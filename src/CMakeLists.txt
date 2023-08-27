add_executable(${PROJECT_NAME})
target_sources(  
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

if (WIN32)
    add_subdirectory(dlfcn-win32)
    # find_package(dlfcn-win32 REQUIRED)
    set(CMAKE_DL_LIBS dl)
endif(WIN32)
    
target_link_libraries(${PROJECT_NAME} pluginloader ${CMAKE_DL_LIBS})
add_subdirectory(plugins)
add_subdirectory(pluginloader)

