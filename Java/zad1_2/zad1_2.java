package POB_2019.Java.zad1_2;

public class zad1_2 {
    public static void main(String[] args){
        Vector2D vec1 = new Vector2D(5, 11);
        Vector2D vec2 = new Vector2D(-2, 4);
        Vector2D vec3 = vec1.add(vec2);
        Vector2D vec4 = vec2.substract(vec1);
        double multiplicationResult = vec2.multiply(vec1);
        System.out.println(vec3);
        System.out.println(vec4);
        System.out.println(multiplicationResult);
    }
}