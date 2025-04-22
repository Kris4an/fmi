
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "homework1")

target_sources(
    application
    PRIVATE
        "application.cpp"
)