package POB_2019.Java.zad1_1;

import java.util.ArrayList;
import java.util.List;

public class zad1_1 {
    public static void main(String[] args) {
        List<Przedmiot> subjects = new ArrayList<Przedmiot>();
        subjects.add(new Przedmiot("Ball"));
        subjects.add(new Przedmiot("Chair"));
        subjects.add(new Przedmiot("Table"));
        for(Przedmiot p : subjects){
            System.out.println(p);
        }
    }
}
