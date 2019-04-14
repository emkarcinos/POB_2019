package POB_2019.Java.zad2_1;

import java.util.List;
import java.util.ArrayList;

public class Koszyk {
    private List<Produkt> products = new ArrayList<Produkt>();
    private String name;

    public Koszyk(String _name){
        this.name=_name;
    }
    public void addProduct(Produkt product){
        products.add(product);
    }
    private float totalCost(){
        float sum=0;
        for(Produkt p : products)
            sum+=p.getPrice();
        return sum;
    }
    public String toString(){
        String fullDesc="Koszyk " + this.name + ":\n";
        for(Produkt p : products)
            fullDesc = fullDesc + p.toString();
        fullDesc = fullDesc + "Total: " + totalCost() + "\n";
        return fullDesc;
    }
}