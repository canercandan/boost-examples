CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

FIND_PACKAGE(Boost 1.42 COMPONENTS python)
FIND_PACKAGE(PythonLibs)

IF(Boost_FOUND)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})

LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

SET(FILE_LIST
  hello_ext
)

FOREACH(current ${FILE_LIST})
  ADD_LIBRARY(${current} SHARED ${current}.cpp)
  TARGET_LINK_LIBRARIES(${current} ${PYTHON_LIBRARY} ${Boost_LIBRARIES})
ENDFOREACH(current)

ENDIF()
