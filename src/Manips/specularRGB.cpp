////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-1999 Mark Danks.
//    Copyright (c) G�nther Geiger.
//    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::f�r::uml�ute. IEM
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////

// 1307:forum::f�r::uml�ute:20000

#include "specularRGB.h"
#include "Base/GemException.h"

CPPEXTERN_NEW_WITH_GIMME(specularRGB)

/////////////////////////////////////////////////////////
//
// specularRGB
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
specularRGB :: specularRGB(int argc, t_atom *argv)
{
    if (argc == 4)
    {
        m_vector[0] = atom_getfloat(&argv[0]);
        m_vector[1] = atom_getfloat(&argv[1]);
        m_vector[2] = atom_getfloat(&argv[2]);
        m_vector[3] = atom_getfloat(&argv[3]);
    }
    else if (argc == 3)
    {
        m_vector[0] = atom_getfloat(&argv[0]);
        m_vector[1] = atom_getfloat(&argv[1]);
        m_vector[2] = atom_getfloat(&argv[2]);
        m_vector[3] = 1.f;
    }
    else if (argc == 0)
    {
        m_vector[0] = 0.f;
        m_vector[1] = 0.f;
        m_vector[2] = 0.f;
        m_vector[3] = 1.f;
    }
    else
    {
      throw(GemException("needs 0, 3 or 4 arguments"));
    }

    // create the new inlets
    inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("rVal"));
    inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("gVal"));
    inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("bVal"));
    inlet_new(this->x_obj, &this->x_obj->ob_pd, &s_float, gensym("aVal"));
}

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
specularRGB :: ~specularRGB()
{ }

/////////////////////////////////////////////////////////
// postrender
//
/////////////////////////////////////////////////////////
void specularRGB :: postrender(GemState *)
{
	glEnable(GL_COLOR_MATERIAL);
}

/////////////////////////////////////////////////////////
// render
//
/////////////////////////////////////////////////////////
void specularRGB :: render(GemState *)
{
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m_vector);
}

/////////////////////////////////////////////////////////
// rMess
//
/////////////////////////////////////////////////////////
void specularRGB :: rMess(float val)
{
    m_vector[0] = val;
    setModified();
}

/////////////////////////////////////////////////////////
// gMess
//
/////////////////////////////////////////////////////////
void specularRGB :: gMess(float val)
{
    m_vector[1] = val;
    setModified();
}

/////////////////////////////////////////////////////////
// bMess
//
/////////////////////////////////////////////////////////
void specularRGB :: bMess(float val)
{
    m_vector[2] = val;
    setModified();
}

/////////////////////////////////////////////////////////
// aMess
//
/////////////////////////////////////////////////////////
void specularRGB :: aMess(float val)
{
    m_vector[3] = val;
    setModified();
}

/////////////////////////////////////////////////////////
// static member function
//
/////////////////////////////////////////////////////////
void specularRGB :: obj_setupCallback(t_class *classPtr)
{
    class_addmethod(classPtr, reinterpret_cast<t_method>(&specularRGB::rMessCallback),
    	    gensym("rVal"), A_FLOAT, A_NULL); 
    class_addmethod(classPtr, reinterpret_cast<t_method>(&specularRGB::gMessCallback),
    	    gensym("gVal"), A_FLOAT, A_NULL); 
    class_addmethod(classPtr, reinterpret_cast<t_method>(&specularRGB::bMessCallback),
    	    gensym("bVal"), A_FLOAT, A_NULL); 
    class_addmethod(classPtr, reinterpret_cast<t_method>(&specularRGB::aMessCallback),
    	    gensym("aVal"), A_FLOAT, A_NULL); 
}
void specularRGB :: rMessCallback(void *data, t_floatarg val)
{
    GetMyClass(data)->rMess((float)val);
}
void specularRGB :: gMessCallback(void *data, t_floatarg val)
{
    GetMyClass(data)->gMess((float)val);
}
void specularRGB :: bMessCallback(void *data, t_floatarg val)
{
    GetMyClass(data)->bMess((float)val);
}
void specularRGB :: aMessCallback(void *data, t_floatarg val)
{
    GetMyClass(data)->aMess((float)val);
}
