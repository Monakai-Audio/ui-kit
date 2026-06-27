cmake_minimum_required(VERSION 3.22)
project(monakai-ui-kit VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        7.0.12
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(JUCE)

add_library(monakai-ui-kit STATIC
    src/Knob.cpp
    src/Slider.cpp
    src/Meter.cpp
    src/WaveformDisplay.cpp
)

target_include_directories(monakai-ui-kit
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_definitions(monakai-ui-kit
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(monakai-ui-kit
    PUBLIC
        juce::juce_gui_basics
        juce::juce_graphics
        juce::juce_audio_basics
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

option(UI_KIT_BUILD_DEMO "Build ui-kit demo" OFF)
if(UI_KIT_BUILD_DEMO)
    add_subdirectory(demo)
endif()
