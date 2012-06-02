# Add executables and libraries here.

add_executable(ImageReadWrite ImageReadWrite.cxx)
target_link_libraries(ImageReadWrite ${ITK_LIBRARIES})

add_executable(RGBImageReadWrite RGBImageReadWrite.cxx)
target_link_libraries(RGBImageReadWrite ${ITK_LIBRARIES})

