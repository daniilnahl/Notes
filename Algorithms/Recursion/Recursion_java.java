public class Recursion_java {
    //function that recursively adds () to a word based on n value.
    public static String paranthesize(String word, int n){
        if ( n < 0){
            throw new IllegalArgumentException();
        }else if (n == 0) return word;
        else {
            return "(" + paranthesize(word, n-1) + ")";
        }
    }

    //output of n number is how to get it with one odd number getting multiplied by even numbers.
    public static void print_twos(int n){
        if ( n < 1) {
            throw new IllegalArgumentException();
        } else if (n % 4 == 0) {
            System.out.println("2 * ");
            print_twos(n / 4);
            System.out.println(" * 2");
        } else if (n % 2 == 0) {
            System.out.println("2 * "+ n/2);
        }else{//odd numbers
            System.out.println(n);
        }
    }
    
    public static void sequencee(int k){
        if (k < 1) throw new IllegalArgumentException();
        if (k == 1) System.err.print("1");

        else if (k % 2 == 0){
            System.out.print("(" + k + " + ");
            sequencee(k-1);
            System.out.print(")");
        }else {
            System.out.print("(");
            sequencee(k-1);
            System.out.print(" + " + k + ")"); 
        }
    
    }

    public static void print_symmetric(int n){
        if (n < 1){
            throw new IllegalArgumentException();
        }
        switch (n) {
            case 1 -> System.out.print("1");
            case 2 -> System.out.print("1 1");
            default -> {
                int num_print = (n + 1)/2;
                System.out.print(num_print + " ");
                print_symmetric(n - 2);
                System.out.print(" " + num_print);
            }
        }
    }
    
    public static int factorial(int n){
        if (n == 0){
            return 1;
        }
        
        if (n==1){
            return 1;
        }
        else{
            return n * factorial(n - 1);
        }
    }
   
    public static void recursionMystery10(int x) {
        System.out.print(x + " ");
        if (x <= 1) {
            System.out.print("END ");
        } else if (x % 2 == 0) {
            recursionMystery10(x / 2);
            System.out.print("+ ");
        } else {
            System.out.print("[ ");
            recursionMystery10(3 * x + 1);
            System.out.print("] ");
        }
    }

    public static void recursionMystery1(int x, int y) {
        if (y <= 0) {
            System.out.print("0 ");
        } else if (x > y) {
            System.out.print(x + " ");
            recursionMystery1(x - y, y);
        } else {
            recursionMystery1(x, y - x);
            System.out.print(y + " ");
        }
    }
    
    public static int sumOfSquares(int n){
        if ( n < 0) throw new IllegalArgumentException(); 
        else if (n == 0) return 0;
        
        if (n == 1){
            return 1;
        }
        else{
            return n * n + sumOfSquares(n - 1);
        }
    }
    
    public static String reverse(String string){
        if (string.length() == 0){
            return "";
        }
        else if (string.length() == 1){
            return string;
        }
        else{
            // System.out.print(string.charAt(string.length()-1)); //IN JAVA YOU CANT ACCESS THE -1 INDEx. THATS WHAT YOU DID HERE BEFORE you figured it out. REMEMBER NO -1 INDEx.
            return string.charAt(string.length()-1) + reverse(string.substring(0, string.length()-1));
        }
    }

    public static boolean isPalindrome(String string){
        string = string.toLowerCase();
        
        if (string.length() <= 1){
            return true;
        }
        else if (string.charAt(0) != string.charAt(string.length()-1)){
            return false;
        }  

        return isPalindrome(string.substring(1, string.length()-1));
        
    }

    public static void hanoi(int num, int fromPeg, int toPeg) {
        if (num == 1) {
            System.out.println("move disk 1 from peg " + fromPeg + " to peg " + toPeg);
            return;
        }
        int auxPeg = 6 - fromPeg - toPeg; // Calculate auxiliary peg
        hanoi(num - 1, fromPeg, auxPeg);
        System.out.println("move disk " + num + " from peg " + fromPeg + " to peg " + toPeg);
        hanoi(num - 1, auxPeg, toPeg);
    }

    public static void main(String[] args) {
        
        
    }
}