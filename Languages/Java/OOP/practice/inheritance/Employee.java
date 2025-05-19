package csbs.inheritance;

// A class to represent employees in general.
public class Employee {
	public int getHours() {
		return __baseHours;                // 40 hours/week
	}

	public double getSalary() {
		return __baseSalary;               // $40,000.00
	}

	public int getVacationDays() {
		return __baseVacationDays;         // 10 days
	}

	public String getVacationForm() {
		return __baseVacationForm;         // yellow
	}


	// These are so that test cases can change the base values
	// and make sure that subclasses also change their values.
	// (Your code that you submit is NOT supposed to directly use, call,
	// or modify the values below!  They are here only to help our site
	// successfully test your code.  Please ignore them.)
	
	private static int __baseHours = 40;
	private static double __baseSalary = 40000.0;
	private static int __baseVacationDays = 10;
	private static String __baseVacationForm = "yellow";
	
	public static final void setBaseHours(int hours) {
		__baseHours = hours;
	}
	public static final void setBaseSalary(double salary) {
		__baseSalary = salary;
	}
	public static final void setBaseVacationDays(int days) {
		__baseVacationDays = days;
	}
	public static final void setBaseVacationForm(String form) {
		__baseVacationForm = form;
	}
}
