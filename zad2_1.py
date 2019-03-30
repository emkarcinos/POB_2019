class Produkt():
    def __init__(self, id, name, price):
        self.id=id
        self.name=name
        self.price=price
    def __str__(self):
        return str(self.id) + ' Nazwa: ' + self.name + '\n' + 'Cena: ' + str(self.price) + 'PLN'

class Koszyk():
    def __init__(self, clientName):
        self.clientName=clientName
        self.due=0
        self.products=[]
    def dodajProdukt(self, produkt):
        self.products.append(produkt)
        self.due+=produkt.price
        self.due=round(self.due, 2)
        print('Dodano produkt do koszyka')
    def lacznyKoszt(self):
        return "Do zapłaty: " + str(self.due)
    def __str__(self):
        return ('Koszyk użytkownika ' + self.clientName + 
                '\nProdukty w koszyku:\n' +
                '\n'.join(map(str, self.products)))

products=[Produkt(1, 'Jabłko', 3.19),
        Produkt(2, 'Pomarańcza', 2.59), 
        Produkt(3, 'Banan', 5.99),
        Produkt(4, 'Śliwka', 4.89)]

print("Wprowadź nazwę użytkownika: ", end='')
username=input()
koszyk=Koszyk(username)
print("Witaj " + username + "!")
print("Lista dostępnych produktów:")
for product in products:
    print(product)
print("Aby dodać produkt do koszyka, wprowadź jego numer. Wpisz '0' aby zobaczyć zawartość swojego koszyka.")
while True:
    while True:
        choice=int(input())
        if choice > len(products) or choice < 0:
            print("Nie ma produktu o takim numerze.")
            continue
        elif choice==0:
            print(koszyk)
            break
        else:
            koszyk.dodajProdukt(products[choice-1])
    print(koszyk.lacznyKoszt())
    print("Chcesz zakończyć zakupy i zapłacić? [Y/n]", end=' ')
    wantExit=input()
    if wantExit=='Y' or wantExit=='y':
        print("Zapłacono " + str(koszyk.due) + '.')
        print("Dziękujemy za zakupy!")
        break