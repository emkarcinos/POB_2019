#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

class Person;
class Vehicle;

class Entity {
    private:
        static int nextId;
    protected:
        static vector<Entity*> entities;
        int id;
    public:
        Entity(){
            id=nextId++;
            entities.push_back(this);
        }
        static Entity* getEntityById(int _id){
            for(Entity *entity : entities){
                if (entity->id==_id)
                    return entity;
            }
            cout << "Could not find any entity with id " << _id << ".\n";
            return nullptr;
        }
        int getId(){
            return id;
        }
        virtual ~Entity(){
            for(unsigned int i=0; i<=entities.size(); i++){
                if (entities[i]->id==id)
                    entities.erase(entities.begin()+i);
            }
        }
};

int Entity::nextId=0;
vector <Entity*> Entity::entities;

class Vehicle : public Entity {
    friend class Person;
    private:
        set<int> idsInside;
        const short unsigned int limit=5;
    public:
        void addPerson(Person &person);
        int occupiedSpaces(){
            return idsInside.size();
        }
        void whoIsInside(){
            cout << "People inside car " << id << ":\n";
            if(idsInside.size()==0)
                return;
            for(int pid : idsInside){
                cout << pid << endl;
            }
            return;
        }
        virtual ~Vehicle();
};

class Person : public Entity {
    friend class Vehicle;
    private:
        int vehicleId;
        bool isInVehicle;
    public:
        Person(){
            vehicleId=-1;
            isInVehicle=false;
        }
        void getOut(){
            if(vehicleId==-1){
                cout << "This person is not inside any vehicle.\n";
                return;
            }
            Vehicle* vehicle=(Vehicle*)getEntityById(vehicleId);
            vehicle->idsInside.erase(vehicle->idsInside.find(id));
            vehicleId=-1;
            isInVehicle=false;
        }
        virtual ~Person(){
            getOut();
        }
};

void Vehicle::addPerson(Person &person){
    if(idsInside.size()>=limit) {
        cout << "This vehicle has no more room for another passenger.\n";
        return;
    } else if (person.isInVehicle==true){
        cout << "The person is alredy in some other vehicle.\n";
        return;
    } else {
        idsInside.insert(person.getId());
    person.isInVehicle=true;
        person.vehicleId=id;
    }
}

Vehicle::~Vehicle(){
    for(int id : idsInside){
        Person* personInside=(Person*)getEntityById(id);
        personInside->getOut();
    }
}
        
int main(){
    vector<Person*> people;
    for(int i=0; i<10; i++)
        people.push_back(new Person);
    Vehicle* car1=new Vehicle();
    for(Person *newguy : people)
        car1->addPerson(*newguy);
    delete people[0];
    people.erase(people.begin());
    car1->whoIsInside();
    delete car1;
    Vehicle* car2=new Vehicle();
    for(Person *newguy : people)
        car2->addPerson(*newguy);
    car2->whoIsInside();
}