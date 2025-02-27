
if(action == "Colorize"){ Q_EMIT doActionColorize(); return; }
if(action == "SetUniqueColor"){ Q_EMIT doActionSetUniqueColor(); return; }
if(action == "RGBToGreyScale"){ Q_EMIT doActionRGBToGreyScale(); return; }
if(action == "SetColorGradient"){ Q_EMIT doActionSetColorGradient(); return; }
if(action == "ChangeColorLevels"){ Q_EMIT doActionChangeColorLevels(); return; }
if(action == "InterpolateColors"){ Q_EMIT doActionInterpolateColors(); return; }
if(action == "InterpolateScalarFields"){ Q_EMIT doActionInterpolateScalarFields(); return; }
if(action == "EnhanceRGBWithIntensities"){ Q_EMIT doActionEnhanceRGBWithIntensities(); return; }
if(action == "ColorFromScalars"){ Q_EMIT doActionColorFromScalars(); return; }
if(action == "InvertNormals"){ Q_EMIT doActionInvertNormals(); return; }
if(action == "ConvertNormalsToDipDir"){ Q_EMIT doActionConvertNormalsToDipDir(); return; }
if(action == "ConvertNormalsToHSV"){ Q_EMIT doActionConvertNormalsToHSV(); return; }
if(action == "ComputeKdTree"){ Q_EMIT doActionComputeKdTree(); return; }
if(action == "ComputeOctree"){ Q_EMIT doActionComputeOctree(); return; }
if(action == "ResampleWithOctree"){ Q_EMIT doActionResampleWithOctree(); return; }
if(action == "ApplyTransformation"){ Q_EMIT doActionApplyTransformation(); return; }
if(action == "ApplyScale"){ Q_EMIT doActionApplyScale(); return; }
if(action == "EditGlobalShiftAndScale"){ Q_EMIT doActionEditGlobalShiftAndScale(); return; }
if(action == "FlagMeshVertices"){ Q_EMIT doActionFlagMeshVertices(); return; }
if(action == "MeasureMeshVolume"){ Q_EMIT doActionMeasureMeshVolume(); return; }
if(action == "MeasureMeshSurface"){ Q_EMIT doActionMeasureMeshSurface(); return; }
if(action == "ComputeDistancesFromSensor"){ Q_EMIT doActionComputeDistancesFromSensor(); return; }
if(action == "ComputeScatteringAngles"){ Q_EMIT doActionComputeScatteringAngles(); return; }
if(action == "SetViewFromSensor"){ Q_EMIT doActionSetViewFromSensor(); return; }
if(action == "CreateGBLSensor"){ Q_EMIT doActionCreateGBLSensor(); return; }
if(action == "CreateCameraSensor"){ Q_EMIT doActionCreateCameraSensor(); return; }
if(action == "ModifySensor"){ Q_EMIT doActionModifySensor(); return; }
if(action == "ProjectUncertainty"){ Q_EMIT doActionProjectUncertainty(); return; }
if(action == "CheckPointsInsideFrustum"){ Q_EMIT doActionCheckPointsInsideFrustum(); return; }
if(action == "ShowDepthBuffer"){ Q_EMIT doActionShowDepthBuffer(); return; }
if(action == "ExportDepthBuffer"){ Q_EMIT doActionExportDepthBuffer(); return; }
if(action == "ComputePointsVisibility"){ Q_EMIT doActionComputePointsVisibility(); return; }
if(action == "ConvertTextureToColor"){ Q_EMIT doActionConvertTextureToColor(); return; }
if(action == "SamplePointsOnMesh"){ Q_EMIT doActionSamplePointsOnMesh(); return; }
if(action == "SamplePointsOnPolyline"){ Q_EMIT doActionSamplePointsOnPolyline(); return; }
if(action == "SmoohPolyline"){ Q_EMIT doActionSmoohPolyline(); return; }
if(action == "FilterByValue"){ Q_EMIT doActionFilterByValue(); return; }
if(action == "SFConvertToRandomRGB"){ Q_EMIT doActionSFConvertToRandomRGB(); return; }
if(action == "SFConvertToRGB"){ Q_EMIT doActionSFConvertToRGB(); return; }
if(action == "ToggleActiveSFColorScale"){ Q_EMIT doActionToggleActiveSFColorScale(); return; }
if(action == "ShowActiveSFPrevious"){ Q_EMIT doActionShowActiveSFPrevious(); return; }
if(action == "ShowActiveSFNext"){ Q_EMIT doActionShowActiveSFNext(); return; }
if(action == "RenameSF"){ Q_EMIT doActionRenameSF(); return; }
if(action == "OpenColorScalesManager"){ Q_EMIT doActionOpenColorScalesManager(); return; }
if(action == "AddIdField"){ Q_EMIT doActionAddIdField(); return; }
if(action == "SplitCloudUsingSF"){ Q_EMIT doActionSplitCloudUsingSF(); return; }
if(action == "SFGaussianFilter"){ Q_EMIT doActionSFGaussianFilter(); return; }
if(action == "SFBilateralFilter"){ Q_EMIT doActionSFBilateralFilter(); return; }
if(action == "SmoothMeshSF"){ Q_EMIT doActionSmoothMeshSF(); return; }
if(action == "EnhanceMeshSF"){ Q_EMIT doActionEnhanceMeshSF(); return; }
if(action == "SubdivideMesh"){ Q_EMIT doActionSubdivideMesh(); return; }
if(action == "FlipMeshTriangles"){ Q_EMIT doActionFlipMeshTriangles(); return; }
if(action == "SmoothMeshLaplacian"){ Q_EMIT doActionSmoothMeshLaplacian(); return; }
if(action == "Merge"){ Q_EMIT doActionMerge(); return; }
if(action == "Register"){ Q_EMIT doActionRegister(); return; }
if(action == "4pcsRegister"){ Q_EMIT doAction4pcsRegister(); return; }
if(action == "Subsample"){ Q_EMIT doActionSubsample(); return; }
if(action == "StatisticalTest"){ Q_EMIT doActionStatisticalTest(); return; }
if(action == "ComputeStatParams"){ Q_EMIT doActionComputeStatParams(); return; }
if(action == "LabelConnectedComponents"){ Q_EMIT doActionLabelConnectedComponents(); return; }
if(action == "SetSFAsCoord"){ Q_EMIT doActionSetSFAsCoord(); return; }
if(action == "ExportCoordToSF"){ Q_EMIT doActionExportCoordToSF(); return; }
if(action == "ExportNormalToSF"){ Q_EMIT doActionExportNormalToSF(); return; }
if(action == "Rasterize"){ Q_EMIT doActionRasterize(); return; }
if(action == "DeleteScanGrids"){ Q_EMIT doActionDeleteScanGrids(); return; }
if(action == "MeshScanGrids"){ Q_EMIT doActionMeshScanGrids(); return; }
if(action == "ComputeMeshAA"){ Q_EMIT doActionComputeMeshAA(); return; }
if(action == "ComputeMeshLS"){ Q_EMIT doActionComputeMeshLS(); return; }
if(action == "FitQuadric"){ Q_EMIT doActionFitQuadric(); return; }
if(action == "ComputeDistanceMap"){ Q_EMIT doActionComputeDistanceMap(); return; }
if(action == "ComputeDistToBestFitQuadric3D"){ Q_EMIT doActionComputeDistToBestFitQuadric3D(); return; }
if(action == "ComputeCPS"){ Q_EMIT doActionComputeCPS(); return; }
if(action == "ComputeNormals"){ Q_EMIT doActionComputeNormals(); return; }
if(action == "OrientNormalsMST"){ Q_EMIT doActionOrientNormalsMST(); return; }
if(action == "OrientNormalsFM"){ Q_EMIT doActionOrientNormalsFM(); return; }
if(action == "FindBiggestInnerRectangle"){ Q_EMIT doActionFindBiggestInnerRectangle(); return; }
if(action == "MatchBBCenters"){ Q_EMIT doActionMatchBBCenters(); return; }
if(action == "MatchScales"){ Q_EMIT doActionMatchScales(); return; }
if(action == "SORFilter"){ Q_EMIT doActionSORFilter(); return; }
if(action == "FilterNoise"){ Q_EMIT doActionFilterNoise(); return; }
if(action == "Unroll"){ Q_EMIT doActionUnroll(); return; }
if(action == "ResetGUIElementsPos"){ Q_EMIT doActionResetGUIElementsPos(); return; }
if(action == "ResetAllVBOs"){ Q_EMIT doActionResetAllVBOs(); return; }
if(action == "ShowHelpDialog"){ Q_EMIT doActionShowHelpDialog(); return; }
if(action == "RenderToFile"){ Q_EMIT doActionRenderToFile(); return; }
if(action == "EditCamera"){ Q_EMIT doActionEditCamera(); return; }
if(action == "AdjustZoom"){ Q_EMIT doActionAdjustZoom(); return; }
if(action == "SaveViewportAsCamera"){ Q_EMIT doActionSaveViewportAsCamera(); return; }
if(action == "Crop"){ Q_EMIT doActionCrop(); return; }
if(action == "Clone"){ Q_EMIT doActionClone(); return; }
if(action == "AddConstantSF"){ Q_EMIT doActionAddConstantSF(); return; }
if(action == "AddClassificationSF"){ Q_EMIT doActionAddClassificationSF(); return; }
if(action == "ScalarFieldFromColor"){ Q_EMIT doActionScalarFieldFromColor(); return; }
if(action == "ScalarFieldArithmetic"){ Q_EMIT doActionScalarFieldArithmetic(); return; }
if(action == "FitSphere"){ Q_EMIT doActionFitSphere(); return; }
if(action == "FitPlane"){ Q_EMIT doActionFitPlane(); return; }
if(action == "FitFacet"){ Q_EMIT doActionFitFacet(); return; }
if(action == "SFGradient"){ Q_EMIT doActionSFGradient(); return; }
if(action == "CreateCloudFromEntCenters"){ Q_EMIT doActionCreateCloudFromEntCenters(); return; }
if(action == "ComputeBestICPRmsMatrix"){ Q_EMIT doActionComputeBestICPRmsMatrix(); return; }
if(action == "ExportPlaneInfo"){ Q_EMIT doActionExportPlaneInfo(); return; }
if(action == "ExportCloudInfo"){ Q_EMIT doActionExportCloudInfo(); return; }
if(action == "CloudCloudDist"){ Q_EMIT doActionCloudCloudDist(); return; }
if(action == "CloudMeshDist"){ Q_EMIT doActionCloudMeshDist(); return; }
if(action == "CloudPrimitiveDist"){ Q_EMIT doActionCloudPrimitiveDist(); return; }
if(action == "EnableBubbleViewMode"){ Q_EMIT doActionEnableBubbleViewMode(); return; }
if(action == "DeleteShader"){ Q_EMIT doActionDeleteShader(); return; }
if(action == "LoadFile"){ Q_EMIT doActionLoadFile(); return; }
if(action == "SaveFile"){ Q_EMIT doActionSaveFile(); return; }
if(action == "LoadShader"){ Q_EMIT doActionLoadShader(); return; }
if(action == "KMeans"){ Q_EMIT doActionKMeans(); return; }
if(action == "FrontPropagation"){ Q_EMIT doActionFrontPropagation(); return; }
if(action == "GlobalShiftSeetings"){ Q_EMIT doActionGlobalShiftSeetings(); return; }
if(action == "CompressFWFData"){ Q_EMIT doActionCompressFWFData(); return; }
if(action == "ShowWaveDialog"){ Q_EMIT doActionShowWaveDialog(); return; }
if(action == "CreatePlane"){ Q_EMIT doActionCreatePlane(); return; }
if(action == "EditPlane"){ Q_EMIT doActionEditPlane(); return; }
if(action == "FlipPlane"){ Q_EMIT doActionFlipPlane(); return; }
if(action == "ComparePlanes"){ Q_EMIT doActionComparePlanes(); return; }
