add_executable(${PROJECT_NAME})
target_sources(  
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} sortverse-core Qt::Core Qt::Gui Qt5::Widgets)
add_subdirectory(plugins)
add_subdirectory(core)
