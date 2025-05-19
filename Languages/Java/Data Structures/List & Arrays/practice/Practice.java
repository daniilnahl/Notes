import java.util.Arrays;

public class Practice {
    public static void arrayMysteryExam2(int[] a) {
    for (int i = 0; i < a.length - 1; i++) {
        if (a[i] > a[i + 1]) {
            int temp = a[i];
            System.out.println(i);
            a[i] = a[i + 1];
            a[i + 1] = temp;
            a[0]++;
            }
        }
    System.out.println(Arrays.toString(a));
    }
    
    public static int[] evenBeforeOdd(int[] a){
        int i = 0;
        int j = a.length - 1;
        while (i <= j) {
            if ((a[i] % 2 != 0) && (a[j] % 2 == 0)){
                int temp_i = a[i];
                int temp_j = a[j];
                a[i] = temp_j;
                a[j] = temp_i;
                
            }
            
            if (a[i] % 2 == 0){
                i++;
            }

            if(a[j] % 2 != 0){
                j--;
            }
        }
        
        
        return a;
    }

    public static boolean sorted(double[] a){
        for (int i = 0; i < a.length - 1; i++){
            if (a[i+1] < a[i]){
                return false;
            }
        }

        return true;
    }

    public static boolean isMonotonic(int[] a){
        if ((a.length == 0) || (a.length == 1) || (a.length == 2)){
            return true;
        }

        //do while loop with one pointer and for the first instance of loop check if its increasing or decreasing and then from that do checks.
        int i = 0;
        boolean decreasing = a[i] >= a[i+1];
        boolean increasing = a[i] <= a[i+1];
        i++;

        while (i < a.length-1){
            if ((increasing) && (decreasing)){ //cehck if both conditions are set to true
                decreasing = a[i] >= a[i+1];
                increasing = a[i] <= a[i+1];
            }

            else if ((increasing) && (a[i] > a[i+1])){
                return false;
            }
            
            else if ((decreasing) && (a[i] < a[i+1])){
                return false;
            } 

            i++;
        }

        return true;
    }

    public static void main(String[] args) { 
        
    }


}
