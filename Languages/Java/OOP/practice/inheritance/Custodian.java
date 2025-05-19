package csbs.inheritance;

public class Custodian extends Employee {
    
    public int getHours(){
        return super.getHours() * 2;
    }

    public double getSalary(){
        return super.getSalary() - 10000;
    }

    public int getVacationDays(){
        return super.getVacationDays() / 2;
    }

    public String clean(){
        return "Workin' for the man.";
    }
	
    
}
