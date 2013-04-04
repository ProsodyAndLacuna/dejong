//
//  JSONObject.h
//  mathtest
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#ifndef mathtest_JSONObject_h
#define mathtest_JSONObject_h

#include <cstdlib>
#include <iostream>
#include <sstream>

class JSONObject {
public:
    virtual std::string toJSON() = 0;
protected:
    template <class T>
    inline std::string to_string (const T& t)
    {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }
};

#endif
