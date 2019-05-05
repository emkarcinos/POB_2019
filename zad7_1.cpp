#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Vec2 {
    private:
        int x,y;
    public:
        Vec2(int _x, int _y){
            x=_x;
            y=_y;
        }
        string toString(){
            stringstream s;
            s << "[" << x << ", " << y << "]";
            return s.str();
        }
        Vec2 operator+(const Vec2& vec){
            return Vec2(x+vec.x, y+vec.y);
        }
        Vec2 operator-(const Vec2& vec){
            return Vec2(x-vec.x, y-vec.y);
        }
        Vec2& operator+=(const Vec2& vec){
            x=vec.x+x;
            y=vec.y+y;
            return *this;
        }
        Vec2& operator-=(const Vec2& vec){
            x=vec.x-x;
            y=vec.y-y;
            return *this;
        }
        float operator*(const Vec2& vec){
            return (float)x*vec.x + (float)y+vec.y;
        }
        bool operator==(const Vec2& vec){
            if(x==vec.x && y==vec.y) return 1;
            else return 0;
        }
        bool operator!=(const Vec2& vec){
            if(x==vec.x && y==vec.y) return 0;
            else return 1;
        }
};

int main(){
    Vec2 vec1 = Vec2(5,1);
    Vec2 vec2 = Vec2(3,4);
    Vec2 vec3 = vec1 + vec2;
    cout << vec3.toString() << endl;
    vec3+=vec2;
    cout << vec3.toString() << endl;
    vec3-=vec1;
    cout << vec3.toString() << endl;
    cout << vec3*vec2 << endl;
}