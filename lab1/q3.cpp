#include <GL/glut.h>
#include <bits/stdc++.h>


const int WINDOW_POSITION[2] = {0, 0};
const int numSegmentsCircle = 1000;
int WINDOW_SIZE[2];
const char* diagramName = "Cycle";

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
    glBegin(GL_LINE_LOOP);

    for(int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = xc + rad * cos(theta);
        float y = yc + rad * sin(theta);
        glVertex2f(x, y);
    }

    glEnd();    
}

void makePolygonOutline(float* x, float* y, int cnt)
{
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < cnt; i++)        glVertex2f(x[i], y[i]);
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
    float xc = 400;
    float yc = 400;
    float rad = 100;
    makeCircle(xc * normalizeX, yc * normalizeY, rad * sqrt(normalizeX * normalizeX + normalizeY * normalizeY), numSegmentsCircle);
    xc = 800;
    makeCircle(xc * normalizeX, yc * normalizeY, rad * sqrt(normalizeX * normalizeX + normalizeY * normalizeY), numSegmentsCircle);
    float xt[3] = {400, 600, 600};
    float yt[3] = {400, 400, 600};
    makePolygonOutline(mult(xt, 3, normalizeX), mult(yt, 3, normalizeY), 3);
    float xt1[3] = {600, 600, 800};
    float yt1[3] = {400, 600, 600};
    makePolygonOutline(mult(xt1, 3, normalizeX), mult(yt1, 3, normalizeY), 3);
    float xl[2] = {800, 800};
    float yl[2] = {400, 600};
    makePolygonOutline(mult(xl, 2, normalizeX), mult(yl, 2, normalizeY), 2);
    float xq[4] = {575, 625, 625, 575};
    float yq[4] = {600, 600, 625, 620};
    makePolygonOutline(mult(xq, 4, normalizeX), mult(yq, 4, normalizeY), 4);
    float xl1[2] = {750, 825};
    float yl1[2] = {650, 575};
    makePolygonOutline(mult(xl1, 2, normalizeX), mult(yl1, 2, normalizeY), 2);
    float xl2[2] = {750, 765};
    float yl2[2] = {650, 665};
    makePolygonOutline(mult(xl2, 2, normalizeX), mult(yl2, 2, normalizeY), 2);
    float xl3[2] = {825, 840};
    float yl3[2] = {575, 590};
    makePolygonOutline(mult(xl3, 2, normalizeX), mult(yl3, 2, normalizeY), 2);
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
