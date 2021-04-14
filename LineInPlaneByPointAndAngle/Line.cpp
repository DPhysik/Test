
#include <iostream>
#include <cmath>
#include "Line.h"

using namespace std;

Line::Line(double _x, double _y, double _angle)
{
    setLine(_x, _y, _angle);

    cout<<"Line was instantiated at point: ("<<x<<" "<<y<<") and angle: "<<angle<<endl;
}

 void Line::mashineTest(){
    cout<<"-----------------Machine test------------------"<<endl;
    cout<<endl;

    Line l1(1., 3., 30.), lr(1,1, 90.);
    cout<<endl;

    l1.print();
    cout<<l1;
    cout<<"Crossing with abscissa at Point ("<<l1.abscissaCross()<<", 0)"<<endl;
    cout<<endl;

    Line rotated = l1 * lr;
    rotated.print();
    cout<<rotated;
    cout<<"Crossing with abscissa at Point ("<<rotated.abscissaCross()<<", 0)"<<endl;
    cout<<endl;

    cout<<"--------------------Ended---------------------"<<endl;
    cout<<endl;
    cout<<endl;
}

void Line::setLine(double _x, double _y, double _angle)
{
    x = _x;
    y = _y;
    angle = _angle;
}

double Line::calculateXByY(double _y){
    //return x + (_y - y)/tan(angle((22./7.)/180.));
    return x + (_y - y)/tan(angle*((22./7.)/180.));
    //return tan(angle*((22./7/)/180.));
}

double Line::abscissaCross(){
    return calculateXByY(0.);
}

void Line::print()
{
    cout<<"Line formula: y = tg("<<angle<<" * pi/180)(x - "<<x<<") + "<<y<<endl;
}

Line Line :: operator * (const Line &l )
{
    double degToRad = (22./7.)/180.;
    double nX = l.getX() + cos(l.getAngle() * degToRad)*(this->x-l.getX())+ -1. * sin(l.getAngle() * degToRad) * (this->y-l.getY());
    double nY = l.getY() + sin(l.getAngle() * degToRad) * (this->x-l.getX()) + cos(l.getAngle() * degToRad) * (this->y-l.getY());
    double nAngle = this->angle + l.getAngle();

    Line result(nX,nY,nAngle);
    return result;
}

Line::~Line(){
    cout<<"Object was destroid"<<endl;
}

ostream &operator<<( ostream &output, const Line &l )
{
   output <<"Line start point: ("<<l.x<<" "<<l.y<<").\nLine Angle with abscissa : "<<l.angle<< "\n";

   return output;
}

istream &operator>>( istream &input, Line &l )
{
    cout<<"Enter x cord"<<endl;
   input>>l.x;
   cout<<"Enter y cord"<<endl;
   input>>l.y;
   cout<<"Enter angle cord"<<endl;
   input>>l.angle;

   cout<<l<<endl;
   l.print();

   return input;
}
