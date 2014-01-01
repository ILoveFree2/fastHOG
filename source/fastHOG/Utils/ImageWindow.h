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

        HOGImage *image;
	
	ImageWindow() { }
	
	static void glutDraw();
public:

	static ImageWindow *getInstance();

        void initAndRun(int *argc, char **argv, HOGImage *image, char *title, void (*)(void));

	void drawRect(int x, int y, int w, int h);

	~ImageWindow() { }
        
	std::vector<struct rect *> rects;
	
};

#endif
