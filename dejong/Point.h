//
//  Point.h
//  mathtest
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#include "JSONObject.h"
#include <cstdlib>
#include <iostream>

#ifndef mathtest_Point_h
#define mathtest_Point_h

class Point : JSONObject {
    std::string NAME;
    std::string VERSION;
public:
    Point(int x, int y);
    int X;
    int Y;
    virtual std::string toJSON();
};


#endif
