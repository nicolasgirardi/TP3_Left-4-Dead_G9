# Archivo CMakeLists.txt en la carpeta common_libs

# Agrega todos los archivos de código fuente en el directorio actual
file(GLOB COMMON_LIBS_SRC "*.cpp" "*.h")

# Crea una biblioteca a partir de los archivos de código fuente
add_library(CommonLibs ${COMMON_LIBS_SRC})
