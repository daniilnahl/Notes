JAVA WAS NOT DESIGNED FOR FILE PROCESSING

## WHAT IS FILE PROCESSING IN JAVA?
    It's an object that can be accessed using Scanner method. Scanner method is basically the input function of JAVA.

## HOW TO USE FILE PROCESSING IN JAVA?
    Import java.io and then construct a file object. Example in main file.
    You can use simpe file name to access it, "funny1.txt" or 
    "fully qualified" (complete name), "C:/data/numbers.dat".
    You can also shorten it to "data/numbers.dat".
    
    Token Based Processing - one word processing at a time.
        nextInt - reads int value.
        nextDouble - read double value.
        next - reads as String.
        nextLine - read a whole line.

    USEFUL methods:
    hasNext() - checks if there's more data to read.
    hasNextLine() - checks if there's more lines
    canRead() - checks if a file exists and can be read. 

    Making a PrintStream object would create a file and allow me to interact with the said file.