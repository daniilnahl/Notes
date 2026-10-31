from datetime import datetime
import time
    
#code to show practical use of read and write
def main_files():
    #assas = open('pg37431.txt') - simple way to open a file
    
    with open('pg37431.txt', encoding="utf-8") as f: #more advance to open a file
        print(f.readline()) #reads a line from a file
    
    example = open('log.txt', "w", encoding="utf-8") #w+ is a mode type.
    for i in range(0,10):
        print(datetime.now().strftime("%Y%m%d_%H:%M:%S–"),i)
        example.write(datetime.now().strftime("%Y%m%d_%H:%M:%S–"))
        time.sleep(1)
        example.write(str(i))
        example.write('\n')
    example.close()
    

if __name__ == "__main_files__":
    main_files()