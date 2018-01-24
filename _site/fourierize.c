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

double samp[200],camp[200];

int fouriermax=50;
int yvalue[2000];
int flag=1;
double t=0,x=0,k=1,c=0.1,A=0.5;
double dt=0.1;

void save_config(void);
void load_config(void);

double theta(int x)
{
  return 2*M_PI*(x-window_size_x*0.1)/(window_size_x*0.8);
}

void compute_fourier(int n)
{
  int xmin=window_size_x*0.1;
  int xmax=window_size_x*0.9;
  int i,j;
  double th;

  for (j=0; j<=n; j++)
  {
    samp[j]=camp[j]=0;

    for (i=xmin; i<xmax; i++)
    {
      samp[j] += sin(theta(i)*j) * yvalue[i] * sqrt(2*M_PI)/(window_size_x*0.8);  
      camp[j] += cos(theta(i)*j) * yvalue[i] * sqrt(2*M_PI)/(window_size_x*0.8);
    }
    printf("Coefficients %d: sin %e, cos %e\n",j,samp[j],camp[j]);
  }
}  

void myColor3f(double r, double g, double b)
{
  glColor4f(r,g,b,1);
}


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

void colorize(int j)
{
  if (j%6 == 1) myColor3f(1,0,0);
  if (j%6 == 2) myColor3f(0,1,0);
  if (j%6 == 3) myColor3f(0.5,0.5,1);
  if (j%6 == 4) myColor3f(1,1,0);
  if (j%6 == 5) myColor3f(1,0,1);
  if (j%6 == 0) myColor3f(0,1,1);
}


void idle(void)
{
    double x,y;
  usleep(100);
  // first indicate to the user the range in which we want input
  myColor3f(0.4,0.4,0.4);
  glBegin(GL_LINES);
  glVertex3f(-0.8,-1,0);
  glVertex3f(-0.8,1,0);
  glVertex3f(0.8,-1,0);
  glVertex3f(0.8,1,0);
  glEnd();
  int i;

  double avgy;
  int ny;

  avgy=0;
  ny=0;

  glBegin(GL_LINE_STRIP);
  myColor3f(1,1,1);
  for (i=window_size_x*0.1; i<window_size_x*0.9; i++)
  {
    x=-1 + ((float)i / window_size_x * 2);
    y=1 - ((float)yvalue[i] / window_size_y * 2);
    avgy+=y;
    ny++;
//    printf("vertex at %f,%f -> %d,%d\n",x,y,i,yvalue[i]);
    glVertex3f(x,y,0);
  }
  glEnd();

avgy/=ny;

  if (flag == 2)
  {
    for (int j=1; j<fouriermax; j++)
    {
      colorize(j);
      glBegin(GL_LINE_STRIP);
	for (int i=window_size_x*0.1; i<window_size_x*0.9; i++)
	{
          double th=theta(i);
          x=-1 + ((float)i / window_size_x * 2);
          y=-((sin(th*j)*samp[j]) / window_size_y * 2) * 0.8;
	  glVertex3f(x,y+avgy,0);
	}
      glEnd();
    }
    for (int j=1; j<fouriermax; j++)
    {
      colorize(j+1);
      glBegin(GL_LINE_STRIP);
	for (int i=window_size_x*0.1; i<window_size_x*0.9; i++)
	{
          double th=theta(i);
          x=-1 + ((float)i / window_size_x * 2);
          y=-((cos(th*j)*camp[j]) / window_size_y * 2) * 0.8;
	  glVertex3f(x,y+avgy,0);
	}
      glEnd();
    }
   }


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

void keyb(unsigned char key, int x, int y)
{
  if (key == 'Q') {exit(0);}
  if (key == ' ') 
  {
    int i;
    for (i=0; i<window_size_x; i++) yvalue[i]=window_size_y/2;
    flag = 1;
  }
  if (key == 's')
  {
    int i; float slope; float avg=0;
    for (i=window_size_x*0.1; i<=window_size_x*0.9; i++)
    {
      avg += yvalue[i];
    }
    avg /= window_size_x*0.8;

    slope = (yvalue[(int)(window_size_x * 0.9)] - yvalue[(int)(window_size_x * 0.1)]) / (window_size_x * 0.8);
    for (i=window_size_x*0.1; i<=window_size_x*0.9; i++)
    {
      yvalue[i]-=slope * (i-window_size_x/2) + avg - window_size_y/2;
    }
  }
  if (key == 'f')
  {
    compute_fourier(50);
    flag = 2;
  }

  if (key == '1')
  {
    flag = 1;
    int xmin=window_size_x*0.1;
    int xmax=window_size_x*0.9;
    int i;
    double th;

      for (i=xmin; i<=xmax; i++)
      {
	yvalue[i] = window_size_y/2 + sin(2*theta(i)/2.0) * 100;
      }
    }

  if (key == '2')
  {
    flag = 1;
    int xmin=window_size_x*0.1;
    int xmax=window_size_x*0.9;
    int i;
    for (i=xmin; i<=xmax; i++)
    {
      yvalue[i] = 0;
      if (i>=window_size_x*0.1) yvalue[i]=-300+window_size_y/2;
      if (i>=window_size_x*0.3) yvalue[i]=300+window_size_y/2;
      if (i>=window_size_x*0.5) yvalue[i]=-300+window_size_y/2;
      if (i>=window_size_x*0.7) yvalue[i]=300+window_size_y/2;
    }
  }
  if (key == '3')
  {
    flag = 1;
    int xmin=window_size_x*0.1;
    int xmax=window_size_x*0.9;
    int i,ct=-window_size_x*0.2;
    printf("sawtooth?\n");
    for (i=xmin; i<=xmax; i++)
    {
      yvalue[i]=ct+window_size_y/2;
      ct++;
      if (ct == window_size_x*0.2) ct=-window_size_x*0.2; 
    }
    
  } 
 if (key == '4')
  {
    flag = 1;
    int xmin=window_size_x*0.1;
    int xmax=window_size_x*0.9;
    int i,ct=0;
    int s=1;
    for (i=xmin; i<=xmax; i++)
    {
      yvalue[i]=ct+window_size_y/2;
      ct+=s*2;
      if (abs(ct) == window_size_x*0.2) {s*=-1; }
    }
    
  } 

  if (key == 'w')
  {
    FILE *wave;
    wave=fopen ("output.txt","w");
    double t=0;
    double xmin=window_size_x*0.1, xmax=window_size_x*0.9;
    for (int j=0; j<200; j++)
      for (int i=xmin; i<xmax; i++)
      {
	t=t+0.01;
	fprintf(wave,"%e %d\n",t,yvalue[i] - window_size_y/2);
      }
    fclose(wave);
//    system("makeaudio output.txt");
    char cmd[100];
    sprintf(cmd,"cat output.txt | makeaudio output.wav %d",window_size_x*2);
    system(cmd);
    system("play output.wav");
  }


  

}

void flip (int &a, int &b)
{
  int c;
  c=a; a=b; b=c;
}

void move_mouse(int x, int y)
{
  flag=1;
  static int lastx=0, lasty=0;
  if (lastx==0 && lasty==0) {lastx=x; lasty=y;}
  // smoothly interpolate between last position and current one
  int xc,yc;
  int step=1;
  if (x > lastx) {step=-1;}

  printf("Mouse now at %d,%d: loop from %d to %d\n",x,y,x,lastx);
  if (lastx==x)
  {
    yvalue[x]=y;
    return;
  }
  for (xc=x; xc*step<=lastx*step; xc+=step)
  {
    yc = y + (float)(lasty-y) / (float)(lastx-x) * (xc-x);
  //  yc=y;
    yvalue[xc]=yc;
  }
  lastx=x;
  lasty=y;
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
  glutCreateWindow("Fourier-O-Matic");
    int i;
    for (i=0; i<window_size_x; i++) yvalue[i]=window_size_y/2;

  //SET CALLBACKS
  glutDisplayFunc(disp);
  glutKeyboardFunc(keyb);
  glutIdleFunc(idle);
  glutReshapeFunc(resize);
  glutMotionFunc(move_mouse);
  //DO OPENGL INIT
  glEnable(GL_BLEND);
  glEnable(GL_MULTISAMPLE);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
    
  glutMainLoop();
}
