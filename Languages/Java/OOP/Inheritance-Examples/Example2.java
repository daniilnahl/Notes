public class Example2 extends Example1{
    // this is the only added behavior
    
    public Example2(String name){
        super(name); //must do super since parent class has name as private for OOP encapsulation
    }
    public void takeDictation() {
        System.out.println("I know how to take dictation.");
    }

    public double getSalary() {
        return super.getSalary() + 5000; //5k more for this specific role
    }
    public static void main(String[] args) {
        Example1 a1 = new Example1("John");
        Example2 a2 = new Example2("Mike");
        System.out.println(a1.getHours() +"1");
        System.out.println(a2.getHours() +"!");
    }
    }