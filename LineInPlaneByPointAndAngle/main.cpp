#include <iostream>
#include "Line.h"
#include "Point.h"
#include <limits>


using namespace std;

int main()
{
    Line::mashineTest();

    //User
    cout<<"-----------------User test------------------"<<endl;
    cout<<endl;

    //cout<<"Enter point 'x' 'y'"<<endl;
    //cout<<"Enter angle in degrees 'angle'"<<endl;

    Line userl(0, 0, 0);
    cout<<endl;

    cout<<"Data is in double format"<<endl;
    //cin>>userl;

    while(!(cin >>userl)){
    cout << "Bad value!"<<endl;
    cout<<"Enter again"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout<<"Line cross abscissa at Point ("<<userl.abscissaCross()<<", 0)"<<endl;
    cout<<endl;

    cout<<"---Rotation test---"<<endl;
    cout<<endl;

    cout<<"Enter rotation point 'x' 'y'"<<endl;
    cout<<"Line will be rotated by this point with 90deg angle"<<endl;
    double x,y;
    //cin>>x>>y;

    while(!(cin >> x>>y)){
    cout << "Bad value!";
    cout<<"Enter rotation point 'x' 'y' again"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double angle = 90.;

    cout<<endl;
    Line rotationL(x, y, angle);
    cout<<endl;

    Line userRotatedLine = userl * rotationL;
    userRotatedLine.print();
    cout<<"Crossing with abscissa at Point ("<<userRotatedLine.abscissaCross()<<", 0)"<<endl;
    cout<<endl;



}

