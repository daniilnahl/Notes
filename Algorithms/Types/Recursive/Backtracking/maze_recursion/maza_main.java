package Recursive_Algorithms.Backtracking.maze_recursion;

public class maza_main {
    public static boolean escapeMaze(Maze maze, int row, int column){
        //BASE CASE: if square is not empty = return false
        if (maze.getSquare(row, column) != ' ') {
            return false;
        //BASE CASE: if on explored square return false
        }else if (maze.isExplored(row, column)){
            return false;
        }
        //BASE CASE: if on the edge(width) - check if  found exit
        else if ((row == maze.getHeight()-1 || row == 0 || column == maze.getWidth()-1 || column == 0) && maze.getSquare(row, column) == ' '){ 
            maze.setSquare(row, column, '.');
            return true; //if on the bound and free space means found exit
            
        } else{ //RECURSIVE CASE:
            //BACKTRACKING ALGORITHM:
            //mark current square as explored(backtracking)
            maze.setExplored(row, column, true);
            
            if (escapeMaze(maze, row + 1, column) 
                || escapeMaze(maze, row -1, column)
                || escapeMaze(maze, row, column+1) 
                || escapeMaze(maze, row, column-1))
            {
            maze.setSquare(row, column, '.'); //marks path if either returns true  
            System.out.println(maze.toString());
            return true;
            }

            //mark current square as not explored and go backwards (backtracking)
            maze.setExplored(row, column, false);
            return false;
        }
    }
    //TIPS
    // 1.Identify the Base Case First
    // What’s the condition for success? (In this case, reaching an empty edge square.)
   
    // 2.Handle Invalid Moves Early
    // Check for walls, boundaries, or already-visited spots to avoid unnecessary work.
   
    // 3.Use Recursion to Explore All Possibilities
    // Try all directions (up, down, left, right).
    // Combine results with OR (||) logic because you only need one path to succeed.
    
    // 4. Mark Your Path (Backtracking)
    // Mark squares when you visit them to avoid loops.
    // Unmark them if you need to backtrack and try other options.
    
    // 5. Think of Recursion as Stacking Moves
    // Each recursive call is like stacking moves on top of each other.
    // When you hit a dead-end, you "pop" off the stack and try another move.
    
    // 6.Draw It Out
    // For tricky mazes, drawing the maze and tracing the algorithm’s decisions helps a lot.
    
    public static void main(String[] args) {
        Maze maze = new Maze(   "##########\r\n" + 
                                "#        #\r\n" + 
                                "# ### ## #\r\n" + 
                                "# #    # #\r\n" + 
                                "# #  # # #\r\n" + 
                                "# ## #####\r\n" + 
                                "# #      #\r\n" + 
                                "# # #  # #\r\n" + 
                                "##### ####\r\n" + 
                                "#   #     \r\n" + 
                                "# #    # #\r\n" + 
                                "##########");
        System.out.println(maze.getHeight());
        System.out.println(maze.getWidth());
        escapeMaze(maze, 6, 1);
        
    }
}
