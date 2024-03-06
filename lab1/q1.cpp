#include <GL/glut.h>

const int WINDOW_POSITION[2] = {0, 0};
int WINDOW_SIZE[2];
const char* diagramName = "Christmas Tree";
const float GREEN[3] = {0.0f, 1.0f, 0.0f};
const float BROWN[3] = {0.647f, 0.165f, 0.165f};

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

void setColor(const float* colors)
{
    glColor3f(colors[0], colors[1], colors[2]);
}

void displayMe(void)
{
    const float normalizeX = WINDOW_SIZE[0] / 1920.0f;
    const float normalizeY = WINDOW_SIZE[1] / 1080.0f;

    glClear(GL_COLOR_BUFFER_BIT);
    setColor(GREEN);
    float xt[3] = {750 * normalizeX, 1250 * normalizeX, 1000 * normalizeX};
    float yt[3] = {750 * normalizeY, 750 * normalizeY, 850 * normalizeY};
    makeTriangle(xt, yt);
    float xq[4] = {750 * normalizeX, 1250 * normalizeX, 1150 * normalizeX, 850 * normalizeX};
    float yq[4] = {700 * normalizeY, 700 * normalizeY, 750 * normalizeY, 750 * normalizeY};
    makeQuad(xq, yq);
    float *xq1 = xq;
    float yq1[4] = {650 * normalizeY, 650 * normalizeY, 700 * normalizeY, 700 * normalizeY};
    makeQuad(xq1, yq1);
    float xq2[4] = {950 * normalizeX, 1050 * normalizeX, 1050 * normalizeX, 950 * normalizeX};
    float yq2[4] = {550 * normalizeY, 550 * normalizeY, 650 * normalizeY, 650 * normalizeY};
    setColor(BROWN);
    makeQuad(xq2, yq2);
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