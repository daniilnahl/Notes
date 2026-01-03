package Queues;

import java.util.LinkedList;
import java.util.Queue;

public class Queues {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        // .offer()//     Inserts the specified element into this queue if it is possible to do
        //         //  * so immediately without violating capacity restrictions.
        //         //  * When using a capacity-restricted queue, this method is generally
        //         //  * preferable to {@link #add}, which can fail to insert an element only
        //         //  * by throwing an exception.
        // .poll() //Retrieves and removes the head of this queue. (doesnt throw exception but .remove() does)
        // .element() //Retrieves, but does not remove, the head of this queue. throws an exception if queue is empty.
        // .peek() // Retrieves, but does not remove, the head of this queue.

        queue.add(10);
        queue.add(20);
        queue.add(30);

        System.out.println("Front element: " + queue.peek()); // 10

        System.out.println("Dequeued: " + queue.poll()); // 10
        System.out.println("Dequeued: " + queue.poll()); // 20

        System.out.println("Is queue empty? " + queue.isEmpty()); // false
    }
}
