# CMakeList.txt: проект CMake для YandexSchedules; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("YandexSchedules")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (YandexSchedules "YandexSchedules.cpp" "YandexSchedules.h" "Tools.h" "Tools.cpp" "Webapp.h" "Webapp.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET YandexSchedules PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
include_directories("C:/src/vcpkg/packages/cpp-httplib_x64-windows/include")
include_directories("C:/src/vcpkg/packages/nlohmann-json_x64-windows/include")