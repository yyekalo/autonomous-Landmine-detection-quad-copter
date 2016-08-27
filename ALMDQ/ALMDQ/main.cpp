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
    
  
    radio.transmite(1, 120);

    
    while (true) {
        
         radio.transmite(1, 200);
        cout<<200<<endl;
        sleep(5);
        radio.transmite(1,69);
        cout<<69<<endl;
        sleep(5);
        

        
       
    }
    
  
    


    return 0;
}
