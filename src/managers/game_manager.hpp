
#pragma once
#include "../headers/renderer.h"
#include "../headers/controller.h"
#include "enemy_manager.hpp"
#include "player_manager.hpp"
//#include "enemy_manager.hpp"
#include <memory>

#define REFRESH_RATE 60 // in ms
#define INTRO 0 // intro screen
#define GAME_OVER 1 // game over screen
#define GAMEPLAY 2
#define UFO_VALUE 130 // 130 points per enemy
#define MAX_LANDED 5 // at most 5 enemies can land
#define MAX_LEVEL 9 //
#define MAX_ENERGY 113 

  //Forward Declare classes
  class EnemyManager;
  class PlayerManager;
  class Controller;

//----Refactor Code to use Smart Pointers----
 class GameManager
 //class GameManager:public std::enable_shared_from_this<GameManager>
 {

    //int StartMsg=90;//milliseconds to show starting message
    //std::string StartMessage="Go!!";//starting message
	//AudioClip expsound; // explosion sound
	//AudioClip shot; //when shooting
	//int screen; // which screen to show

    private:
	// state of the game
	bool playing; 
    int score;
	
    //----Refactor Code to use Smart Pointers----
    /*Renderer* renderer;
	Controller* controller;
	PlayerManager* pm;
	EnemyManager* em;
	*/
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Controller> controller;
	std::shared_ptr<PlayerManager> pm;
	std::shared_ptr<EnemyManager> em;

	int numLanded; // num of enemies landed
	
	std::string  scoreString = "Score: ";
	std::string  ufoLandedString = "Enemies passed: ";
	std::string  gameOverString = " GAME OVER ";
	std::string  gameName = "AERO INVADERS";
	//int stringWidth;
	//std::string  clickString = "Shift-Click to Continue";
	//std::string  introString;
	
	int width, height; // window dimensions
	
	// customizable parameters
	int startLevel;

	int energyDec;
	bool sound;
	std::size_t target_frame_duration;
	//***********************************************************************************************************

    public:
    //----Refactor Code to use Smart Pointers----
	//GameManager(int _width, int _height, Renderer* _renderer,std::size_t _target_frame_duration);
	GameManager(int _width, int _height,const std::shared_ptr<Renderer> _renderer,std::size_t _target_frame_duration);
    int currentLevel;
	void init();
	void MusicPlayer();
	// CUSTOMIZE MANAGERS!
	void setOptions(int startLevel,int energyDec,bool sound);
	// increase score
	 void incrementScore();
	// count number of ufo's(enemies) landed
	 void alienLanded();
     void loadImages();
	// GameManager’s newGame():
	// initialize params for new game
	 void newGame();	
	// handle game over
	 void gameOver();
	 void start();
	// update managers. only update gun if playing
	 void updateManagers();		
	 void paint();
	// the Video Game Loop
	 void run();
	 void stop();
	 std::shared_ptr<GameManager> getGameManager();
};