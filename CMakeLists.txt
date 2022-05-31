cmake_minimum_required(VERSION 3.21)
project(Lab_02_PRG2 C)

set(CMAKE_C_STANDARD 17)

add_executable(Lab_2_PRG2 main.c Vehicule.c Vehicule.h Taxe.c Taxe.h Parking.c
        Parking.h Statistique.h Statistique.c AffichageVehicule.c AffichageVehicule.h)
