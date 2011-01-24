SET(FILE_LIST
#  example1
#  example2
  example3
#  fail1
#  fail2
  test
)

FOREACH (file ${FILE_LIST})
  ADD_EXECUTABLE(${file} ${file}.cpp)
ENDFOREACH (file)
