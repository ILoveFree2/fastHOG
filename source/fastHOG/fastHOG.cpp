/*
 * fastHog.cpp
 *
 *  Created on: May 14, 2009
 *      Author: viprad
 */

#include <stdio.h>

#include "HOG/HOGEngine.h"
#include "HOG/HOGImage.h"

#include "Utils/ImageWindow.h"
#include "Utils/Timer.h"

#include "Others/persondetectorwt.tcc"

using namespace HOG;

HOGImage* image;

void doStuffHere()
{

	ImageWindow *fastHOGWindow = ImageWindow::getInstance();
/*
	fastHOGWindow->drawRect(277, 164, 138, 227);
	fastHOGWindow->drawRect(148, 109, 144, 288);
	fastHOGWindow->drawRect(233, 121, 135, 271);
	fastHOGWindow->drawRect(119, 139, 104, 208);
	fastHOGWindow->drawRect( 45, 115, 117, 235);
	fastHOGWindow->drawRect(-35, 288, 113, 226);

	return;
*/
	HOGEngine::Instance()->InitializeHOG(image->width, image->height,
			PERSON_LINEAR_BIAS, PERSON_WEIGHT_VEC, PERSON_WEIGHT_VEC_LENGTH);

	//HOGEngine::Instance()->InitializeHOG(image->width, image->height,
	//		"Files//SVM//head_W24x24_C4x4_N2x2_G4x4_HeadSize16x16.alt");
       
	Timer t;
	t.restart();
	HOGEngine::Instance()->BeginProcess(image);
	HOGEngine::Instance()->EndProcess();
	t.stop(); t.check("Processing time");

	printf("Found %d positive results.\n", HOGEngine::Instance()->formattedResultsCount);

	for (int i=0; i<HOGEngine::Instance()->nmsResultsCount; i++)
	{
		printf("%1.5f %1.5f %4d %4d %4d %4d %4d %4d\n",
				HOGEngine::Instance()->nmsResults[i].scale,
				HOGEngine::Instance()->nmsResults[i].score,
				HOGEngine::Instance()->nmsResults[i].origX,
				HOGEngine::Instance()->nmsResults[i].origY,
				HOGEngine::Instance()->nmsResults[i].x,
				HOGEngine::Instance()->nmsResults[i].y,
				HOGEngine::Instance()->nmsResults[i].width,
				HOGEngine::Instance()->nmsResults[i].height);
		                fastHOGWindow->drawRect(HOGEngine::Instance()->nmsResults[i].x, HOGEngine::Instance()->nmsResults[i].y, HOGEngine::Instance()->nmsResults[i].width, HOGEngine::Instance()->nmsResults[i].height);
	}

	printf("Drawn %d positive results.\n", HOGEngine::Instance()->nmsResultsCount);

	HOGEngine::Instance()->FinalizeHOG();
}

int main(int argc, char **argv)
{
        if (argc == 1) {
	     image = new HOGImage("testImage.bmp");
        } else {
             image = new HOGImage(argv[1]);
        }
	ImageWindow::getInstance()->initAndRun(&argc, argv, image, "fastHOG", doStuffHere);
	doStuffHere();

	// no return from initAndRun ...
	return 0;
}
