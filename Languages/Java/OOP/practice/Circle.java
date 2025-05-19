package csbs;
public class Circle {
    private double r;

    public Circle(double r){
        this.r = r;
    }

    public double area(){
        return ((r*r) * Math.PI);
    }

    public double circumference(){
        return ((2*r) * Math.PI);
    }

    public double getRadius(){
        return r;
    }

    public String toString(){
        return "Circle{radius=" + r + "}";
    }
}
