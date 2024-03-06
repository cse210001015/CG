#include <GL/glut.h>
#include <math.h>

const int WINDOW_POSITION[2] = {100,100};
float matrix[601][601][3];
float bdy[3] = {0.5f, 1.0f, 1.0f};
const float EPSILON = 0.005;

void assign(float* a, float* b)
{
    for(int i=0;i<3;i++)        a[i] = b[i];
}   

void putPt(float* color, int x, int y)
{
    assign(matrix[x][y], color);
}

void lineDraw(float x0, float y0, float x1, float y1) 
{
    int dx=x1-x0,dy=y1-y0;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float incX = dx/(double) steps;
    float incY = dy/(double) steps;

    for(int i=0;i<=steps;i++) 
    {
        putPt(bdy, round(x0),round(y0));
        x0 += incX,y0 += incY;
    }
}

void putPoints(float xc, float yc, float x, float y) 
{       
    float color[3];
    assign(color, bdy);
    putPt(color, round(xc + x), round(yc + y));
    putPt(color, round(xc + x), round(yc - y));
    putPt(color, round(xc - x), round(yc + y));
    putPt(color, round(xc - x), round(yc - y));
    putPt(color, round(xc + y), round(yc + x));
    putPt(color, round(xc + y), round(yc - x));
    putPt(color, round(xc - y), round(yc + x));
    putPt(color, round(xc - y), round(yc - x));
}

void circleDraw(float xc, float yc, float r)
{
    float x=0,y=r,d=3-2*r;

    putPoints(xc, yc, x, y);
    while(x<=y)
    {
        x++;
        if(d<=0)        d = d+4*x+6;
        else            y--,d = d+4*(x-y)+10;
        putPoints(xc, yc, x, y);
    }
}

bool chk(float a, float b)
{
    return abs(a-b) <= EPSILON;
}

bool check(float* old, int x, int y)
{
    return chk(old[0], matrix[x][y][0]) && chk(old[1], matrix[x][y][1]) && chk(old[2], matrix[x][y][2]);
}

void scanline(float* new_)
{
    for(int i=0;i<=600;i++)
    {
        int prev = -1;
        for(int j=0;j<=600;j++)
        {
            if(check(bdy, j, i))
            {
                if(prev == -1)
                {
                    prev = j;
                }
                else
                {
                    for(int k=prev+1;k<j;k++)
                    {
                        putPt(new_, k, i);
                    }
                    prev = -1;
                }
            }
        }        
    }
}

void init()
{
    float color[3] = {0.0f, 0.0f, 0.0f};
    for(int i=0;i<=600;i++)
    {
        for(int j=0;j<=600;j++)
        {
            putPt(color, i, j);
        }
    }
}

void make_matrix()
{
    init();
    
    circleDraw(150, 100, 50);
    circleDraw(450, 100, 50);

    lineDraw(200, 100, 400, 100);
    lineDraw(50, 100, 100, 100);
    lineDraw(500, 100, 550, 100);
    lineDraw(50, 100, 50, 300);
    lineDraw(550, 100, 550, 300);
    lineDraw(50, 300, 550, 300);

    lineDraw(225, 200, 275, 200);
    lineDraw(225, 100, 225, 200);
    lineDraw(275, 100, 275, 200);

    lineDraw(300, 200, 350, 200);
    lineDraw(300, 150, 350, 150);
    lineDraw(300, 150, 300, 200);
    lineDraw(350, 150, 350, 200);

    lineDraw(375, 200, 425, 200);
    lineDraw(375, 150, 375, 200);
    lineDraw(425, 150, 425, 200);
    lineDraw(375, 150, 425, 150);

    float new_[3] = {1.0f, 0.0f, 0.0f};
    scanline(new_);
}

void displayMe()
{
    make_matrix();

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for(int i = 0; i <= 600; i++)
    {
        for(int j = 0; j <= 600; j++)
        {
            float* ma = matrix[i][j];
            glColor3f(ma[0], ma[1], ma[2]);
            glVertex2f(i, j);
        }
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
    glutCreateWindow("Scan Line");
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}