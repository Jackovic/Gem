/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    diffuse a gem object

    Copyright (c) 1997-1999 Mark Danks. mark@danks.org
    Copyright (c) Günther Geiger. geiger@epy.co.at
    Copyright (c) 2001-2002 IOhannes m zmoelnig. forum::für::umläute. IEM. zmoelnig@iem.kug.ac.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_MANIPS_DIFFUSERGB_H_
#define _INCLUDE__GEM_MANIPS_DIFFUSERGB_H_

#include "Base/GemBase.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    diffuseRGB
    
    diffuse a gem object

DESCRIPTION
    
    Inlet for R - "rVal"
    Inlet for G - "gVal"
    Inlet for B - "bVal"

-----------------------------------------------------------------*/
class GEM_EXTERN diffuseRGB : public GemBase
{
    CPPEXTERN_HEADER(diffuseRGB, GemBase);

    public:

        //////////
        // Constructor
    	diffuseRGB(int argc, t_atom *argv);
    	
    protected:
    	
    	//////////
    	// Destructor
    	virtual ~diffuseRGB();

    	//////////
    	// Turn back on the color material
    	virtual void 	postrender(GemState *state);

    	//////////
    	// When rendering occurs
    	virtual void	render(GemState *state);

    	//////////
    	// The translation vector (r, g, b, a)
    	float	    	m_vector[4];

    	//////////
    	// R value changed
    	void	    	rMess(float val);
    	
    	//////////
    	// G value changed
    	void	    	gMess(float val);
    	
    	//////////
    	// B value changed
    	void	    	bMess(float val);
    	
    	//////////
    	// A value changed
    	void	    	aMess(float val);
    	
    private:
    	
    	//////////
    	// static member functions
    	static void 	rMessCallback(void *data, t_floatarg val);
    	static void 	gMessCallback(void *data, t_floatarg val);
    	static void 	bMessCallback(void *data, t_floatarg val);
    	static void 	aMessCallback(void *data, t_floatarg val);
};

#endif	// for header file
