#pragma once
#include "ccStdPluginInterface.h"
#include <fstream>

class VBasing : public QObject, public ccStdPluginInterface
{
	Q_OBJECT
	Q_INTERFACES( ccPluginInterface ccStdPluginInterface )

	// Replace "Example" by your plugin name (IID should be unique - let's hope your plugin name is unique ;)
	// The info.json file provides information about the plugin to the loading system and
	// it is displayed in the plugin information dialog.
	Q_PLUGIN_METADATA( IID "tech.unn4m3d.VBasing" FILE "../info.json" )

public:
	explicit VBasing( QObject *parent = nullptr );
	~VBasing() override = default;

    void onNewSelection( const ccHObject::Container &selectedEntities ) override;

	QList<QAction *> getActions() override;

private:
	//! Default action
	/** You can add as many actions as you want in a plugin.
		Each action will correspond to an icon in the dedicated
		toolbar and an entry in the plugin menu.
	**/
	std::string getFIFOPath();

	QAction* m_action;
	std::fstream m_io;
};