cmake_minimum_required(VERSION 3.16)

project(color_detect)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)
find_package(fmt)
find_package(glog 0.6.0 REQUIRED)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC1)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/detect/src SRC2)
set(SRC ${SRC1} ${SRC2})

set(${EXECUTABLE_OUTPUT_PATH} /home/Desktop/color_detect)
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/detect/include)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${OpenCV_LIBS} 
        fmt::fmt 
        glog::glog)