
//Definition of 'Movable' Interface 
#pragma once

class Moveable
 {
       public:
        virtual void setPosition(int x, int y) = 0;
        virtual void setVelocity(int x, int y) = 0;
        virtual void updatePosition() = 0;
 };