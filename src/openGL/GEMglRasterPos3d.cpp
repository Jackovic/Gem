////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// Implementation file
//
// Copyright (c) 2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM
//	zmoelnig@iem.kug.ac.at
//  For information on usage and redistribution, and for a DISCLAIMER
//  *  OF ALL WARRANTIES, see the file, "GEM.LICENSE.TERMS"
//
//  this file has been generated...
////////////////////////////////////////////////////////

#include "GEMglRasterPos3d.h"

CPPEXTERN_NEW_WITH_THREE_ARGS ( GEMglRasterPos3d , t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT)

/////////////////////////////////////////////////////////
//
// GEMglViewport
//
/////////////////////////////////////////////////////////
// Constructor
//
GEMglRasterPos3d :: GEMglRasterPos3d	(t_floatarg arg0=0, t_floatarg arg1=0, t_floatarg arg2=0) :
		x((GLdouble)arg0), 
		y((GLdouble)arg1), 
		z((GLdouble)arg2)
{
	m_inlet[0] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("x"));
	m_inlet[1] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("y"));
	m_inlet[2] = inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("z"));
}
/////////////////////////////////////////////////////////
// Destructor
//
GEMglRasterPos3d :: ~GEMglRasterPos3d () {
inlet_free(m_inlet[0]);
inlet_free(m_inlet[1]);
inlet_free(m_inlet[2]);
}

/////////////////////////////////////////////////////////
// Render
//
void GEMglRasterPos3d :: render(GemState *state) {
	glRasterPos3d (x, y, z);
}

/////////////////////////////////////////////////////////
// Variables
//
void GEMglRasterPos3d :: xMess (t_float arg1) {	// FUN
	x = (GLdouble)arg1;
	setModified();
}

void GEMglRasterPos3d :: yMess (t_float arg1) {	// FUN
	y = (GLdouble)arg1;
	setModified();
}

void GEMglRasterPos3d :: zMess (t_float arg1) {	// FUN
	z = (GLdouble)arg1;
	setModified();
}


/////////////////////////////////////////////////////////
// static member functions
//

void GEMglRasterPos3d :: obj_setupCallback(t_class *classPtr) {
	 class_addmethod(classPtr, (t_method)&GEMglRasterPos3d::xMessCallback,  	gensym("x"), A_DEFFLOAT, A_NULL);
	 class_addmethod(classPtr, (t_method)&GEMglRasterPos3d::yMessCallback,  	gensym("y"), A_DEFFLOAT, A_NULL);
	 class_addmethod(classPtr, (t_method)&GEMglRasterPos3d::zMessCallback,  	gensym("z"), A_DEFFLOAT, A_NULL);
};

void GEMglRasterPos3d :: xMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->xMess ( (t_float)    arg0);
}
void GEMglRasterPos3d :: yMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->yMess ( (t_float)    arg0);
}
void GEMglRasterPos3d :: zMessCallback (void* data, t_floatarg arg0){
	GetMyClass(data)->zMess ( (t_float)    arg0);
}
