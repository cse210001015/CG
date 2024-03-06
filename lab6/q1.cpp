#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Global variables
int width = 800;
int height = 600;
int numSides = 3; // Number of sides of the polygon
float polygonVertices[10][2]; // Array to store the vertices of the polygon

// Function to draw the polygon
void drawPolygon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSides; i++) {
        glVertex2f(polygonVertices[i][0], polygonVertices[i][1]);
    }
    glEnd();
}

// Function to perform translation
void translate(float tx, float ty) {
    for (int i = 0; i < numSides; i++) {
        polygonVertices[i][0] += tx;
        polygonVertices[i][1] += ty;
    }
}

// Function to perform rotation
void rotate(float angle) {
    float radians = angle * M_PI / 180.0;
    float centerX = 0.0, centerY = 0.0; // Assuming the center of the polygon is at (0, 0)
    for (int i = 0; i < numSides; i++) {
        float x = polygonVertices[i][0];
        float y = polygonVertices[i][1];
        polygonVertices[i][0] = centerX + (x - centerX) * cos(radians) - (y - centerY) * sin(radians);
        polygonVertices[i][1] = centerY + (x - centerX) * sin(radians) + (y - centerY) * cos(radians);
    }
}

// Function to perform scaling
void scale(float sx, float sy) {
    for (int i = 0; i < numSides; i++) {
        polygonVertices[i][0] *= sx;
        polygonVertices[i][1] *= sy;
    }
}

// Function to perform shear
void shear(float shx, float shy) {
    for (int i = 0; i < numSides; i++) {
        float x = polygonVertices[i][0];
        float y = polygonVertices[i][1];
        polygonVertices[i][0] = x + shx * y;
        polygonVertices[i][1] = y + shy * x;
    }
}

// Function to perform reflection
void reflect() {
    for (int i = 0; i < numSides; i++) {
        polygonVertices[i][1] *= -1;
    }
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color for the polygon
    drawPolygon();
    glFlush();
}

// Function to handle keyboard events
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 't': // Translate
            float tx, ty;
            std::cout << "Enter translation values (tx ty): ";
            std::cin >> tx >> ty;
            translate(tx, ty);
            break;
        case 'r': // Rotate
            float angle;
            std::cout << "Enter rotation angle (in degrees): ";
            std::cin >> angle;
            rotate(angle);
            break;
        case 's': // Scale
            float sx, sy;
            std::cout << "Enter scaling factors (sx sy): ";
            std::cin >> sx >> sy;
            scale(sx, sy);
            break;
        case 'h': // Shear
            float shx, shy;
            std::cout << "Enter shear factors (shx shy): ";
            std::cin >> shx >> shy;
            shear(shx, shy);
            break;
        case 'f': // Reflect
            reflect();
            break;
        case 'q': // Quit
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Function to initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // White background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    std::cout << "Enter the number of sides of the polygon: ";
    std::cin >> numSides;
    std::cout << "Enter the vertices of the polygon (x y):" << std::endl;
    for (int i = 0; i < numSides; i++) {
        std::cin >> polygonVertices[i][0] >> polygonVertices[i][1];
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Polygon Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
