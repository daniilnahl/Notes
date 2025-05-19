package csbs;
import java.util.*;
// Class ArrayIntList can be used to store a list of integers.
public class ArrayIntList implements Iterable<Integer> {
	private int[] elementData;  // list of integers
	private int size = 0;       // current number of elements in the list

	public static final int DEFAULT_CAPACITY = 10;

	// post: constructs an empty list of default capacity
	public ArrayIntList() {
		this(DEFAULT_CAPACITY);
	}

	// pre : capacity >= 0
	// post: constructs an empty list with the given capacity
	private ArrayIntList(int capacity) {
		if (capacity < 0) {
			throw new IllegalArgumentException("Capacity must be at least 0: " + capacity);
		}
		elementData = new int[capacity];
	}

	// for creating test cases more easily
	public ArrayIntList(int... elements) {
		this(Math.max(DEFAULT_CAPACITY, elements.length * 2));
		for (int n : elements) {
			add(n);
		}
	}

	public ArrayIntList(Iterable<Integer> elements) {
		this();
		for (int n : elements) {
			add(n);
		}
	}

	// for creating test cases more easily (a dupe of the above constructor)
	public static ArrayIntList withValues(int... elements) {
		ArrayIntList list = new ArrayIntList(Math.max(DEFAULT_CAPACITY, elements.length * 2));
		for (int n : elements) {
			list.add(n);
		}
		return list;
	}

	// for creating test cases more easily
	public ArrayIntList(int element, boolean notCapacity) {
		this();
		add(element);
	}

	// copy constructor; for creating test cases more easily
	public ArrayIntList(ArrayIntList list) {
		this(Math.max(DEFAULT_CAPACITY, list.size() * 2));
		addAll(list);
	}

	// pre : size() < capacity (elementData.length)
	// post: appends the given value to the end of the list
	public void add(int value) {
		ensureCapacity(size + 1);
		elementData[size] = value;
		size++;
	}

	// post: appends all values in the given list to the end of this list
	public void addAll(ArrayIntList other) {
		for (int i = 0; i < other.size; i++) {
			add(other.elementData[i]);
		}
	}

	// post: list is empty
	public void clear() {
		size = 0;
	}

	// post: ensures that the underlying array has the given capacity; if not,
	// the size is doubled (or more if given capacity is even larger)
	protected void ensureCapacity(int capacity) {
		if (capacity > elementData.length) {
			int newCapacity = elementData.length * 2 + 1;
			if (capacity > newCapacity) {
				newCapacity = capacity;
			}
			int[] newList = new int[newCapacity];
			for (int i = 0; i < size; i++) {
				newList[i] = elementData[i];
			}
			elementData = newList;
		}
	}

	// returns true if o is an ArrayIntList with the same size and elements as this one
	public boolean equals(Object o) {
		if (!(o instanceof ArrayIntList)) {
			return false;
		}

		ArrayIntList other = (ArrayIntList) o;
		if (this.size != other.size) {
			return false;
		}

		for (int i = 0; i < size; i++) {
			if (elementData[i] != other.elementData[i]) {
				return false;
			}
		}

		return true;
	}

	// pre : 0 <= index < size()
	// post: returns the integer at the given index in the list
	public int get(int index) {
		checkIndex(index);
		return elementData[index];
	}

	// post: returns capacity of this list's underlying array
	protected int getCapacity() {
		return elementData.length;
	}

	// post: returns true if list is empty, false otherwise
	public boolean isEmpty() {
		return size == 0;
	}

	// post: returns an iterator for this list
	public Iterator<Integer> iterator() {
		return new ArrayIntListIterator(this);
	}

	// pre : 0 <= index < size()
	// post: replaces the integer at the given index with the given value
	public void set(int index, int value) {
		checkIndex(index);
		elementData[index] = value;
	}

	// post: returns the current number of elements in the list
	public int size() {
		return size;
	}

	// post: returns an array version of the contents of this list
	public int[] toArray() {
		return Arrays.copyOf(elementData, size);
	}

	// post: creates a comma-separated, bracketed version of the list
	public String toString() {
		String result = "[";
		for (int i = 0; i < size; i++) {
			if (i > 0) {
				result += ", ";
			}
			if (i < elementData.length) {
				result += elementData[i];
			} else {
				// student's code is bogus; OOB
				result += "OOB!";
			}
		}
		result += "]";
		return result;
	}

	// helpers to make sure indexes do not fall out of bounds
	private void checkIndex(int index) {
		checkIndex(index, 0, size - 1);
	}

	private void checkIndex(int index, int min, int max) {
		if (min > max) {
			throw new ArrayIndexOutOfBoundsException("Illegal index " + index);
		}
		if (!(min <= index && index <= max)) {
			throw new ArrayIndexOutOfBoundsException("Illegal index " + index + "; must be between " + min + " and " + max);
		}
	}

	// parses a string such as "[10, 20, 30]" into an ArrayIntList
	public static ArrayIntList parse(String elements) {
		elements = elements.trim();
		if (elements.length() < 2) {
			throw new IllegalArgumentException("invalid format: \"" + elements + "\"");
		}

		// remove [] {}
		if (elements.charAt(0) == '[' || elements.charAt(0) == '{') {
			elements = elements.substring(1);
		}
		if (elements.charAt(elements.length() - 1) == ']' || elements.charAt(elements.length() - 1) == '}') {
			elements = elements.substring(0, elements.length() - 1);
		}

		ArrayIntList list = new ArrayIntList();
		if (elements.isEmpty()) {
			return list;
		}

		// parse each element
		String[] tokens = elements.split("[ ]*,[ ]*");
		for (String token : tokens) {
			try {
				int num = Integer.parseInt(token);
				list.add(num);
			} catch (NumberFormatException nfe) {
				throw new IllegalArgumentException("invalid token format: \"" + token + "\"");
			}
		}

		return list;
	}


	// The ArrayIntListIterator class provides a set of utilities for iterating
	// over an ArrayIntList and possibly removing values from the list.
	private static class ArrayIntListIterator implements Iterator<Integer> {
		private ArrayIntList list;    // list to iterate over
		private int position;          // current position within the list
		private boolean removeOK;      // whether it's okay to remove now

		// pre : list != null
		// post: constructs an iterator for the given list
		public ArrayIntListIterator(ArrayIntList list) {
			this.list = list;
			position = 0;
			removeOK = false;
		}

		// post: returns true if there are more elements left, false otherwise
		public boolean hasNext() {
			return position < list.size();
		}

		// pre : hasNext()
		// post: returns the next element in the iteration
		public Integer next() {
			if (!hasNext())
				throw new NoSuchElementException();
			int result = list.get(position);
			position++;
			removeOK = true;
			return result;
		}

		// pre : next() has been called without a call on remove (i.e., at most one
		//     call per call on next)
		// post: removes the last element returned by the iterator
		public void remove() {
			// if (!removeOK)
			throw new IllegalStateException();
			// list.remove(position - 1);
			// position--;
			// removeOK = false;
		}
	}

// YOUR CODE GOES HERE
	//Write a new method for the ArrayIntList class named add that accepts an integer index and a value to add as parameters 
	//and inserts the given value at the given index, shifting subsequent values to the right. 
	public void add(int index, int value){
		if (index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException();
		}
		
		ensureCapacity(size + 1);

		if (index == size){
			elementData[size] = value;
		}

		for (int i = size; i > index; i--){
			elementData[i] = elementData[i-1];
		}
		elementData[index] = value;
		size++;
	}
	// Write a new method for the ArrayIntList class named indexOf that accepts an integer parameter representing an element 
	// value and returns the index of the first occurrence of that value in the list. If the value is not in the list, it should return -1. 
	//
	 public int indexOf(int value){
		for (int i = 0; i < size; i++){
			if (elementData[i] == value){
				return i;
			}
		}

		return -1;
	 }

	//  Write a new method for the ArrayIntList class named remove that accepts
	//   an integer index as its parameter and removes the value at the given index, shifting subsequent values to the left
	public void remove(int index){
		checkIndex(index);

		for (int i = index; i < size - 1; i++){
			elementData[i] = elementData[i+1];
		}

		size--;
	}
	//Write a new method for the ArrayIntList class named stutter that doubles the size of the list by replacing every integer in the list with two of that integer
	public void stutter() {
		ensureCapacity(size * 2);
		for (int i = size - 1; i >= 0; i--) {
			elementData[2 * i + 1] = elementData[i];
			elementData[2 * i] = elementData[i];
		}
		size *= 2;
	}
}