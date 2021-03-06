/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    color a gem object

    Copyright (c) 1997-1999 Mark Danks. mark@danks.org
    Copyright (c) Günther Geiger. geiger@epy.co.at
    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_MANIPS_COLORRGB_H_
#define _INCLUDE__GEM_MANIPS_COLORRGB_H_

#include "Base/GemBase.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    colorRGB

    color a gem object

DESCRIPTION

    Inlet for R - "rVal"
    Inlet for G - "gVal"
    Inlet for B - "bVal"

-----------------------------------------------------------------*/
class GEM_EXTERN colorRGB : public GemBase
{
    CPPEXTERN_HEADER(colorRGB, GemBase);

    public:

        //////////
        // Constructor
    	colorRGB(int argc, t_atom *argv);

    protected:

    	//////////
    	// Destructor
    	virtual ~colorRGB();

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
};

#endif	// for header file
