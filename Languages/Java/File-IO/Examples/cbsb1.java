package practice;

import java.util.*;

public class cbsb1 {
   //piglet
   public static void main(String[] args) {
    Scanner console = new Scanner(System.in);
    Random rand = new Random();

    boolean numIsOne = true;
    int points = 0;

    System.out.println("Welcome to Piglet!");

    while(numIsOne){
        int role = rand.nextInt(1,7);
        points += role;

        System.out.println("You rolled a " + role + "!");
        if (role == 1){
            points = 0;
            System.out.println("You got " + points + " points.");
            numIsOne = false;
        }
        else{
            System.out.print("Roll again? ");
            String userInput = console.nextLine();
            if (userInput.equals("yes") || userInput.equals("y")){
            }
            if(userInput.equals("no") || userInput.equals("n")){
                System.out.println("You got " + points + " points.");
                numIsOne = false;
            }
        }
        

       }
       console.close();
   } 
}
