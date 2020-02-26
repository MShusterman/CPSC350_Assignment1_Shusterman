#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//void Log(const char* message);

int main() {

    cout << '\n';
    cout << "***************************************************************************" << std::endl;
    cout << '\n';

    cout << "==========================" << std::endl;
    cout << "This is Michael's DNA Code" << std::endl;
    cout << "Please enter name of text file: ";
    string fileName = "";
    getline(cin, fileName);
    cout << "==========================" << std::endl;
    cout << '\n';

    string dnaline;
    ifstream dnaFile (fileName);

    int dnaSum = 0;
    int dnaStringCount = 0;
    int amountOfDNALines = 0;

    if (dnaFile.is_open()) {
      while (getline(dnaFile,dnaline)){
        amountOfDNALines++;
      }
    }

    cout << "==========================" << std::endl;
    cout << "The number of DNA lines is: ";
    cout << amountOfDNALines;
    dnaFile.clear(); //resets the input text file
    dnaFile.seekg(0, ios::beg); //resets the input text file
    cout << '\n';

    //printDNA(filename, amountOfDNALines); // This operation will print out the string names to the console
    //int dnaSum = dnaSum(filename, amountofDNAlines); // This opeartion should assign the DNA sum of characters
    //int dnaMean = dnaMean(filename, amountofDNAlines); 

    float dnaLengthArray[amountOfDNALines];
    int DLAMarker = 0;

    cout << "Here is the following DNA strings:" << std::endl;
    if (dnaFile.is_open()) {
      while (getline(dnaFile,dnaline)){
        int lineLength = dnaline.length() - 1; //the lengths are one too many each line (excluding the last one) | this sets the size of the int
        dnaLengthArray[DLAMarker] = lineLength; // this sets the spot in the array equal to the line length
        DLAMarker++; // this increments the spot in the array to move it up by one
        dnaSum += lineLength; // this increases the sum of the dnaSum to be equal to the length
        dnaStringCount++; // this counts the amount of dna strings in total
          for (int i = 0; i < lineLength; ++i){ // this ensures all of the characters in the DNA string are uppercase
            dnaline[i] = toupper(dnaline[i]);
          }
        cout << dnaline << '\n'; // this prints out the dnaLine
      }
    }
    else cout << "Unable to open file";
    cout << "==========================" << std::endl;
    cout << '\n';

    cout << "==========================" << std::endl;
    cout << "Here is the length of each DNA string:" << std::endl;
    dnaFile.clear(); //resets the input text file
    dnaFile.seekg(0, ios::beg); //resets the input text file
    int i = 0;
    if (dnaFile.is_open()) {
      while (getline(dnaFile,dnaline)){
        i++;
        int newLength = dnaline.length() - 1;
        cout << "Line " << i << " is " << newLength << " acids long" << '\n';
      }
    }
    cout << "==========================" << std::endl;
    cout << '\n';

    cout << "==========================" << std::endl;
    cout << "Here is the length of each DNA string in the array:" << std::endl;
    for (int x : dnaLengthArray)
      cout << x << endl;
    cout << "==========================" << std::endl;

    // the math starts here

    //here I calculate mean
    float dnaMean = 0.0;
    dnaMean = (float)dnaSum / (float)dnaStringCount; // calculates the mean of the set

    //this is where I calculate variance (ophh boi)
    float dnaVarianceArray[amountOfDNALines];
    float dnaVariance = 0.0;
    for (int i = 0; i < amountOfDNALines; ++i){
      dnaVarianceArray[i] = (float)dnaLengthArray[i];
      dnaVarianceArray[i] = dnaVarianceArray[i] - (float)dnaMean;
      dnaVarianceArray[i] = dnaVarianceArray[i] * dnaVarianceArray[i];
      dnaVariance = dnaVariance + dnaVarianceArray[i];
    }
    dnaVariance = dnaVariance / amountOfDNALines;

    //this is where I calculate standard devidation
    float dnaDeviationArray[amountOfDNALines];
    float dnaDeviation = 0.0;
    float dnaDeviationMean = 0.0;
    for (int i = 0; i < amountOfDNALines; ++i){
      dnaDeviationArray[i] = float(dnaLengthArray[i]);
      dnaDeviationArray[i] = dnaDeviationArray[i] - float(dnaMean);
      dnaDeviationArray[i] = dnaDeviationArray[i] * dnaDeviationArray[i];
      dnaDeviationMean += dnaDeviationArray[i];
    }
    dnaDeviationMean = dnaDeviationMean / amountOfDNALines;
    dnaDeviation = sqrt(dnaDeviationMean);

    cout << '\n';
    cout << "==========================" << std::endl;
    cout << "The Sum of the length of the DNA strings is: " << dnaSum << std::endl;
    cout << "The Mean of the length of the DNA strings is: " << dnaMean << std::endl;
    cout << "The variance of the length of the DNA strings is: " << dnaVariance << std::endl;
    cout << "The deviation of the length of the DNA strings is: " << dnaDeviation << std::endl;
    cout << "==========================" << std::endl;
    cout << '\n';
    cout << "***************************************************************************" << std::endl;
    cout << '\n';

    return 0;
}
