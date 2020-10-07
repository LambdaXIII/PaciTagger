cmake_minimum_required (VERSION 3.14)

project (PaciTagger)



add_subdirectory(${CMAKE_SOURCE_DIR}/PaciDeps)
add_subdirectory(${CMAKE_SOURCE_DIR}/Tagger)
add_subdirectory(${CMAKE_SOURCE_DIR}/PaciStringKit)


#list(APPEND QML_DIRS "${QML_IMPORT_PATH}")
list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/deps/QoolUI/src")
list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/src/lib/PaciFontDesigner")
list(APPEND QML_DIRS "${CMAKE_SOURCE_DIR}/Tagger")
set(QML_IMPORT_PATH ${QML_DIRS} CACHE STRING "Creator qml path")
