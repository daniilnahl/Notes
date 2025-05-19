import java.util.*;

public class Main{

    public static void enhancedLoopANDSequentialAlgorithm(){
        // Step 1: Initialize the array
        int[] numbers = {1, 2, 3, 4, 5};
        // Step 2: Sequentially process each element in the array
        for (int num : numbers){
        //!!! {
            // Step 3: Print the current number
            System.out.println("Number: " + num);
        }
        // Step 4: End of the sequential process
    }

    public static void listExample(){
        // Creating a List of Strings
        List<String> fruits = new ArrayList<>();

        // Adding elements to the list
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Mango");

        // Accessing elements
        System.out.println("First fruit: " + fruits.get(0));

        // Removing an element
        fruits.remove("Banana");

        // Iterating through the List
        for (String fruit : fruits) {
            System.out.println("Fruit: " + fruit);
        }
    }

    public static void nestedLoopAlgorithm(){
         // Outer loop for rows
         for (int i = 1; i <= 3; i++) {
            // Inner loop for columns
            for (int j = 1; j <= 3; j++) {
                System.out.print(i * j + "\t");  // Print multiplication result
            }
            System.out.println();  // Newline after each row
         }

    }
    public static void main(String[] args) {
        System.out.println("enhanced loop and sequential");
        enhancedLoopANDSequentialAlgorithm();

        System.out.println("list example");
        listExample();

        System.out.println("nested loop algorithm");
        nestedLoopAlgorithm();
    }
}