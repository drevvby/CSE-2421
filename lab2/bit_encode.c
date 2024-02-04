/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
** TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
** THIS ASSIGNMENT.
*/

#include <stdio.h> /* copy IO library prototypes and other information from /usr/include/stdio.h */

/* create prototypes for bit-shifting functions as well as key creation and output display */
unsigned char create_key();
unsigned char rotate_right(unsigned char a);
unsigned char rotate_left(unsigned char a);
int display_input(char input[], int i);
int display_cyphertext(char input[], unsigned char key, int m);
int main(void)
{

/*
** BY: Andrew White
**
** this program is designed to take in text from a user, and then encode it using 
** a 4-bit key the user also provides along with bitwise operators such as inclusive OR 
** and bitwise shifting.
*/

/*initialize variables to collect the user's text input, as well as a loop variable*/
	char input[201];
	int ch;
	int i = 0;
/*prompt user for input text*/
#ifdef PROMPT
	printf("Enter cleartext: ");
#endif
/*read each non-newline character and append to char array*/
	while((ch = getchar()) != '\n')
	{
		input[i++] = ch;
	}
/*display the user's input as both cleartext and hexadecimal values*/
#ifdef PROMPT
	display_input(input, i);
#endif
/*ask for a key  from the user and store it as an unsigned character*/
	unsigned char user_key = create_key();
/*display the user's encoded text*/
#ifdef PROMPT
	printf("Hex cyphertext: \n");
#endif
	display_cyphertext(input, user_key, i);
	
	return 0;
}
/*
** this function simply prints each character of the users input to the screen as its cleartext
** and hex value.
*/
int display_input(char input[], int i)
{
	/*relay the user's string back to them by printing to console*/
	printf("%s\n", input);
	/*display user's text as 10 hexadecimal characters per line*/
	printf("\nHex encoding: \n");
	for(int j = 0; j < i; j = j + 1){
		printf("%x", input[j]);
		if(j % 10 != 9){
			printf(" ");
		}
		else {
			printf("\n");
		}	
	}
	return 0;
	
}

/*
** this function prompts the user for a 4-bit key, and uses left_shift and right_shift
** in order to encode the users input, and displays the input.
*/
unsigned char create_key() 
{
	/*initialize variables for the 8-bit key to return, as well as the user's input*/
	unsigned char key = '0';
	unsigned char curr_input;
	/*prompt user for a 4 bit key*/
#ifdef PROMPT
	printf("\n\nEnter a 4-bit key: ");
#endif
	/*get each digit by OR'ing the key (initially zero) with each 1 or 0 of the user's
	**input(which is 49 and 48 in hexadecimal respectively), and shifting the digit to
	**the left*/
	for(int i = 0; i < 4; i++){
		curr_input = getchar();
	key = (key << 1) | (curr_input - 48);
	}
	key = (key << 4) | key;
	
	return key;
	


}

/*
** this function applies a right-shift to a given character of the user's input that is 
** determined by the 4-bit key provided by the user
*/
unsigned char rotate_right(unsigned char a)
{
	/*by applying a left shift of 6, we can successfully "wrap-around" the two digits
	**that get chopped off when right shifting by two*/
	unsigned char temp1 = a << 6;
	unsigned char temp2 = a >> 2;
	/*this OR calculation combines the right-shifted bit-string and the two rotated values*/
	return temp1 | temp2;
	
}

/*
** this function applies a left-shift to a given character of the user's input that is 
** determined by the 4-bit key provided by the user
*/
unsigned char rotate_left(unsigned char a)
{
	/*by applying a right shift of 6, we can successfully "wrap-around" the two digits
	**that get chopped off when left shifting by two*/
	unsigned char temp1 = a << 2;	
	unsigned char temp2 = a >> 6;
	/*this OR calculation combines the right-shifted bit-string and the two rotated values*/
	return temp1 | temp2;
}

/*
** this function diplays the encoded string
*/
int display_cyphertext(char input[], unsigned char key, int m){
	/*initialize counter variable and a temp  variable to store each character during 		**encription*/
	int n = 0;
	unsigned char curr_char;
	while(n < m){
		/*inclusive OR as first step of character bit-encription*/
		curr_char = input[n]^key;
		/*left shift every odd character, right shift every even character*/
		if(n % 2 == 0){
			curr_char = rotate_left(curr_char);
		}
		else {
			curr_char = rotate_right(curr_char);
		}
	/*print each encoded hexadecimal character 10 per line*/
		printf("%x ", curr_char);
#ifdef PROMPT
		if(n % 10 == 9){
		
			printf("\n");
		}
#endif
	/*increment counter*/
	n = n + 1;
	}
	return 0;
	
}
