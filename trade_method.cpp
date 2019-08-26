/*
Name: Jamian Smith
Course: CSE703
Assignment Type: Project
Assignment Name: 30 Day Moving Average Calculation

Description: This program reads in the closing stock prices for the dates of
Jan-1-2015 through April-2-2016. After reading in the prices, the 30 day moving average
is calculated. The 30 day moving average and corresponding current stock price for that
time frame are written to an output file which will be used within MATLAB to display the
technical graphs of the stock prices over time.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
 ////////////Read in Prices//////////////////////////
 vector<long double> numbers;
 long double prices;
  
 fstream (dataFile);
 dataFile.open("pricesOnly.txt");
  
 while(! dataFile.eof()){
   dataFile >> prices;
   numbers.push_back(prices);

 }
 dataFile.close();
 /////////////End of Read in Prices////////////////////

 ofstream myfile ("current_vs_movingAverage.txt");
 if(myfile.is_open())
 {
   //  Initialize variables.
   const int NUMBERS_SIZE = 344;
   long double accountBalance = 10000.00; 

   

   int windowSize = 30;
   long double sum = 0.0;
   long double movingAverage = 0.0;


   //  Loop through nums in list, excluding any at the end that will be
   //+ covered by the nested for-loop.
   for (int i = 0; i <= (NUMBERS_SIZE - windowSize); i++) {

      sum = 0.0;                // Reinitialize sum back to zero.
      //cout << "For numbers ";

      // Loop through x numbers from current i position where x = windowSize.
      for (int j = i; j < i + windowSize; j++) {
         sum += numbers[j];           // Increment sum.
         //cout << numbers[j] << " ";
      }
      
      // Print out current price.
      cout <<  "Current Price: " << numbers[i + windowSize];

      // Calculate moving average and display.
      movingAverage = sum / windowSize;
      cout << "    " << "Moving Average: " << movingAverage;

      if (numbers[i + windowSize] > movingAverage){
        cout << "    " << "Buy Side at: " << numbers[i + windowSize];
      }

      if (numbers[i + windowSize] < movingAverage){
        cout << "    " << "Sell Side at: " << numbers[i + windowSize];
      }

      myfile << numbers[i +windowSize] << ", " << movingAverage << endl;

      cout << endl;
   }
  myfile.close();
  }
   return 0;
}
