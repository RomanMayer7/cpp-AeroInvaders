#include "game_manager.hpp"

GameManager::GameManager(int _width, int _height, Renderer* _renderer,std::size_t _target_frame_duration)
	{
		 std::cout << "GameManager().\n";
          renderer=_renderer;
		  width=_width;
		  height =_height;
		  target_frame_duration =_target_frame_duration;
	}

	void GameManager::init()
    {
       std::cout << "GameManager::init().\n";

	
    //TODO:LOAD IMAGES
    //showStatus("Loading Images -- WAIT!");
	loadImages();
	
    //TODO:LOAD AUDIO

    em =new EnemyManager(5,MAX_LEVEL,width,height,renderer,this);
	//pm = new PlayerManager(MAX_ENERGY,5,width,height,renderer,reinterpret_cast<Intersect**>(em->getEnemies()) );
	pm = new PlayerManager(MAX_ENERGY,5,width,height,renderer,em->getEnemies() );

	controller=new Controller(pm);
	
	em->initialize(pm); // initialize gun parameters

	
	playing = false; // not playing

	//MusicPlayer();//call Music Player to load audio track 
	
	}
		
	void GameManager::MusicPlayer()
	 {	

	 }
	
	// CUSTOMIZE MANAGERS!
	 void GameManager::setOptions(int startLevel,int energyDec,bool sound)
	 {
	   if (startLevel >= 1 && startLevel < MAX_LEVEL)
	    {
	      this->startLevel = startLevel;
	      em->setStartLevel(startLevel); // set startLevel
	    }
	   if (energyDec >= 0 && energyDec <= MAX_ENERGY) 
	   {
	     this->energyDec = energyDec;
	     pm->setEnergyDec(energyDec); // set energy lost
	   }

	 }
	
	// increase score
	 void GameManager::incrementScore()
	 {
	   score += UFO_VALUE;
	 }

	// count number of ufo's(enemies) landed
	 void GameManager::alienLanded()
	{
	  numLanded++;
	  if (numLanded == MAX_LANDED)
	   {
	     gameOver();
	   }
	}
	
     void GameManager::loadImages()
	 {

	 }

	// initialize params for new game
	 void GameManager::newGame()
	{

	   playing=true;
	   score = 0; // no score at start
	   numLanded = 0; // no aliens landed
       //StartMsg=90;//milliseconds to show starting message
	   pm->newGame(); // call newGame in
	   em->newGame(); // manager classes
	   MusicPlayer();
	 }
	
	// handle game over
	 void GameManager::gameOver() 
	{
	  if (playing) 
	   {
	     playing = false;
	     //screen = GAME_OVER;
	   }
	}
	
 
	 void GameManager::start() 
	{
	    //TODO::showStatus("Starting Game!");

    }

	// update managers. only update gun if playing
	 void GameManager::updateManagers() 
	{
	  if (playing) 
	   {
	     pm->update(); //update PlayerManager
		 em->update();  //update GameManager
	   }
	    
	}
	
		
	 void GameManager::paint()
		{
              //std::cerr << "paint()\n";
              //draw window with background image
              renderer->Render();

		      // tell UFOManager and GunManager to paint
		      pm->paint(renderer);  //draw player's aircraft
			  em->paintAll();       //draw enemy aircrafts

              // Update Screen
              SDL_RenderPresent(renderer->background_renderer);
		
		      // draw status info

		      //draw starting message
	    
          }
		
		// the Video Game Loop
		 void GameManager::run()
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
                  renderer->UpdateWindowTitle(score, frame_count,currentLevel);
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
		}
		
		  void GameManager::stop()
		 {
		    //TODO:: showStatus("Game Stopped");

		  }