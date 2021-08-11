#pragma once

#include "rect_sprite.hpp"
#include "intersect.hpp"
#include "rcolor.hpp"

class MissileSprite: public RectSprite {
    
    protected:
        int vy; // velocity in y coordinate
        int start_y; // starting y coord
        int stop_y; // stop at y coord

        Intersect** target;
	    Intersect** target2;
	    Intersect* onetarget;

	//AudioClip missleShotsound;
	int Constructor;//constructor ID

    public:
    
	MissileSprite();
	//*******************Constructor for one group of enemies (targets)
	MissileSprite(int w,int h,RColor* c,int _vy, int _start_y,int _stop_y,Intersect** _target);

	//*********************Constructor for one target(player's ship)
	MissileSprite(int w,int h,RColor* c,int _vy,int _start_y,int _stop_y,Intersect* _target);

	//******************************** Constructor for two enemy  groups (arrays) of targets
	MissileSprite(int w,int h,RColor*  c,int _vy,int _start_y,int _stop_y,
			       Intersect** _target,Intersect** _target2);

	// start the missile at the given x coordinate
	 void init(int x);

	 void changeoneTarget(Intersect* target);

	 void update();
};