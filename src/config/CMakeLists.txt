cmake_minimum_required(VERSION 3.16)

set(lib_name config)

# 1. Definimos la librería como INTERFACE (Header-only)
add_library(${lib_name} INTERFACE)

# 2. Exponemos la carpeta actual para los Includes
target_include_directories(${lib_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# 3. Buscamos el paquete de Threads del sistema (pthreads en Linux)
find_package(Threads REQUIRED)

# 4. Vinculamos Threads a la interfaz para que cualquier ejecutable que use 
# esta librería también herede la configuración de hilos automáticamente.
target_link_libraries(${lib_name} INTERFACE Threads::Threads)