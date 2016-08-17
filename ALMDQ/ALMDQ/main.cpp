//
//  main.cpp
//  ALMDQ
//
//  Created by Yekalo Berhane on 8/14/16.
//  Copyright © 2016 Yikealo Abraha. All rights reserved.
//

#include <iostream>
#include "Pctx.hpp"
#include <unistd.h>
using namespace std;
#include "hid.h"


int main() {
    
    Pctx radio;
    
    
    char buffer[32];
    
    buffer[0] = 128;
    buffer[1] = 128;
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
//    buffer[25] = 0;
//    buffer[26] = 0;
//    buffer[27] = 0;
//    buffer[28] = 0;
//    buffer[29] = 0;
//    buffer[30] = 0;
//    buffer[31] = 0;
    
    
    int counter=0;
    rawhid_open(1, 0x0925, 0x1299, -1, -1);
    
    radio.transmite(1, 120);

    
    while (true) {
        
        int max=190;
        int min=66;
        
         cout<<"here begin"<<endl;
        for (int h=min; h<max; h++) {
            buffer[5]=h;
            rawhid_send(0, buffer, 32, 1000);
            cout<<h<<endl;
        }
        
        
        for (int h=max; h>min; h--) {
            buffer[5]=h;
            rawhid_send(0, buffer, 32, 1000);
            cout<<h<<endl;
        }
        
        cout<<"here"<<endl;
        
 
    }
    


    return 0;
}
