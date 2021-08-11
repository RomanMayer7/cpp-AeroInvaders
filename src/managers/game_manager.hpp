#include "../headers/renderer.h"
#include "../headers/controller.h"
#include "player_manager.hpp"
//#include "enemy_manager.hpp"

#define REFRESH_RATE 60 // in ms
#define INTRO 0 // intro screen
#define GAME_OVER 1 // game over screen
#define GAMEPLAY 2
#define UFO_VALUE 130 // 130 points
#define MAX_LANDED 5 // at most 5 alienscan land
#define MAX_LEVEL 9 //
#define MAX_ENERGY 113 

 class GameManager {

	//Graphics offscreen;
	//Image image;
	//Image ufoImages[] = new Image[3]; // 3 ufo Images
	//Image attackImages[] = new Image[3]; // 3 attack Images
	//Image explodeImages[] = new Image[18];// 18 explode Images
	//Image ufo2Images[]=new Image[1];
	//Image ufo2atckImages[]=new Image[1];

	//Image cityBG;//Background Image
	
    //int StartMsg=90;//milliseconds to show starting message

    //std::string StartMessage="Go!!";//starting message
    //Image StartMessageImg;//alternative image starting message
    
	//Image gunImages[]=new Image[5]; // player aircraft images
	//AudioClip expsound; // explosion sound
	//AudioClip shot; //when shooting
	
    private:
	// state of game
	bool playing; 
    int score;
	int screen; // which screen to show
    
    Renderer* renderer;
	Controller* controller;
    //Controller& controller;
	PlayerManager* gm;
	//EnemyManager um;

	int numLanded; // num of enemies landed
	
	std::string  scoreString = "Score: ";
	std::string  ufoLandedString = "Enemies passed: ";
	std::string  gameOverString = " GAME OVER ";
	std::string  gameName = "AERO INVADERS";
	int stringWidth;
	std::string  clickString = "Shift-Click to Continue";
	//std::string  introString[11];
	
	
	int width, height; // window dimensions
	
	
	// customizable parameters
	int startLevel;
	int energyDec;
	bool sound;
	std::size_t target_frame_duration;
	//***********************************************************************************************************
	Intersect** target=nullptr; 
	Intersect** target2=nullptr;;

    public:

	GameManager(int _width, int _height, Renderer* _renderer,std::size_t _target_frame_duration)
	{
		 std::cout << "GameManager().\n";
          renderer=_renderer;
		  width=_width;
		  height =_height;
		  target_frame_duration =_target_frame_duration;
	}

	void init()
    {
       std::cout << "GameManager::init().\n";
	//setBackground(Color.black); // applet background
	//width =610; // set window dimensions
	//height = 710;
	
    //LOAD IMAGES
    //showStatus("Loading Images -- WAIT!");
	loadImages();
	
    //LOAD AUDIO
	// try {
	// 	expsound = getAudioClip(getCodeBase(),"BOMB.WAV");
	// 	level1sound=getAudioClip(getCodeBase(),"The Shadows - Riders In The Sky.wav");
	// 	shot=getAudioClip(getCodeBase(),"SHOT.wav");
	// 	}
	// catch (Exception e) {System.out.println("The problem with audioclip loading\n"+e.getMessage()); }

    //**************************************************************************************************************	
    // um = new UFOManager(2,MAX_LEVEL,width,height,ufoImages,
	// 			attackImages,explodeImages,ufo2Images,ufo2atckImages,
	// 			this,expsound,congratulis,shot);

	gm = new PlayerManager(MAX_ENERGY,5,width,height,renderer,target,target2/* ,um.getUFO(),um.getUFO2(),this*/);
	controller=new Controller(gm);
	
	//um.initialize(gm); // initialize gun parameters

	
	playing = false; // not playing

	//MusicPlayer();//call Music Player to load audio track for the Intro
	
	}
	
	
	  void MusicPlayer()
	 {	
	    // switch(screen)
	    //  {
	    //    case INTRO:introsound.play();
	    //    break;
	    //    case GAMEPLAY:introsound.stop();  level1sound.play();
	    //    break;
	    //  }
	  }
	

	// CUSTOMIZE MANAGERS!
	 void setOptions(int startLevel,int energyDec,bool sound)
	 {
	   if (startLevel >= 1 && startLevel < MAX_LEVEL)
	    {
	      this->startLevel = startLevel;
	      //um->setStartLevel(startLevel); // set startLevel
	    }
	   if (energyDec >= 0 && energyDec <= MAX_ENERGY) 
	   {
	     this->energyDec = energyDec;
	     gm->setEnergyDec(energyDec); // set energy lost
	   }
	   //this.sound = sound;
	   //um.setSound(sound); // set sound
	 }
	
	// increase score
	 void incrementScore()
	 {
	   score += UFO_VALUE;
	 }

	// count number of ufo's(enemies) landed
	 void alienLanded()
	{
	  numLanded++;
	  if (numLanded == MAX_LANDED)
	   {
	     gameOver();
	   }
	}
	
     void loadImages()
	 {

	 }

	// GameManager’s newGame():
	// initialize params for new game
	 void newGame()
	{

	   playing=true;
	   score = 0; // no score
	   numLanded = 0; // no aliens landed
       //StartMsg=90;//milliseconds to show starting message
	   gm->newGame(); // call newGame in
	   //um->newGame(); // manager classes
	   MusicPlayer();
	 }
	
	// handle game over
	 void gameOver() 
	{
	  if (playing) 
	   {
	     playing = false;
	     screen = GAME_OVER;
	   }
	}
	
 
	 void start() 
	{
	    //showStatus("Starting Game!");
	    //animation = new Thread(this);
	    //if (animation != null)
	    //{
		//   animation.start();
		//}
    }

	// update managers. only update gun if playing
	 void updateManagers() 
	{
	  if (playing) 
	   {
	     gm->update(); //update PlayerManager
	   }
	  //um.update();
	}
	
		
	 void paint()
		{
              //std::cerr << "paint()\n";
		      //offscreen.setColor(Color.white);
		      //offscreen.fillRect(0,0,width,height); // clear buffer

		      //g.drawImage(cityBG, 0, 0, this);

              //draw window with background image
              renderer->Render();

		      // tell UFOManager and GunManager to paint
		      gm->paint(renderer);  //draw player's aircraft


                   // Update Screen
                SDL_RenderPresent(renderer->background_renderer);

		      //um.paint(renderer->background_renderer));  //draw enemies
		
		      // draw status info
		    //   offscreen.setFont(mediumFont);
		    //   offscreen.setColor(Color.red);
		    //   offscreen.drawString(scoreString+score,width - 130,13);
		    //   offscreen.drawString(ufoLandedString+numLanded,width - 130,27);
		    //   offscreen.drawString("Level:"+" "+(um.level-1),width/2,13);

		      //draw starting message
		    //   if (StartMsg>0)
		    //    {
		    //      //offscreen.drawString(StartMessage, width/2,height/2);
		    //        offscreen.drawImage(StartMessageImg, (width/2)-130, (height/2)-60, this);
		    //        StartMsg--; //decreasing the time to show message
		    //    }

		    //g.drawImage(image,0,0,this);
	    
          }
		
		// the Video Game Loop
		 void run()
		{

           Uint32 title_timestamp = SDL_GetTicks();
           Uint32 frame_start;
           Uint32 frame_end;
           Uint32 frame_duration;
           int frame_count = 0;
           bool running = true;

           while (running)
		    {
              frame_start = SDL_GetTicks();
              // Input, Update, Render - the main game loop.
              controller->HandleInput(running/*, snake*/);
              //Update();
              renderer->Render(/*snake, food*/);
			  paint();
		      updateManagers();
              frame_end = SDL_GetTicks();

              // Keep track of how long each loop through the input/update/render cycle
              // takes.
              frame_count++;
              frame_duration = frame_end - frame_start;

              // After every second, update the window title.
              if (frame_end - title_timestamp >= 1000)
			   {
                  renderer->UpdateWindowTitle(score, frame_count);
                  frame_count = 0;
                  title_timestamp = frame_end;
               }

              // If the time for this frame is too small (i.e. frame_duration is
              // smaller than the target ms_per_frame), delay the loop to
              // achieve the correct frame rate.
              if (frame_duration < target_frame_duration) {
                 SDL_Delay(target_frame_duration - frame_duration);
              }
           }       

		  //while (true) 
		    //{
		      //paint();
		      //updateManagers();
		      //Thread.currentThread().yield();
		    //   try 
		    //    {
		    //      Thread.sleep (REFRESH_RATE);
		    //    } 
		    //   catch (Exception exc) { };
		    //}
		}
		
		  void stop()
		 {
		 // showStatus("Game Stopped");
		//   if (animation != null) 
		//      {
		//       animation.stop();
		//       animation = null;
		//      }
		  }
		};