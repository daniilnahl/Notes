// represents a time span of elapsed hours and minutes
public class example {
    private int hours;
    private int minutes;

    public example(int hours, int minutes) {
        if (hours < 0 || minutes < 0) {
        throw new IllegalArgumentException();
        }
        
        this.hours = hours + minutes / 60;
        this.minutes = minutes % 60;
    }

    public void add(int hours, int minutes) {
        if (hours < 0 || minutes < 0) {
        throw new IllegalArgumentException();
        }

        this.hours += hours;
        this.minutes += minutes;

        // converts each 60 minutes into one hour
        this.hours += this.minutes / 60;
        this.minutes = this.minutes % 60;
    }    

    public String toString() {
        return hours + "h " + minutes + "m";
    }
}
