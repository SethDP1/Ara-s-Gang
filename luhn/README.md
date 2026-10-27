# Alex could you pretty please type out your Luhn implementation plan here :)

1. take the card number as a 16 character array
2. verify if the number is correctly formatted
3. start the verification from the right
4. double every second number and if greater than 9 either subract 9 or add the digits together(same result)
5. sum all the doubled numbers and the untouched numbers 
6. take the modulo 10 of the sum and if the result is 0 then the number is possible