#include "../include/Circle.h"
#include "../include/Rectangle.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<Figure*> figures = {
		(Figure*)new Rectangle(10, 2),
		(Figure*)new Rectangle(3, 3),
		(Figure*)new Circle(5),
		(Figure*)new Circle(1)
	};
	for (Figure *f : figures) {
		cout << f->type() << ": area = " << f->area() << "\n";
	}
	return 0;
}
