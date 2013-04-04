//
//  Point.cpp
//  mathtest
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#include "Point.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

Point::Point(int x, int y)
{
    NAME = "Point";
    VERSION = "1.0";
    X = x;
    Y = y;
}

string Point::toJSON()
{
    return "\"{\\\"klass\\\":{\\\"name\\\":\\\"" + NAME + "\\\",\\\"version\\\":\\\"" + VERSION + "\\\"},\\\"x\\\":" + to_string(X) + ",\\\"y\\\":" + to_string(Y) + "}\"";
};

