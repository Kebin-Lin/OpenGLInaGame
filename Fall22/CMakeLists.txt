set(SOURCE_FILES
    Fall22.cpp
)
set(HEADER_FILES

)

add_executable(FinalGame ${SOURCE_FILES} ${HEADER_FILES})
include_directories(../Foundry)
target_link_libraries(FinalGame Foundry)