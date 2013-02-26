
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
#include "glutScene.h"
#include "boost-test.h"
#include "xml.h"

using namespace std;


int main(int argc,char *argv[])
{
	std::string scene_fname;
	int res_x;
	int res_y;
	std::string output;
	
//my_ray_tracing.exe --scene=my_scene.xml --resolution_x=30 --resolution_y=45 --output=my_scene.png
	  try {
		po::options_description desc("Allowed options");
		desc.add_options()
			("help", "produce help message")
			("resolution_x", po::value<int>(&res_x)->default_value(30), "resolution_x")
			("resolution_y", po::value<int>(&res_y)->default_value(45), "resolution_y")
			("scene", po::value<string>(&scene_fname)->default_value("my_scene.xml"), "scene")
			("output", po::value<string>(&output)->default_value("my_scene.png"), "output snapshot");
		po::variables_map vm;        
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("scene")) {
            cout << "scene is loading from "<< vm["scene"].as<string>() << ".\n";
			parse(vm["scene"].as<string>());
        } else {
            cout << "Scene file was not set.\n";
        }



    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

	getchar();


//	testtest();
	mainGlut(argc,argv);
}
