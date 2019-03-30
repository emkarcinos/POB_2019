#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Produkt{
    public:
    float price;
        Produkt(int iId, string iName, float iPrice){
            id=iId;
            name=iName;
            price=iPrice;
        }
        string description(){
            stringstream s;
            s << id << " Nazwa: " << name << "\n" << "Cena: "
            << price << "PLN" << endl;
            return s.str();
        }
    private:
    int id;
    string name;
};

class Koszyk{
    public:
    float due;
        Koszyk(string iClientName){
            clientName=iClientName;
            due=0;
        }
        void dodajProdukt(Produkt produkt){
            products.push_back(produkt);
            due+=produkt.price;
            cout << "Dodano produkt do koszyka" << endl;
        }
        string lacznyKoszt(){
            stringstream s;
            s << "Do zapłaty: " << due << "PLN.\n";
            return s.str();
        }
        string description(){
            stringstream s;
            s << "Koszyk użytkownika " << clientName << "\nProdukty w koszyku\n";
            for(Produkt x : products)
                s << x.description();
            s << endl;
            return s.str();
        }
    private:
        string clientName;
        vector<Produkt> products;

};

int main(){
    vector<Produkt*> products;
    products.push_back(new Produkt(1, "Jabłko", 3.19));
    products.push_back(new Produkt(2, "Pomarańcza", 2.59));
    products.push_back(new Produkt(3, "Banan", 5.99));
    products.push_back(new Produkt(4, "Śliwka", 4.89));

    cout << "Wprowadź nazwę użytkownika: " << endl;
    string username;
    cin >> username;
    Koszyk* koszyk = new Koszyk(username);
    cout << "Witaj " << username << "!\n"
    << "Lista dostępnych produktów:\n";
    for(Produkt *p : products)
        cout << p->description();
    cout << "Aby dodać produkt do koszyka, wprowadź jego numer. Wpisz '0' aby zobaczyć zawartość swojego koszyka.\n";
    while(true){
        while(true){
            string choice;
            cin >> choice;
            int choiceNumber=stoi(choice, nullptr, 10);
            if(choiceNumber > products.size()){
                cout << "Nie ma produktu o takim numerze.\n";
                continue;
            } else if(choiceNumber==0){
                cout << koszyk->description();
                break;
            } else 
                koszyk->dodajProdukt(*products[choiceNumber-1]);
        }
        cout << koszyk->lacznyKoszt() << "\nChcesz zakończyć zakupy i zapłacić? [Y/n]\n";
        string wantExit;
        cin >> wantExit;
        if(wantExit[0]=='Y' || wantExit[0]=='y'){
            cout << "Zapłacono " << koszyk->due << ".\nDziękujemy za zakupy!";
            break;
        }
    }
}
    
