#include <vector>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Shape
{
public:
	virtual void draw(Mat &img) = 0;
};

class Circle : public Shape
{
public:
	Circle(int x, int y, int r)
		: _x(x), _y(y), _r(r) {}

	virtual void draw(Mat &img) {
		circle(img, Point(_x, _y), _r, Scalar(0,0,0));
	}

private:
	int _x, _y, _r;
};

class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, int w, int h)
		: _x(x), _y(y), _w(w), _h(h) {}

	virtual void draw(Mat &img) {
		rectangle(img, Point(_x, _y),
			Point(_x+_w, _y+_h), Scalar(0,0,0));
	}

private:
	int _x, _y, _w, _h;
};

int main()
{
	const char wnd[] = "test";
	namedWindow(wnd, WINDOW_AUTOSIZE);
	int width = 1000, height = 800;

	vector<Shape*> shapes {
		new Circle(300, 200, 100),
		new Rectangle(500, 200, 300, 100),
		new Circle(500, 600, 100),
		new Rectangle(100, 400, 100, 150)
	};

	Mat img = Mat::zeros(height, width, CV_8UC3);

	while (true)
	{
		img = Scalar(255,255,255);
		for (Shape* shape : shapes) {
			shape->draw(img);
		}
		imshow(wnd, img);
		int key = waitKey(40);
		if ((key & 255) == 27) break;
	}

	for (Shape* shape : shapes) delete shape;
        	shapes.clear();


	return 0;
}