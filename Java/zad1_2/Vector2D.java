package POB_2019.Java.zad1_2;

public class Vector2D {
    private int x, y;
    public Vector2D(int _x, int _y){
        this.x=_x;
        this.y=_y;
    }
    public Vector2D add(Vector2D vec2){
        int newX, newY;
        newX=this.x + vec2.x;
        newY=this.y + vec2.y;
        return new Vector2D(newX, newY);
    }
    public Vector2D substract(Vector2D vec2){
        int newX, newY;
        newX=this.x - vec2.x;
        newY=this.y - vec2.y;
        return new Vector2D(newX, newY);
    }
    public double multiply(Vector2D vec2){
        return (this.x*vec2.x + this.y*vec2.y);
    }
    public String toString(){
        return String.format("[%s, %s]", this.x, this.y);
    }
}