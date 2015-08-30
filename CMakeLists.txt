set(mikanSource
  ${mikanSource}
  ${CMAKE_CURRENT_SOURCE_DIR}/Debug.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Engine.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/Entity.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/EntityLoader.cc
  PARENT_SCOPE
)

add_library(
  mikan
  STATIC
  ${mikanSource}
)

ADD_DEFINITIONS(-std=c++11)

