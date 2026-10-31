
import java.util.*;

public class csbs {
    public static int maxValue(int[] a){

        return Arrays.stream(a).max().getAsInt();
    }

    public static int longestSortedSequence(int[] a){
        int sequenceCur = 1;
        int sequenceMax = 1;
        //first check
        if (a.length == 0){
        return 0;
        }
        //start from 1 since its easier to check the past element than the future element. Avoids checking for out of bound inside the for loop.
        for (int i = 1; i < a.length; i++){
            if (a[i] >= a[(i-1)]){
                sequenceCur++;
            } else{
                if (sequenceCur > sequenceMax){
                    sequenceMax = sequenceCur;
                }
                sequenceCur = 1;//resets
            }
        }

        if (sequenceCur > sequenceMax){
            sequenceMax = sequenceCur;//final check if last element made the sequence longer
        }

        return sequenceMax;
    }

    public static void mystery(int[] list) {
        for (int i = 1; i < list.length; i++) {
            list[i] = list[i] + list[i - 1];
        }

        for (int i = 0; i < list.length; i++){
            System.out.println(list[i]);
        }

        System.out.println("ENDED");
    }

    public static void banish(int[] a1, int[] a2){
        int writeIndex = 0; //tracks where to write the next valid element in a1

        //loops through each element in a1
        for (int i = 0; i < a1.length; i++) {
            boolean toRemove = false;
    
            for (int j = 0; j < a2.length; j++) {
                if (a1[i] == a2[j]) {
                    toRemove = true;
                    break;
                }
            }
    
            //if not in a2 writes it to the next position and increments writeindex
            if (!toRemove) {
                a1[writeIndex] = a1[i];
                writeIndex++;
            }
        }
    
        //fill remaining elements
        for (int i = writeIndex; i < a1.length; i++) {
            a1[i] = 0;
        }

        for (int i = 0; i < a1.length; i++){
            System.out.println(a1[i]);
        }
    }

    public static int[] collapse(int[] a){
        int[] x;
        int xIndex = 0;

        if (a.length % 2 == 0){//even
            x = new int[(a.length/2)];
        }else{
            x = new int[(a.length/2) + 1];//odd
        }


           for (int i = 0; i < a.length-1; i+=2){
                x[xIndex] = (a[i] + a[i+1]);
                System.out.println(a[i] + a[i+1]);
                xIndex++;
           }
        
           if (a.length % 2 != 0){
                x[xIndex] = a[(a.length-1)];
           }
            
           return x;
        }
        
    public static void main(String[] args) {
        int [] x = {7, 2, 8, 9, 4, 13, 7, 1, 9, 10};
        int[] y =  {1, 2, 3, 4, 5};
        

        collapse(x);
        collapse(y);

        
    }
}
