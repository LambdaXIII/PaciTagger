cmake_minimum_required(VERSION 3.14)

project(PaciStringKit LANGUAGES CXX)

set(target_name "PaciStringKit")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/pacistringkit SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/pacistringkit/nodes SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/pacistringkit/factories SRC_FILES)

add_library(${target_name} SHARED
  ${SRC_FILES}
)

target_link_libraries(${target_name}
 Qt${QT_VERSION_MAJOR}::Core
 warlock
 PaciBase
)

target_include_directories(${target_name} PUBLIC ${PROJECT_SOURCE_DIR})
target_compile_definitions(${target_name} PRIVATE DLL_EXPORT)

if(WIN32)
  target_compile_definitions(${target_name} PRIVATE OS_WIN)
endif(WIN32)
