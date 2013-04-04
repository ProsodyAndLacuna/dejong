//
//  main.cpp
//  dejong
//
//  Created by Marshall Mickelson on 2/25/13.
//  Copyright (c) 2013 Marshall Mickelson. All rights reserved.
//

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "Point.h"
#include "Frame.h"

using namespace std;

double map_space(double value, double start1, double stop1, double start2, double stop2)
{
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

double drift()
{
    return map_space( rand(), 0, RAND_MAX, -1.0, 1.0 );
}

int main(int argc, const char * argv[])
{
    string sx = "12";
    string sy = "610";
    stringstream ss;
    if ( argc == 3 )
    {

        sx = argv[1];
        sy = argv[2];
    }
    else
    {
        for( int i = 0; i < argc; i++ )
        {
            cout << i << " : " << argv[i] << " ";
        }
        cout << "/n";
        return 1;
    }
    const int DEFAULT_ITERATIONS = 128 * 26 * 1000 * 4;
    const double IMAGE_SIZE = 1024.0;

    srand(time(0));

    // user supplied x and y
    Point *p = new Point(0,0);
    stringstream(sx) >> p->X;
    stringstream(sy) >> p->Y;

    Frame *f = new Frame(IMAGE_SIZE);
    f->start = p;
    f->current = new Point(0,0);

    double x = p->X;
    double y = p->Y;

    double startx = IMAGE_SIZE / 2;
    double starty = IMAGE_SIZE / 2;
    //int pixels[(int)IMAGE_SIZE][(int)IMAGE_SIZE];
    int maxdensity = 0;

    // map the user coordinates to our a,b,c,d values
    double a = map_space(x, 0.0, IMAGE_SIZE, -1.0, 1.0) * f->sensitivity;
    double b = map_space(y, 0.0, IMAGE_SIZE, -1.0, 1.0) * f->sensitivity;
    double c = map_space(x, 0.0, IMAGE_SIZE, 1.0, -1.0) * f->sensitivity;
    double d = map_space(y, 0.0, IMAGE_SIZE, 1.0, -1.0) * f->sensitivity;

    // reset the values to the center of the image
    x = startx;
    y = starty;


    int i = 0;
    //cout << "Starting Calculations for X: " << f->start->X << ", Y: " << f->start->Y << " !\n";
    time_t begin, end;
    time(&begin);

    for ( i = 0; i < DEFAULT_ITERATIONS; i++ )
    {
        double newx = ((sin(a * y) - cos(b * x)) * IMAGE_SIZE * 0.2) + (IMAGE_SIZE / 2) + drift();
        double newy = ((sin(c * x) - cos(d * y)) * IMAGE_SIZE * 0.2) + (IMAGE_SIZE / 2) + drift();

        int ix = (int)newx;
        int iy = (int)newy;

        x = newx;
        y = newy;

        f->current->X = ix;
        f->current->Y = iy;

        if ( ix < IMAGE_SIZE && iy < IMAGE_SIZE )
        {
            f->pixels[ix][iy]++;
            if ( f->pixels[ix][iy] > maxdensity )
            {
                maxdensity = f->pixels[ix][iy];
            }
        }
    }

    std::string json = f->toJSON();
    cout << json;
    /*
    ofstream myfile;
    myfile.open ( "/Users/marshall/tmp/" + f->to_filename() );
    myfile << json;
    myfile.close();

    time(&end);

    cout << "Done with " << i << " siterations w/maxdensity = " << maxdensity
         << " in " << difftime(end, begin) << " s, saved to " << f->to_filename() << "\n";
     */
    delete p;
    delete f->current;
    delete f;

    return 0;
}



