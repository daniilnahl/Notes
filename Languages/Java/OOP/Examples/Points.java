package csbs;
import java.awt.Point;
public class Points {
    public static void main(String[] args) {
        Point p1 = new Point(17, 9);
        Point p2 = new Point(4, -1);
        Point p3 = p2;

        p1.translate(3, 1);
        p2.x = 50;
        p3.translate(-4, 5);
        System.out.println(p1 + " " + p2 + " " + p3);
    }
}
