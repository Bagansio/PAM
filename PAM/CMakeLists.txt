# CMakeList.txt: proyecto de CMake para PAM, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Agregue un origen al ejecutable de este proyecto.
add_executable (PAM "PAM.cpp" "PAM.h" "Person.cpp" "Person.h" "Scheduler.h" "Scheduler.cpp" "Event.h" "Event.cpp" "EventFather.h" "EventType.h" "States.h")

# TODO: Agregue pruebas y destinos de instalación si es necesario.
