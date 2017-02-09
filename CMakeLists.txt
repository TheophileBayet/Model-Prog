#Déclaration du projet

project(lab1)



#Génération de la liste des fichiers sources

file(

        GLOB_RECURSE

        source_files

        src/*

)



#Déclaration de l'exécutable

add_executable(

        my_exe

        ${source_files}

)
