#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


const int WINDOW_POSITION[2] = {0, 0};
int WINDOW_SIZE[2];
const char* diagramName = "Midpoint Line Drawing";
const int STARTS[3][2] = {{200, 200}, {200, 200}, {200, 200}};
const int ENDS[3][2] = {{1000, 1050}, {1000, 1000}, {1000, 950}};
const int NUM_LINES = 3;

void setColor(float* colors)
{
    glColor3f(colors[0], colors[1], colors[2]);
}

float* mult(float* a, int b, float c)
{
    for(int i = 0; i < b; i++)      a[i] = a[i] * c;
    return a;
}

void drawLine(const int* start, const int* end)
{
    glBegin(GL_POINTS);
    float dy = static_cast<float>((abs(end[1] - start[1]))), dx = static_cast<float>(abs(end[0] - start[0]));
    float param = dy > dx ? dx - dy / 2.0 : dy - dx / 2.0;
    int x = start[0], y = start[1];
    int steps = max(dx, dy);

    glVertex2f(x, y);
    while(steps--)
    {
        if(param <= 0)       param += dy > dx ? dx : dy;
        else
        {
            param += dy > dx ? (dx - dy) : (dy - dx);
            if(dy > dx)         x += x < end[0] ? 1 : -1;
            else                y += y < end[1] ? 1 : -1;
        }  
        if(dy <= dx)        x += x < end[0] ? 1 : -1;
        else                y += y < end[1] ? 1 : -1;
        glVertex2f(x, y);
    }
    glEnd();
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0; i < NUM_LINES; i++)      drawLine(STARTS[i], ENDS[i]);
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