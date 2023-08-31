add_library(sortverse-core)
target_sources(sortverse-core PRIVATE sortverseplugin.cpp pluginloader.cpp util.cpp)
target_link_libraries(sortverse-core ${CMAKE_DL_LIBS})
