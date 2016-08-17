//
//  Pctx.cpp
//  ALMDQ
//
//  Created by Yekalo Berhane on 8/14/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#include "Pctx.hpp"


Pctx::Pctx(int Vendoreid,int Productid)
{
    vendorid=Vendoreid;
    
    productid=Productid;
    
    
    buffer[0] = 0;
    buffer[1] = 0;
    buffer[2] = 0;
    buffer[3] = 0;
    buffer[4] = 0;
    buffer[5] = 0;
    buffer[6] = 0;
    buffer[7] = 0;
    buffer[8] = 0;
    buffer[9] = 0;
    buffer[10] = 0;
    buffer[11] = 0;
    buffer[12] = 0;
    buffer[13] = 0;
    buffer[14] = 0;
    buffer[15] = 0;
    buffer[16] = 0;
    buffer[17] = 0;
    buffer[18] = 0;
    buffer[19] = 0;
    buffer[20] = 0;
    buffer[21] = 0;
    buffer[22] = 0;
    buffer[23] = 0;
    buffer[24] = 0;
    buffer[25] = 0;
    buffer[26] = 0;
    buffer[27] = 0;
    buffer[28] = 0;
    buffer[29] = 0;
    buffer[30] = 0;
    buffer[31] = 0;

    
 rawhid_open(1, vendorid, productid , -1, -1);
    
}






Pctx::~Pctx()
{
    rawhid_close(1);
    
}






bool Pctx::transmite(int channel1,int channel2,int channel3,int channel4,int channel5,int channel6,int channel7,int channel8)
{
    buffer[0] = channel1;
    buffer[1] = channel2;
    buffer[2] = channel3;
    buffer[3] = channel4;
    buffer[4] = channel5;
    buffer[5] = channel6;
    buffer[6] = channel7;
    buffer[7] = channel8;
    
    
    return 1==rawhid_send(0, buffer, 32, 200);
}






bool Pctx::transmite(int channel, char value)
{
    buffer[channel-1]=value;
    
    return 1==rawhid_send(0, buffer, 32, 100);
}