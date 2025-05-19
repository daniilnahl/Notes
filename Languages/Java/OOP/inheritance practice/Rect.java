public class Rect implements Shape{
    private double x;
    private double y;

    public Rect(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double getArea() {
        return x * y;
    }

    public double getPerimeter() {
        return (x+y)*2;
    }
}
