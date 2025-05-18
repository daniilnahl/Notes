### WHAT IS A FILE?
    In python a file is a resource you can use to store data on pc. There's writing and readin a file.

### WHY IS FILE IMPORTANT?
    It lets you store data from your app. Like how I am storing transactions in my project, but they reset each time, but with a file I could store for next time use. 

### WHY SHOULD I LEARN FILE?
    Its fundemntals of making apps. It lets you store data into files you can use later. 
    Opinion: Right now I need to know it for my project. Just two months into my journey I already need it.

### WHEN DO I USE FILE?
    WHEN:
        1. I need to store data to use it after my program terminates.
        2. I need to read data from files such as CSV, text, JSON, etc.
        3. I need to export data for a user or another program to use.
        4. Useful for logging information such as debugging and monitoring(FROM GOOGLE DONT KNOW HOW TO USE)

### HOW DO I USE FILE?
    There are three parts of using file functions in python. First is opening, 2nd reading and 3rd writing. 
    Down below are definitions and how they work. The python file has examples:
        1. open('FILE NAME', "mode", encoding="") - opens a file to let you access it. Assign to a variable. Also creates a file if no file with such name provided.
        2. .close() - closes a file. Used at the end of actions with a file, to ensure file is properly closed
            and all content in the buffer is written to a file.

        Reading files:
        1. read() - extract content of a file. 
        2. readline() - prints a specifc line.

        Writing Files:
        1. write() - records whatever in the () into a file. Doesn't automatically make a new line.
        
    MODE(the way you handle a file):
        w+, a mode that supports both reading and writing   
        r: The default mode. This opens a file for reading.
        w: Write mode. This opens a file for writing, creates a new file if the file does not exist, 
        and overwrites the content if the file already exists.
        x: This creates a new file. This operation fails if the file exists.
        a: This opens a file in append mode and creates a new file if a file does not exist.
        b: This opens a file in binary mode.
    
    ENCODING:
        utf-8: handles any character.
        ascii: only handles English characters and a small subset of symbols. Used in legacy systems.
        utf-16 or utf-32:  handle more characters per byte than UTF-8 but take up more space. They’re not often necessary unless you specifically need them for particular applications.
    