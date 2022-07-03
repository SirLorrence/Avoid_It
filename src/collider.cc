#include "../include/collider.h"

Collider::Collider(){
    left_corner = 0;
    right_corner = 0;
    upper_corner = 0;
    bottom_corner = 0;
};

    // ========= collision
    // circle

    // int lc_circle{xCoord - circleRadius};
    // int rc_circle{xCoord + circleRadius};
    // int uc_circle{yCoord - circleRadius};
    // int bc_circle{yCoord + circleRadius};
  
    // ========= axe

    // int lc_axe{300};
    // int rc_axe{300 + axeLength};
    // int uc_axe{Axe_coord};
    // int bc_axe{Axe_coord + axeLength};

// This creates the collider and is able to update the collider (recreate) with circles and rectangles
void Collider::UpdateCollider(float& x, float& y){
    left_corner = x - radius;
    right_corner = x + radius + length;
    upper_corner = y - radius;
    bottom_corner = y + radius + length;
}

