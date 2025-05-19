package practice;

import java.util.*;
import java.io.*;

public class piglation2 {
    public static void pigLatin2(Scanner input){
        String convertedText = "";        
        String vowels = "aeiouAEIOU"; //use .contains() to check for vowel

        while (input.hasNextLine()){
            String line = input.nextLine();
            String[] words = line.split(" ");

            //checks if the line is empty. .trim() deletes all white spaces and .isEmpty() checks if the the line contains anything
            if (line.trim().isEmpty()) {
                convertedText += "\n"; //append an empty line
                continue; //skips all other code
            }

            for (int i = 0; i < words.length; i++){
                if(vowels.contains((String.valueOf(words[i].charAt(0))))){ //gets 0 element of string through char and then converts it to string using string class
                    convertedText += words[i] + "yay ";
                }
                else{ //in this one for constants move them to the end until a sylabul is found
                    String temp_word = "";
                    String constants = "";
                    boolean foundVowel = false;

                    for (int j = 0; j < words[i].length(); j++){
                        if (vowels.contains((String.valueOf(words[i].charAt(j)))) || foundVowel == true){
                            temp_word += (String.valueOf(words[i].charAt(j)));
                            foundVowel = true;
                        }
                        else{
                            constants += (String.valueOf(words[i].charAt(j)));
                        }
                    }

                    temp_word += constants + "ay"; //adds first letter to the end and the ay
                    convertedText += temp_word + " ";
                }
            }
            convertedText += "\n";
        }

        System.out.println(convertedText);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner input = new Scanner(new File("pigg1.txt"));
        pigLatin2(input);
    }
}