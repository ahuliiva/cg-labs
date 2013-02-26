#ifndef LIGHT_H
#define LIGHT_H

#include "coords.h"

class light
{
	v3 _pos;
	v3 _dir;
	v3 _ambient;
	v3 _specular;
	v3 _diffuse;

public:
	light()
	{
	}

	light(const light&l)
		//: _pos(l._pos), _dir(l._dir),_diffuse(l._diffuse), _specular(l._specular), _ambient(l._ambient)
	{
		_pos = l._pos;
		_dir = l._dir;
		_diffuse = l._diffuse;
		_specular = l._specular;
		_ambient = l._ambient;
	}
	
	light(v3 pos, v3 dir, v3 ambient, v3 diffuse, v3 specular)
		: _pos(pos), _dir(dir),_diffuse(diffuse), _specular(specular), _ambient(ambient)
	{
	}

	~light()
	{
	}
};

#endif 