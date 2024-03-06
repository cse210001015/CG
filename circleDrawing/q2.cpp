#include <GL/glut.h>

const int WINDOW_SIZE[2] = {150,150}; 
const int WINDOW_POSITION[2] = {100,100};
const float RADIUS = 50.0;
const float CENTER[2] = {0.0, 0.0};

void putPoints(float xc, float yc, float x,float y) 
{       
    glVertex2f(xc+x, xc+y);
    glVertex2f(xc+x, xc-y);
    glVertex2f(xc-x, xc+y);
    glVertex2f(xc-x, xc-y);
    glVertex2f(xc+y, xc+x);
    glVertex2f(xc+y, xc-x);
    glVertex2f(xc-y, xc+x);
    glVertex2f(xc-y, xc-x);
}

void displayMe()
{
    float r = RADIUS;
    float xc = CENTER[0], yc = CENTER[1];
    float x=0,y=r,d = (x+1)*(x+1)+(y-0.5)*(y-0.5)-r*r;

    glClear(GL_COLOR_BUFFER_BIT);
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