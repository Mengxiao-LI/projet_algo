cmake_minimum_required(VERSION 3.26)
project(projet_Mengxiao_Zhengdao C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_Mengxiao_Zhengdao main.c
        echauffement/echauffement.h
        echauffement/echauffement.c
        echauffement/test/testEchauffement.c
        echauffement/test/testEchauffement.h
        tas/tas.h
        tas/tas.c)
