add_executable(ev_cost_calculator
    main.cc
)

target_include_directories(ev_cost_calculator
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_compile_features(ev_cost_calculator PRIVATE cxx_std_17)
