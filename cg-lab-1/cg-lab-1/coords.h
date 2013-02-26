#ifndef V3_H
#define V3_H

class v3
{
public:
	float _x;
	float _y;
	float _z;


	v3(float x=0, float y=0, float z=0)
		: _x(x), _y(y), _z(z)
	{
	}


	v3(v3 &v)
	{
		_x = (&v)->_x;
		_y = (&v)->_y;
		_z = (&v)->_z;
	}
	
	~v3()
	{
	}
};
#endif