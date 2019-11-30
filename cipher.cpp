#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	ifstream inf("encrypted.txt");
	ofstream outf("decrypted.txt");
class CaeserCipher
{
public:
	CaeserCipher();//default constructor

	string encryptline;
	string decryptline;
	int shift;
	string Encrypt();
	string Decrypt();
	string UpperCase();
	void SetShift();
	string ReadPlainText();
	void WriteCipherText();
	string ReadCipherText();
	void WritePlainText();	

};


int main()
{
	
	int count = 0;
	inf >> count;
	outf << "MARQUISE BLUE\n" << "11/22/2019\n" << "Program 4 Output\n\n";
	for (int i = 0; i < count; i++)
	{
		CaeserCipher c;
		c.ReadCipherText();
		c.Decrypt();
		c.WritePlainText();
	}
	return 0;
}
/**
 * CaeserCipher
 *
 * Description:
 *     pulling in encryptline and decrypt line
 *		and setting shift as 0
 * Params:
 *      none
 *
 * Returns:
 *     none
 */
CaeserCipher::CaeserCipher()
{
	encryptline = ' ';
	decryptline = ' ';
	shift = 0;
}


/**
 *SetShift
 *
 * Description:
 *     infiling the shift
 * Params:
 *      none
 * Returns:none
 */
void CaeserCipher::SetShift()
{
	inf >> shift;
}

/**
 * Encrypt
 *
 * Description:
 *      encrypting a line of string to see if it can be decrypted 
		and picking diffrent words from the ASCII code
 *
 * Params:
 *      none
 *
 * Returns:
 *     encryptline:return the string of the encrypt words
 */
string CaeserCipher::Encrypt()
{
	int intVal = 0;
	string line = decryptline;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 65 && line[i] <= 90)
		{
			intVal = (int)line[i] - 65;//turn it into an integer number 
										//between 0-25
			intVal += shift;
			intVal = intVal % 26;
			line[i] = intVal + 65;
		}
	}
	encryptline = line;
	return encryptline;
}

/**
 * Decrypt
 *
 * Description:
 *     decrypting the encrypt string
 * Params:
 *      none
 *
 * Returns:
 *     the decrypted lines
 */
string CaeserCipher::Decrypt() 
{
	int intVal = 0;
	string line = encryptline;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] >= 65 && line[i] <= 90)
		{
			intVal = (int)line[i] - 65;//turn it into an integer number 
										//between 0-25
			intVal -= shift;
			if (intVal < 0)//if negative, add 26 to bring it back up
			{
				intVal += 26;
			}
			intVal = intVal % 26;//shift the letter, using mod to wrap back
								//around
			line[i] = intVal + 65;//turn integer back into an ASCII upper 
									//case letter
		}
	}
	decryptline = line;
	return line;
}
/**
 * UpperCase
 *
 * Description:
 *     making the strings sentac work for uppercases words
 *
 * Params:
 *     none
 * Returns:
 *      decrypted line to the uppercase
 */
string CaeserCipher::UpperCase()
{
	for (int i = 0; i < decryptline.size(); i++)
	{
		if (decryptline [i] >= 97 && decryptline[i] <= 122)
		{
			decryptline[i] -= 32;
		}
	}
	return decryptline;
}
/**
 * WriteCipherText
 *
 * Description:
 *     outfiling the cipher text message 
 * Params:
 *     none
 *
 * Returns:
 *     none
 */
void CaeserCipher::WriteCipherText() 
{
	outf << encryptline << endl << endl;
}

/**
 * ReadCipherText
 *
 * Description:
 *      bringing shift and get line from the input file
 *
 * Params:
 *      none
 *
 * Returns:
 *      encrypted line
 */
string CaeserCipher::ReadCipherText()
{
	SetShift();
	getline(inf, encryptline);
	getline(inf, encryptline);
	return encryptline;
}

/**
 * WritePlainText
 *
 * Description:
 *     outfiling the decyrpted string to screen
 *
 * Params:
 *      none
 *
 * Returns:
 *     none
 */
void CaeserCipher::WritePlainText()
{
	outf << decryptline << endl << endl;
}

/**
 * ReadPlainText
 *
 * Description:
 *     getting the line from the file and decrypting it
 *
 * Params:
 *    none
 *
 * Returns:
 *     decryptline
 */
string CaeserCipher::ReadPlainText()
{
	getline(inf, decryptline);
	getline(inf, decryptline);

	UpperCase();
	return decryptline;
}