#include <stdio.h>
#include <stdlib.h>

/*
 Student Name: Mory Fode Traore
 Date: 01/18/2020

ECE 2035 Homework 1-2

This is the only file that should be modified for the C implementation
of Homework 1.

This program determines whether the value of the global variable x
(expressed in hexadecimal notation) is a 16-Harshad number and if so,
whether the factors involved are mirrors of each other.  That is, if x
= p * q, where p = sum of hexadecimal digits of x and q is the reverse
of p (same digits in reverse order).  For example, 6A5 = 15*51 in base
16.

The program prints a statement indicating which of 3 cases is true:
1) x is not a 16-Harshad number,
2) x is a 16-Harshad number without mirror factors (and gives the factors), or
3) x is a 16-Harshad number with mirror factors (and gives the factors).

FOR FULL CREDIT, BE SURE TO TRY MULTIPLE TEST CASES and DOCUMENT YOUR CODE.

Test cases:  0x1AAF (Fail), 0x1A5F (Fail), 0xE29 (Pass - w), 0x1B00(Pass -w/o),
        0x1D2F (Pass -w), 0x1A90 (Pass -w/o), 0xE30 (Fail) || 0x6A4 (Pass w/o),
        0x6A5 (Pass -w), 0x6A3 (fail).

*/
// DO NOT change the following declaration (you may change the initial value):

unsigned x = 0x6A3;                 // value of x to changed and check through the code

int main() {

    unsigned p=0x0;                  // sum
    unsigned q=0x0;                 // remainder
    unsigned n;                    // store x
    unsigned mirror = 0;          // initializing the mirror
    unsigned l;                   // store value of mirror by base 16
    unsigned w;                   // Store mod
    unsigned p_copy;

    n = x;                       // Storing x to a variable

   while (x > 0){
    w = x % 16;                 // Getting the remain from module of x by base 16 in hexadecimal
    p = p + w;                  // Getting the sum of p and q
    x = x / 16;                 // Storing and getting the quotient of x by base 16 in hexadecimal
   }

   p_copy = p;                  // Setting p to a variable for mirroring process.

   while (p_copy > 0){
    l = p_copy % 16;            // Getting the remain of p_copy which is 1.
    p_copy = p_copy / 16;
    mirror = mirror << 4;       // Shifting the coefficient of mirror by 4
    mirror = mirror + l;        // Adding the value of mirror to make space for l
   }

   q = n / p;                 // Setting q equal to the original value of x divide by q to have a 16-harshad number.
   printf("%#x \n", p);
   printf("%#x \n", q);
   printf("%#x \n", mirror);
   // your program should use these print statements

   if (n%p != 0)        // Conditioning if the remainder is zero then x is not harshard.
        printf("%#x is not a 16-Harshad number.\n", n);
    else if (mirror == q)    // Conditioning if the shifted value of p is equal to q then it becomes its mirror as in 15 and 51.
        printf("%#x is a 16-Harshad number, w/ mirror factors: %#x * %#x\n", n, p, q );
    else                // Conditioning if the shifted value of p is not equal to q then it's not its mirror as in 14 and 50.
        printf("%#x is a 16-Harshad number, w/out mirror factors: %#x * %#x\n", n, p, q );

  return 0;
}

