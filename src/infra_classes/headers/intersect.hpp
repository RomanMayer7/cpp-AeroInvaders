
#pragma once
//Definition of 'Intersect' Interface 

class Intersect
 {
       public:
        virtual bool intersect(int x1,int y1,int x2,int y2) = 0;
        virtual void hit() = 0;
 };