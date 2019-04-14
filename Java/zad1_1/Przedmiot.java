package POB_2019.Java.zad1_1;

public class Przedmiot {
    private String subjectName;
    public Przedmiot(String name){
        this.subjectName=name;
    }
    public String toString(){
        return this.subjectName + "JEchane";
    }
}