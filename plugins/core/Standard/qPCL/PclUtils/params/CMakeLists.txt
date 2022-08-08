target_sources( ${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/FastGlobalRegistrationParams.h
		${CMAKE_CURRENT_LIST_DIR}/NormalEstimationParams.h
)

target_include_directories( ${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)