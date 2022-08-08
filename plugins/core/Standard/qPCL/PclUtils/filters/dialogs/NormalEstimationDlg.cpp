//##########################################################################
//#                                                                        #
//#                       CLOUDCOMPARE PLUGIN: qPCL                        #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 or later of the License.      #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                         COPYRIGHT: Luca Penasa                         #
//#                                                                        #
//##########################################################################
//
#include "NormalEstimationDlg.h"

NormalEstimationDialog::NormalEstimationDialog(QWidget* parent)
	: QDialog(parent)
	, Ui::NormalEstimationDialog()
{
	setupUi(this);
}

void NormalEstimationDialog::apply(const advapi::NormalEstimationParams& p)
{
	using P = advapi::NormalEstimationParams;

	vb::SetterList<P> l;

	vb::addSetter(l, &P::radius, radiusDoubleSpinBox);
	vb::addSetter(l, &P::useKnn, useKnnCheckBox);
	vb::addSetter(l, &P::knnRadius, knnSpinBox);
	vb::addSetter(l, &P::overwriteCurvature, curvatureCheckBox);

	for(auto& s : l) s(p);
}