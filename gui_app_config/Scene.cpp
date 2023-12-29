#include "Scene.h"





bool operator==(const Scene::Actor& left, const Scene::Actor& right)
{
	return left.shape_actor == right.shape_actor;
}