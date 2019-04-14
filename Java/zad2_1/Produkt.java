package POB_2019.Java.zad2_1;

public class Produkt {
    private String name;
    private float  price;

    public Produkt(String _name, float _price){
        this.name=_name;
        this.price=_price;
    }
    public String toString(){
        return String.format("Nazwa: %s\nCena: %.2f\n\n", this.name, this.price);
    }
    public float getPrice(){
        return this.price;
    }
}