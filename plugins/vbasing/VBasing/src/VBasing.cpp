#include <QtGui>

#include "VBasing.hpp"
#include <mainwindow.h>
#include "json.hpp"
#include <ccGenericPointCloud.h>
// Default constructor:
//	- pass the Qt resource path to the info.json file (from <yourPluginName>.qrc file) 
//  - constructor should mainly be used to initialize actions and other members

template<typename T>
static nlohmann::json matrixToJson(const T& mat)
{

}

VBasing::VBasing( QObject *parent )
	: QObject( parent )
	, ccStdPluginInterface( ":/CC/plugin/VBasing/info.json" )
	, m_io(getFIFOPath())
{
	auto window = MainWindow::TheInstance();
	connect(window, &MainWindow::onRegistrationSuccess, this, [this](const ccGenericPointCloud* cloud, const ccGLMatrix& mat){
		nlohmann::json j;
		j["name"] = cloud->getName().toStdString();
		j["regMat"] = matrixToJson(mat);
		if(cloud)
			j["absMat"] = matrixToJson(cloud->getGLTransformationHistory());
		m_io << j.dump() << std::endl;
		getMainAppInterface()->dispToConsole( QString("onRegistrationSuccess finished, man"), ccMainAppInterface::STD_CONSOLE_MESSAGE );
	});
}

// This method should enable or disable your plugin actions
// depending on the currently selected entities ('selectedEntities').
void VBasing::onNewSelection( const ccHObject::Container &selectedEntities )
{
    getMainAppInterface()->dispToConsole( QString("Selection: %1").arg(selectedEntities.size()), ccMainAppInterface::STD_CONSOLE_MESSAGE );
}

// This method returns all the 'actions' your plugin can perform.
// getActions() will be called only once, when plugin is loaded.
QList<QAction *> VBasing::getActions()
{
	return QList<QAction*>();
}

std::string VBasing::getFIFOPath()
{
	auto envpath = getenv("VBASING_FIFO_PATH");

	if(envpath) return envpath;
	else return "/var/vbasing.fifo";
}