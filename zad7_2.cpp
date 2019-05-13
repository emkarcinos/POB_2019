#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename num>
class Vec2 {
    private:
        num x,y;
    public:
        Vec2(num _x, num _y){
            x=_x;
            y=_y;
        }
        string toString(){
            stringstream s;
            s << "[" << x << ", " << y << "]";
            return s.str();
        }
        Vec2 add(const Vec2& vec){
            return Vec2(x+vec.x, y+vec.y);
        }
        num multiply(const Vec2& vec){
            return (float)x*vec.x + (float)y*vec.y;
        }
};

int main(){
    Vec2<float> vec1 = Vec2<float>(5.5f,1.2f);
    Vec2<float> vec2 = Vec2<float>(3.4f,4.2f);
    Vec2<float> vec3 = vec1.add(vec2);
    cout << vec3.toString() << endl;
}