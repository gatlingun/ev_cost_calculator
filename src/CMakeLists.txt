find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ev_cost_calculator
    main.cc
    gui/cost_comparison_window.cc
)

target_include_directories(ev_cost_calculator
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_compile_features(ev_cost_calculator PRIVATE cxx_std_17)

target_link_libraries(ev_cost_calculator PRIVATE Qt6::Widgets)
