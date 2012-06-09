#
#  Unit testing infrastructure
#
set(Archimedes_DATA_ROOT "${PROJECT_SOURCE_DIR}/Data")

set(TEMP "${PROJECT_BINARY_DIR}/Testing/Temporary")

#
# Tell modules how to add their tests.
#
function(archimedes_add_test)
  # Add tests with data in the ArchimedesPalimsestITKTestData group.
  ExternalData_add_test(ArchimedesPalimsestITKTestData ${ARGN})
endfunction()

#
# Define test harness
#
create_test_sourcelist(TESTS_SOURCE_LIST
  archimedesCxxTests.cxx
  ExtractRegionOfInterestTest.cxx
  )

add_executable(archimedesCxxTests ${TESTS_SOURCE_LIST})
target_link_libraries(archimedesCxxTests ${ITK_LIBRARIES} ${VTK_LIBRARIES})

archimedes_add_test(extHeibergTest
  ${EXECUTABLE_OUTPUT_PATH}/archimedesCxxTests
  ExtractRegionOfInterestTest
  DATA{${Archimedes_DATA_ROOT}/099v-101r/099v-101r_Arch51v_Heiberg_ultraviolet_stitch.jpg}
  100 100  # Start index
  256 256  # Region size
  ${TEMP}/099v-101r_Arch51v_Heiberg_ultraviolet_stitch_region.jpg
  )

#
# Create target to download data from the ArchimedesPalimsestITKTestData group.  This must come after
# all tests have been added that reference the group, so we put it last.
#
ExternalData_Add_Target(ArchimedesPalimsestITKTestData)
