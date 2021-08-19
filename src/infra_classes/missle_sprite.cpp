#include "headers/missle_sprite.hpp"

 MissileSprite::MissileSprite(){}


 MissileSprite::MissileSprite(int w,int h,RColor*  c,int _vy, int _start_y,int _stop_y,Intersect** _target):
                RectSprite(w,h,c)
       {
	      setFill(true); // fill rect sprite
	      vy = _vy; // initialize speed
	      start_y = _start_y; // initialize starting point
	      stop_y = _stop_y; // initialize stopping point
	      target = _target; // initialize targets
	      //this.missleShotsound=missleShotsound;//initializing shot sound
	      Constructor=1;
	      suspend();
	   }

	   	 MissileSprite::MissileSprite(int w,int h,RColor*  c,int _vy, int _start_y,int _stop_y,EnemySprite** _target):
                RectSprite(w,h,c)
       {
	      setFill(true); // fill rect sprite
	      vy = _vy; // initialize speed
	      start_y = _start_y; // initialize starting point
	      stop_y = _stop_y; // initialize stopping point
	      e_target = _target; // initialize targets
	      //this.missleShotsound=missleShotsound;//initializing shot sound
	      Constructor=1;
	      suspend();
	   }

	//*********************Constructor for one target(player's ship)
	  MissileSprite::MissileSprite(int w,int h,RColor*  c,int _vy,int _start_y,int _stop_y,Intersect* _target):
	  RectSprite(w,h,c)
        {
			setFill(true); // fill rect sprite
			vy = _vy; // initialize speed
			start_y = _start_y; // initialize starting point
			stop_y = _stop_y; // initialize stopping point
			onetarget = _target; // initialize targets
			//this.missleShotsound=missleShotsound;//initializing shot sound
			suspend();
			Constructor=2;
		}

	//******************************** Constructor for two target array's
	  MissileSprite::MissileSprite(int w,int h,RColor*  c,int _vy,int _start_y,int _stop_y,
			       Intersect** _target,Intersect** _target2):
				   RectSprite(w,h,c)
        {
	
			setFill(true); // fill rect sprite
			vy = _vy; // initialize speed
			start_y = _start_y; // initialize starting point
			stop_y = _stop_y; // initialize stopping point
			target = _target; // initialize targets
			target2=_target2;//initialize second target's array
			//this.missleShotsound=missleShotsound;//initializing shot sound
			Constructor=3;
			suspend();
		}
	
	// start the missile at the given x coordinate
	 void  MissileSprite::init(int x)
      {
	   //missleShotsound.play();
	   locx = x;
	   locy = start_y;
	   restore();	
	}

	 void  MissileSprite::changeoneTarget(Intersect* target)
     {
	    onetarget=target;	
	 }

	 void  MissileSprite::update() 
    {
		 // std::cout<<"MissileSprite::update()";
	   if ( active && ((e_target!=nullptr) ||(onetarget!=nullptr) ) )
         {
	         // Move Missile
	         locy += vy;

	         if(vy<0)
             {
	            if (locy < stop_y)
                {
				 //std::cout<<"suspend!"<<std::endl;
		         suspend();
                }
		     }
	         if(vy>0)
            {
		       if (locy > stop_y)
              {
		    	  suspend();
              }
		    }
         
		      else 
              {
			 	//if missile hits Target, Suspend it
	             if (Constructor==1)
                 {
					 //std::cout<<"Constructor 1"<<std::endl;
		             for (int i=0; i<9; i++) 
                     {
						//cout<<"Intersect target x:"<<target[i]<<endl;
		              //
					   bool res=false;
					   //cout<<"Result:"<<res<<endl;
					   res=e_target[i]->intersect(locx,locy,locx+width,locy+height);
					   //cout<<"Result:"<<res<<endl;
					   if (res)
                        {
						  cout<<"MISSLE HIT!"<<endl;
	                      e_target[i]->hit(); // tell target it's been hit
		                  //suspend();
		                  break;
		                }
		             }
	     	     }
	             else if(Constructor==2)
                 {
	    	         if (onetarget->intersect(locx,locy,locx+width,locy+height)) 
                     {
	    	 	      onetarget->hit(); // tell target it's been hit
	    	 	      suspend();
	    	         }
	             }
	              else  if (Constructor==3)
                 {
			         for (int i=0; i<9; i++) 
                     {
			 	       if (target[i]->intersect(locx,locy,locx+width,locy+height)) 
                         {
			 	          target[i]->hit(); // tell target it's been hit
			 	          suspend();
                         }
			 	       if (target2[i]->intersect(locx,locy,locx+width,locy+height))
                         {
			 	          target2[i]->hit(); // tell target it's been hit
			 	          suspend();
			 	          break;
			   	        }
			         }				
		         }
			  }
        }
    }