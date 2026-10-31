package java_collections.maps;
import java.util.*;

public class map_examples {
    public static void main(String[] args) {
        // HashMap Example
        HashMap<String, Integer> hashMap = new HashMap<>();
        hashMap.put("Apple", 10);
        hashMap.put("Banana", 20);
        hashMap.put("Apple", 30); // Key overwritten
        System.out.println("HashMap: " + hashMap);
    
        // LinkedHashMap Example
        LinkedHashMap<String, Integer> linkedHashMap = new LinkedHashMap<>();
        linkedHashMap.put("Cherry", 40);
        linkedHashMap.put("Date", 50);
        System.out.println("LinkedHashMap: " + linkedHashMap);
    
        // TreeMap Example
        TreeMap<String, Integer> treeMap = new TreeMap<>();
        //sorts by the keys not the value
        treeMap.put("Elderberry", 60);
        treeMap.put("Fig", 70);
        treeMap.put("Apple", 100);
        System.out.println("TreeMap (Sorted): " + treeMap);        
    }
}
