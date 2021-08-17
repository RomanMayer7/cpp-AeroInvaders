
#pragma once
#include "../headers/renderer.h"
#include "../headers/controller.h"
#include "enemy_manager.hpp"
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

  //Forward Declare classes
  class EnemyManager;
  class PlayerManager;
  class Controller;

 class GameManager
 {

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
	PlayerManager* pm;
	EnemyManager* em;

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
	//Intersect** target=nullptr; 
	//Intersect** target2=nullptr;;

    public:

	GameManager(int _width, int _height, Renderer* _renderer,std::size_t _target_frame_duration);
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
};