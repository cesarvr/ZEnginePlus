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
#include "zeTile.h"
#include "zeShader.h"
#include "zeImport.h"







class zeRender{
protected:
    zeShader zombiShader;
    

public:
    zeRender();
    void setShader(zeShader shader);
    void cargarShader();
    void draw(zeTile tile);
    void limpiar();
    void volcarBuffer();
    

};


#endif /* defined(__ZEnginePlus__zeRender__) */
