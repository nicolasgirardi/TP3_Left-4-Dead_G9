# Archivo CMakeLists.txt en la carpeta common_libs

# Agrega todos los archivos de código fuente en el directorio actual
file(GLOB_RECURSE SERVER_MODELO_SRC
    "*.h"
    "*.cpp"
)

# Crea una biblioteca a partir de los archivos de código fuente
add_library(SercerModelo ${SERVER_MODELO_SRC})
