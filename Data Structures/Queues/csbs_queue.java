package Queues;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class csbs_queue {

    public static void collectionMystery7(Queue<Integer> queue) {
    Stack<Integer> stack = new Stack<Integer>();
    int qsize = queue.size();
    for (int i = 0; i < qsize; i++) {
        if (queue.peek() % 2 == 0) {
            queue.add(queue.remove());
        } else {
            stack.push(queue.peek());
            stack.push(queue.remove());
        }
    }
    while (!queue.isEmpty()) {
        stack.push(queue.remove());
    }
    while (!stack.isEmpty()) {
        System.out.print(stack.pop() + " ");
    }

    System.out.println(stack);
}
    
    public static void stutter(Queue<Integer> queue) {
        for (int i = 0; i < queue.size();) {
            int n = queue.poll();
            queue.add(n);
            queue.add(n);
            i+=2;
        }
    
    }

    public static void mirror(Queue<String> q){
        Stack<String> s = new Stack<String>();
        int size = q.size();

        for (int i = 0; i < size; i++){
            String n = q.remove();
            s.push(n);
            q.add(n);
        }

        while(!s.isEmpty()){
            q.add(s.pop());
        }
    }

    public static void flipHalf(Queue<Integer> q){
        Stack<Integer> s = new Stack<>();
        int size = q.size();
        int i = 0;

        while(i < size){
            if (i % 2 == 0){
                q.add(q.remove());
            }else{
                s.push(q.remove());
                q.add(-122);
            }
            i++;
        }

        i = 0;
        
        while(i < size){
            if (i % 2 == 0){
                q.add(q.remove());
            }else{
                q.remove();
                q.add(s.pop());
            }
            i++;
        }
        
    }
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i < 8; i++){
            queue.add(i);
        }

        System.out.println(queue);
        flipHalf(queue);
        System.out.println(queue);
    }
}
