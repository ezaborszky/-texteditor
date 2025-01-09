add_executable(text-editor main.cpp text.cpp site.cpp utilites.cpp)
target_link_libraries(text-editor PRIVATE ImGui-SFML::ImGui-SFML)
