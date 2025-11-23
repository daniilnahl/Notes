/*** Your goals are the following. You will model a Motor as an abstract data type. You will model a PiCamera as an abstract data type. You will model a MecanumCar that is composed of four motors and one camera and that tracks its position and heading in a 2D space. All data members must be private. The visualization program will only interact with your code through the public interface of MecanumCar and will not access any internal details.
You will work on two files: CarModel.h and CarModel.cpp. The header file CarModel.h is given to you and you should not change it. The implementation file CarModel.cpp contains TODO comments that you must complete. The visualization program is in CarSimulatorGUI.cpp. You do not modify CarSimulatorGUI.cpp; it is only used to test and visualize your work.
At the end, you will submit a single .zip file containing only CarModel.h and CarModel.cpp. Do not include CarSimulatorGUI.cpp in the zip. To test your work locally, place all three files in the same folder and compile and run from the terminal with:
g++ -std=c++14 CarModel.cpp CarSimulatorGUI.cpp -o CarSimulatorGUI
./CarSimulatorGUI
All three files must be in the same folder when you compile and run.
When you are done, compress CarModel.h and CarModel.cpp into a single zip file and upload that zip file as your submission.
***/