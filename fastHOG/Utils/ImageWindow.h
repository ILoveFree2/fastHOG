#ifndef __IMAGE_WINDOW_H__
#define __IMAGE_WINDOW_H__

#include "../HOG/HOGImage.h"

#include <vector>

using namespace HOG;

class ImageWidget
{
	struct rect
	{
		int x, y, w, h;
		rect(int x_, int y_, int w_, int h_)
                {
                    x = x_;
                    y = y_;
                    w = w_;
                    h = h_;
                };
                rect()
                {
                };
	};

private:
      struct rect bounds_;

public:
	std::vector<rect> rects;

	unsigned char* pixels;

	ImageWidget(int x, int y, int w, int h)
	{
		bounds_.x = x;
                bounds_.y = y;
                bounds_.w = w;
                bounds_.h = h; 
                // OpenDisplay();
	}

	ImageWidget(int x, int y, int w, int h, unsigned char* pixels)
	{
		this->pixels = pixels;
		bounds_.x = x;
                bounds_.y = y;
                bounds_.w = w;
                bounds_.h = h; 
	}

	void draw() // draws image and marks found targets with red boxes
	{
                // TODO draw image
                // TODO draw redboxes
		for (std::size_t i=0; i<rects.size(); i++) {
		        // drawRectangle(rects[i].x, rects[i].y, rects[i].w-1, rects[i].h-1);
                }
                // redraw(); // if necessary
	}

	void setImage(unsigned char* pixelsNew)
	{
		this->pixels = pixelsNew;
	}

	void drawRect(int x, int y, int w, int h)
	{
		rects.push_back(rect(x,y,w,h));
		// redraw(); //  if necessary
	}
};

class ImageWindow
{
	bool colorImage;

	int width, height;

	ImageWidget* imageWidget;

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
