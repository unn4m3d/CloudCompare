//##########################################################################
//#                                                                        #
//#                    CLOUDCOMPARE PLUGIN: qRANSAC_SD                     #
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
//#                  COPYRIGHT: Daniel Girardeau-Montaut                   #
//#                                                                        #
//##########################################################################

#include "ccRansacSDDlg.h"
#include <vb/field.hpp>

#include <ccOctree.h>

static int    s_minSupport       = 500;		// this is the minimal numer of points required for a primitive
static double s_maxNormalDev_deg = 25.0;	// maximal normal deviation from ideal shape (in degrees)
static double s_probability      = 0.01;	// probability that no better candidate was overlooked during sampling

ccRansacSDDlg::ccRansacSDDlg(QWidget* parent)
	: QDialog(parent, Qt::Tool)
	, Ui::RansacSDDialog()
{
	setupUi(this);

	connect(buttonBox, &QDialogButtonBox::accepted, this, &ccRansacSDDlg::saveSettings);

	supportPointsSpinBox->setValue(s_minSupport);
	maxNormDevAngleSpinBox->setValue(s_maxNormalDev_deg);
	probaDoubleSpinBox->setValue(s_probability);
}

void ccRansacSDDlg::saveSettings()
{
	s_minSupport = supportPointsSpinBox->value();
	s_maxNormalDev_deg = maxNormDevAngleSpinBox->value();
	s_probability = probaDoubleSpinBox->value();
}

void ccRansacSDDlg::apply(const advapi::RANSACParams& p)
{
	using P = advapi::RANSACParams;

	vb::SetterList<P> l;
	vb::addSetter(l, &P::plane, planeCheckBox);
	vb::addSetter(l, &P::sphere, sphereCheckBox);
	vb::addSetter(l, &P::cylinder, cylinderCheckBox);
	vb::addSetter(l, &P::cone, coneCheckBox);
	vb::addSetter(l, &P::torus, torusCheckBox);
	vb::addSetter(l, &P::minSupportPoints, supportPointsSpinBox);
	vb::addSetter(l, &P::maxDistance, epsilonDoubleSpinBox);
	vb::addSetter(l, &P::resolution, bitmapEpsilonDoubleSpinBox);
	vb::addSetter(l, &P::maxDeviation, maxNormDevAngleSpinBox);
	vb::addSetter(l, &P::overlooking, probaDoubleSpinBox);

	vb::addSetter(l, &P::minSphereRadius, minSphereRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::minSphereRadius, minSphereRadiuscheckBox);
	vb::addSetter(l, &P::maxSphereRadius, maxSphereRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::maxSphereRadius, maxSphereRadiuscheckBox);

	vb::addSetter(l, &P::minCylinderRadius, minCylinderRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::minCylinderRadius, minCylinderRadiuscheckBox);
	vb::addSetter(l, &P::maxCylinderRadius, maxCylinderRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::maxCylinderRadius, maxCylinderRadiuscheckBox);

	vb::addSetter(l, &P::minTorusMinorRadius, minTorusMinorRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::minTorusMinorRadius, minTorusMinorRadiuscheckBox);
	vb::addSetter(l, &P::maxTorusMinorRadius, maxTorusMinorRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::maxTorusMinorRadius, maxTorusMinorRadiuscheckBox);


	vb::addSetter(l, &P::minTorusMajorRadius, minTorusMajorRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::minTorusMajorRadius, minTorusMajorRadiuscheckBox);
	vb::addSetter(l, &P::maxTorusMajorRadius, maxTorusMajorRadiusdoubleSpinBox);
	vb::addEnabledCondition(l, &P::maxTorusMajorRadius, maxTorusMajorRadiuscheckBox);
	
	for(auto& s : l) s(p);
}