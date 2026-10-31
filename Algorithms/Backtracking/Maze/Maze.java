package Recursive_Algorithms.Backtracking.maze_recursion;
public class Maze {
    private char[][] squares;
    private boolean[][] explored;
    
    public Maze(String text) {
        this(text.split("[\r]?\n"));
    }
    
    public Maze(String[] lines) {
        if (lines == null || lines.length == 0 || lines[0].length() == 0) {
            throw new IllegalArgumentException("empty lines data");
        }
        
        squares = new char[lines.length][lines[0].length()];
        explored = new boolean[lines.length][lines[0].length()];
        
        for (int row = 0; row < getHeight(); row++) {
            if (lines[row].length() != getWidth()) {
                throw new IllegalArgumentException("line " + row + " wrong length");
            }
            
            for (int col = 0; col < getWidth(); col++) {
                squares[row][col] = lines[row].charAt(col);
            }
        }
    }
    
    public boolean equals(Object o) {
        if (o == this) {
            return true;
        } else if (o instanceof Maze) {
            Maze other = (Maze) o;
            if (getWidth() != other.getWidth()) {
                return false;
            }
            for (int row = 0; row < getHeight(); row++) {
                for (int col = 0; col < getWidth(); col++) {
                    if (squares[row][col] != other.squares[row][col]) {
                        return false;
                    }
                }
            }

            return true;
        } else {
            return false;
        }
    }
    
    public int getHeight() {
        return squares.length;
    }
    
    public char getSquare(int row, int col) {
        checkIndexes(row, col);
        return squares[row][col];
    }
    
    public int getWidth() {
        return squares[0].length;
    }
    
    public boolean isExplored(int row, int col) {
        checkIndexes(row, col);
        return explored[row][col];
    }
    
    public void setExplored(int row, int col, boolean value) {
        checkIndexes(row, col);
        explored[row][col] = value;
    }
    
    public void setSquare(int row, int col, char value) {
        checkIndexes(row, col);
        if (squares[row][col] != ' ' && squares[row][col] != '.') {
            throw new IllegalArgumentException(
                    "Cannot set square at (" + row + ", " + col + 
                    "): cannot change " + squares[row][col] + " to " + value);
        }
        squares[row][col] = value;
    }
    
    public String toString() {
        String result = new String(squares[0]);
        for (int i = 1; i < getHeight(); i++) {
            result += "\n" + new String(squares[i]);
        }
        return result;
    }
    
    private void checkIndexes(int row, int col) {
        if (row < 0 || row >= getHeight() || col < 0 || col >= getWidth()) {
            throw new IllegalArgumentException("illegal indexes: (" + 
                                               row + ", " + col + ")");
        }
    }
    
    public boolean isEscaped() {
        // check left/right edges
        for (int row = 0; row < getHeight(); row++) {
            if (squares[row][0] == '.' || squares[row][getWidth() - 1] == '.') {
                return true;
            }
        }

        // check top/bottom edges
        for (int col = 0; col < getWidth(); col++) {
            if (squares[0][col] == '.' || squares[getHeight() - 1][col] == '.') {
                return true;
            }
        }
        
        return false;
    }
    
// YOUR CODE GOES HERE
    
}
