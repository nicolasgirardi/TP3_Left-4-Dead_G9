cmake_minimum_required(VERSION 3.0)
project(TuProyecto)

# Agrega las carpetas y archivos fuente de tu proyecto
file(GLOB_RECURSE COMMON_LBS_SOURCES "common_lbs/*.cpp")
file(GLOB_RECURSE SERVER_MODELO_SOURCES "server_modelo/*.cpp")
file(GLOB_RECURSE SERVER_START_SOURCES "server_start/*.cpp")

# Agrega todas las fuentes en un solo conjunto
set(ALL_SOURCES
    ${COMMON_LBS_SOURCES}
    ${SERVER_MODELO_SOURCES}
    ${SERVER_START_SOURCES}
)

# Genera los archivos objeto (*.o)
foreach(source_file ${ALL_SOURCES})
    get_filename_component(base_name ${source_file} NAME_WE)
    set(obj_file "${CMAKE_CURRENT_BINARY_DIR}/${base_name}.o")
    add_library(${base_name} OBJECT ${source_file})
    set_property(TARGET ${base_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
    set_property(TARGET ${base_name} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    list(APPEND OBJECT_FILES $<TARGET_OBJECTS:${base_name}>)
endforeach()

# Configura la compilación de tu proyecto con los archivos objeto generados y crea el ejecutable
add_executable(TuEjecutable server_start/server_main.cpp ${OBJECT_FILES})

# Configura opciones o enlaces de bibliotecas adicionales si es necesario
# ...

# Por ejemplo, si necesitas enlazar con la biblioteca Math en tu sistema:
# target_link_libraries(TuEjecutable m)

