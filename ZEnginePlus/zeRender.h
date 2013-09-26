//
//  zeRender.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeRender__
#define __ZEnginePlus__zeRender__

#include <iostream>
#include "zeShader.h"
#include "zeImport.h"
#include "zeSuperficieDib.h"
#include "zeVoxel.h"





class zeRender{
protected:
    zeShader zombiShader;
    

public:
    zeRender();
    void    setShader       (zeShader shader);
    void    cargarShader    ();

    void    draw            (zeSuperficie superficie);
    void    draw            (zeVoxel superficie);
  
    void    limpiar         ();
    void    volcarBuffer    ();


};


#endif /* defined(__ZEnginePlus__zeRender__) */
