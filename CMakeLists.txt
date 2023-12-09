cmake_minimum_required(VERSION 3.26)
project(projet_Mengxiao_Zhengdao C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_Mengxiao_Zhengdao main.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        echauffement/test/testEchauffement.c
        echauffement/test/testEchauffement.h
        tas/tas.h
        tas/tas.c
        tas/list.h
        tas/list.c)

add_executable(filebinomiale
        main_File_Binomiale.c
        fileBinomiale/filebinomiale.c
        fileBinomiale/filebinomiale.h

)
add_executable(main_Tas_Min main_TasMin.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        tas/tas.h
        tas/tas.c
        tas/list.h
        tas/list.c
        tas/tasArbre.c
        tas/tasArbre.h
)
add_executable(Tas_Q8Q9 main_Tas_Q89.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        tas/tas.h
        tas/tas.c
        tas/list.h
        tas/list.c
        tas/tasArbre.c
        tas/tasArbre.h
)
