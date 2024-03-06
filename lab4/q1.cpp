#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


const int WINDOW_POSITION[2] = {0, 0};
int WINDOW_SIZE[2];
const char* diagramName = "DDA Line Drawing";
const int STARTS[3][2] = {{200, 200}, {200, 200}, {200, 200}};
const int ENDS[3][2] = {{1000, 1050}, {1000, 1000}, {1000, 950}};
const int NUM_LINES = 3;

void displayMe(void)
{
    
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