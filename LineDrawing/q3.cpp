#include <GL/glut.h>
#include <math.h>

const int WINDOW_SIZE[2] = {150,150}; 
const int WINDOW_POSITION[2] = {100,100};
const int START[2] = {-100,-100};
const int END[2] = {100,100};

void displayMe()
{
    float x0=START[0],y0=START[1];
    float x1= END[0],y1=END[1];

    float dx=x1-x0,dy=y1-y0;
    float p = dy-dx/2;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    while(x0<=x1)
    {
        glVertex2f(x0, y0);
        if(p>=0)        y0++,p += dy-dx;
        else            p += dy;
        x0++;
    }
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(WINDOW_POSITION[0], WINDOW_POSITION[1]);
    glutCreateWindow("Midpoint Algorithm");
    gluOrtho2D(-WINDOW_SIZE[0], WINDOW_SIZE[0], -WINDOW_SIZE[1], WINDOW_SIZE[1]);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}

