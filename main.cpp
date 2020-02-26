#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#include <string>
#include <cstdio>
#include <stdio.h>

void append(string newFileName, string originalFile){

  cout << "\n";
  cout << "Appending..." << std::endl;
  string newString = "";

  ofstream ogFile;
  ogFile.open(originalFile, std::ios_base::app);

  if (ogFile.is_open()) {
    string copyString;
    ifstream newfile (newFileName);
      while(getline(newfile,newString)){
        copyString = newString;
        ogFile << copyString << std::endl;
      }
    newfile.close();

    if (remove ( newFileName.c_str() ) != 0)
      perror("Error deleting appended File");
    else
      cout << "\n";

  }
  ogFile.close();
}

int main(){

  bool newList = true;
  int fileNumber = -1;
  bool newProcess = false;
  string originalFile = "";

  while (newList == true){

  //HEADER - Establishes console design and gets the name of the file
  newList = false;
  fileNumber++;

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

  //Declerations
  int amountOfDNALines = 0;

  int dnaSum = 0;
  float dnaMean = 0.0;
  float dnaVariance = 0.0;
  float dnaDeviation = 0.0;

  int totalAcid = 0;
  int dnaPairSum = 0;
  int aAcid = 0;
  int cAcid = 0;
  int tAcid = 0;
  int gAcid = 0;
  double aAcidProbability = 0.0;
  double cAcidProbability = 0.0;
  double tAcidProbability = 0.0;
  double gAcidProbability = 0.0;
  int acidAA = 0;
  int acidAC = 0;
  int acidAT = 0;
  int acidAG = 0;
  int acidCA = 0;
  int acidCC = 0;
  int acidCT = 0;
  int acidCG = 0;
  int acidTA = 0;
  int acidTC = 0;
  int acidTT = 0;
  int acidTG = 0;
  int acidGA = 0;
  int acidGC = 0;
  int acidGT = 0;
  int acidGG = 0;
  double acidAAProbability = 0.0;
  double acidACProbability = 0.0;
  double acidATProbability = 0.0;
  double acidAGProbability = 0.0;
  double acidCAProbability = 0.0;
  double acidCCProbability = 0.0;
  double acidCTProbability = 0.0;
  double acidCGProbability = 0.0;
  double acidTAProbability = 0.0;
  double acidTCProbability = 0.0;
  double acidTTProbability = 0.0;
  double acidTGProbability = 0.0;
  double acidGAProbability = 0.0;
  double acidGCProbability = 0.0;
  double acidGTProbability = 0.0;
  double acidGGProbability = 0.0;
  double acidAARankedProbability = 0.0;
  double acidACRankedProbability = 0.0;
  double acidATRankedProbability = 0.0;
  double acidAGRankedProbability = 0.0;
  double acidCARankedProbability = 0.0;
  double acidCCRankedProbability = 0.0;
  double acidCTRankedProbability = 0.0;
  double acidCGRankedProbability = 0.0;
  double acidTARankedProbability = 0.0;
  double acidTCRankedProbability = 0.0;
  double acidTTRankedProbability = 0.0;
  double acidTGRankedProbability = 0.0;
  double acidGARankedProbability = 0.0;
  double acidGCRankedProbability = 0.0;
  double acidGTRankedProbability = 0.0;
  double acidGGRankedProbability = 0.0;


  ifstream dnaFile (fileName);

  //Body A - This gets the amount of DNA lines present in the text file
  string dnaLine;
  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){
      amountOfDNALines++;
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  cout << "==========================" << std::endl;
  cout << "The number of DNA lines is: ";
  cout << amountOfDNALines << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body B - This gets the amount of DNA characters present in the text file
  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){
      int lineLength = dnaLine.length() - 1;
      dnaSum += lineLength;
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  cout << "==========================" << std::endl;
  cout << "The sum of the DNA lines is: ";
  cout << dnaSum << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body C - This gets the mean of DNA string lengths present in the text file
  dnaMean = (float)dnaSum / (float)amountOfDNALines;

  cout << "==========================" << std::endl;
  cout << "The mean of the DNA lines is: ";
  cout << dnaMean << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body D - This gets the variance of DNA string lengths present in the text file
  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){
      float lineLength = dnaLine.length() - 1;
      lineLength  -= (float)dnaMean;
      lineLength = lineLength * lineLength;
      dnaVariance += lineLength;
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  dnaVariance = dnaVariance / amountOfDNALines;

  cout << "==========================" << std::endl;
  cout << "The variance of the DNA lines is: ";
  cout << dnaVariance << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body E - This gets the deviation of DNA string lengths present in the text file
  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){
      float lineLength = dnaLine.length() - 1;
      lineLength  -= (float)dnaMean;
      lineLength = lineLength * lineLength;
      dnaDeviation += lineLength;
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  dnaDeviation = dnaDeviation / amountOfDNALines;
  dnaDeviation = sqrt(dnaDeviation);

  cout << "==========================" << std::endl;
  cout << "The deviation of the DNA lines is: ";
  cout << dnaDeviation << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body F - This gets the relative probability of each nucleotide
  totalAcid = dnaSum; //this is redudant but helps me think better ¯\_(ツ)_/¯.

  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){ //iterates through each line
      for (int i = 0; i < dnaLine.length(); ++i){ //iterates through each character
        char acidTest = toupper(dnaLine[i]);
        if (acidTest == 'A'){
          aAcid++;
        }
        else if (acidTest == 'C'){
          cAcid++;
        }
        else if (acidTest == 'T'){
          tAcid++;
        }
        else if (acidTest == 'G'){
          gAcid++;
        }
      }
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  aAcidProbability = (double)aAcid / (double)totalAcid;
  cAcidProbability = (double)cAcid / (double)totalAcid;
  tAcidProbability = (double)tAcid / (double)totalAcid;
  gAcidProbability = (double)gAcid / (double)totalAcid;

  cout << "==========================" << std::endl;
  cout << "A: ";
  cout << aAcid << " | " << aAcidProbability << std::endl;
  cout << "C: ";
  cout << cAcid << " | " << cAcidProbability << std::endl;
  cout << "T: ";
  cout << tAcid << " | " << tAcidProbability << std::endl;
  cout << "G: ";
  cout << gAcid << " | " << gAcidProbability << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body G - This gets the relative probability of each nucleotide combination
  if (dnaFile.is_open()){
    while(getline(dnaFile,dnaLine)){
      for (int i = 0; i < dnaLine.length(); i = i + 2){
        int nextUp = i + 1;
        char acidOneTest = toupper(dnaLine[i]);
        char acidTwoTest = toupper(dnaLine[nextUp]);

        if (acidOneTest == 'A'){
          if (acidTwoTest == 'A'){
            acidAA++;
          }
          else if (acidTwoTest == 'C'){
            acidAC++;
          }
          else if (acidTwoTest == 'T'){
            acidAT++;
          }
          else if (acidTwoTest == 'G'){
            acidAG++;
          }
        }
        if (acidOneTest == 'C'){
          if (acidTwoTest == 'A'){
            acidCA++;
          }
          else if (acidTwoTest == 'C'){
            acidCC++;
          }
          else if (acidTwoTest == 'T'){
            acidCT++;
          }
          else if (acidTwoTest == 'G'){
            acidCG++;
          }
        }
        if (acidOneTest == 'T'){
          if (acidTwoTest == 'A'){
            acidTA++;
          }
          else if (acidTwoTest == 'C'){
            acidTC++;
          }
          else if (acidTwoTest == 'T'){
            acidTT++;
          }
          else if (acidTwoTest == 'G'){
            acidTG++;
          }
        }
        if (acidOneTest == 'G'){
          if (acidTwoTest == 'A'){
            acidGA++;
          }
          else if (acidTwoTest == 'C'){
            acidGC++;
          }
          else if (acidTwoTest == 'T'){
            acidGT++;
          }
          else if (acidTwoTest == 'G'){
            acidGG++;
          }
        }
      }
    }
  }
  dnaFile.clear(); //resets the input text file
  dnaFile.seekg(0, ios::beg); //resets the input text file

  dnaPairSum = dnaSum / 2;
  acidAAProbability = (double)acidAA / (double)dnaPairSum;
  acidACProbability = (double)acidAC / (double)dnaPairSum;
  acidATProbability = (double)acidAT / (double)dnaPairSum;
  acidAGProbability = (double)acidAG / (double)dnaPairSum;
  acidCAProbability = (double)acidCA / (double)dnaPairSum;
  acidCCProbability = (double)acidCC / (double)dnaPairSum;
  acidCTProbability = (double)acidCT / (double)dnaPairSum;
  acidCGProbability = (double)acidCG / (double)dnaPairSum;
  acidTAProbability = (double)acidTA / (double)dnaPairSum;
  acidTCProbability = (double)acidTC / (double)dnaPairSum;
  acidTTProbability = (double)acidTT / (double)dnaPairSum;
  acidTGProbability = (double)acidTG / (double)dnaPairSum;
  acidGAProbability = (double)acidGA / (double)dnaPairSum;
  acidGCProbability = (double)acidGC / (double)dnaPairSum;
  acidGTProbability = (double)acidGT / (double)dnaPairSum;
  acidGGProbability = (double)acidGG / (double)dnaPairSum;

  cout << "==========================" << std::endl;
  cout << "AA: " << acidAA << " | " << acidAAProbability << std::endl;
  cout << "AC: " << acidAC << " | " << acidACProbability << std::endl;
  cout << "AT: " << acidAT << " | " << acidATProbability << std::endl;
  cout << "AG: " << acidAG << " | " << acidAGProbability << std::endl;
  cout << "CA: " << acidCA << " | " << acidCAProbability << std::endl;
  cout << "CC: " << acidCC << " | " << acidCCProbability << std::endl;
  cout << "CT: " << acidCT << " | " << acidCTProbability << std::endl;
  cout << "CG: " << acidCG << " | " << acidCGProbability << std::endl;
  cout << "TA: " << acidTA << " | " << acidTAProbability << std::endl;
  cout << "TC: " << acidTC << " | " << acidTCProbability << std::endl;
  cout << "TT: " << acidTT << " | " << acidTTProbability << std::endl;
  cout << "TG: " << acidTG << " | " << acidTGProbability << std::endl;
  cout << "GA: " << acidGA << " | " << acidGAProbability << std::endl;
  cout << "GC: " << acidGC << " | " << acidGCProbability << std::endl;
  cout << "GT: " << acidGT << " | " << acidGTProbability << std::endl;
  cout << "GG: " << acidGG << " | " << acidGGProbability << std::endl;
  cout << "==========================" << std::endl;
  cout << '\n';

  //Body H - This prints out the above to a text file
  string newFileName = "Michael_Shusterman_" + std::to_string(fileNumber) + ".txt";
  ofstream myfile (newFileName);
  if (myfile.is_open())
  {
    myfile << '\n';
    myfile << "********************************************************";
    myfile << '\n';
    myfile << "Name: Michael Shusterman" << "\n";
    myfile << "Student ID: 2287861" << "\n";
    myfile << "\n";
    myfile << "The Sum of the length of the DNA strings is: " << dnaSum << "\n";
    myfile << "The Mean of the length of the DNA strings is: " << dnaMean << "\n";
    myfile << "The Variance of the length of the DNA strings is: " << dnaVariance<< "\n";
    myfile << "The Standard Deviation of the length of the DNA strings is: " << dnaDeviation<< "\n";
    myfile << "Here is the relative probability of each nucleotide: \n";
    myfile << "\n";
    myfile << "A:           " << aAcidProbability << "\n";
    myfile << "C:           " << cAcidProbability << "\n";
    myfile << "T:           " << tAcidProbability << "\n";
    myfile << "G:           " << gAcidProbability << "\n";
    myfile << "\n";
    myfile << "Here is the relative probability of each nucleotide bigram: \n";
    myfile << "\n";
    myfile << "AA:           " << acidAAProbability << "\n";
    myfile << "AC:           " << acidACProbability << "\n";
    myfile << "AT:           " << acidATProbability << "\n";
    myfile << "AG:           " << acidAGProbability << "\n";
    myfile << "CA:           " << acidCAProbability << "\n";
    myfile << "CC:           " << acidCCProbability << "\n";
    myfile << "CT:           " << acidCTProbability << "\n";
    myfile << "CG:           " << acidCGProbability << "\n";
    myfile << "TA:           " << acidTAProbability << "\n";
    myfile << "TC:           " << acidCCProbability << "\n";
    myfile << "TT:           " << acidTTProbability << "\n";
    myfile << "TG:           " << acidTGProbability << "\n";
    myfile << "GA:           " << acidGAProbability << "\n";
    myfile << "GC:           " << acidGCProbability << "\n";
    myfile << "GT:           " << acidGTProbability << "\n";
    myfile << "GG:           " << acidGGProbability << "\n";
    myfile << "\n";

    myfile.close();
  }
  else cout << "Unable to open file";

  //Body I - This appends a new list of DNA strings
  ofstream myNewFile;
  myNewFile.open(newFileName, std::ios_base::app);

  bool firstTimeDNA = true;
  bool writeDNA = true;
  bool dnaWritePass = true;

  while (writeDNA == true){

    if (firstTimeDNA == true){
      myNewFile << "Here are 1000 DNA strings:" << '\n';
      firstTimeDNA = false;
      dnaWritePass = true;
    }
    else{
      cout << "Would you like another list of DNA strings? (Y/N): ";
      string answer = "";
      getline(cin, answer);

      if (answer == "Y"){
        myNewFile << '\n';
        myNewFile << "Here are 1000 more DNA strings:" << '\n';
        dnaWritePass = true;
      }
      else{
        dnaWritePass = false;
        writeDNA = false;
      }
    }

    if(dnaWritePass == true){
      int upDownVar = 0;

        for (int i = 0; i < 1000; i++){
          double aRan = ((double) rand() / (RAND_MAX));
          double bRan = ((double) rand() / (RAND_MAX));

          double gaussianPartA = sqrt(-2*log(aRan)); // I split these up because my computer was having troubles with them together ¯\_(ツ)_/¯.
          double gaussianPartB = cos(2*(M_PI)*bRan); // yeah that ^

          double GaussianVariable = gaussianPartA * gaussianPartB;
          GaussianVariable = dnaMean*GaussianVariable + dnaVariance;
          if (GaussianVariable < 0) {
            GaussianVariable = GaussianVariable * (-1);
          }

          int GaussianLength = (int)GaussianVariable;
          if (GaussianLength % 2 != 0){
            if (upDownVar == 1){
              GaussianLength = GaussianLength + 1;
              upDownVar = upDownVar - 1;
            }
            else{
              upDownVar++;
              GaussianLength = GaussianLength - 1;
            }
          }

          if (GaussianLength == 0){
            i = i - 1;
          }
          else{

            acidAARankedProbability = 0.0 + acidAAProbability;
            acidACRankedProbability = acidAARankedProbability + acidACProbability;
            acidATRankedProbability = acidACRankedProbability + acidATProbability;
            acidAGRankedProbability = acidATRankedProbability + acidAGProbability;
            acidCARankedProbability = acidAGRankedProbability + acidCAProbability;
            acidCCRankedProbability = acidCARankedProbability + acidCCProbability;
            acidCTRankedProbability = acidCCRankedProbability + acidCTProbability;
            acidCGRankedProbability = acidCTRankedProbability + acidCGProbability;
            acidTARankedProbability = acidCGRankedProbability + acidTAProbability;
            acidTCRankedProbability = acidTARankedProbability + acidTCProbability;
            acidTTRankedProbability = acidTCRankedProbability + acidTTProbability;
            acidTGRankedProbability = acidTTRankedProbability + acidTGProbability;
            acidGARankedProbability = acidTGRankedProbability + acidGAProbability;
            acidGCRankedProbability = acidGARankedProbability + acidGCProbability;
            acidGTRankedProbability = acidGCRankedProbability + acidGTProbability;
            acidGGRankedProbability = acidGTRankedProbability + acidGGProbability;


            string newGaussianString = "";
            for (int j = 0; j < GaussianLength / 2; j++){
              float newGaussianSection = (float) rand() / RAND_MAX;
              if ( (newGaussianSection >= 0) && (newGaussianSection <= acidAARankedProbability)){
                newGaussianString = newGaussianString + "AA";
              }
              else if (newGaussianSection > acidAAProbability && newGaussianSection <= acidACRankedProbability){
                newGaussianString = newGaussianString + "AC";
              }
              else if (newGaussianSection > acidACProbability && newGaussianSection <= acidATRankedProbability){
                newGaussianString = newGaussianString + "AT";
              }
              else if (newGaussianSection > acidATProbability && newGaussianSection <= acidAGRankedProbability){
                newGaussianString = newGaussianString + "AG";
              }
              else if (newGaussianSection > acidAGProbability && newGaussianSection <= acidCARankedProbability){
                newGaussianString = newGaussianString + "CA";
              }
              else if (newGaussianSection > acidCAProbability && newGaussianSection <= acidCCRankedProbability){
                newGaussianString = newGaussianString + "CC";
              }
              else if (newGaussianSection > acidCCProbability && newGaussianSection <= acidCTRankedProbability){
                newGaussianString = newGaussianString + "CT";
              }
              else if (newGaussianSection > acidCTProbability && newGaussianSection <= acidCGRankedProbability){
                newGaussianString = newGaussianString + "CG";
              }
              else if (newGaussianSection > acidCGProbability && newGaussianSection <= acidTARankedProbability){
                newGaussianString = newGaussianString + "TA";
              }
              else if (newGaussianSection > acidTAProbability && newGaussianSection <= acidTCRankedProbability){
                newGaussianString = newGaussianString + "TC";
              }
              else if (newGaussianSection > acidTCProbability && newGaussianSection <= acidTTRankedProbability){
                newGaussianString = newGaussianString + "TT";
              }
              else if (newGaussianSection > acidTTProbability && newGaussianSection <= acidTGRankedProbability){
                newGaussianString = newGaussianString + "TG";
              }
              else if (newGaussianSection > acidTGProbability && newGaussianSection <= acidGARankedProbability){
                newGaussianString = newGaussianString + "GA";
              }
              else if (newGaussianSection > acidGAProbability && newGaussianSection <= acidGCRankedProbability){
                newGaussianString = newGaussianString + "GC";
              }
              else if (newGaussianSection > acidGCProbability && newGaussianSection <= acidGTRankedProbability){
                newGaussianString = newGaussianString + "GT";
              }
              else if (newGaussianSection > acidGTProbability && newGaussianSection <= acidGGRankedProbability){
                newGaussianString = newGaussianString + "GG";
              }
            }
            myNewFile << newGaussianString << std::endl;
          }
        }
      }
    }
  myNewFile << "********************************************************";
  myNewFile << '\n';

  myNewFile.close();

  if (newProcess == false){
    originalFile = newFileName;
  }
  else if (newProcess == true){
    append(newFileName, originalFile);
  }

  cout << "Would you like to process another list of input DNA?(Y/N): ";
  string reset = "";
  getline(cin, reset);

  if (reset == "Y"){
    newList = true;
    newProcess = true;
  }
  else{
    newList = false;
    newProcess = false;
  }
  cout << '\n';
  cout << "***************************************************************************" << std::endl;
}
  return 0;
}
