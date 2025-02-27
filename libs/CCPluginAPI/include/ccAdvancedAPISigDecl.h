#pragma once
#include <QObject>

class CCPLUGIN_LIB_API ccAdvancedAPISigDecl : public QObject
{
    Q_OBJECT
public:
    ccAdvancedAPISigDecl(QObject* parent = nullptr) : QObject(parent){}
Q_SIGNALS:
    void doActionColorize();
    void doActionSetUniqueColor();
    void doActionRGBToGreyScale();
    void doActionSetColorGradient();
    void doActionChangeColorLevels();
    void doActionInterpolateColors();
    void doActionInterpolateScalarFields();
    void doActionEnhanceRGBWithIntensities();
    void doActionColorFromScalars();
    void doActionInvertNormals();
    void doActionConvertNormalsToDipDir();
    void doActionConvertNormalsToHSV();
    void doActionComputeKdTree();
    void doActionComputeOctree();
    void doActionResampleWithOctree();
    void doActionApplyTransformation();
    void doActionApplyScale();
    void doActionEditGlobalShiftAndScale();
    void doActionFlagMeshVertices();
    void doActionMeasureMeshVolume();
    void doActionMeasureMeshSurface();
    void doActionComputeDistancesFromSensor();
    void doActionComputeScatteringAngles();
    void doActionSetViewFromSensor();
    void doActionCreateGBLSensor();
    void doActionCreateCameraSensor();
    void doActionModifySensor();
    void doActionProjectUncertainty();
    void doActionCheckPointsInsideFrustum();
    void doActionShowDepthBuffer();
    void doActionExportDepthBuffer();
    void doActionComputePointsVisibility();
    void doActionConvertTextureToColor();
    void doActionSamplePointsOnMesh();
    void doActionSamplePointsOnPolyline();
    void doActionSmoohPolyline();
    void doActionFilterByValue();
    void doActionSFConvertToRandomRGB();
    void doActionSFConvertToRGB();
    void doActionToggleActiveSFColorScale();
    void doActionShowActiveSFPrevious();
    void doActionShowActiveSFNext();
    void doActionRenameSF();
    void doActionOpenColorScalesManager();
    void doActionAddIdField();
    void doActionSplitCloudUsingSF();
    void doActionSFGaussianFilter();
    void doActionSFBilateralFilter();
    void doActionSmoothMeshSF();
    void doActionEnhanceMeshSF();
    void doActionSubdivideMesh();
    void doActionFlipMeshTriangles();
    void doActionSmoothMeshLaplacian();
    void doActionMerge();
    void doActionRegister();
    void doAction4pcsRegister();
    void doActionSubsample();
    void doActionStatisticalTest();
    void doActionComputeStatParams();
    void doActionLabelConnectedComponents();
    void doActionSetSFAsCoord();
    void doActionExportCoordToSF();
    void doActionExportNormalToSF();
    void doActionRasterize();
    void doActionDeleteScanGrids();
    void doActionMeshScanGrids();
    void doActionComputeMeshAA();
    void doActionComputeMeshLS();
    void doActionFitQuadric();
    void doActionComputeDistanceMap();
    void doActionComputeDistToBestFitQuadric3D();
    void doActionComputeCPS();
    void doActionComputeNormals();
    void doActionOrientNormalsMST();
    void doActionOrientNormalsFM();
    void doActionFindBiggestInnerRectangle();
    void doActionMatchBBCenters();
    void doActionMatchScales();
    void doActionSORFilter();
    void doActionFilterNoise();
    void doActionUnroll();
    void doActionResetGUIElementsPos();
    void doActionResetAllVBOs();
    void doActionShowHelpDialog();
    void doActionRenderToFile();
    void doActionEditCamera();
    void doActionAdjustZoom();
    void doActionSaveViewportAsCamera();
    void doActionCrop();
    void doActionClone();
    void doActionAddConstantSF();
    void doActionAddClassificationSF();
    void doActionScalarFieldFromColor();
    void doActionScalarFieldArithmetic();
    void doActionFitSphere();
    void doActionFitPlane();
    void doActionFitFacet();
    void doActionSFGradient();
    void doActionCreateCloudFromEntCenters();
    void doActionComputeBestICPRmsMatrix();
    void doActionExportPlaneInfo();
    void doActionExportCloudInfo();
    void doActionCloudCloudDist();
    void doActionCloudMeshDist();
    void doActionCloudPrimitiveDist();
    void doActionEnableBubbleViewMode();
    void doActionDeleteShader();
    void doActionLoadFile();
    void doActionSaveFile();
    void doActionLoadShader();
    void doActionKMeans();
    void doActionFrontPropagation();
    void doActionGlobalShiftSeetings();
    void doActionCompressFWFData();
    void doActionShowWaveDialog();
    void doActionCreatePlane();
    void doActionEditPlane();
    void doActionFlipPlane();
    void doActionComparePlanes();
};
