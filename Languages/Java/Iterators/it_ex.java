package java_collections.iterators;
import java.util.*;
public class iteratorss {
    public static void main(String[] args) {
        ArrayList<String> fruits = new ArrayList<>();
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");

        Iterator<String> iterator = fruits.iterator();
        while (iterator.hasNext()) {
            String fruit = iterator.next();
            System.out.println(fruit);

            // Remove Banana safely
            if (fruit.equals("Banana")) {
                iterator.remove();
            }
        }

        System.out.println("Updated List: " + fruits);
    }
}
