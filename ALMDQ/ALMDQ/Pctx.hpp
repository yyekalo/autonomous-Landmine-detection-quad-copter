//
//  Pctx.hpp
//  ALMDQ
//
//  Created by Yekalo Berhane on 8/14/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#ifndef Pctx_hpp
#define Pctx_hpp
extern "C" {
#include "hid.h"
    
}

#include <stdio.h>


class Pctx
{
public:
    
    Pctx(int Vendoreid=0x0925,int productid=0x1299);
    
    ~Pctx();
    
    bool transmite(int channel1,int channel2,int channel3,int channel4,int channel5,int channel6,int channel7,int channel8);
    
    bool transmite(int channel, char value);
    
    
private:
    
    int productid;
    
    int vendorid;
    
     char buffer[32];
    
    
    
    

    
    
    
    
    
    
    
    
    
    
};

#endif /* Pctx_hpp */
