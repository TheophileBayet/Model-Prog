#Déclaration du projet

project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

#Génération de la liste des fichiers sources

file(

        GLOB_RECURSE

        source_files

        src/*

)

file(

        GLOB_RECURSE

        doc_files

        doc/*

)

file(

        GLOB_RECURSE

        test_files

        test/*

)
#Déclaration de l'exécutable du main de src

add_executable(

        ./src/src_exe

        ${source_files}

)

add_executable(

        ./test/test_exe

        ${test_files}

        ./src/Dvector.cpp

)
