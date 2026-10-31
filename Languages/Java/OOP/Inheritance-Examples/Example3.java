public class Example3 extends Example1{
    
    public Example3(String name){
        super(name);
    }
    //overrides get vacation days
    public int getVacationDays() {
        return 15;
    }

    //added behavior
    public void sue() {
        System.out.println("I'll see you in court!");
    }
}
