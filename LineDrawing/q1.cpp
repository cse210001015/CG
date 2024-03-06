#include <GL/glut.h>
#include <math.h>

const int WINDOW_SIZE[2] = {150,150}; 
const int WINDOW_POSITION[2] = {100,100};
const int START[2] = {-100,-100};
const int END[2] = {100,100};

void displayMe()
{
    int x0=START[0],y0=START[1];
    int x1= END[0],y1=END[1];

    int dx=x1-x0,dy=y1-y0;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float incX = dx/(double) steps;
    float incY = dy/(double) steps;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for(int i=0;i<=steps;i++) 
    {
        glVertex2f(round(x0),round(y0));
        x0 += incX,y0 += incY;
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

