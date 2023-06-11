cmake_minimum_required(VERSION 3.16.3) 

project(LEFT4DEAD)

# Agrega los directorios de las carpetas que contienen los archivos de código fuente
add_subdirectory(common_libs)
add_subdirectory(server_modelo)
add_subdirectory(server_start)

# Agrega todos los archivos de código fuente de las carpetas especificadas
file(GLOB COMMON_LIBS_SRC "common_libs/*.cpp" "common_libs/*.h")
file(GLOB SERVER_MODELO_SRC "server_modelo/*.cpp" "server_modelo/*.h")
file(GLOB SERVER_START_SRC "server_start/*.cpp" "server_start/*.h")
file(GLOB SERVER_EVENTOS_SRC "server_eventos/*.cpp" "server_eventos/*.h")
# Agrega los archivos de código fuente a tu ejecutable
add_executable(server
    ${COMMON_LIBS_SRC}
    ${SERVER_MODELO_SRC}
    ${SERVER_START_SRC}
    ${SERVER_EVENTOS_SRC}
)