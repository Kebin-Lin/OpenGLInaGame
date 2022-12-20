set(SOURCE_FILES
    Fall22.cpp
    Anim.cpp
    Entity.cpp
)
set(HEADER_FILES
    Anim.h
    Entity.h
)

add_executable(FinalGame ${SOURCE_FILES} ${HEADER_FILES})
include_directories(../Foundry)
target_link_libraries(FinalGame Foundry)