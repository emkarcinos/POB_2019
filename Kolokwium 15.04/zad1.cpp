#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Geometry {
    public:
        virtual string type()=0;
        virtual float  volume()=0;
};

class Box : public Geometry {
    private:
        int dimX, dimY, dimZ;
    public:
        Box(int _dimX, int _dimY, int _dimZ){
            dimX=_dimX;
            dimY=_dimY;
            dimZ=_dimZ;
        }
        virtual string type(){
            return "Box";
        }
        virtual float volume(){
            return(dimX*dimZ*dimY);
        }
};

class Ball : public Geometry {
    private:
        int radius;
    public:
        Ball(int _radius){
            radius=_radius;
        }
        virtual string type(){
            return "Ball";
        }
        virtual float volume(){
            return (float)4/3*M_PI*pow(radius, 3);
        }
};

int main()
{
	vector<Geometry*> geometries = {
		(Geometry*)new Box(10, 2, 3),
		(Geometry*)new Box(3, 3, 1),
		(Geometry*)new Ball(5),
		(Geometry*)new Ball(1)
	};
	for (Geometry *f : geometries) {
		cout << f->type() << ": volume = " << f->volume() << "\n";
	}
	return 0;
}