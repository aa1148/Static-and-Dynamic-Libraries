//
// Autor: Andres Altamirano
// Matricula: A01191723
// Fecha: Octubre 10, 2016
//
// Program that converts a string of characters
// in different formats such as binary and
// hexadecimal to integer, or from a string of
// a double to an actual double.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Converts a string in binary format to an integer
int asciiBinaryToInt(char *cArr)
{
	// initialize the variable that will hold the integer value
	int iTotal = 0;
	
	for (int iCount = 0; iCount < strlen(cArr); iCount++) {
		
		// The conversion finishes if we reached an invalid character
		if (cArr[iCount] != '1' && cArr[iCount] != '0')
		{
			return iTotal;
		}
		
		// multiply by 2 the value of total
		iTotal *= 2;
		
		// add one total if the current character is one
		if (cArr[iCount] == '1')
		{
			iTotal++;
		}
	}
	
	return iTotal;
}

// Converts a string in Hex format to an integer
int asciiHEXToInt(char *cArr)
{
	// Initialize the last position of the number
	// we need this because it can change if we have an
	// invalid character
	int iLastPos = (int)strlen(cArr);
	
	// Find the last position of the number.
	// If there is an invalid character, that will be the
	// last position
	for (int iCount = 0; iCount < iLastPos; iCount++)
	{
		if (!((cArr[iCount] >= '0' && cArr[iCount] <= '9') ||
			  (cArr[iCount] >= 'a' && cArr[iCount] <= 'f') ||
			  (cArr[iCount] >= 'A' && cArr[iCount] <= 'F')))
		{
			iLastPos = iCount;
		}
	}
	
	// Initialize the variable that will hold the total sum
	int iSum = 0;
	
	// Add the values to iSum
	// We iterate from end to start so that we can keep the index
	// as our multiplier (N * 16 ^ index)
	for (int iCount = iLastPos - 1; iCount >= 0; iCount--)
	{
		// if it is a number, we add (num * 16 ^ index)
		if (cArr[iCount] >= '0' && cArr[iCount] <= '9')
		{
			iSum += (cArr[iCount] - '0') * pow(16, (iLastPos - 1) - iCount);
		}
		// if it is a letter, we add (letterValue * 16 ^ index), where
		// a = 10, b = 11, c = 12, d = 13, e = 14, f = 15
		else if (cArr[iCount] >= 'a' && cArr[iCount] <= 'f')
		{
			iSum += (cArr[iCount] - 'a' + 10) * pow(16, (iLastPos - 1) - iCount);
		}
		// same as last case, but with uppercase
		else if (cArr[iCount] >= 'A' && cArr[iCount] <= 'F')
		{
			iSum += (cArr[iCount] - 'A' + 10) * pow(16, (iLastPos - 1) - iCount);
		}
		
	}
	
	return iSum;
}

// Converts a string in Double format to an actual double
double asciiToDouble(char *cArr)
{
	// Initialize the last position of the number
	// we need this because it can change if we have an
	// invalid character
	int iLastPos = (int)strlen(cArr);
	
	// Checks whether the input contains a sign or not
	int iSign = 0;
	
	// Checks the type of sign in case it exists
	// Initialize to a positive number
	int iSignType = 0;
	
	// Checks for a sign and assigns it to signType
	if (cArr[0] == '-' || cArr[0] == '+')
	{
		// Mark that there is a sign
		iSign = 1;
		
		// if sign is '+', signType = 0. Else, signType = 1;
		if (cArr[0] == '-')
		{
			iSignType = 1;
		}
	}
	
	// counts how many numbers are in each side of the decimal
	int iNumsLeft = 0, iNumsRight = 0;
	
	// checks whether we are on the left or
	// on the right side of the decimal
	// 0 = left, 1 = right
	int iSide = 0;
	
	// Count the amount of numbers to the left of the decimal
	// and to the right of the decimal
	// iCount starts at position 1 if there is a sign
	for (int iCount = iSign; iCount < iLastPos; iCount++)
	{
		// Only counts digits
		if (cArr[iCount] >= '0' && cArr[iCount] <= '9')
		{
			// checks if we are on the left
			if (iSide == 0)
			{
				iNumsLeft++;
			}
			// checks if we are on the right
			else if (iSide == 1)
			{
				iNumsRight++;
			}
		}
		// if it is a decimal point, we change sides
		else if (cArr[iCount] == '.')
		{
			iSide = 1;
		}
		// skip the sign
		else if (cArr[iCount] == '+' || cArr[iCount] == '-')
		{
			continue;
		}
		// stop if we find an invalid character
		else
		{
			// set the last position at the current index
			iLastPos = iCount;
			break;
		}
	}
	
	// initialize variable that will hold the double
	double dNum = 0;
	
	// initialize multiplier to add the left side of the number
	int iMultiplier = pow(10, iNumsLeft - 1);
	
	// Add the left side of the number to dNum
	// iCount starts at position 1 if there is a sign
	for (int iCount = iSign; iCount < iNumsLeft + iSign; iCount++)
	{
		// add the number times the multiplier
		dNum += (cArr[iCount] - '0') * iMultiplier;
		
		// reduce a digit of the multiplier as we are moving
		// to the right of the number
		iMultiplier /= 10;
	}
	
	// initialize divider to add the right side of the number
	double dDivider = 10;
	
	// adds the right side of the number to dNum.
	// starts at the position to the right of the decimal point
	for (int iCount = iNumsLeft + iSign + 1; iCount < iLastPos; iCount++)
	{
		// add the number divided by the divider
		dNum += ((double)(cArr[iCount] - '0')) / dDivider;
		
		// increase the divider as we are moving to the
		// right of the number
		dDivider *= 10;
	}
	
	// if it has a negative sign, multiply by one
	if (iSignType == 1)
	{
		dNum *= -1;
	}
	
	return dNum;
	
}