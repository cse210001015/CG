#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


const int WINDOW_POSITION[2] = {0, 0};
const int numSegmentsCircle = 1000;
int WINDOW_SIZE[2];
const char* diagramName = "Mouse and Keyboard Clicks";
float COLOR[3] = {1.0f, 1.0f, 1.0f};
float x[5] = {200, 400, 375, 300, 225};
float y[5] = {200, 200, 300, 350, 300};

void makePolygon(float* x, float* y, int cnt)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < cnt; i++)        glVertex2f(x[i], y[i]);
    glEnd();
}

void setColor(float* colors)
{
    glColor3f(colors[0], colors[1], colors[2]);
}

float* mult(float* a, int b, float c)
{
    for(int i = 0; i < b; i++)      a[i] = a[i] * c;
    return a;
}

void displayMe(void)
{
    const float normalizeX = WINDOW_SIZE[0] / 1920.0f;
    const float normalizeY = WINDOW_SIZE[1] / 1080.0f;

    glClear(GL_COLOR_BUFFER_BIT);
    setColor(COLOR);
    makePolygon(mult(x, 5, normalizeX), mult(y, 5, normalizeY), 5);
    glFlush();
}

void handleMouseClick(int button, int state, int x, int y)
{
    for(int i = 0; i < 3; i++)      COLOR[i] = static_cast<double>(rand()) / RAND_MAX;
    glutPostRedisplay();
}

void add(float* a, int cnt, float val)
{
    for(int i = 0; i < cnt; i++)        a[i] += val;
}

void handleSpecialKey(int key, int x1, int y1)
{
    if(key == GLUT_KEY_UP)              add(y, 5, 5);   
    else if(key == GLUT_KEY_DOWN)       add(y, 5, -5);
    else if(key == GLUT_KEY_LEFT)       add(x, 5, -5);
    else if(key == GLUT_KEY_RIGHT)      add(x, 5, 5);
    glutPostRedisplay();
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
    glutMouseFunc(handleMouseClick);
    glutSpecialFunc(handleSpecialKey);
    glutMainLoop();
    return 0;
}