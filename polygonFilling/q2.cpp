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
    float x=0,y=r,d = (x+1)*(x+1)+(y-0.5)*(y-0.5)-r*r;

    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    putPoints(xc, yc, x, y);
    while(x<=y)
    {
        x++;
        if(d<=0)        d = d+2*x+3;
        else            y--,d = d+2*(x-y)+5;
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

    //Q2
    // circleDraw(150, 100, 50);
    // circleDraw(450, 100, 50);

    // lineDraw(200, 100, 400, 100);
    // lineDraw(50, 100, 100, 100);
    // lineDraw(500, 100, 550, 100);
    // lineDraw(50, 100, 50, 300);
    // lineDraw(550, 100, 550, 300);
    // lineDraw(50, 300, 550, 300);

    // lineDraw(225, 200, 275, 200);
    // lineDraw(225, 100, 225, 200);
    // lineDraw(275, 100, 275, 200);

    // lineDraw(300, 200, 350, 200);
    // lineDraw(300, 150, 350, 150);
    // lineDraw(300, 150, 300, 200);
    // lineDraw(350, 150, 350, 200);

    // lineDraw(375, 200, 425, 200);
    // lineDraw(375, 150, 375, 200);
    // lineDraw(425, 150, 425, 200);
    // lineDraw(375, 150, 425, 150);

    //Q1

    
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