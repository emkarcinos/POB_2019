#!/usr/bin/env python3
from turtle import *

class Shape():
    def __init__(self):
        pass
    def draw(self):
        pass

class Circle(Shape):
    def __init__(self, _posX, _posY, _size):
        self.posX=_posX
        self.posY=_posY
        self.size=_size
    def draw(self):
        goto(self.posX, self.posY)
        pendown()
        circle(self.size)
        penup()

class Rect(Shape):
    def __init__(self, _posX, _posY, _sizeX, _sizeY):
        self.posX=_posX
        self.posY=_posY
        self.sizeX=_sizeX
        self.sizeY=_sizeY
    def draw(self):
        goto(self.posX, self.posY)
        pendown()
        for i in range(2):
            forward(self.sizeX)
            right(90)
            forward(self.sizeY)
            right(90)
        penup()
penup()
shapes=[Circle(-200,100,100),
        Rect(100,100,200,100)]
for shape in shapes:
    shape.draw()