package java_collections.linked_lists;
import java.util.*;

public class Example_lists {
    
    public static void main(String[] args) {
        // ArrayList Example
        ArrayList<String> arrayList = new ArrayList<>();
        arrayList.add("Apple");
        arrayList.add("Banana");
        arrayList.add("Cherry");
        System.out.println("ArrayList: " + arrayList);

        // LinkedList Example
        LinkedList<String> linkedList = new LinkedList<>();
        linkedList.add("Dog");
        linkedList.add("Cat");
        linkedList.add("Elephant");
        System.out.println("LinkedList: " + linkedList);

        // Accessing elements
        System.out.println("First item in ArrayList: " + arrayList.get(0)); // Fast in ArrayList
        System.out.println("First item in LinkedList: " + linkedList.getFirst()); // Fast in LinkedList    
    }
}
