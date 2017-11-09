file(
	GLOB _source_files 
	LIST_DIRECTORIES false
	"${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

set(LABFOLDER Lab10)

MESSAGE(${CMAKE_CURRENT_SOURCE_DIR})

foreach(_source IN ITEMS ${_source_files})
	get_filename_component(_source_path "${_source}" PATH)
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	get_filename_component(execName ${_source} NAME_WE)
	MESSAGE(>${execName})
	add_executable("${execName}" "${_source}")

	set_target_properties(${execName} PROPERTIES FOLDER ${LABFOLDER}/${_group_path})
	set_target_properties( ${execName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${LABFOLDER}/${_group_path} )

	if ( MSVC )   
		set_target_properties( ${execName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${LABFOLDER}/${_group_path} )
		set_target_properties( ${execName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${LABFOLDER}/${_group_path} )
	endif ( MSVC )

endforeach()