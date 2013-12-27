#include "ImageWindow.h"

#include <stdio.h>
//#include <fltk/draw.h>

ImageWindow::ImageWindow(int width, int height, char* title)
{
	this->width = width;
	this->height = height;

	imageWidget = new ImageWidget(0, 0, width, height);

	doStuff = 0;
}

ImageWindow::ImageWindow(HOGImage* image, char* title)
{
	this->width = image->width;
	this->height = image->height;

	imageWidget = new ImageWidget(0, 0, image->width, image->height, image->pixels);
}

ImageWindow::~ImageWindow(void)
{
    delete imageWidget;
}

void ImageWindow::show(int x, int y)
{
	if (x == -1 || y == 1) {
		//fltk::Window::show();
	} else {
		//this->position(x, y);
		//fltk::Window::show();
	}
    printf("TODO show()\n");
}

void ImageWindow::setImage(HOGImage* image)
{
	imageWidget->setImage((unsigned char*) image->pixels);
	imageWidget->draw(); 
}

int ImageWindow::handle(int eventId)
{
	int ret = 0;
/*	switch (eventId)
	{
	case fltk::MOVE:
		ret = 1;

		break;
	case fltk::PUSH:

		imageWidget->rects.clear();

		if (doStuff != 0)
			doStuff();

		break;
	}
*/
	return ret;
}

void ImageWindow::drawRect(int x, int y, int w, int h)
{
	imageWidget->drawRect(x, y, w, h);
}


void ImageWindow::Close() { }
