import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class csbs_stacks {
public static void collectionMystery6(Stack<Integer> s) {
    Queue<Integer> q = new LinkedList<Integer>();
    Stack<Integer> s2 = new Stack<Integer>();

    while (!s.isEmpty()) {
        if (s.peek() % 2 == 0) {
            q.add(s.pop());
        } else {
            s2.push(s.pop());
        }
    }

    while (!q.isEmpty()) {
        s.push(q.remove());
    }
    while (!s2.isEmpty()) {
        s.push(s2.pop());
    }

    System.out.println(s);
}

public static void splitStack(Stack<Integer> s){
    Queue<Integer> q = new LinkedList<>();
    int size = s.size();
    for (int i = 0; i < size; i++){
        q.add(s.pop());
    }

    for (int i = 0; i < size; i++){
        if (q.peek() < 0){
            s.push(q.remove());
        } else{
            q.add(q.remove());
        }
    }
    
    while(!q.isEmpty()){
        s.push(q.remove());
    }
}

    
public static boolean isSorted(Stack<Integer> s) {
    if (s.isEmpty() || s.size() == 1) {
        return true;
    }

    Queue<Integer> q = new LinkedList<>();
    boolean sorted = true;
    int prev = s.pop();
    q.add(prev);

    while (!s.isEmpty()) {
        int curr = s.pop();
        q.add(curr);
        if (prev > curr) { // Change comparison to check for non-decreasing order
            sorted = false;
        }
        prev = curr;
    }

    while (!q.isEmpty()) {
        s.push(q.remove());
    }

    while (!s.isEmpty()) {
        q.add(s.pop());
    }

    while (!q.isEmpty()) {
        s.push(q.remove());
    }

    return sorted;
}
    


    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(5);
        stack.push(4);
        stack.push(3);
        stack.push(1);
        stack.push(2);

       System.out.println(isSorted(stack));
    }
}
