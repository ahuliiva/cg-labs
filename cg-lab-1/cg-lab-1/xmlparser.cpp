#include "pugixml.hpp"
#include <iostream>

#include "scene.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "object.hpp"
#include "coords.h"


void parse_vertex(pugi::xml_node vertex, v3 *v)
{
	float x = vertex.attribute("x").as_float();
	float y = vertex.attribute("y").as_float();
	float z = vertex.attribute("z").as_float();

	v = new v3(x,y,z);
}

void parse_camera(pugi::xml_node camera_node, camera *cam)
{
	v3 pos;
	v3 up;
	v3 look_at;
	float fov_x, fov_y;
	float dist;

	parse_vertex(camera_node.child("pos"), &pos);
	parse_vertex(camera_node.child("up"), &up);
	parse_vertex(camera_node.child("look_at"), &look_at);

	fov_x = camera_node.child("fov_x").attribute("angle").as_float();
	fov_y = camera_node.child("fov_y").attribute("angle").as_float();
	
	dist = camera_node.child("dist_to_near_plane").attribute("dist").as_float();

	cam = new camera(pos, up,look_at,fov_x,fov_y, dist);
}

void parse_light(pugi::xml_node light_node, light *directionLight)
{
    v3 pos;
	v3 dir;
	v3 ambient;
	v3 specular;
	v3 diffuse;

	parse_vertex(light_node.child("pos"), &pos);
	parse_vertex(light_node.child("dir"), &dir);
	parse_vertex(light_node.child("ambient_emission"), &ambient);
	parse_vertex(light_node.child("diffuse_emission"), &diffuse);
	parse_vertex(light_node.child("specular_emission"), &specular);
	
	directionLight = new light(pos, dir, ambient, diffuse, specular);
}

void parse_sphere(pugi::xml_node sphere_node, object *obj)
{
    float rad = sphere_node.child("radius").attribute("r").as_float();
	obj = new sphere(rad);
}

void parse_plane(pugi::xml_node plane_node, object *obj)
{
	v3 normal;
	float d = plane_node.child("D").attribute("d").as_float();
	parse_vertex(plane_node.child("normal"), &normal);
	obj = new plane(normal,d);
}

void parse_triangle(pugi::xml_node triangle_node, object *obj)
{
	v3 a,b,c;
	parse_vertex(triangle_node.child("pos"), &a);
	parse_vertex(triangle_node.child("pos").next_sibling(), &b);
	parse_vertex(triangle_node.child("pos").next_sibling().next_sibling(), &c);
	obj = new triangle(a,b,c);
}

void parse_cylinder(pugi::xml_node cylinder_node, object *obj)
{
    float rad = cylinder_node.child("radius").attribute("r").as_float();
	float h = cylinder_node.child("height").attribute("h").as_float();
	obj = new cylinder(rad, h);
}

void parse_cone(pugi::xml_node cone_node, object *obj)
{
    float rad = cone_node.child("radius").attribute("r").as_float();
	float h = cone_node.child("height").attribute("h").as_float();
	obj = new conus(rad, h);
}



int parse(std::string filename)
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(filename.c_str());

	if (result)
	{
		std::cout << "XML [" << filename << "] parsed without errors, attr value: [" << doc.child("scene").attribute("attr").value() << "]\n\n";
		pugi::xml_node scene_node = doc.child("scene");

		pugi::xml_node camera_node = scene_node.child("camera");
	
		scene scene;
		
		camera cam;
		parse_camera(doc.child("camera"), &cam);
		scene.setCamera(cam);
	

		pugi::xml_node light_nodes = scene_node.child("light");
		for (pugi::xml_node light_node = light_nodes.first_child(); light_node; light_node = light_node.next_sibling())
		{
			light directionLight;
			parse_light(light_node, &directionLight);
			scene.addLight(directionLight);	
		}
		
		
		pugi::xml_node obj_nodes = scene_node.child("objects");
		for (pugi::xml_node obj_node = obj_nodes.first_child(); obj_node; obj_node = obj_node.next_sibling())
		{
			object obj;
			//parse_object(obj_node, &obj);
			scene.addObject(obj);	
		}
		
	}
	else
	{
		std::cout << "XML [" << filename << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << result.description() << "\n";
		std::cout << "Error offset: " << result.offset << " (error at [..." << (filename.c_str() + result.offset) << "]\n\n";
	}
	return 0;
}

