# find_package(raylib 5.5 REQUIRED)
include_directories(${PROJECT_NAME}/src)

file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)