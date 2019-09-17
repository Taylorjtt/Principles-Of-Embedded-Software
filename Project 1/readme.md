
### Student : John Taylor

### Assignment:	Project 1


# Installation/Execution Notes
A shell script named buildAndRun.sh has been included in each program's directory
running this script will compile and run the program. Program output is piped to 
a file named Program(number).out, for example "Program1.out"

# Program Descriptions (taken from assignment document)

## Program 1: Integer Representation
A program that takes a numerical value, a radix and an operand size and outputs
a table of the value's representation in the following formats

Binary (abs)
Octal (abs)
Decimal(abs)
Hexidecimal(abs)
Signed One's Compliment
Signed Two's Compliment
Sign-Maginitude
as well as the minimum and maximum for each representation given the operand size.

The program has several error codes

* **Invalid Radix**			-  Radix != 8, 10 or 16
* **Invalid Operand Size**	-> Operand Size != 4, 8 or 16
* **< Error**				-> the given value is too small (too negative) to be represented with the given operand size
* **> Error**				-> the given value is too large to be represented with the given operand size



## Program 2: CharacterCodeTest
A program that uses a logical expression that tests whether a given character code is a

* **lower case**	(value 97-22)
* **upper case** 	(value 65-90)
* **digit** 		(value 48-57)
* **white space** 	(value 0-32 or 127)
* **special char** 	(any other value)

## Program 3: Bitwise Manipulation
A program that given the starting integer value 0xCAFE, performs each of these operations in
series.

1. Print the original input in hexadecimal
2. Test if **ANY** 3 of last 4 bits are on, and print the value in binary (along with the result of the test –
  true/false)
3. Reverse the byte order, print the value in hexadecimal
4. Test if **ANY** 3 of last 4 bits are on, and print the value in binary (along with the result of the test –
  true/false)
5. Rotate the value by four bits to the left, print the value in hexadecimal
6. Test if **ANY** 3 of last 4 bits are on, and print the value in binary (along with the result of the test –
  true/false)
7. Rotate the value by eight bits to the right, print the value in hexadecimal
8. Test if **ANY** 3 of last 4 bits are on, and print the value in binary (along with the result of the test - true/false
)
