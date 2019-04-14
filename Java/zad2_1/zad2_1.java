package POB_2019.Java.zad2_1;

public class zad2_1 {
    public static void main(String[] args){
        Koszyk cart1 = new Koszyk("Marcin");
        cart1.addProduct(new Produkt("Banan", 3.19f));
        cart1.addProduct(new Produkt("Ananas", 5.69f));
        cart1.addProduct(new Produkt("Pomarańcza", 2.99f));
        System.out.println(cart1);
    }
}