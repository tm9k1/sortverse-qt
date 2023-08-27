add_library(pluginloader STATIC pluginloader.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pluginloader ${CMAKE_DL_LIBS})