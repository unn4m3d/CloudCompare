
target_sources( ${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/CCPluginAPI.h
		${CMAKE_CURRENT_LIST_DIR}/ccColorScaleSelector.h
		${CMAKE_CURRENT_LIST_DIR}/ccColorScaleEditorDlg.h
		${CMAKE_CURRENT_LIST_DIR}/ccColorScaleEditorWidget.h
		${CMAKE_CURRENT_LIST_DIR}/ccCommandLineInterface.h
		${CMAKE_CURRENT_LIST_DIR}/ccMainAppInterface.h
		${CMAKE_CURRENT_LIST_DIR}/ccOverlayDialog.h
		${CMAKE_CURRENT_LIST_DIR}/ccPersistentSettings.h
		${CMAKE_CURRENT_LIST_DIR}/ccPickingHub.h
		${CMAKE_CURRENT_LIST_DIR}/ccPickingListener.h
		${CMAKE_CURRENT_LIST_DIR}/ccQtHelpers.h
		${CMAKE_CURRENT_LIST_DIR}/ccRenderToFileDlg.h
		${CMAKE_CURRENT_LIST_DIR}/ccAdvancedAPI.h
		${CMAKE_CURRENT_LIST_DIR}/ccScopeGuard.h
		${CMAKE_CURRENT_LIST_DIR}/ccAdvancedAPISigDecl.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/MeshSampleParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/SORFilterParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/SubsampleParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/AutoOnlyParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/RegisterParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/4pcsRegisterParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/ComputeKdTreeParams.h
		${CMAKE_CURRENT_LIST_DIR}/advapi/ComputeMeshParams.h
)

target_include_directories( ${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
