#pragma once

#include "rect_sprite.hpp"
#include "intersect.hpp"
#include "rcolor.hpp"
#include "../headers/enemy_sprite.hpp"

class EnemySprite;

class MissileSprite: public RectSprite {
    
    protected:
        int vy; // velocity in y coordinate
        int start_y; // starting y coord
        int stop_y; // stop at y coord
        
		//----Refactor Code to use Smart Pointers----
        // Intersect** target;
		// EnemySprite** e_target;
	    // Intersect** target2;
	    // Intersect* onetarget;
        std::vector<std::shared_ptr<Intersect>> target;
		std::vector<std::shared_ptr<EnemySprite>> e_target;
		std::vector<std::shared_ptr<Intersect>> target2;
	    std::shared_ptr<Intersect> onetarget;

	//AudioClip missleShotsound;
	int Constructor;//constructor ID

    public:
    
	MissileSprite();
	//----Refactor Code to use Smart Pointers----------------------------------------------------------
	//*******************Constructor for one group of enemies (targets)
	//MissileSprite(int w,int h,RColor* c,int _vy, int _start_y,int _stop_y,Intersect** _target);
	MissileSprite(int w,int h,std::shared_ptr<RColor> c,int _vy, int _start_y,int _stop_y,std::vector<std::shared_ptr<Intersect>>_target);

		//*******************Constructor for one group of enemies (targets)
	//MissileSprite(int w,int h,RColor* c,int _vy, int _start_y,int _stop_y,EnemySprite** _target);
	MissileSprite(int w,int h,std::shared_ptr<RColor> c,int _vy, int _start_y,int _stop_y,std::vector<std::shared_ptr<EnemySprite>>_target);

	//*********************Constructor for one target(player's ship)
	//MissileSprite(int w,int h,RColor* c,int _vy,int _start_y,int _stop_y,Intersect* _target);
	MissileSprite(int w,int h,std::shared_ptr<RColor> c,int _vy,int _start_y,int _stop_y,std::shared_ptr<Intersect> _target);

	//******************************** Constructor for two enemy  groups (arrays) of targets
	//MissileSprite(int w,int h,RColor*  c,int _vy,int _start_y,int _stop_y,
	//		       Intersect** _target,Intersect** _target2);
		MissileSprite(int w,int h,std::shared_ptr<RColor>  c,int _vy,int _start_y,int _stop_y,
			           std::vector<std::shared_ptr<Intersect>> _target , std::vector<std::shared_ptr<Intersect>> _target2);
	//------------------------------------------------------------------------------------------------

	// start the missile at the given x coordinate
	 void init(int x);

     //----Refactor Code to use Smart Pointers-----------
	 //void changeoneTarget(Intersect* target);
	 void changeoneTarget(std::shared_ptr<Intersect> target);

	 void update();
};