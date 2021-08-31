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
    //----Refactor Code to use Smart Pointers----
    //RectSprite(int w,int h,RColor*  color);
	//RectSprite(int x,int y,int w,int h,RColor*  color);
    RectSprite(int w,int h,std::shared_ptr<RColor> c);
	RectSprite(int x,int y,int w,int h,std::shared_ptr<RColor> c);

	// provide implementation of abstract methods:
	void update() override;

	// check if sprite's visible before painting
    //----Refactor Code to use Smart Pointers----
    //void paint(Renderer* r); //override;
    void paint(std::shared_ptr<Renderer> r); //override;
};
