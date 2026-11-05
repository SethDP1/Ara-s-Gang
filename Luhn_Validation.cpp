#include <iostream>
using namespace std;

bool Digit_Processing(char card_characters[16])
{
  bool is_valid = false;
  int temp = 0;
  int sum[16] = {};
  int card_integers[16] = {};
  int Total_sum = 0;

  cout << "Correct Format; ";
      /*
      -----------Digit Processing-----------
      */

  //Char to Int conversion
  for(int index = 0; index < 16; index++)
  {
    //subtracting the ASCII value for the character number and the ASCII , for 0 
    card_integers[index] = (card_characters[index] - '0');
  }

    //Digit Calculation
  for(int digit = 15; digit >= 0; digit--)
  {

    if ((digit %2) == 1)
    {
      sum[digit] = card_integers[digit];
    }
    else if((digit %2) == 0)
    {
      temp = (card_integers[digit] * 2);
      if (temp > 9)
      {
        sum[digit] = (temp - 9);
      }
      else if (temp <= 9)
      {
        sum[digit] = temp;
      }
    }
  }


      /*
      -----------SUM & CHECK-----------
      */
    
  //SUM
  for(int j = 0; j < 16; j++)
  {
    Total_sum += sum[j];
  }
  //Mod 10 check
  if((Total_sum % 10) != 0)
  {
    is_valid = false;
  }
  else if ((Total_sum % 10) == 0)
  {
    is_valid = true;
  }

  return (is_valid);
}





int main()
{
  //VARIABLE BANK FOR REPEATS
  bool exit = false;
  bool repeat_error = false;
  string repeat = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";

  
//THE LOOP
  while (exit == false)
  {
    //RESET VARIABLE BANK
    char card_characters[16] = {};
    int count = 0;
    bool is_letter = false;
    bool Dig_Check = false;

      
    //Receive the Card Number from User
    cout << "Please enter the number for verification: ";
    cin >> card_characters;


    /*
    -----------CHECK FORMATTING-----------
    */

    //Check digit count
    while(card_characters[count] != '\0')
    {
      count += 1;
    }

    if (count == 16)
    {
      Dig_Check = true;
    }

    //Check if all numbers
    for(int check = 0; check < 16; check++)
    {
      if ((card_characters[check] - '0') < 0 || (card_characters[check] - '0') > 9)
      {
        is_letter = true;
      }
    }
    
    if (Dig_Check == true && is_letter == false)
    {
      //Is_valid Output
      if (Digit_Processing(card_characters))
      {
        cout << "Checksum Passes" << endl;
      }
      else
      {
          cout << "Checksum Fails" << endl;
      }
    }

    /*
    -----------Outputs-----------
    */

    //formating outputs

    if (Dig_Check == false)
    {
      cout << "Reject: " << count << " digits" << endl;
    }
    else if (is_letter == true)
    {
      cout << "Reject: Invalid Digit (Letter or Space) " << endl;
    }

    repeat_error = true;

    while (repeat_error == true)
    {
      cout << "Would you like to exit (Yes or No): " << endl;
      cin >> repeat;
      cout << "'" << repeat << "'" << endl;
      if (repeat == "Yes" || repeat == "yes" || repeat == "YES")
      {
        cout << "Thank you for using this algorithm :)";
        exit = true;
        repeat_error = false;
      }
      else if (repeat == "No" || repeat == "no" || repeat == "NO")
      {
        exit = false;
        repeat_error = false;
      }
      else
      {
        cout << "Input '" << repeat << "' not understood, Please try again. ";
        repeat_error = true;
      }
    }
  }

  return 0;
} 