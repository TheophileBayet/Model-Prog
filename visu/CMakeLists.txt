set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})
#Configuration de la bibliothèque

file(

        GLOB_RECURSE

        source_files

        ./*

)

add_library(

        visu

        SHARED

        ${source_files}

)

add_executable(launch main.cxx)
target_link_libraries(launch vector visu)
add_test(launch launch)


add_custom_target(simu COMMAND ${CMAKE_CTEST_COMMAND}
                  DEPENDS launch)
