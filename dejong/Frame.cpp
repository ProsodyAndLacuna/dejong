//
//  Frame.cpp
//  mathtest
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#include "Frame.h"
#include "Point.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

Frame::Frame(int imagesize)
{
    image_size = imagesize;
    NAME = "Frame";
    VERSION = "1.0";
    sensitivity = 0.017;
}

string Frame::pixels_to_json( int pixels[][1024], int size )
{
    std::stringstream ss;
    ss << '[';
    for (int i = 0; i < size; i++) {
        ss << '[';
        for (int j = 0; j < size; j++) {
            ss << pixels[i][j];
            if ( j != size - 1 )
            {
                ss << ',';
            }
        }
        ss << ']';
        if ( i != size - 1 )
        {
            ss << ',';
        }
    }
    ss << ']';
    return ss.str();
}

string Frame::to_filename()
{
    return "dejong-" + to_string(image_size) + "-" + to_string( start->X ) + "-" + to_string( start->Y ) + ".json";
}

string Frame::toJSON()
{
    return "{\"klass\":{\"name\":\"" + NAME + "\",\"version\":\"" + VERSION + "\"}," +
            "\"start\":" + start->toJSON() + "," +
            "\"current\":" + current->toJSON() + "," +
            "\"sensitivity\":" + to_string(sensitivity) + "," +
            "\"image_size\":" + to_string(image_size) + "," +
            "\"pixels\":" + pixels_to_json( pixels, image_size ) + "}";
}