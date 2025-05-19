public class TwoPoint {
    // accepts an array of integers as a parameter and rearranges its elements 
    // so that all even values appear before all odds. 
    // For example, if the following array is passed to your method:
    public static int[] evenBeforeOdd(int[] a){
        int i = 0; //bottom pointer
        int j = a.length - 1; //upper pointer
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
    
    public static void main(String[] args) { 
        int[] numbers = {5, 2, 4, 9, 3, 6, 2, 1, 11, 1, 10, 4, 7, 3};
        System.out.println(numbers.toString());
        evenBeforeOdd(numbers);
        System.out.println(numbers.toString());
    }

}
