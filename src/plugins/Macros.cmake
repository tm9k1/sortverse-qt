include_guard()
function(add_plugin plugin)

  set(options STATIC)
  set(oneValueArgs JSON INSTALL_NAMESPACE)
  set(multiValueArgs SOURCES)
  cmake_parse_arguments(PLUGIN "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN}) 
  # prefix is set to PLUGIN, so args will be parsed as PLUGIN_args 
  add_library(${plugin} MODULE ${PLUGIN_SOURCES})
  target_include_directories(${plugin} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  set_target_properties(${plugin} PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/plugins")

endfunction(add_plugin)
