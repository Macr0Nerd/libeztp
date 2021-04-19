#Adding in the source files
target_sources(libeztp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/armor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/background.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dice.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/race.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/weapons.cpp
)