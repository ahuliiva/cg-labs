#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "camera.hpp"
#include "light.hpp"
#include "object.hpp"

class scene
{
private:
	std::vector<light> _lights;
	camera _camera;
	std::vector<object> _objects;

public:

	void setCamera(camera cam)
	{
		_camera = cam;
	}
	
	void addLight(light l)
	{
		_lights.push_back(l);
	}

	void addObject(object o)
	{
		_objects.push_back(o);
	}
};


#endif