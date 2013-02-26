#ifndef CAM_H
#define CAM_H
#include "coords.h"

class camera
{
public:
	v3 _pos;
	v3 _up;
	v3 _look_at;
	float _fov_x, _fov_y;
	float _dist;

	camera()
		: _pos(0, 0, 0), _up(0, 1, 0), _look_at(1, 0, 0), _fov_x(0), _fov_y(0), _dist(0)
	{
	}

	camera(v3 pos, v3 up, v3 look_at, float fov_x, float fov_y, float dist)
		: _pos(pos), _up(up), _look_at(look_at), _fov_x(fov_x), _fov_y(fov_y), _dist(dist)
	{
	}

	~camera()
	{
	}
};

#endif