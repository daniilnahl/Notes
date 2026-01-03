import java.util.Stack;

public class Stacks {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println(stack);
        //peek() - Looks at the object at the top of this stack without removing it from the stack.
        System.out.println("Top element: " + stack.peek()); // 30
        System.out.println("value 30 is at place: " + stack.search(30)); //top of stack
        System.out.println("value 10 is at place: " + stack.search(10)); //bottom of stack
        System.out.println("Popped: " + stack.pop()); // 30
        System.out.println("Popped: " + stack.pop()); // 20

        System.out.println("Is stack empty? " + stack.isEmpty()); // false
    }
}
