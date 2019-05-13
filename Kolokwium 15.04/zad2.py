#!/usr/bin/env python3

class Owner():
    def __init__(self, _name, _surname):
        self.name=_name
        self.surname=_surname
    def __str__(self):
        return "%s %s" % (self.name, self.surname)

class Car(Owner):
    def __init__(self, _brand, _owner):
        self.brand=_brand
        self.owner=_owner
    def __str__(self):
        return "%s, %s %s" % (self.brand, self.owner.name, self.owner.surname)

class Parking(Car):
    def __init__(self, _parkingSpaces):
        self.cars=[]
        self.parkingSpaces=_parkingSpaces
    def addCar(self, car):
        if len(self.cars)>=self.parkingSpaces:
            return;
        else:
            self.cars.append(car)
    def removeCar(self, selectedCar):
        if selectedCar in self.cars:
            self.cars.remove(selectedCar)
    def count(self):
        return str(len(self.cars))
    def freePlaces(self):
        return str(self.parkingSpaces-len(self.cars))
    def __str__(self):
        sStream=''
        sStream=sStream + str(len(self.cars)) + ' cars:\n'
        for car in self.cars:
            sStream=sStream + str(car) + '\n'
        return sStream
parking = Parking(3)

owner1 = Owner("Jan", "Sienkiewicz")
owner2 = Owner("Marek", "Kowalski")

car1 = Car("Renault", owner1)
car2 = Car("BMW", owner2)
car3 = Car("Opel", owner1)
car4 = Car("Mercedes", owner1)

parking.addCar(car1)
parking.addCar(car2)
parking.addCar(car3)
parking.addCar(car4)
parking.removeCar(car3)
parking.addCar(car4)

print(parking)