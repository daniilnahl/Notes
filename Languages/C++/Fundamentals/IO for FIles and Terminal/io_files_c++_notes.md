# How to interact with a file in C++?
1. include the headers -> <ifstream> and <ofstream> or <fstream> for both.
2. define a file stream object.
    - ifstream NAME; -> for reading from a file.
    - ofstream NAME; -> for writing to a file.
3. open the file:
    - inFile.open("inventory.dat");
    - outFile.open("report.txt");
    OR (creates and open a object and a file)
    - ifstream inFile("inventory.dat");
    - ofstream outFile("report.txt");
4. Use these:
    - outFile << "MESSAGE"; -> send data to file
    - inFile >> VARIABLE; -> copy data from the file
5. CLOSE THE FILE!
    - inFile.close();
    - outFIle.close();