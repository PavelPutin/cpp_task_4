cmake_minimum_required(VERSION 3.27)

set(HEADER_FILES SynonymTable.h)
set(SOURCE_FILES SynonymTable.cpp)

add_library(SynonymTableLib STATIC ${HEADER_FILES} ${SOURCE_FILES})