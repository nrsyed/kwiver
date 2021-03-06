#
# CMake file for the arrows.vtk.applets
#

set( sources
  register_applets.cxx

  color_mesh.cxx
  estimate_depth.cxx
  fuse_depth.cxx
  )

set( headers
  color_mesh.h
  estimate_depth.h
  fuse_depth.h
  )

if(NOT KWIVER_ENABLE_MVG)
  message(FATAL_ERROR "-- The MVG arrow must be enabled (KWIVER_ENABLE_MVG)")
endif()

# Add applet plugin
kwiver_add_plugin( kwiver_algo_vtk_applets
  SUBDIR       ${kwiver_plugin_applets_subdir}
  SOURCES      ${sources} ${headers}
  PRIVATE      kwiver_algo_core
               kwiver_algo_mvg
               kwiver_algo_vtk
               kwiver_tools_applet
               kwiversys
               vtkFiltersCore
               vtkIOGeometry
               vtkIOPLY
               vtkIOXML
  )
