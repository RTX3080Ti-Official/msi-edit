cmake_minimum_required(VERSION 3.10)
project(MsiEdit)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Sphinx)

if(Sphinx_FOUND)
    add_custom_target(docs
        COMMAND ${SPHINX_EXECUTABLE} -b html 
                "${CMAKE_CURRENT_SOURCE_DIR}/Documentation" 
                "${CMAKE_CURRENT_BINARY_DIR}/docs_html"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        COMMENT "Generating HTML documentation with Sphinx"
        VERBATIM
    )
endif()

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui")
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/home.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/menu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/dialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/msi/MsiFile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/msi/reader.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${IMGUI_SOURCES})

if(WIN32)
    target_link_libraries(MsiEdit PRIVATE msi)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${IMGUI_DIR} 
    ${IMGUI_DIR}/backends
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ui
    ${CMAKE_SOURCE_DIR}/include/msi
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw 
    OpenGL::GL
)

target_compile_options(${PROJECT_NAME} PRIVATE 
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wformat=2
    )