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

macro(region_test image_band format)
archimedes_add_test(extHeibergTest
  ${EXECUTABLE_OUTPUT_PATH}/archimedesCxxTests
  ExtractRegionOfInterestTest
  DATA{${Archimedes_DATA_ROOT}/099v-101r/099v-101r_Arch51v_${image_band}.${format}}
  100 100  # Start index
  256 256  # Region size
  ${TEMP}/099v-101r_Arch51v_${image_band}_region.jpg
  )
endmacro()

region_test(Heiberg_ultraviolet_stitch jpg)
region_test(Heiberg_visible_stitch jpg)
region_test(Sinar_LED365_01_pack8 jpg)
region_test(Sinar_LED445_01_pack8 jpg)
region_test(Sinar_LED470_01_pack8 jpg)
region_test(Sinar_LED505_01_pack8 jpg)
region_test(Sinar_LED530_01_pack8 jpg)
region_test(Sinar_LED570_01_pack8 jpg)
region_test(Sinar_LED617_01_pack8 jpg)
region_test(Sinar_LED625_01_pack8 jpg)
region_test(Sinar_LED700_01_pack8 jpg)
region_test(Sinar_LED735_01_pack8 jpg)
region_test(Sinar_LED870_01_pack8 jpg)
region_test(Sinar_RAKBLL_01_pack8 jpg)
region_test(Sinar_RAKBLR_01_pack8 jpg)
region_test(Sinar_RAKIRL_01_pack8 jpg)
region_test(Sinar_RAKIRR_01_pack8 jpg)
region_test(Sinar_TNGSTN_01_pack8 jpg)
region_test(Sinar_pseudo_no-veil jpg)
region_test(Sinar_pseudo_sharpie jpg)
region_test(Sinar_true_pack8 jpg)
region_test(Sinar_ultraviolet_norm8 jpg)
region_test(Sinar_uvblue_norm8 jpg)


region_test(Heiberg_ultraviolet_stitch tif)
region_test(Heiberg_visible_stitch tif)
region_test(Sinar_LED365_01_pack8 tif)
region_test(Sinar_LED445_01_pack8 tif)
region_test(Sinar_LED470_01_pack8 tif)
region_test(Sinar_LED505_01_pack8 tif)
region_test(Sinar_LED530_01_pack8 tif)
region_test(Sinar_LED570_01_pack8 tif)
region_test(Sinar_LED617_01_pack8 tif)
region_test(Sinar_LED625_01_pack8 tif)
region_test(Sinar_LED700_01_pack8 tif)
region_test(Sinar_LED735_01_pack8 tif)
region_test(Sinar_LED870_01_pack8 tif)
region_test(Sinar_RAKBLL_01_pack8 tif)
region_test(Sinar_RAKBLR_01_pack8 tif)
region_test(Sinar_RAKIRL_01_pack8 tif)
region_test(Sinar_RAKIRR_01_pack8 tif)
region_test(Sinar_TNGSTN_01_pack8 tif)
region_test(Sinar_pseudo_no-veil tif)
region_test(Sinar_pseudo_sharpie tif)
region_test(Sinar_true_pack8 tif)
region_test(Sinar_ultraviolet_norm8 tif)
region_test(Sinar_uvblue_norm8 tif)


#
# Create target to download data from the ArchimedesPalimsestITKTestData group.  This must come after
# all tests have been added that reference the group, so we put it last.
#
ExternalData_Add_Target(ArchimedesPalimsestITKTestData)
