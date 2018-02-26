#include <stdio.h>
#include <math.h>

double k=1;
double vb=1;
double vcrit=0.7;

double elastic(double x)
{
  double f=-k*x;
  return f;
}

double friction(double v2)
{
  v2*=3;
  double v=fabs(v2);
  return -(4-log((v+vcrit))) * fabs(v)/v2;
}




int main(void)
{

 double x=0;
 double v=0;
 double dt=0.0001;
 double m=1;
 int fs=200;
 int f=0;
 double t=0;
 while (1) 
 {
   t+=dt;
   f++;
   x += v*dt/2;
   v += (1.0/m) * (elastic(x) + friction(v-vb)) * dt/2;
   v += (1.0/m) * (elastic(x) + friction(v-vb)) * dt/2;
   x += v*dt/2;
   
  if (f%fs==0)
  {
  printf("C 0 1 0\n");
  printf("c %e -4 0.3\n",x);


  printf("C 0.7 0.7 0.7\n");
  printf("l 0 0 6 0\n");
  printf("l 6 5 6 0\n");
  printf("l 0 5 6 5\n");
  printf("l 0 5 0 0\n");
  printf("C 1 1 1\n");
  printf("t -2 3\nFriction\n"); 
  printf("t 0 -.3\nDifference in velocity between bow and string\n"); 
  for (double vd=-6; vd<-0.1; vd+=0.1)
  {
    printf("l %e %e %e %e\n",-vd,fabs(friction(vd)),-(vd+0.1),fabs(friction(vd+0.1)));
  }

  printf("C 0.5 0.5 1\n");
  printf("l 0 %e 6 %e\n",-elastic(x),-elastic(x));
  printf("C 1 0 0\n");
  printf("c %e %e 0.2\n",-(v-vb),fabs(friction(v-vb)));
  printf("F\n");

    double seg=1;
  for (double dx=-10; dx<10; dx+=seg)
  {
    double offset=vb*t - (int)(vb*t/seg)*seg;
    printf("l %e %e %e %e\n",dx+offset,-4.3,dx+offset,-5.3);
  }

 }
 }
}

