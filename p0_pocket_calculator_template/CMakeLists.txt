cmake_minimum_required(VERSION 3.16)
project(pocket_calculator)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(GTest REQUIRED)



# Hello world executable.
add_executable(hello_world src/1_hello_world.cpp)

# Go blue executable.
add_executable(go_blue src/2_go_blue.cpp)

# Fight song executable.
add_executable(fight_song src/3_fight_song.cpp)

# Eliza executable.
add_executable(eliza src/4_eliza.cpp)

# Calculator operation executable.
add_executable(calc_op src/5_calc_op.cpp)

# Pocket calculaotr executable.
add_executable(pocket_calculator src/6_pocket_calc.cpp
  src/common/utils.cpp
)
target_include_directories(pocket_calculator PRIVATE
  include
)

# TESTS
enable_testing()

# Public test cases.
add_executable(test_public test/test_public.cpp
  src/common/utils.cpp
)
target_link_libraries(test_public GTest::gtest GTest::gtest_main)
target_include_directories(test_public PRIVATE
  include
  test
)
set_target_properties(test_public PROPERTIES INSTALL_RPATH "@loader_path/../lib:/opt/miniconda3/lib")

# Add individual tests for CTest
add_test(NAME HelloWorld.TestOutput COMMAND test_public --gtest_filter=HelloWorld.TestOutput)
add_test(NAME GoBlue.TestOutput COMMAND test_public --gtest_filter=GoBlue.TestOutput)
add_test(NAME FightSong.TestOutput COMMAND test_public --gtest_filter=FightSong.TestOutput)
add_test(NAME Eliza.TestInputOutput COMMAND test_public --gtest_filter=Eliza.TestInputOutput)
add_test(NAME CalcOp.TestAdd COMMAND test_public --gtest_filter=CalcOp.TestAdd)
add_test(NAME CalcOp.TestSubtract COMMAND test_public --gtest_filter=CalcOp.TestSubtract)
add_test(NAME CalcOp.TestMultiply COMMAND test_public --gtest_filter=CalcOp.TestMultiply)
add_test(NAME CalcOp.TestDivide COMMAND test_public --gtest_filter=CalcOp.TestDivide)
add_test(NAME CalcOp.TestDivideFloat COMMAND test_public --gtest_filter=CalcOp.TestDivideFloat)
add_test(NAME CalcOp.TestDivideByZero COMMAND test_public --gtest_filter=CalcOp.TestDivideByZero)
add_test(NAME CalcOp.TestBadOp COMMAND test_public --gtest_filter=CalcOp.TestBadOp)
add_test(NAME PocketCalculator.TestAddTwoNumbers COMMAND test_public --gtest_filter=PocketCalculator.TestAddTwoNumbers)
add_test(NAME PocketCalculator.TestSubtractTwoNumbers COMMAND test_public --gtest_filter=PocketCalculator.TestSubtractTwoNumbers)
add_test(NAME PocketCalculator.TestMultiplyTwoNumbers COMMAND test_public --gtest_filter=PocketCalculator.TestMultiplyTwoNumbers)
add_test(NAME PocketCalculator.TestDivideTwoNumbers COMMAND test_public --gtest_filter=PocketCalculator.TestDivideTwoNumbers)
add_test(NAME PocketCalculator.TestGetNumber COMMAND test_public --gtest_filter=PocketCalculator.TestGetNumber)
add_test(NAME PocketCalculator.TestGetOperatorBasic COMMAND test_public --gtest_filter=PocketCalculator.TestGetOperatorBasic)
add_test(NAME PocketCalculator.TestGetOperatorPromptUser COMMAND test_public --gtest_filter=PocketCalculator.TestGetOperatorPromptUser)
add_test(NAME PocketCalculator.TestGetOperatorInvalidOp COMMAND test_public --gtest_filter=PocketCalculator.TestGetOperatorInvalidOp)
add_test(NAME PocketCalculator.TestPerformOperation COMMAND test_public --gtest_filter=PocketCalculator.TestPerformOperation)
add_test(NAME PocketCalculator.TestMainBasicOperators COMMAND test_public --gtest_filter=PocketCalculator.TestMainBasicOperators)
add_test(NAME PocketCalculator.TestMainBadOperator COMMAND test_public --gtest_filter=PocketCalculator.TestMainBadOperator)
add_test(NAME PocketCalculator.TestMainDivideByZero COMMAND test_public --gtest_filter=PocketCalculator.TestMainDivideByZero)
add_test(NAME PocketCalculator.TestMainEarlyQuit COMMAND test_public --gtest_filter=PocketCalculator.TestMainEarlyQuit)
add_test(NAME PocketCaculator.TestMainBadOperatorDuplicate COMMAND test_public --gtest_filter=PocketCaculator.TestMainBadOperatorDuplicate)

# Set environment for all tests
set_tests_properties(
  HelloWorld.TestOutput GoBlue.TestOutput FightSong.TestOutput Eliza.TestInputOutput
  CalcOp.TestAdd CalcOp.TestSubtract CalcOp.TestMultiply CalcOp.TestDivide CalcOp.TestDivideFloat CalcOp.TestDivideByZero CalcOp.TestBadOp
  PocketCalculator.TestAddTwoNumbers PocketCalculator.TestSubtractTwoNumbers PocketCalculator.TestMultiplyTwoNumbers PocketCalculator.TestDivideTwoNumbers
  PocketCalculator.TestGetNumber PocketCalculator.TestGetOperatorBasic PocketCalculator.TestGetOperatorPromptUser PocketCalculator.TestGetOperatorInvalidOp
  PocketCalculator.TestPerformOperation PocketCalculator.TestMainBasicOperators PocketCalculator.TestMainBadOperator PocketCalculator.TestMainDivideByZero
  PocketCalculator.TestMainEarlyQuit PocketCaculator.TestMainBadOperatorDuplicate
  PROPERTIES ENVIRONMENT "DYLD_LIBRARY_PATH=/opt/miniconda3/lib"
)
