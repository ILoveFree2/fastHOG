#ifndef __IMAGE_WINDOW_H__
#define __IMAGE_WINDOW_H__

#include "../HOG/HOGImage.h"

#include <stdio.h>
#include <vector>

#include <GL/gl.h>
#include <GL/glut.h>

using namespace HOG;

class ImageWindow
{
        struct rect {
              int x,y,w,h;
        };

private:
        char *title;

public:


	ImageWindow(HOGImage* image, char* title);

        void initAndRun(int *argc, char **argv, void (*)(void));

	void drawRect(int x, int y, int w, int h);

	~ImageWindow(void);
        
        HOGImage *image;
	std::vector<struct rect *> rects;
};

#endif
