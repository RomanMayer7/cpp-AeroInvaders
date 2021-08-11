#pragma once
#include <iostream>
#include "../../headers/renderer.h"

using namespace std;

class RectSprite : public Sprite2D 
{
    protected:
    int width, height; // dimensions of rectangle

    public:
    RectSprite();
    RectSprite(int w,int h,RColor*  color);
	RectSprite(int x,int y,int w,int h,RColor*  color);

	// provide implementation of abstract methods:
	void update() override;

	// check if sprite's visible before painting
    void paint(Renderer* r); //override;
};
