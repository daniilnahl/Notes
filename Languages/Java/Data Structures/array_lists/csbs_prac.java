package csbs;

// Write a method named countInRange that accepts three parameters: an ArrayList of integers, a minimum and maximum integer, 
// and returns the number of elements in the list within that range inclusive. For example, 
// if the list v contains {28, 1, 17, 4, 41, 9, 59, 8, 31, 30, 25}, the call of countInRange(v, 10, 30) should return 4.
//  If the list is empty, return 0. Do not modify the list that is passed in.


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class csbs_prac {
    public static int countInRange(ArrayList<Integer> list, int min, int max){
        int counter = 0;
        for (int i =0; i < list.size(); i++){
            if (list.get(i) >= min && list.get(i) <= max){
                counter++;
            }
        }
        return counter;

    }

    public static void addStars(ArrayList<String> list){
        for (int i = 0; i <= list.size(); i+=2){
            list.add(i, "*");
        }

    }

    public static void arrayListMystery1(ArrayList<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            int n = list.get(i);
            if (n % 10 == 0) {
                list.remove(i);
                list.add(n);
            }
        }
        System.out.println(list);
    }

    public static void switchPairs(ArrayList<String> list){
        for (int i = 0; i < list.size(); i+=2){
            if (i+1 < list.size()){
                String temp = list.get(i);
                list.set(i, list.get(i+1));
                list.set(i+1, temp);
            }
        }
    }
    
    public static void deleteDuplicates(ArrayList<String> list){
        for (int i = 0; i < list.size();){
            System.out.println(list.size());
            if (i + 1 < list.size() && list.get(i).equals(list.get(i + 1))){
                list.remove(i);
            } else{
                i++;
            }
        }
    }
    
    public static void mirror(ArrayList<String> list){
        for ( int i = list.size() - 1; i >= 0; i--){
            list.add(list.get(i));
        }
    }


    // public static ArrayList<Integer> getDigits(int target) {
    //     ArrayList<Integer> list = new ArrayList<>();

    //     if (target < 10){
    //         list.add(target);
    //     }
        
    //     while (target > 0) {
    //         list.add(0, target % 10); 
    //         target = target / 10;
    //     }
    

    //     return list; //returns the digits
    // }

    public static boolean isKeithNumber(int target){
        ArrayList<Integer> list = new ArrayList<>();
        int temp_targ = target;

        if (target < 10){//if single digit
            System.out.println(target + ": ["+target+"]");//for find keith function
            return true;
        }
 
        while (temp_targ > 0) {
            list.add(0, temp_targ % 10); 
            temp_targ = temp_targ / 10;
        }

        int original_digit = list.size();
        int i = 0;
        while (list.get(list.size() - 1) < target){
            int new_element = 0;

            for (int l = 0; l < original_digit; l++){
                new_element += list.get(l + i);
            }
            list.add(new_element);
            i++;
            
        }
        //this is changed from "return list.get(list.size() - 1) == target" to this for findKeithNumbers.
        if (list.get(list.size() - 1) == target) {
            System.out.println(target + ": " + list);

        }

        return true;
    }
    public static void findKeithNumbers(int min, int max){
        for (int i = min; i <= max; i++){
            isKeithNumber(i);
        }

    }

    public static void collectionMystery1(ArrayList<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            int n = list.get(i);
            System.out.println("list size: " + list.size() + "   " + i + " index of value: " + n);
            list.remove(i);
            if (n % 2 == 0) {
                list.add(i);
            }
        }
        System.out.println(list);
    }

    public static void collectionMystery5(ArrayList<String> list1, ArrayList<String> list2) {
    HashMap<String, String> result = new HashMap<>();

    for (int i = 0; i < list1.size(); i++) {
        String s1 = list1.get(i);
        String s2 = list2.get(i);

        if (!result.containsKey(s1)) {
            result.put(s1, s2);
        } else if (!result.containsKey(s2)) {
            result.put(s2, s1);
        } else {
            result.put(s1 + s2, s1);
        }
    }
    System.out.println(result);
}

public static void collectionMystery123(HashMap<String, String> map) {
    HashMap<String, String> result = new HashMap<>();
    for (String k : map.keySet()) {
        String v = map.get(k);
        if (k.charAt(0) <= v.charAt(0)) {
            result.put(k, v);
        } else {
            result.put(v, k);
        }
    }
    System.out.println(result);
}
    public static void main(String[] args) {
        ArrayList<String> list1 = new ArrayList<>(Arrays.asList("1","1","1","1","1","1","1","1","2"));
        
        deleteDuplicates(list1);


    }
}
