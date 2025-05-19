package equalscode;

public class Point{
    private int x;
    private int y;
        
     public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public double distanceTo(Point other) {
        int dx = other.x - this.x;
        int dy = other.y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public boolean equals(Object o) {
        if (o instanceof Point){
            Point other = (Point) o;
            return x == other.x && y == other.y;
        } else {
            return false;
        }
        
    }
}