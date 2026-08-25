/* Based on the viewing angle, subtract 30 degrees (half of the FOV).
Starting from column 0:
Cast a ray. (The term “cast” is a bit confusing. Imagine the player as a wizard who can “cast” rays instead of spells. The ray is just an “imaginary” line extending from the player.)
 Trace the ray until it hits a wall.
Record the distance to the wall (the distance is equal to the length of the ray).
Add the angle increment so that the ray moves to the right (we know from Figure 10 that the value of the angle increment is 60/320 degrees).
Repeat step 2 and 3 for each subsequent column until all 320 rays are cast.


Dimension of the Projection Plane = 320 x 200 units
Center of the Projection Plane = (160,100)
Distance to the Projection Plane = 277 units
Angle between subsequent rays = 60/320 degrees */

#include "cub3d.h"