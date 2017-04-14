
cmake_minimum_required(VERSION 2.6)

#Configuration du projet

project(Vector)

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})


#Configuration de la bibliothèque

file(

        GLOB_RECURSE

        source_files

        ./*

)

add_library(

        vector

        SHARED

        ${source_files}

)
