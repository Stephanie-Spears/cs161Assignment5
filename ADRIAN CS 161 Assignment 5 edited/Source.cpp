#include <iostream>
#include <string>
#include <sstream>
#include <istream>

using namespace std;

int main()
{
	int width;
	int height;
	int e = 1;
	int i = 0;
	bool Control;
	int InputLength;
	stringstream ss;
	string Dimension;
	string Input;
	string CleanInput;
	char c;

	while (e < 3)
	{
		Control = true;

		while (Control == true)
		{
			if (e == 1)
			{
				Dimension = "width";
			}

			else if (e == 2)
			{
				Dimension = "height";
			}

			cout << "Enter " + Dimension + " : ";
			getline(cin, Input);
			InputLength = (Input.length());

			

			if (InputLength > 0)
			{
				while (i < (InputLength))
				{
					c = Input.at(i);

					if (isdigit(c))
					{
						CleanInput = CleanInput + c;
						++i;
					}

					else
					{
						i = 0;
						cout << "Invalid input. Try again." << endl;
						break;
					}
				}

				if (i == InputLength)
				{
					ss << CleanInput;

					if (e == 1)
					{
						ss >> width;

						if ((width <= 0) || (width >= 25))
						{
							i = 0;
							cin.clear();
							ss.clear();
							ss.str("");
							Input = "";
							CleanInput = "";
							InputLength = 0;
							cout << "You must enter a width greater than 0, less than 25. Try again." << endl;
							//Adrian says: There is no reason to split this into two if statements, one for upper limit and one for lower limit.
							break;
						}
					}
					else
					{
						ss >> height;
						if ((height <= 0) || (height >= 25))
						{
							i = 0;
							cin.clear();
							ss.clear();
							ss.str("");
							Input = "";
							CleanInput = "";
							InputLength = 0;
							cout << "You must enter a height greater than 0, less than 25. Try again." << endl;
							break;
						}
						else
						{
							Control = false;
						}
					}

					i = 0; //Adrian says: no, your note here was wrong.  This only is evaluated when the program doesn't hit a break.  Since you constantly broke, it wasn't being evaluated.
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;
					e++;
					//Adrian says: You had a control=false here and accurately observed that without it, your code would loop infinitely. 
					//The problem is that when your code worked like you intended it to, you would be setting control false when 
					//you were evaluating width too.  Since you also increment e here, a user could theoretically screw up the width multiple times, 
					//which would mean that e would be greater than two and that control would be false.  That would cause your program to terminate
					//prematurely.  Control should only be set false when you've gotten all the data when you wanted, not because your program keeps
					//looping and throwing in a way of breaking it randomly will stop it from doing so.

				}
				else //this else statement executes if isdigit "else" test fails. clears everything.
				{
					i = 0;
					cin.clear();
					ss.clear();
					ss.str("");
					Input = "";
					CleanInput = "";
					InputLength = 0;
					cout << "You must enter whole numbers only.  Try again.";
					break;
				}
			} //Adrian says: You had a ton of weird little shit beyond this point, I trimmed it out.  Yes, every check and reset is necessary.  
			  //Your range coding wasn't working in part because it was carrying failed values through to the next loop.
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cout << "X";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
}

/*
For this assignment you will create a program to print a box of Xs on
the screen.Your program must use user - defined functions as a part of
the solution.

There are a couple tricky parts in this assignment so give yourself
plenty of time to work on it.

Details
------ -

You program should first prompt the user to enter a width and a
height.It should validate that both the width and height are greater
than 0 and less than 25.  Then it should generate a rectangle of Xs
with the given width and height.

For example consider the following run :

---- -
Enter width : 0
You must enter a width greater than 0.  Try again.
Enter width : zz
Invalid input.Try again.
Enter width : 5
Enter height : -10
You must enter a height greater than 0.  Try again.
Enter height : -8
You must enter a height greater than 0.  Try again.
Enter height : 3

XXXXX
XXXXX
XXXXX

Exiting...
---- -

Notice that the validation will continue until a valid number is entered.

Your program must include a function that will take in an integer for
width and height and draw the rectangle with that.It should also
have a function to request the user input and return the valid value.
This input function will take a string parameter that is set to
"width" or "height" by the caller and then use that parameter to
generate the correct text to the user.The input function will return
an integer, which is the correct value.
*/