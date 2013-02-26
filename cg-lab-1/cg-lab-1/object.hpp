#ifndef OBJECT_H
#define OBJECT_H

#include "coords.h"

class object
{
private:
	v3 _pos;
	v3 _specular;
	v3 _diffuse;
	v3 _ambient;
	float _spec_power;
	//float refraction_coeff; //theta
	
public:
	object()
	{
	}
	object(const object&o)
	{
		_pos = o._pos;
		_specular = o._specular;
		_diffuse = o._diffuse;
		_ambient = o._ambient;
		_spec_power = o._spec_power;
	}

	void setParam(v3 pos, v3 specular, v3 diffuse, v3 ambient,float spec_power)
	{
		_pos = pos;
		_specular = specular;
		_diffuse = diffuse;
		_ambient = ambient;
		_spec_power = spec_power;
	}

	~object()
	{
	}
} ;


class plane: public object
{
	float _d;
	v3 _normal;

public:
	plane(v3 normal,float d)
		: _normal(normal), _d(d)
	{
	}


	~plane()
	{
	}

};

class triangle: public object
{
	v3 _a;
	v3 _b;
	v3 _c;


public:
	triangle(v3 a, v3 b, v3 c)
		: _a(a), _b(b), _c(c)
	{
	}

	~triangle()
	{
	}

};

class sphere: public object
{
	float _radius;
public:
	sphere(float radius)
		: _radius(radius)
	{
	}

	~sphere()
	{
	}

};

class cylinder: public object
{
	float _radius;
	float _height;
public:
	cylinder(float radius, float height)
		: _radius(radius), _height(height)
	{
	}

	~cylinder()
	{
	}

};


class conus: public object
{
	float _radius;
	float _height;
public:
	conus(float radius, float height)
		: _radius(radius), _height(height)
	{
	}

	~conus()
	{
	}

};

#endif 