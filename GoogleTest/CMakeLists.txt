project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} lib/googlemock/include/)
include_directories("../SynonymTableLib")
add_executable(Google_Tests_run SynonymTableTest.cpp
        WordsListTest.cpp
        WordsListFileReaderTest.cpp
        SynonymTableFileReaderTest.cpp
        WordsListFileWriterTest.cpp)

target_link_libraries(Google_Tests_run
        gtest
        gtest_main
        SynonymTableLib
)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR}/GoogleTest)
