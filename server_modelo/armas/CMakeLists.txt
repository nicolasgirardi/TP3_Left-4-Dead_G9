# Archivo CMakeLists.txt en la carpeta common_libs

# Agrega todos los archivos de código fuente en el directorio actual
file(GLOB SERVER_WEAPON_SRC
    "*.h"
    "*.cpp"
)

# Crea una biblioteca a partir de los archivos de código fuente
add_library(SercerWeapon ${SERVER_WEAPON_SRC})