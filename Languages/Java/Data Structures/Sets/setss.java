package java_collections.sets;
import java.util.*;

public class setss {
    public static void main(String[] args) {
        // HashSet Example
        HashSet<Integer> hashSet = new HashSet<>();
        hashSet.add(10);
        hashSet.add(20);
        hashSet.add(10); // Duplicate ignored
        System.out.println("HashSet: " + hashSet);

        // LinkedHashSet Example
        LinkedHashSet<Integer> linkedHashSet = new LinkedHashSet<>();
        linkedHashSet.add(30);
        linkedHashSet.add(40);
        linkedHashSet.add(50);
        linkedHashSet.add(60);
        linkedHashSet.add(30); // Duplicate ignored
        System.out.println("LinkedHashSet: (Maintains order of insertion)" + linkedHashSet);

        // TreeSet Example
        TreeSet<Integer> treeSet = new TreeSet<>();
        treeSet.add(50);
        treeSet.add(40);
        treeSet.add(70);
        treeSet.add(120);
        treeSet.add(1);
        treeSet.add(50); // Duplicate ignored
        treeSet.remove(50);
        System.out.println("TreeSet (Sorted): " + treeSet);
        System.out.println("TreeSet (Sorted): " + treeSet.reversed());

    }
}
