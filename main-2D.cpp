#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

double test(double, double);

int main()
{
    double a1=-20.0,a2=-20.0;
    double b1=20.0,b2=20.0;
    double h1=(b1-a1)/10000.0;
    double h1m=(b1-a1)/2.0;
    double h2=(b2-a2)/10000.0;
    double h2m=(b2-a2)/2.0;
    long i;
    int A=1500,j,e;
    double w1=0.0;
    double w2=0.0;
    double w3=0.0;
    double x,y,z,u,g,d;
    double f1,f2,f3;
    mt19937 generator(time(0));
    for (i=1;i<1000000001;i++){
        if (i%2==1){
            uniform_int_distribution<long> distribution(-i,i);
            z=distribution(generator)/(i/b1);
            u=distribution(generator)/(i/b2);
            if (i>1){
                    if (test(z,u)>test(x,y)){
                        x=z;
                        y=u;
                    }
            }
            else{
                x=z;
                y=u;
            }
        }
        else{
            uniform_int_distribution<int> distribution(0,1);
            e=2*distribution(generator)-1;
            f1=test(max(x-h1,a1),min(max(y-e*h2,a2),b2));
            f2=test(x,y);
            f3=test(min(x+h1,b1),max(min(y+e*h2,b2),a2));
            j=i%(3*A);
            d=fabs(f3-f1);
            if (j<=A && j>0) w1+=d;
            else if (j<=2*A && j>0) w2+=d;
            else w3+=d;

            if (f1>f2 && f1>f3){
                x=max(x-h1,a1);
                y=min(max(y-e*h2,a2),b2);
            }
            else if (f3>f2){
                x=min(x+h1,b1);
                y=max(min(y+e*h2,b2),a2);
            }

            if (j==0){
                if (w1==0.0 || w2==0.0 || w3==0.0) g=1.0;
                else g=(w2/w1)*(w2/w3);
                if (g==1.0) g=0.75;
                h1=min(h1*g,h1m);
                h2=min(h2*g,h2m);
                w1=0.0;
                w2=0.0;
                w3=0.0;
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << i-1 << "   " << x << "   " << y << "   " << test(x,y) << "   " << h1 << endl;
    system("pause");
    return 0;
}

double test(double x, double y){
    return cos(4.9*(x+y))+sin(4.9*(x+y))
            +2*cos(4.95*(x+2*y))+2*sin(4.95*(x+2*y))
            +4*cos(5*(x+4*y))+4*sin(5*(x+4*y))
            +8*cos(5.05*(x+8*y))+8*sin(5.05*(x+8*y))
            +16*cos(2.1*(x+16*y))+16*sin(2.1*(x+16*y));
}
