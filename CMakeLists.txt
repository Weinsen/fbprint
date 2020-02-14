cmake_minimum_required (VERSION 2.8.11)
project (fbprint)

include_directories(include)
include_directories(icons)

add_executable(fbprint
  fbprint.c
  bitmap.c
  )

add_executable(bmp2header
  bmp2header.c
  bitmap.c
  )

add_custom_target(ICONS
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/install-icons.sh 
        )
add_dependencies(fbprint ICONS)

install(TARGETS fbprint bmp2header DESTINATION bin)

