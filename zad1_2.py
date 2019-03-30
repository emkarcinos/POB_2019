class Vector2D():
    def __init__(self, xCoord, yCoord):
        self.x=xCoord
        self.y=yCoord

    def add(self, vec):
        return Vector2D(self.x+vec.x, self.y+vec.y)
    
    def multiply(self, vec):
        return (float(self.x*vec.x) + float(self.y*vec.y))

    def __str__(self):
        return ("[" + str(self.x) + ", " + str(self.y) + "]")

# test data 

vec1=Vector2D(-3, 1.4)
vec2=Vector2D(2, 2.7)
vec3=vec1.add(vec2)

vec4=vec1.multiply(vec2)

print(vec3)
print(vec4)

