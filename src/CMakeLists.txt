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
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} sortverse-core Qt::Core Qt::Gui Qt5::Widgets ${CMAKE_DL_LIBS})
add_subdirectory(plugins)
add_subdirectory(core)
