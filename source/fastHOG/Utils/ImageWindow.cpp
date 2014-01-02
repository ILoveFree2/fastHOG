#include "ImageWindow.h"

#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>

static ImageWindow *instance;

void ImageWindow::glutDraw()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ImageWindow *instance = ImageWindow::getInstance();
    // mirror at height / 2
    int width = instance->image->width;
    int height = instance->image->height;
    unsigned char *pixels = instance->image->pixels;
    unsigned char color[width * height * 4];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
              int i = x + y * width;
              int j = x + (height - y) * width;
              for (int c = 0; c < 4; c++) {
                  color[i * 4 + c] = pixels[j * 4 + c];
              }
        }
    }
    glDrawPixels(width, height, GL_BGRA, GL_UNSIGNED_BYTE, &color);
    
    // red boxes
    glColor3ub(255, 0, 0);
    int xOffset = width / 2;
    int yOffset = height / 2;
    for (int i = 0; i < instance->rects.size(); i++) {
        double x1, x2, y1, y2;
        x1 = instance->rects[i]->x;
        x2 = instance->rects[i]->w + x1;
        y1 = instance->rects[i]->y;
        y2 = instance->rects[i]->h + y1;
        
        // scale to [-1,-1]    
        x1 = (x1 - xOffset) / xOffset;
        x2 = (x2 - xOffset) / xOffset;
        y1 = -(y1 - yOffset) / yOffset; // - for mirroring
        y2 = -(y2 - yOffset) / yOffset;


//       printf("rect %d (%d,%d) (%d, %d) -> %f %f %f %f\n", i, instance->rects[i]->x, instance->rects[i]->y, instance->rects[i]->w, instance->rects[i]->h, x1, y1, x2, y2);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x1, y2);

        glVertex2f(x1, y2);
        glVertex2f(x2, y2);

        glVertex2f(x2, y2);
        glVertex2f(x2, y1);

        glVertex2f(x2, y1);
        glVertex2f(x1, y1);
        glEnd();
    }

    glutSwapBuffers();
}

ImageWindow *ImageWindow::getInstance() {
    if (instance == NULL)
        instance = new ImageWindow();
     return instance;
}

void ImageWindow::initAndRun(int *argc, char **argv, HOGImage *image, char *title, void (*func)(void))
{
    this->image = image;
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(image->width, image->height);
    glutCreateWindow(title);
    glutDisplayFunc(glutDraw);
    func();
    glutMainLoop();
}

void ImageWindow::drawRect(int x, int y, int w, int h)
{
   struct rect *rectNew = (struct rect *) malloc(sizeof(struct rect));
   rectNew->x = x;
   rectNew->y = y;
   rectNew->w = w;
   rectNew->h = h;
   rects.push_back(rectNew);
}
