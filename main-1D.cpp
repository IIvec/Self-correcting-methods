#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

double test(double);

int main()
{
    double a=-20.0;
    double b=20.0;
    double h=(b-a)/10000.0;
    double hm=(b-a)/2.0;
    long i;
    int A=800,j;
    double w1=0.0;
    double w2=0.0;
    double w3=0.0;
    double x,z,g,d;
    double f1,f2,f3;
    mt19937 generator(time(0));
    for (i=1;i<10000001;i++){
        if (i%2==1){
            uniform_int_distribution<long> distribution(-i,i);
            z=distribution(generator)/(i/b);
            if (i>1){
                    if (test(z)>test(x)) x=z;
            }
            else x=z;
        }
        else{
            f1=test(max(x-h,a));
            f2=test(x);
            f3=test(min(x+h,b));
            j=i%(3*A);
            d=fabs(f3-f1);
            if (j<=A && j>0) w1+=d;
            else if (j<=2*A && j>0) w2+=d;
            else w3+=d;

            if (f1>f2 && f1>f3) x=max(x-h,a);
            else if (f3>f2) x=min(x+h,b);

            if (j==0){
                if (w1==0.0 || w2==0.0 || w3==0.0) g=1.0;
                else g=(w2/w1)*(w2/w3);
                if (g==1.0) g=0.5;
                h=min(h*g,hm);
                w1=0.0;
                w2=0.0;
                w3=0.0;
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << i-1 << "   " << x << "   " << test(x) << "   " << h << endl;
    system("pause");
    return 0;
}

double test(double x){
    return cos(4.9*x)+sin(4.9*x)+2*cos(4.95*x)+2*sin(4.95*x)+4*cos(5*x)+4*sin(5*x)+8*cos(5.05*x)+8*sin(5.05*x)+16*cos(2.1*x)+16*sin(2.1*x);
}
