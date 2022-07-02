#ifndef COLLIDER_H
#define COLLIDER_H

struct Collider
{

    /* ========================== Coordinates for edge
    
        1x------------2x
        |              |
        |              |
        |      c       |
        |              |
        |              |
        3x------------4x
       LEFT = 1x 
       RIGHT = 2x 
       UPPER = 2x 
       BOTTOM = 4x 

    */ 

    /* data */

   int left_corner{};
   int right_corner{};
   int upper_corner{};
   int bottom_corner{};
   float radius{};
   int length{};

   Collider();
   void UpdateCollider(float& x, float& y);   
};
#endif 