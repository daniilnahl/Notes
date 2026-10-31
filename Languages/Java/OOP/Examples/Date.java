package csbs;

public class Date {
    public int hour;
    public String amPm;
    private int month;
    private int day;
    private int[] daysInMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    public Date(int month, int day){
        this.day = day;
        this.month = month;
    }

    public int daysInMonth(){
        return daysInMonth[month];
    }

    public int getDay(){
        return day;
    }

    public int getMonth(){
        return month;
    }

    public void nextDay(){
        day++;
        if (daysInMonth[month] < day){
            month++;
            day = 1;
        }

        if (month > 12){
            month = 1;
        }
    }

    public String toString(){
        String dday = "";
        String monthh = "";

        if (day < 10){
            dday = "0" + Integer.toString(day);
        }else{
            dday = Integer.toString(day);
        }

        if (month < 10){
            monthh = "0" + Integer.toString(month);
        }else{
            monthh = Integer.toString(month);

        }
        
        return monthh + "/" + dday;
    }
    
}
