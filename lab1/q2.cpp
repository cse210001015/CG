#include <GL/glut.h>
#include <bits/stdc++.h>


const int WINDOW_POSITION[2] = {0, 0};
const int numSegmentsCircle = 1000;
int WINDOW_SIZE[2];
const char* diagramName = "House";
const float GREEN[3] = {0.0f, 1.0f, 0.0f};
const float BROWN[3] = {0.647f, 0.165f, 0.165f};
const float WHITE[3] = {1.0f, 1.0f, 1.0f};
const float BLACK[3] = {0.0f, 0.0f, 0.0f};
const float RED[3] = {1.0f, 0.0f, 0.0f};

void makeTriangle(float* x, float* y)
{
    glBegin(GL_POLYGON);
        glVertex2f(x[0], y[0]);
        glVertex2f(x[1], y[1]);
        glVertex2f(x[2], y[2]);
    glEnd();
}

void makeQuad(float* x, float* y)
{
    glBegin(GL_POLYGON);
        glVertex2f(x[0], y[0]);
        glVertex2f(x[1], y[1]);
        glVertex2f(x[2], y[2]);
        glVertex2f(x[3], y[3]);
    glEnd();
}

void makeCircle(float xc, float yc, float rad, int numSegments)
{
    glBegin(GL_POLYGON);

    for(int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = xc + rad * cos(theta);
        float y = yc + rad * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();    
}

void setColor(const float* colors)
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
    setColor(BROWN);
    float xt[3] = {750, 1250, 1000};
    float yt[3] = {750, 750, 1000};
    makeTriangle(mult(xt, 3, normalizeX), mult(yt, 3, normalizeY));
    setColor(RED);
    float xq[4] = {800, 1200, 1200, 800};
    float yq[4] = {350, 350, 750, 750};
    makeQuad(mult(xq, 4, normalizeX), mult(yq, 4, normalizeY));
    setColor(GREEN);
    float xq1[4] = {850, 900, 900, 850};
    float yq1[4] = {550, 550, 600, 600};
    makeQuad(mult(xq1, 4, normalizeX), mult(yq1, 4, normalizeY));
    float xq2[4] = {1100, 1150, 1150, 1100};
    float yq2[4] = {550, 550, 600, 600};
    makeQuad(mult(xq2, 4, normalizeX), mult(yq2, 4, normalizeY));
    float xq3[4] = {950, 1050, 1050, 950};
    float yq3[4] = {400, 400, 600, 600};
    makeQuad(mult(xq3, 4, normalizeX), mult(yq3, 4, normalizeY));
    float xc = 975;
    float yc = 500;
    float rad = 10;
    setColor(BLACK);
    makeCircle(xc * normalizeX, yc * normalizeY, rad * sqrt(normalizeX * normalizeX + normalizeY * normalizeY), numSegmentsCircle);
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