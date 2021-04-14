
#ifndef LINE_H
#define LINE_H

using namespace std;

class Line {
    friend ostream &operator<<( ostream &, const Line & );
    friend istream &operator>>( istream &, Line & );
public:
    Line operator *(const Line & );

   Line(double, double, double);
   ~Line();

    static void mashineTest();

   void setLine( double, double, double );

   double getAngle() const { return angle; }
   double getX() const { return x; }
   double getY() const { return y; }

   double calculateXByY(double);

   double abscissaCross();

   void print();

protected:
   double x;
   double y;
   double angle;
};

#endif
