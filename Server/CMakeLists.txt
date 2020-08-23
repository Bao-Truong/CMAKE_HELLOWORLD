
file(GLOB ChatServers_Header
    "./Headers/*.h"
)
file(GLOB ChatServer_Source
    "./src/*.cpp"
)

add_library(
    ChatServer SHARED
    ${ChatServer_Source}
    ${ChatServers_Header}
)
target_include_directories(ChatServer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

add_executable(server main.cpp )

target_link_libraries(server PRIVATE ChatServer cpprestsdk::cpprest)