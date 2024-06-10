cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(EventPHQMDLibrary)

macro(add_target_property _target _prop _value)
  get_target_property(_oldprop "${_target}" ${_prop})
  if(NOT _oldprop)
    set_target_properties("${_target}" PROPERTIES ${_prop} "${_value}")
  else(NOT _oldprop)
    set_target_properties("${_target}" PROPERTIES ${_prop} "${_oldprop} ${_value}")
  endif(NOT _oldprop)
endmacro(add_target_property)

if (CMAKE_VERSION VERSION_LESS "3.1")
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
endif ()
else ()
  set (CMAKE_CXX_STANDARD 17)
endif ()

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS} ${ROOTSYS})

find_package(ROOT REQUIRED RIO)

Set(INCLUDE_DIRECTORIES
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/unigen
  ${PROJECT_SOURCE_DIR}/EventFreeze
  ${PROJECT_SOURCE_DIR}/converter
)

include(${ROOT_USE_FILE})
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
Include_Directories( ${CMAKE_SOURCE_DIR} ${INCLUDE_DIRECTORIES} )
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE OFF)

set(LINK_DIRECTORIES
  ${ROOT_LIBRARY_DIR}
)
 
link_directories( ${LINK_DIRECTORIES})

set (SOURCES
  src/PEventHadrons.cxx
  src/PEventBaryons.cxx
  src/PRun.cxx
  src/PBaryon.cxx
  src/PHadron.cxx
  EventFreeze/RunFreeze.cxx
  EventFreeze/EventFreeze.cxx
  EventFreeze/ParticleFreeze.cxx
  unigen/URun.cxx
  unigen/UEvent.cxx
  unigen/UParticle.cxx
  converter/PConverter.cxx
)

string(REPLACE ".cxx" ".h" HEADERS "${SOURCES}")

ROOT_GENERATE_DICTIONARY(G__EventPHQMD ${HEADERS} LINKDEF EventPHQMDLinkDef.h)
add_library(EventPHQMD SHARED ${SOURCES} G__EventPHQMD.cxx)
target_link_libraries(EventPHQMD ${ROOT_LIBRARIES})

install(FILES ${HEADERS} ${NODICT_HEADERS} DESTINATION include)
install(FILES ${CMAKE_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}EventPHQMD_rdict.pcm DESTINATION lib OPTIONAL)
install(FILES ${CMAKE_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}EventPHQMD.rootmap DESTINATION lib)
install(TARGETS EventPHQMD DESTINATION lib)

