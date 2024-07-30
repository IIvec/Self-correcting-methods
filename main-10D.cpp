#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

double test(double, double, double, double, double, double, double, double, double, double);

int main()
{
    double a1=-20.0,a2=-20.0,a3=-20.0,a4=-20.0,a5=-20.0,a6=-20.0,a7=-20.0,a8=-20.0,a9=-20.0,a10=-20.0;
    double b1=20.0,b2=20.0,b3=20.0,b4=20.0,b5=20.0,b6=20.0,b7=20.0,b8=20.0,b9=20.0,b10=20.0;
    double h1=(b1-a1)/10000.0;
    double h1m=(b1-a1)/2.0;
    double h2=(b2-a2)/10000.0;
    double h2m=(b2-a2)/2.0;
    double h3=(b3-a3)/10000.0;
    double h3m=(b3-a3)/2.0;
    double h4=(b4-a4)/10000.0;
    double h4m=(b4-a4)/2.0;
    double h5=(b5-a5)/10000.0;
    double h5m=(b5-a5)/2.0;
    double h6=(b6-a6)/10000.0;
    double h6m=(b6-a6)/2.0;
    double h7=(b7-a7)/10000.0;
    double h7m=(b7-a7)/2.0;
    double h8=(b8-a8)/10000.0;
    double h8m=(b8-a8)/2.0;
    double h9=(b9-a9)/10000.0;
    double h9m=(b9-a9)/2.0;
    double h10=(b10-a10)/10000.0;
    double h10m=(b10-a10)/2.0;
    long i;
    int A=3000,j,e2,e3,e4,e5,e6,e7,e8,e9,e10;
    double w1=0.0;
    double w2=0.0;
    double w3=0.0;
    double x1,x1m,x1p,x2,x2m,x2p,x3,x3m,x3p,x4,x4m,x4p,x5,x5m,x5p,x6,x6m,x6p,x7,x7m,x7p,x8,x8m,x8p,x9,x9m,x9p,x10,x10m,x10p,z1,z2,z3,z4,z5,z6,z7,z8,z9,z10,g,d;
    double f1,f2,f3;
    mt19937 generator(time(0));
    for (i=1;i<300000001;i++){
        if (i%2==1){
            uniform_int_distribution<long> distribution(-i,i);
            z1=distribution(generator)/(i/b1);
            z2=distribution(generator)/(i/b2);
            z3=distribution(generator)/(i/b3);
            z4=distribution(generator)/(i/b4);
            z5=distribution(generator)/(i/b5);
            z6=distribution(generator)/(i/b6);
            z7=distribution(generator)/(i/b7);
            z8=distribution(generator)/(i/b8);
            z9=distribution(generator)/(i/b9);
            z10=distribution(generator)/(i/b10);
            if (i>1){
                    if (test(z1,z2,z3,z4,z5,z6,z7,z8,z9,z10)>test(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)){
                        x1=z1;x2=z2;x3=z3;x4=z4;x5=z5;x6=z6;x7=z7;x8=z8;x9=z9;x10=z10;
                    }
            }
            else{
                x1=z1;x2=z2;x3=z3;x4=z4;x5=z5;x6=z6;x7=z7;x8=z8;x9=z9;x10=z10;
            }
        }
        else{
            uniform_int_distribution<int> distribution(0,1);
            e2=2*distribution(generator)-1;
            e3=2*distribution(generator)-1;
            e4=2*distribution(generator)-1;
            e5=2*distribution(generator)-1;
            e6=2*distribution(generator)-1;
            e7=2*distribution(generator)-1;
            e8=2*distribution(generator)-1;
            e9=2*distribution(generator)-1;
            e10=2*distribution(generator)-1;
            x1m=max(x1-h1,a1);
            x2m=min(max(x2-e2*h2,a2),b2);
            x3m=min(max(x3-e3*h3,a3),b3);
            x4m=min(max(x4-e4*h4,a4),b4);
            x5m=min(max(x5-e5*h5,a5),b5);
            x6m=min(max(x6-e6*h6,a6),b6);
            x7m=min(max(x7-e7*h7,a7),b7);
            x8m=min(max(x8-e8*h8,a8),b8);
            x9m=min(max(x9-e9*h9,a9),b9);
            x10m=min(max(x10-e10*h10,a10),b10);
            f1=test(x1m,x2m,x3m,x4m,x5m,x6m,x7m,x8m,x9m,x10m);
            f2=test(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10);
            x1p=min(x1+h1,b1);
            x2p=max(min(x2+e2*h2,b2),a2);
            x3p=max(min(x3+e3*h3,b3),a3);
            x4p=max(min(x4+e4*h4,b4),a4);
            x5p=max(min(x5+e5*h5,b5),a5);
            x6p=max(min(x6+e6*h6,b6),a6);
            x7p=max(min(x7+e7*h7,b7),a7);
            x8p=max(min(x8+e8*h8,b8),a8);
            x9p=max(min(x9+e9*h9,b9),a9);
            x10p=max(min(x10+e10*h10,b10),a10);
            f3=test(x1p,x2p,x3p,x4p,x5p,x6p,x7p,x8p,x9p,x10p);
            j=i%(3*A);
            d=fabs(f3-f1);
            if (j<=A && j>0) w1+=d;
            else if (j<=2*A && j>0) w2+=d;
            else w3+=d;

            if (f1>f2 && f1>f3){
                x1=x1m;x2=x2m;x3=x3m;x4=x4m;x5=x5m;x6=x6m;x7=x7m;x8=x8m;x9=x9m;x10=x10m;
            }
            else if (f3>f2){
                x1=x1p;x2=x2p;x3=x3p;x4=x4p;x5=x5p;x6=x6p;x7=x7p;x8=x8p;x9=x9p;x10=x10p;
            }

            if (j==0){
                if (w1==0.0 || w2==0.0 || w3==0.0) g=1.0;
                else g=(w2/w1)*(w2/w3);
                if (g==1.0) g=0.9990234375;
                h1=min(h1*g, h1m);
                h2=min(h2*g, h2m);
                h3=min(h3*g, h3m);
                h4=min(h4*g, h4m);
                h5=min(h5*g, h5m);
                h6=min(h6*g, h6m);
                h7=min(h7*g, h7m);
                h8=min(h8*g, h8m);
                h9=min(h9*g, h9m);
                h10=min(h10*g, h10m);
                w1=0.0;
                w2=0.0;
                w3=0.0;
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << i-1 << "   " << x1 << "   " << x2 << "   " << x3  << "   " << x4 << "   " << x5 << "   " << x6 << "   " << x7 << "   " << x8 << "   " << x9 << "   " << x10 << endl << endl;
    cout << test(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10) << "   " << h1 << endl;
    system("pause");
    return 0;
}

double test(double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8, double x9, double x10){
    return cos(4.9*(x1+x2+x3+x4+x5+x6+x7+x8+x9+x10))+sin(4.9*(x1+x2+x3+x4+x5+x6+x7+x8+x9+x10))
            +2*cos(4.95*(x1+2*x2+4*x3+8*x4+16*x5+32*x6+64*x7+128*x8+256*x9+512*x10))+2*sin(4.95*(x1+2*x2+4*x3+8*x4+16*x5+32*x6+64*x7+128*x8+256*x9+512*x10))
            +4*cos(5*(x1+4*x2+16*x3+64*x4+256*x5+1024*x6+4096*x7+16384*x8+pow(4,8)*x9+pow(4,9)*x10))+4*sin(5*(x1+4*x2+16*x3+64*x4+256*x5+1024*x6+4096*x7+16384*x8+pow(4,8)*x9+pow(4,9)*x10))
            +8*cos(5.05*(x1+8*x2+64*x3+512*x4+4096*x5+pow(8,5)*x6+pow(8,6)*x7+pow(8,7)*x8+pow(8,8)*x9+pow(8,9)*x10))
                    +8*sin(5.05*(x1+8*x2+64*x3+512*x4+4096*x5+pow(8,5)*x6+pow(8,6)*x7+pow(8,7)*x8+pow(8,8)*x9+pow(8,9)*x10))
            +16*cos(2.1*(x1+16*x2+256*x3+4096*x4+pow(16,4)*x5+pow(16,5)*x6+pow(16,6)*x7+pow(16,7)*x8+pow(16,8)*x9+pow(16,9)*x10))
                    +16*sin(2.1*(x1+16*x2+256*x3+4096*x4+pow(16,4)*x5+pow(16,5)*x6+pow(16,6)*x7+pow(16,7)*x8+pow(16,8)*x9+pow(16,9)*x10));
}
