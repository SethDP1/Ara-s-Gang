//Luhn Responsibilities:
#include <iostream>
using namespace std;


int main()
{
  //obtain card number

  char card_digits[16] = {};
  
  cout << "Please enter the number for verification: ";
  cin >> card_digits;
  //read card/string inout

 


  for(int j = 0; j <= 15; j++)
  {
    cout << j << " digit is " << card_digits[j] << endl;
  }


  //perform luhn algorithm
  //report valid/invalid
    return 0;
}

  //read card/string inout
  //perform luhn algorithm
  //report valid/invalid

//Side Note: Luhn is separate entirely from the 2048 game

//Alex is working on Luhn
