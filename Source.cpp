
/*Mihail Ica - G20857128*/

#include <iostream>
using namespace std;

string ToLower(string myString) //Function provided as part of Intro to Programming module, used for input validation by converting strings to lower case.
{
	string lowerString;
	for (auto c : myString) lowerString += tolower(c);
	return lowerString;
}


void ExitApp() //Function that exits app with a polite message.
{
	cout << endl;
	cout << "Thank you for using the UCLan Pizza app, goodbye!";
	cout << endl;
	system("exit");

}


void DrawLines(int lineLength) //This function draws lines that help separate the application menus.
{
	for (int i = 0; i <= lineLength; i++)
	{
		cout << '-';
	}
	cout << endl;
}



int InputValidationNumbers(int from, int to, int userSelection)
{
	
	while (cin.fail() or userSelection < from or userSelection > to) //Basic user input validation, checking if the type of data is correct or if the input is within the range required.
	{
		cin.clear();
		cin.ignore();
		cout << "Sorry, please enter a valid response." << endl;
		cout << "Please enter a number for your selection : "; cin >> userSelection;
		
	}

	
	return userSelection;
}

string InputValidationYesOrNo(string userSelection)
{

	while (cin.fail() or userSelection != "y" and userSelection != "n") //Basic user input validation, checking if the type of data is correct or if the input is within the range required.
	{
		cin.clear();
		cin.ignore();
		cout << "Sorry, please enter a valid response." << endl;
		cout << "Please enter a number for your selection : "; cin >> userSelection;
		userSelection = ToLower(userSelection);

	}

	return userSelection;
}

int DisplayMainMenu(float credits) //Function that handles the main menu of the application.
{
	
	const int halfConsoleLength = 40; // Lenght of line to be drawn. Number is passed onto the function DrawLines as a parameter. This number is half of the console width.
	DrawLines(halfConsoleLength);
	cout << "UClan Pizza" << endl;
	DrawLines(halfConsoleLength);
	cout << endl;

	

	cout << "MAIN MENU" << endl;
	cout << "  1. Add Credits (current credits = " << credits << " )" << endl;
	cout << "  2. Order Pizza" << endl;
	cout << "  0. Exit" << endl;
	cout << endl;

	int mainMenuSelection;

	cout << "Please enter a number : "; cin >> mainMenuSelection;
	cout << endl;

	mainMenuSelection = InputValidationNumbers(0, 2, mainMenuSelection);

	
	return mainMenuSelection;
}

float AddCredits(float credits) //Function that allows the user to add credits (currency).
{
	string yesOrNo;
	float additionalCredits = 0;
	cout << "Please enter the number of credits you wish to add: "; cin >> additionalCredits;
	cout << endl;
	credits += additionalCredits; //Credits get handled by the addition of any credits to the initial amount. This allows the user to go through the process several times.
	cout << "Your new balance = " << credits << " credits" << endl;
	cout << endl;
	cout << "Would you like to continue processing your order?" << endl;
	cout << "Please enter 'Y' for yes or 'N' for no : "; cin >> yesOrNo;
	cout << endl;

	yesOrNo = ToLower(yesOrNo);

	InputValidationYesOrNo(yesOrNo);

	if (yesOrNo == "n")
	{
		ExitApp();
		
	}
	else
	{
		return credits;
	}
	
}


int PizzaSizeMenu(float credits) //Function that handles the pizza size menu of the application.
{
	const int halfConsoleLength = 40;
	int pizzaSizeSelection;
	cout << "ORDER PIZZA - Select Size" << "    " << "[Current Balance = " << credits << " credits ]" << endl;
	cout << endl;
	cout << "Please choose from the following options : " << endl;
	cout << endl;
	cout << "  1. 7 inch  [3.0 credits]" << endl;
	cout << "  2. 9 inch  [5.50 credits]" << endl;
	cout << "  3. 14 inch [7.25 credits]" << endl;
	cout << "  0. Return to Main Menu" << endl;
	DrawLines(halfConsoleLength);

	cout << "Please enter a number : "; cin >> pizzaSizeSelection; cout << endl;

	pizzaSizeSelection = InputValidationNumbers(0, 3, pizzaSizeSelection);

	return pizzaSizeSelection;
}

int ToppingsMenu(float credits, int pizzaSize) //Function that handles the toppings menu of the application.
{
	const int halfConsoleLength = 40;
	int toppingSelection;
	
	cout << "You have selected a " << pizzaSize << " inch pizza.";
	cout << endl;
	DrawLines(halfConsoleLength);
	cout << endl;
	cout << "ORDER PIZZA - Select Toppings" << "    " << "[Current Balance = " << credits << " credits ]" << endl;
	cout << endl;
	cout << "Please choose from the following toppings : ";
	cout << endl;
	cout << "  1. Ham          [0.80 credits]" << endl;
	cout << "  2. Mushrooms    [0.50 credits]" << endl;
	cout << "  3. Pepperoni    [1.00 credits]" << endl;
	cout << "  4. Olives       [0.30 credits]" << endl;
	cout << "  5. Pineapple    [0.60 credits]" << endl;
	cout << "  6. Extra Cheese [1.20 credits]" << endl;
	cout << "  0. Return to Main Menu" << endl;
	DrawLines(halfConsoleLength);
	cout << "Please enter a number : "; cin >> toppingSelection;

	InputValidationNumbers(0, 6, toppingSelection);

	return toppingSelection;
}

string Checkout(float price, float credits) //Function that handles the checkout process.
{
	const int halfConsoleLength = 40;
	string yesOrNo;

	DrawLines(halfConsoleLength);
	cout << "Available balance:    " << credits << " credits" << endl;
	cout << "Pizza price:          " << price << " credits" << endl;

	if (credits >= price)
	{
		credits -= price;
		DrawLines(halfConsoleLength);
		cout << "Your new Balance  = " << credits << " credits" << endl;
		DrawLines(halfConsoleLength);
		cout << "Would you like to order another pizza?" << endl;
		cout << endl;
		cout << "Please input 'Y' for yes and 'N' for no  : "; cin >> yesOrNo;
		yesOrNo = ToLower(yesOrNo);

		InputValidationYesOrNo(yesOrNo);

		return yesOrNo;
	}
	else
	{
		cout << "You do not have sufficient credits for this purchase. You require " << price << " credits." << endl;
		cout << "Would you like to add more credits ?" << endl;
		cout << endl;
		cout << "Please input 'Y' for yes and 'N' for no  : "; cin >> yesOrNo;
		yesOrNo = ToLower(yesOrNo);

		InputValidationYesOrNo(yesOrNo);

		return yesOrNo;
	}
	
}



int main()
{
	const int halfConsoleLength = 40;
	float credits = 0;
	int pizzaSize = 0;
	float pizzaPrice = 0;
	float additionalPrice = 0;
	

	float totalPrice = pizzaPrice + additionalPrice;
	
	string yesOrNo;
	
	
	const int toppingNo = 6; // Constant integer that defines the number of elements held by the pizzaTopping Array.
	const int pizzaSizeNo = 3; // Constant integer that defines the number of elements held by the pizzaSize Array.
	const int pizzaSizePricesNo = 3; // Constant integer that defines the number of elements held by the pizzaSizePrices Array.
	const int pizzaToppingPricesNo = 6; //Constant integer that defines the number of elements held by the pizzaToppingPrices Array.


	string pizzaToppings[toppingNo] = { "Ham", "Mushrooms", "Pepperoni", "Olives", "Pineapple", "Extra Cheese" }; // Array holding the toppings available.
	int pizzaSizes[pizzaSizeNo] = { 7,9,14 }; // Array holding the piza sizes available.
	float pizzaSizePrices[pizzaSizePricesNo] = { 3, 5.50, 7.25 }; // Array holding the pizza prices based on the size selected.
	float pizzaToppingPrices[pizzaToppingPricesNo] = { 0.80, 0.50, 1, 0.30, 0.60, 1.20 }; // Array holding the pizza topping prices.


	bool mainMenuLoop = false;

	do
	{
		mainMenuLoop = false;
		
		int mainMenuSelection = DisplayMainMenu(credits);


		if (mainMenuSelection == 0)
		{
			ExitApp();
		}

		while (mainMenuSelection == 1 && mainMenuLoop == false)
		{
			credits = AddCredits(credits);
			mainMenuLoop = true;
		}

		bool pizzaMenuLoop = true;

		while (mainMenuSelection == 2 && pizzaMenuLoop == true)
		{
			
			int pizzaSizeSelection = PizzaSizeMenu(credits);

			bool toppingMenuLoop = true;

			if (pizzaSizeSelection == 0)
			{
				toppingMenuLoop = false;
				pizzaMenuLoop = false;
				mainMenuLoop = true;
			}

			if (pizzaSizeSelection == 1)
			{
				pizzaSize = pizzaSizes[0];
				pizzaPrice = pizzaSizePrices[0];
			}
			else if (pizzaSizeSelection == 2)
			{
				pizzaSize = pizzaSizes[1];
				pizzaPrice = pizzaSizePrices[1];
			}
			else if (pizzaSizeSelection == 3)
			{
				pizzaSize = pizzaSizes[2];
				pizzaPrice = pizzaSizePrices[2];
			}

			

			while (toppingMenuLoop == true)
			{
				int toppingSelection = ToppingsMenu(credits, pizzaSize);
				

				if (toppingSelection == 0)
				{
					toppingMenuLoop = false;
					pizzaMenuLoop = false;
					mainMenuLoop = true;
				}

				else if (toppingSelection == 1)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[0]; // additionalPrice is added to the topping price in order to increment the total price should the user choose several toppings.
					cout << "You have added " << pizzaToppings[0] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}
				else if (toppingSelection == 2)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[1];
					cout << "You have added " << pizzaToppings[1] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}
				else if (toppingSelection == 3)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[2];
					cout << "You have added " << pizzaToppings[2] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}
				else if (toppingSelection == 4)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[3];
					cout << "You have added " << pizzaToppings[3] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}
				else if (toppingSelection == 5)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[4];
					cout << "You have added " << pizzaToppings[4] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}
				else if (toppingSelection == 6)
				{
					additionalPrice = additionalPrice + pizzaToppingPrices[5];
					cout << "You have added " << pizzaToppings[5] << " to your pizza.Your current price is " << pizzaPrice + additionalPrice << endl;
					cout << endl;

				}

				totalPrice = pizzaPrice + additionalPrice;
				
				
				if (toppingMenuLoop == true)
				{
					cout << endl;
					cout << "Would you like to add additional toppings?" << endl;
					cout << endl;
					cout << "Please input 'Y' for yes and 'N' for no : "; cin >> yesOrNo;
					DrawLines(halfConsoleLength);
					yesOrNo = ToLower(yesOrNo);

					InputValidationYesOrNo(yesOrNo);

					bool checkoutMenuLoop = false;

					if (yesOrNo == "n")
					{
						do
						{
							additionalPrice = 0;
							checkoutMenuLoop = false;
							pizzaMenuLoop = true;
							toppingMenuLoop = false;
							yesOrNo = Checkout(totalPrice, credits);

							if (credits >= totalPrice)
							{
								if (yesOrNo == "n")
								{
									pizzaMenuLoop = false;
									ExitApp();
								}
								else
								{
									pizzaMenuLoop = true;
									credits -= totalPrice;
								}
							}
							else if (credits <= totalPrice)
							{
								checkoutMenuLoop = true;

								if (yesOrNo == "n")
								{
									checkoutMenuLoop = false;
									pizzaMenuLoop = false;
									ExitApp();
								}
								else
								{
									credits = AddCredits(credits);
									pizzaMenuLoop = true;
								}

							}
						} while (checkoutMenuLoop == true);
						
						
						 
					}
					else if (yesOrNo == "y")
					{

						pizzaMenuLoop = true;
						toppingMenuLoop = true;
						
					}
				}
				
			}
			
			
		} 

		if (mainMenuSelection == 3)
		{
			ExitApp();
		}

	} while (mainMenuLoop == true);
	

	

		

		

	
		
	

	
	

	
}