/*-----------------------------------------------------------------
LOG
    GEM - Graphics Environment for Multimedia

    scale a gem object

    Copyright (c) 1997-1999 Mark Danks. mark@danks.org
    Copyright (c) Günther Geiger. geiger@epy.co.at
    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
    For information on usage and redistribution, and for a DISCLAIMER OF ALL
    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_MANIPS_SCALE_H_
#define _INCLUDE__GEM_MANIPS_SCALE_H_

#include "Base/GemBase.h"

/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    scale

    scale a gem object

DESCRIPTION

    Inlet for a list - "vector"
    Inlet for a float - "ft1"

    "vector" - the vector of scale
    "ft1" - the distance

-----------------------------------------------------------------*/
class GEM_EXTERN scale : public GemBase
{
    CPPEXTERN_HEADER(scale, GemBase);

    public:

        //////////
        // Constructor
    	scale(int argc, t_atom *argv);

    protected:

    	//////////
    	// Destructor
    	virtual ~scale();

    	//////////
    	// When rendering occurs
    	virtual void	render(GemState *state);

    	//////////
    	// The translation vector (x, y, z)
    	float	    	m_vector[3];

    	//////////
    	// The scale distance
    	float	    	m_distance;

    	//////////
    	// Distance changed
    	void	    	distanceMess(float distance);

    	//////////
    	// Vector changed
    	void	    	vectorMess(float x, float y, float z);
};

#endif	// for header file
