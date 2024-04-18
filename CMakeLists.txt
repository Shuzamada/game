cmake_minimum_required(VERSION 3.12)

project(MySFMLProject)

set(CMAKE_CXX_STANDARD 11)

# Указываем путь к SFML
set(SFML_DIR "/path/to/SFML")

# Находим SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Автоматически находим все исходные файлы в директории src
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Автоматически находим все заголовочные файлы и добавляем их директории в список директорий для включения
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")
set(INCLUDE_DIRS "")
foreach(_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# Добавляем исполняемый файл
add_executable(MySFMLProject ${SOURCES})

# Связываем SFML с вашим проектом
target_link_libraries(MySFMLProject sfml-graphics sfml-audio)

# Добавляем директории для включения
target_include_directories(MySFMLProject PRIVATE ${INCLUDE_DIRS})

# Добавляем пользовательскую команду для запуска исполняемого файла
add_custom_command(
    TARGET MySFMLProject POST_BUILD
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/MySFMLProject
    COMMENT "Запуск MySFMLProject"
)

# Создаем пользовательский целевой объект для запуска
add_custom_target(run ALL DEPENDS MySFMLProject)
