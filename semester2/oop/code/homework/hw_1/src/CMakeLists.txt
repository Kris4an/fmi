# Sample static library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

target_sources(
    samplelib
    PRIVATE
        "registration_plate.cpp"
        "registration_plate.h"
        "ucn.cpp"
        "ucn.h"
        "vehicle_register.cpp"
        "vehicle_register.h"
)


# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "hw_1")

target_link_libraries(
    application
    PRIVATE
        samplelib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
)