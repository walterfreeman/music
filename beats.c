/**********************************************
anim.c, simple animation routine using OpenGL/GLUT
Written by Walter Freeman

Compile (on Linux) with
gcc anim.c -lGL -lGLU -lglut -lm

Compile (on Mac) with
gcc anim.c -framework GLUT -framework OpenGL -framework Cocoa
**********************************************/

#include <GL/glut.h>      // for Linux
#include <GL/glext.h>      // for Linux
//#include <GLUT/glut.h>       // for Macs 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define timing_hack 1
#define ANIM_FONT GLUT_BITMAP_HELVETICA_18
int window_size=800,window_size_x=800,window_size_y=800;

double t=0,x=0,k=100,k2=100,c=0.1,A=0.15,A2=0.15;
double dt=0.1;

void save_config(void);
void load_config(void);

void myColor4f(double r, double g, double b, double a)
{
  glColor4f(r,g,b,a);
}

void colk(double k)
{
  double r=1/k/k;
  double b=k*k/3;
  double g=0;
  if (k>0.1 && k<3) g=sqrt(2-r*r-b*b);
//  printf("Colors: %e %e %e\n",r,g,b);
  glColor4f(r,g,b,1);
}
void renderBitmapString(
    float x, 
    float y, 
    float z, 
    void *font, 
    char *string) {  
  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

double y2(double x) // t and k globals
{
  return A2*sin(k2*x-k2*c*t);
  
}


double y(double x) // t and k globals
{
  return A*sin(k*x-k*c*t);
  
}

double xpos()
{
  return log(k);
}


double kpos(double x)
{
   return exp((x+0.9) * 0.55 - 0.22);
}

void idle(void)
{
  
//  usleep(15);
  t=t+dt;  
 


   
  double dx=2.0/window_size;
/*
  glBegin(GL_LINES);
  for (x=-.9;x<.9;x+=dx)
  {
    colk(kpos(x));
    if (fabs(log(kpos(x)/k)) < 0.01)
    {
      glColor4f(1,1,1,1);
      glVertex3f(x,0.75,0);
      glVertex3f(x,0.95,0);
    }  
    glVertex3f(x,0.8,0);
    glVertex3f(x,0.9,0);
  }
  glEnd();
 */ 
  // graph sine function

  glColor4f(0,1,0,1);
  glBegin(GL_LINE_STRIP);
  for (double x=-1; x<1; x+=dx)
  {
    glVertex3f(x,y(x)-0.3,0);
  }
 glEnd();
  glColor4f(1,0.5,0.5,1);
  glBegin(GL_LINE_STRIP);
  for (double x=-1; x<1; x+=dx)
  {
    glVertex3f(x,y2(x)-.3,0);
  }
  glEnd();
   glColor4f(1,1,1,1);
  glBegin(GL_LINE_STRIP);
  for (double x=-1; x<1; x+=dx)
  {
    glVertex3f(x,y2(x)+y(x)+0.5,0);
  }
  glEnd();
  
  double yor=y(0);
//  printf("yorigin = %e\n",yor);
//  glColor4f(1,1,1,1);
//  glBegin(GL_LINE_STRIP);
//  double width=glutGet(GLUT_WINDOW_WIDTH), height=glutGet(GLUT_WINDOW_HEIGHT);
//  double asp=width/height;
//  for (double th=0;th<40*M_PI;th+=0.1)
//  {
//    double r=th/4000;
//    glVertex3f(r*sin(th)/asp,yor+r*cos(th),0);
//  }
  char stout[300];
  
  glEnd();
  sprintf(stout,"Frequency 1 = %.3f\t\tFrequency 2 = %.3f\n",k*c*2.5,k2*c*2.5);
  renderBitmapString(-0.8,-0.8,0,ANIM_FONT,stout);

  glutSwapBuffers(); 
  glClear(GL_COLOR_BUFFER_BIT);
  
}

void disp(void)
{
}


void resize(int w, int h)
{
  window_size_x=w;
  window_size_y=h;
  if (h>w) window_size=h; else window_size=w;
   glViewport(0,0,w,h);
}

void up(void)
{
  printf("Frequency = %.3f\t\tWavelength = %.3f\t\tWave speed = %.3f\t\t\n",k * c*2.5, 2*M_PI/k ,c);
}

void keyb(unsigned char key, int x, int y)
{
  if (key == 'Q') {exit(0);}
  if (key == 'r') {k2*=1.01;up();}
  if (key == 'e') {k2/=1.01;up();}
  if (key == 'w') {k*=1.01;up();}
  if (key == 'q') {k/=1.01;up();}
  if (key == 'a') {A*=1.03;up();}
  if (key == 's') {A/=1.03;up();}
  if (key == 'f') {A2*=1.03;up();}
  if (key == 'd') {A2/=1.03;up();}
  if (key == 'x') {c*=1.03; t/=1.03; up();}
  if (key == 'z') {c/=1.03; t*=1.03; up();}
}


int main(int argc, char **argv)
{
  if (argc == 2)
  {
    sscanf(argv[1],"%d",&window_size);
  }
  //INITIALIZATION
  glutInit(&argc, argv);

  //set rgba and double buffering  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |  GLUT_MULTISAMPLE);

  //set window size and position and title
  glutInitWindowSize(window_size,window_size);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Animation");

  //SET CALLBACKS
  glutDisplayFunc(disp);
  glutKeyboardFunc(keyb);
  glutIdleFunc(idle);
  glutReshapeFunc(resize);
  //DO OPENGL INIT
  glEnable(GL_BLEND);
  glEnable(GL_MULTISAMPLE);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.0, 0.0, 0.0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
    
  glutMainLoop();
}
