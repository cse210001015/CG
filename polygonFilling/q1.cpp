#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


float COLORS[3][3] = {{0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}};
const int WINDOW_POSITION[2] = {100,100};

void putPoints(float xc, float yc, float x, float y) 
{       
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc - y, yc - x);
}

void circleDraw(float xc, float yc, float r)
{
    float x=0,y=r,d=3-2*r;

    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    putPoints(xc, yc, x, y);
    while(x<=y)
    {
        x++;
        if(d<=0)        d = d+4*x+6;
        else            y--,d = d+4*(x-y)+10;
        putPoints(xc, yc, x, y);
    }
    glEnd();
}

void lineDraw(float x0, float y0, float x1, float y1) 
{
    int dx=x1-x0,dy=y1-y0;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float incX = dx/(double) steps;
    float incY = dy/(double) steps;

    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for(int i=0;i<=steps;i++) 
    {
        glVertex2f(round(x0),round(y0));
        x0 += incX,y0 += incY;
    }
    glEnd();
}

void displayMe()
{
    glClear(GL_COLOR_BUFFER_BIT);
    circleDraw(150, 100, 50);
    circleDraw(450, 100, 50);

    lineDraw(200, 100, 400, 100);
    lineDraw(50, 100, 100, 100);
    lineDraw(500, 100, 550, 100);
    lineDraw(50, 100, 50, 200);
    lineDraw(550, 100, 550, 200);
    lineDraw(50, 200, 550, 200);
    lineDraw(150, 200, 200, 300);
    lineDraw(400, 300, 450, 200);
    lineDraw(200, 300, 400, 300);

    glFlush();
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(WINDOW_POSITION[0], WINDOW_POSITION[1]);
    glutCreateWindow("Car Filling");
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}