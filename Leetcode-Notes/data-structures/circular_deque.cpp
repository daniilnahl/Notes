class MyCircularDeque {
    int front = 0;
    int size = 0;
    int max_size;
    std::vector<int> storage;

public:
    MyCircularDeque(int k) : storage(k), max_size(k) {
    
    }

    bool insertFront(int value) {
        /*This edge case exists because dont want to update front pointer
        because the deque is only 1 element and both front and rear are pointing to same 1 element.*/
        if (size == 0){ storage[front] = value;
            size++;
            return true;
        } else if (size < max_size){
            //move back 1 element + max_size then modded by max size provides the index 'circled' around the container. 
            //Eg goes from 0 not to -1 but to 10 (if size of collection is 11): 0-1+10= 9 % 10= 9.
            front = (front-1+max_size) % max_size; 
            storage[front] = value;
            size++;
            return true;
        }else return false;
    }

    bool insertLast(int value) {
        if (size < max_size){
            //finds the next free 'rear' by adding the amount of elements (that exist) to the front index and modding my max size. 
            //Ensures that if front is a 'near end index' that the rear 'circles' back around.
            int rear = (front+size) % max_size;
            storage[rear] = value;
            size++;
            return true;
        }else return false;
    }

    bool deleteFront() {
        if (size != 0){
            front = (front+1+max_size) % max_size; //inverted logic from inserting up front
            size--;
            return true;
        }
        return false;
     }

    bool deleteLast() {
        if (size != 0){
            size--;
            return true;
        }
        return false;
    }

    int getFront() {
        if (size!=0) return storage[front];
        return -1;
    }

    int getRear() {
        if (size !=0){
        ////-1 to go to the actual rear element instead of just finding the next fear rear index.
        int rear = (front+size-1) % max_size; 
        return storage[rear];            
        }

        return -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

