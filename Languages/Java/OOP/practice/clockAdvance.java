package csbs;

public class clockAdvance {
    
public static void advance(int minutes, int hour, int minute, String amPm){
    int hoursTotal = minutes / 60;

    while (hoursTotal > 0){
        hour++;
        
        if ((hour > 12) && (amPm.equals("AM"))){
            hour = 1;
            amPm = "PM";
        }else if ((hour > 12) && (amPm.equals("PM"))){
            hour = 1;
            amPm = "AM";
        }
        hoursTotal--;
    }
    minute += minutes % 60;
    if (minute > 60){
        minute -= 60;
        hour++;
        if ((hour > 12) && (amPm.equals("AM"))){
            hour = 1;
            amPm = "PM";
        }else if ((hour > 12) && (amPm.equals("PM"))){
            hour = 1;
            amPm = "AM";
        } 
    }

    System.out.println(hour + ":" + minute + " " + amPm);
}

public static void main(String[] args) {
    advance(61, 12, 0, "AM");
}


}
