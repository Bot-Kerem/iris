project(stb LANGUAGES C)

add_library(stb include/stb/stb_image.h)

target_include_directories(stb PUBLIC include)
set_target_properties(stb PROPERTIES LINKER_LANGUAGE C)

