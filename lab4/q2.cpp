#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


const int WINDOW_POSITION[2] = {0, 0};
int WINDOW_SIZE[2];
const char* diagramName = " Midpoint Circle Drawing";
const int xc = 500;
const int yc = 500;
const int rad = 100;

void putPoints(int xc, int yc, int x, int y)
{
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc - y, yc - x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc + y, yc + x);
}

void drawCircle(int xc, int yc, int rad)
{
    glBegin(GL_POINTS);
    int x = 0, y = rad;
    int param = 1 - rad;

    glVertex2f(xc, yc + rad);
    glVertex2f(xc, yc - rad);
    glVertex2f(xc + rad, yc);
    glVertex2f(xc - rad, yc);
    while(x < y)
    {
        if(param < 0)      param += 2*x + 3;
        else               param += 2*(x - y) + 5, y--;
        x++;
        putPoints(xc, yc, x, y);      
    }
    glEnd();
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(xc, yc, rad);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    WINDOW_SIZE[0] = glutGet(GLUT_SCREEN_WIDTH);
    WINDOW_SIZE[1] = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(WINDOW_SIZE[0], WINDOW_SIZE[1]);
    glutInitWindowPosition(WINDOW_POSITION[0], WINDOW_POSITION[1]);
    glutCreateWindow(diagramName);
    gluOrtho2D(0, WINDOW_SIZE[0], 0, WINDOW_SIZE[1]);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}