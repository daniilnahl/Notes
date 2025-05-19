package practice;

//compute sum of digits of a number
import java.util.*;

public class cbsb2 {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        System.out.print("Type an integer: ");
        String number = console.next();

        int sum = 0;
        for (int i = 0; i < number.length(); i++){
            sum += Character.getNumericValue(number.charAt(i));
        }

        System.out.println("Digit sum is " + sum);
        console.close();
    }
}
