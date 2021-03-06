#include "spaceobject.h"

SpaceObject::SpaceObject(){

}

/*
 * @MethodName: get
 * @Description:
 *			Return specified coordinate
 * @Params:
 *			int t - 0 for x 1 for y
 * @Returns:
 *			int - specified coordinate
 */

int SpaceObject::get(int t){ return coords[t]; }

/*
 * @MethodName: set
 * @Description:
 *			Sets specified coordinate
 * @Params:
 *			int t - 0 for x 1 for y
 *      int v - value of coordinate
 * @Returns:
 *			void
 */

void SpaceObject::set(int t,int v){ coords[t] = v; }

SpaceObject::~SpaceObject(){

}
