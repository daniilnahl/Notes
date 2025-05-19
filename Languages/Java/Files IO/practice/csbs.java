package practice;



public class csbs {
    public static int loopMysteryExam1(int i, int j) {
        while (i != 0 && j != 0) {
            i = i / j;
            j = (j - 1) / 2;
            System.out.print(i + " " + j + " ");
        }
        System.out.println(i);
        return i + j;
    }

    public static void main(String[] args) {
        int i = loopMysteryExam1(16, 5);
        System.out.println(i);
        i = loopMysteryExam1(80, 9);
        System.out.println(i);
        i = loopMysteryExam1(1600, 40);
        System.out.println(i);
    }
}
