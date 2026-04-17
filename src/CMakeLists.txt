
set(app_name cxx_app)
message("App name: " ${app_name})

add_subdirectory(config)

add_executable (${app_name} main.cpp)
target_link_libraries(${app_name} config)