#include "bird.h"





void bird::setup(int X,int Y)
{
	x = X;
	y = Y;
}

void bird::draw()
{
	ofDrawCircle(x, y, 1.5);
	ofPolyline curvedSegmentPolyline;
	curvedSegmentPolyline.curveTo(x- 16, y + 5);
	curvedSegmentPolyline.curveTo(x- 16, y + 5);
	curvedSegmentPolyline.curveTo(x+11, y+23);
	curvedSegmentPolyline.curveTo(x+41, y+55);
	curvedSegmentPolyline.curveTo(x+94, y+52);
	curvedSegmentPolyline.curveTo(x+128, y+69);
	curvedSegmentPolyline.curveTo(x+128, y + 69);
	curvedSegmentPolyline.draw();

	ofPolyline line2;
	line2.curveTo(-16+x, 5+y);
	line2.curveTo(-16+x, 5+y);
	line2.curveTo(-7+x, y-2);
	line2.curveTo(2+x, y-15);
	line2.curveTo(18+x, y-13);
	line2.curveTo(18+x, y-13);
	line2.draw();
	if (ofGetFrameNum() % 2 == 0)
	{
		ofPolyline wing1_1;
		wing1_1.curveTo(x+18, y-13);
		wing1_1.curveTo(x+18, y-13);
		wing1_1.curveTo(x+45, y-61);
		wing1_1.curveTo(x+92, y-78);
		wing1_1.curveTo(x+92, y-78);
		wing1_1.draw();

		ofPolyline wing1_2;
		wing1_2.curveTo(x+92, y-78);
		wing1_2.curveTo(x+92, y-78);
		wing1_2.curveTo(x+89, y-68);
		wing1_2.curveTo(x+86, y-30);
		wing1_2.curveTo(x+69, y-13);
		wing1_2.curveTo(x+69, y-13);
		wing1_2.draw();

		ofPolyline wing2_1;
		wing2_1.curveTo(x+86, y-30);
		wing2_1.curveTo(x+86, y-30);
		wing2_1.curveTo(x+110, y-39);
		wing2_1.curveTo(x+138, y-39);
		wing2_1.curveTo(x+166, y-25);
		wing2_1.curveTo(x+166, y-25);
		wing2_1.draw();

		ofPolyline wing2_2;
		wing2_2.curveTo(x+166, y-25);
		wing2_2.curveTo(x+166, y-25);
		wing2_2.curveTo(x+147, y-19);
		wing2_2.curveTo(x+126, y);
		wing2_2.curveTo(x+96, y+10);
		wing2_2.curveTo(x+96, y+10);
		wing2_2.draw();
	}


	else
	{
		
		ofPolyline wing1_3;
		wing1_3.curveTo(x+18, y-13);
		wing1_3.curveTo(x+18, y-13);
		wing1_3.curveTo(x+6, y+21);
		wing1_3.curveTo(x+14, y+64);
		wing1_3.curveTo(x+14, y+64);
		wing1_3.draw();

		ofPolyline wing1_4;
		wing1_4.curveTo(x+59, y+17);
		wing1_4.curveTo(x+59, y+17);
		wing1_4.curveTo(x+45, y+31);
		wing1_4.curveTo(x+23, y+49);
		wing1_4.curveTo(x+14, y+64);
		wing1_4.curveTo(x+14, y+64);
		wing1_4.draw();

		ofPolyline wing2_3;
		wing2_3.curveTo(x+18, y-13);
		wing2_3.curveTo(x+18, y-13);
		wing2_3.curveTo(x+31, y-12);
		wing2_3.curveTo(x+49, y-23);

		wing2_3.curveTo(x+81, y-26);
		wing2_3.curveTo(x+81, y-26);
		wing2_3.draw();

		ofPolyline wing2_4;
		wing2_4.curveTo(x+81, y-26);
		wing2_4.curveTo(x+81, y-26);

		wing2_4.curveTo(x+75, y-18);
		wing2_4.curveTo(x+72, y+1);
		wing2_4.curveTo(x+96, y+10);
		wing2_4.curveTo(x+96, y+10);

		wing2_4.draw();
	}

	ofPolyline tail1;
	tail1.curveTo(x+96, y+10);
	tail1.curveTo(x+96, y+10);
	tail1.curveTo(x+116, y+27);
	tail1.curveTo(x+149, y+30);
	tail1.curveTo(x+149, y+30);
	tail1.draw();

	ofPolyline tail2;
	tail2.curveTo(x+149, y+30);
	tail2.curveTo(x+149, y+30);
	tail2.curveTo(x+135, y+44);
	tail2.curveTo(x+128, y+69);
	tail2.curveTo(x+128, y+69);
	tail2.draw();
}