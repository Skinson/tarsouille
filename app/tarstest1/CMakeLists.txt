# CMakeList.txt : projet CMake pour tarstest1, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (tarstest1 "tarstest1.cpp" "tarstest1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tarstest1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
target_link_libraries(
    tarstest1
)