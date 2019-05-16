cmake_minimum_required (VERSION 2.8.11)
project (fbprint)

include_directories(include)
add_executable(fbprint
  fbprint.c
  bitmap.c
  )

add_executable(bmp2header
  bmp2header.c
  bitmap.c
  )

install(TARGETS fbprint bmp2header DESTINATION bin)
