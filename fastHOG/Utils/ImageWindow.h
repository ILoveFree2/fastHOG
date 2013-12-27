#ifndef __IMAGE_WINDOW_H__
#define __IMAGE_WINDOW_H__

/*
#include <fltk/Window.h>
#include <fltk/draw.h>
#include <fltk/Rectangle.h>
#include <fltk/Widget.h>
#include <fltk/events.h>
*/

#include "../HOG/HOGImage.h"

//#include <X11/?.h> // for XOpenDisplay
//#include <X11/extensions/XI.h> needed for inlining fltk?

#include <vector>

using namespace HOG;

class ImageWidget //public fltk::Widget
{
	struct rect
	{
		int x, y, w, h;
		rect(int _x, int _y, int _w, int _h) { x = _x; y = _y; w = _w; h = _h; }
	};

	Display *xdisplay; // defined in fltk/x11/run.cxx:497

public:
	std::vector<rect> rects;

	unsigned char* pixels;
	fltk::Rectangle* rectangle;

	ImageWidget(int x, int y, int w, int h) //:
		//fltk::Widget(x, y, w, h)
	{
		rectangle = new fltk::Rectangle(0, 0, w, h);
		// this->box(fltk::BORDER_BOX); // TODO inline
		// this->buttonbox(fltk::FLAT_BOX); // TODO inline
                display = XOpenDisplay(0);
	}

	ImageWidget(int x, int y, int w, int h, unsigned char* pixels) //:
		//fltk::Widget(x, y, w, h)
	{
		this->pixels = pixels;
		rectangle = new fltk::Rectangle(0, 0, w, h);
		//this->box(fltk::BORDER_BOX); // TODO inline
		//this->buttonbox(fltk::FLAT_BOX); // TODO inline
	}

	void draw() // draws image and marks found targets with red boxes
	{
		//fltk::drawimage((unsigned char*) pixels, fltk::RGB32, *rectangle); = draw(Rectangle(rectangle->w(), rectangle->h()), *r) -> TODO code?
		//fltk::setcolor(fltk::RED);
                XSetForeground(xdisplay, gc, 0xff0000); // x11/setcolor.cxx
		for (std::size_t i=0; i<rects.size(); i++) {
			//fltk::strokerect(rects[i].x, rects[i].y, rects[i].w, rects[i].h);
		        XDrawRectangle(xdisplay, xwindow, gc, rects[i].x, rects[i].y, rects[i].w-1, rects[i].h-1); // dont use fltk, call Xlib directly
                }
                //this->redraw(); TODO inline
	}

	void setImage(unsigned char* pixelsNew)
	{
		this->pixels = pixelsNew;
	}

	void drawRect(int x, int y, int w, int h)
	{
		rects.push_back(rect(x,y,w,h));
		//this->redraw(); // TODO
	}
};

class ImageWindow //: public fltk::Window
{
	bool colorImage;

	int width, height;

	ImageWidget* imageWidget;
	//fltk::Window *otherWindow;

public:

	void (*doStuff)();

	ImageWindow(int width, int height, char* title);
	ImageWindow(HOGImage* image, char* title);

	void setImage(HOGImage* image);

	void show(int x = -1, int y = -1);
	void drawRect(int x, int y, int w, int h);

	int handle(int);

	void Close();

	~ImageWindow(void);
};

#endif
