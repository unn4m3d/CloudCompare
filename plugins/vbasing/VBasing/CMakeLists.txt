project( VBasing )
include_directories(${CMAKE_CURRENT_LIST_DIR}/../../../qCC/)
	 
AddPlugin( NAME ${PROJECT_NAME} )
    
add_subdirectory( include )
add_subdirectory( src )