#include <iostream>
using namespace std;
#include <cmath>

double HYPOT( int x , int y ){
    return sqrt(x*x+y*y);
}

double distanceBoxParticle2D(double x, double y, double x_min, double y_min,
        double x_max, double y_max)
{
    if (x < x_min) {
        if (y < y_min)
            return HYPOT(x_min-x, y_min-y);
        else if (y <= y_max)
            return x_min - x;
        else
            return HYPOT(x_min-x, y_max-y);
    } else if (x <= x_max) {
        if (y < y_min)
            return y_min - y;
        else if (y <= y_max)
            return 0;
        else
            return y - y_max;
    } else {
        if (y < y_min)
            return HYPOT(x_max-x, y_min-y);
        else if (y <= y_max)
            return x - x_max;
        else
            return HYPOT(x_max-x, y_max-y);
    }
    return 0.0;
}

int main(){
    int x,y,a,b,c,d;
    std::cin>>x >> y >> a >> b >> c >> d ;
    int x_min , y_min , x_max , y_max;
    if ( a < c && b < d ) {
        x_min = a ;
        y_min = b ; 
        x_max = c ;
        y_max = d ;
    } else if (a > c && b > d ) {
        x_min = c ;
        y_min = d ; 
        x_max = a ;
        y_max = b ;
    } else if (a < c && b > d){
        x_min = a;
        y_min = d;
        x_max = c;
        y_max = b;
    } else if ( a > c && b < d  ){
        x_min = c;
        y_min = b;
        x_max = a;
        y_max = d ;
    }

    std::cout << ceil(distanceBoxParticle2D(x,y,x_min,y_min,x_max,y_max));
    
    return 0;
       
   

    
    
}
