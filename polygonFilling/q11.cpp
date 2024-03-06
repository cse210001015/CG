#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const int WINDOW_POSITION[2] = {100,100};

bool isBoundary(float x, float y){
    unsigned char px[4];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, px);

    unsigned char bd_px[4];
    glReadPixels(190, 130, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, bd_px);

    return px[0] == bd_px[0] && px[1] == bd_px[1] && px[2] == bd_px[2];
}

bool isFilled(float x, float y){
    unsigned char px[4];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, px);

    return px[0] == 255 && px[1] == 255 && px[2] == 255;
}


void floodFill(float x, float y){
    if(isBoundary(x, y)) return;
    if(isFilled(x, y)) return;
    // if(x > 160 || x < 140 || y > 110 || y < 90) return;
    // if(visited.find(make_pair(x, y)) != visited.end()) return;
    // if(visited.find(make_pair(x, y) != visited.end()) return;
    // if(x > 200 || x < 20 || y > 200 || y < 20) return;

    // visited.insert(make_pair(x, y));
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();

    // visited.insert(make_pair(x, y));

    float neighbors[8][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    float fourConnect[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    for(int i = 0; i < 4; i++){
        floodFill(fourConnect[i][0] + x, fourConnect[i][1] + y);
    }

    // for boundary crossings in 8 point algo
    // if neighbor is (x +- 1, y +- 1) we check if the two side-by-side elements are boundary color
    // if they are we dont mess with them
    // cout << x << ' ' << y << '\n';


}
void putPoints(float xc, float yc, float x, float y) 
{       
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc + y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc + y, yc + x);
    glVertex2f(xc + y, yc - x);
    glVertex2f(xc - y, yc + x);
    glVertex2f(xc - y, yc - x);
}

void circleDraw(float xc, float yc, float r)
{
    float x=0,y=r,d=3-2*r;

    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    putPoints(xc, yc, x, y);
    while(x<=y)
    {
        x++;
        if(d<=0)        d = d+4*x+6;
        else            y--,d = d+4*(x-y)+10;
        putPoints(xc, yc, x, y);
    }
    glEnd();
}

void lineDraw(float x0, float y0, float x1, float y1) 
{
    int dx=x1-x0,dy=y1-y0;
    int steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float incX = dx/(double) steps;
    float incY = dy/(double) steps;

    glColor3f(0.5f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for(int i=0;i<=steps;i++) 
    {
        glVertex2f(round(x0),round(y0));
        x0 += incX,y0 += incY;
    }
    glEnd();
}

void displayMe()
{   
    glClear(GL_COLOR_BUFFER_BIT);

    // draw the wheels
    circleDraw(150, 100, 50);
    circleDraw(450, 100, 50);

    // draw lines between the wheels
    lineDraw(190, 130, 410, 130);
    lineDraw(50, 130, 110, 130);
    lineDraw(490, 130, 550, 130);

    // draw the lines to make box 
    lineDraw(50, 130, 50, 200);
    lineDraw(550, 130, 550, 200);
    lineDraw(50, 200, 550, 200);

    // draw slant on back side
    lineDraw(150, 200, 200, 300);

    // draw slant on front side
    lineDraw(400, 300, 450, 200);

    // draw the roof of the car
    lineDraw(400, 300, 200, 300);

    
    floodFill(150, 100);    
   
    
    glFlush();
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(WINDOW_POSITION[0], WINDOW_POSITION[1]);
    glutCreateWindow("Car Filling");
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
