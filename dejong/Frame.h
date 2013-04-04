//
//  Frame.h
//  mathtest
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#include "Point.h"
#include "JSONObject.h"
#include <cstdlib>
#include <iostream>

#ifndef mathtest_Frame_h
#define mathtest_Frame_h

class Frame : JSONObject {
    std::string NAME;
    std::string VERSION;
    
    std::string pixels_to_json( int pixels[][1024], int size );
public:
    static const int DEFAULT_IMAGE_SIZE = 1024;
    
    Frame(int image_size);
    Point* start;
    Point* current;
    double sensitivity;
    int image_size;
    int pixels[DEFAULT_IMAGE_SIZE][DEFAULT_IMAGE_SIZE];
    
    virtual std::string toJSON();
    
    std::string to_filename();
};


#endif
