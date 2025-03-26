cmake_minimum_required (VERSION 2.8...3.10)

set(This BowlingGameTests)
set(Sources
    BowlingGameTests.cpp
)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    BowlingGame
)
add_test(
    NAME ${This}
    COMMAND ${This}
)