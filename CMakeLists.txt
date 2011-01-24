FIND_PACKAGE(Boost 1.33.0 COMPONENTS program_options)

IF(Boost_FOUND)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

ADD_SUBDIRECTORY(spirit)
ADD_SUBDIRECTORY(static_assert)

SET(FILE_LIST
  dynamic_bitset
  lambda
  program_options
  #python
  split
  iter_split
  timer
  tribool
  tuple
  ublas_matrix
  ublas_matrix_diagonal
  ublas_vector
  ublas_vector_expression
  ublas_vector_operator
  variant
  atlas
  #median
)

FOREACH(current ${FILE_LIST})
  ADD_EXECUTABLE(${current} ${current}.cpp)
  TARGET_LINK_LIBRARIES(${current} ${Boost_LIBRARIES})
ENDFOREACH(current)

ENDIF()
