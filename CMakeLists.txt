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

add_executable(filebinomialeComplexite
        main_File_Binomiale.c
        fileBinomiale/filebinomiale.c
        fileBinomiale/filebinomiale.h
        echauffement/echauffement.h
        echauffement/echauffement.c
)

add_executable(filebinomialeKey128
        main_File_BinomialeKey128.c
        fileBinomiale/filebinomiale.c
        fileBinomiale/filebinomiale.h
        echauffement/echauffement.h
        echauffement/echauffement.c
)
add_executable(filebinomialeINTSimple
        main_File_BinomialeINTSimple.c
        fileBinomialeINT/filebinomiale.c
        fileBinomialeINT/filebinomiale.h
        echauffement/echauffement.h
        echauffement/echauffement.c
)

add_executable(md5
        main_MD5.c
        hachage/md5.h
        hachage/md5.c
)

add_executable(main_Tas_Min main_TasMin.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        tas/tas.h
        tas/tas.c
        tas/list.h
        tas/list.c


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


add_executable(test main_test.c
        tas/test.h
        tas/test.c
        echauffement/echauffement.h
        echauffement/echauffement.c)

add_executable(arbreBR
        main_ABR.c
        arbreBR/arbreBR.h
        echauffement/echauffement.h
        echauffement/echauffement.c
        arbreBR/arbreBR.c
        )
add_executable(question6 main_Q6.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        arbreBR/arbreBR.h
        arbreBR/arbreBR.c
        experimentale/experimentale.c
        experimentale/experimentale.h
        fileBinomiale/filebinomiale.c
        fileBinomiale/filebinomiale.h
        hachage/md5.c
        hachage/md5.h
        tas/tas.h
        tas/tas.c
        tas/tasArbre.c
        tas/tasArbre.h

)
