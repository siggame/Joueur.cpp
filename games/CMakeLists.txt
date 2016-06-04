#get a list of all the subdirectories
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)
set(dirlist "")
foreach(child ${children})
   if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
      list(APPEND dirlist ${child})
   endif()
endforeach()

foreach(dir ${dirlist})
   add_subdirectory(${dir})
endforeach()

set(FILES
    ${FILES}
    PARENT_SCOPE)
