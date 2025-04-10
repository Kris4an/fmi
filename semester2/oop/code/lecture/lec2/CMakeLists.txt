cmake_minimum_required (VERSION 3.13)

project ("Simple CMake Template" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
#
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)


# Library target for the sample library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

add_executable(application)

target_sources(
	samplelib
	PRIVATE
		"main.cpp"
		"libarary.cpp"
)


# Executable target for the application

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")


