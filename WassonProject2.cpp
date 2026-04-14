#include <iostream>		// header file needed for console input / output
#include <iomanip> 		// header file used for formatting output
#include <cstdlib>		// header file used for rand and srand
#include <ctime>		// header file used for time
#include <locale>		// header file for commas in numbers
using namespace std;  	// uses standard namespace for C++ keywords



int main()	// main function
{
// constants
		// Bill values
	const int HUNDRED = 100;
	const int FIFTY = 50;
	const int TWENTY = 20; 
	const int TEN = 10;
	const int FIVE = 5;
	const int ONE = 1;
	
		// Coin values
	const double QUARTER = 0.25;
	const double DIME = 0.10;
	const double NICKEL = 0.05;
	const double PENNY = 0.01;
	
		// initial for total amount of bills/coins
	long totalHundreds = 0;
	long totalFifties = 0;
	long totalTwenties = 0;
	long totalTens = 0;
	long totalFives = 0;
	long totalOnes = 0;
	
	long totalQuarters = 0;
	long totalDimes = 0;
	long totalNickels = 0;
	long totalPennies = 0;
	
		// Prize values - tokens
	const int MEGA = 1000;
	const int SUPER = 500;
	const int LARGE = 250; 
	const int MEDIUM = 100;
	const int SMALL = 50;
	const int MINI = 25;
	const int TINY = 10;
	const int STICKER = 5;
	const int CANDY = 1;
	
	const int TOKENS_PER_DOLLAR = 10;
	
	// variables
	int startingBal;			// starting balance of tokens
	int endingBal;				// ending balance of tokens
	int tokensPur = 0;			// intial for token purchased
	int tokensRed = 0;			// intital for tokens redeemed
	int totalTrans = 0;			// total transactions
	int singlePur = 0;			// single transactions
	int singleRedem = 0;		// single redemption
	int multiPur = 0;			// multi purchase
	int multiRedem = 0;			// multi redemption
	int totalPur = 0;			// total purchase
	int totalRedem = 0;			// total redeemed
	int totalTokensPur = 0;		// total token purchase
	int totalTokensRed = 0;		// total token redeemed
	
	// intital for all prize sizes
	int megaCount = 0, superCount = 0, largeCount = 0,  mediumCount = 0, smallCount = 0, miniCount = 0,
	tinyCount = 0, stickerCount = 0, candyCount = 0; 
	int mega, super, large, medium, small, mini, tiny, sticker, candy;
		
	char mainChoice;		// choice of single/multiple transactions or exit
	char purChoice;			// choice of payment cash/coins

	
	// Random starting balance 
	srand(time(0));							// seed random generator
	startingBal = (rand() % 49901) + 100;	// random start balance between 100-50000
	endingBal = startingBal;
	
	// Receipt display and formatting
	cout << setprecision(2) << showpoint << fixed;
	cout.imbue(locale(""));
	
	
	cout <<"\t*** Welcome to the Cosmic Coins Arcade ***\n";
	
	do
	{
	// main menu 
		cout <<"\n\t\t --Main Menu--\n";
		cout <<"Choose from one of the following:\n";
		cout <<"\tA - Single Transaction\n";
		cout <<"\tB - Generate Multiple Transactions\n";
		cout <<"\tC - Exit\n";
		cout <<"\nEnter your choice (A, B, or C): ";
		cin >> mainChoice;
		
		// validate mainChoice menu option
		if (mainChoice != 'A' && mainChoice != 'a' &&
			mainChoice != 'B' && mainChoice != 'b' &&
			mainChoice != 'c' && mainChoice != 'C')
			{
				cout <<"\nERROR: Invalid Menu Choice. Try Again.\n";
				continue;
			}

	// A - single transaction menu/choice/validation
		switch(mainChoice)
		{
			case 'A':
			case 'a':
			{
				int hundreds = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, ones = 0;		// declare bill counters
				int quarters = 0, dimes = 0, nickels = 0, pennies = 0; 							// declare coins counters
				char transChoice;
				
				// Low Balance check
				if (endingBal < 50)
				{
					cout <<"\nWARNING LOW TOKEN BALANCE. PLEASE MAKE A PURCHASE.\n";
					transChoice = 'A';
				}
				else
				{
					// transaction menu
					do
					{
						cout << "\n\t--Single Transaction Menu--\n";
						cout << "\nYour Current Token Balance: " << endingBal << " tokens\n";
						cout << "\nWhat would you like to do today?\n";
			            cout << "\tA - Purchase Tokens" << endl;
			            cout << "\tB - Redeem Tokens for prizes" << endl;
			            cout << "Enter choice (A or B): ";
			            cin >> transChoice;
			            
			            if (transChoice != 'A' && transChoice != 'a' &&
                			transChoice != 'B' && transChoice != 'b')
                			{
                				cout << "\nERROR: Invalid choice.\n";
							}
					} while (transChoice != 'A' && transChoice != 'a' &&
                 			 transChoice != 'B' && transChoice != 'b');
				}
				// ==================================Purchase Tokens====================================================
				if (transChoice == 'A' || transChoice == 'a')
				{
					do
					{
						cout << "\n\t--Token Purchase Menu--\n";
			            cout << "\tA - Cash Only (Bills)\n";
			            cout << "\tB - Coins Only\n";
			            cout << "Enter your choice (A or B): ";
			            cin >> purChoice;
			            
			            
			            if (purChoice != 'A' && purChoice != 'a' &&
                			purChoice != 'B' && purChoice != 'b')
                			{
                				cout << "\nERROR: Invalid choice.\n";
							}
						
					} while (purChoice != 'A' && purChoice != 'a' &&
                 			 purChoice != 'B' && purChoice != 'b');
                 			 
             		singlePur++;
					totalPur++;				
				
				// ======================Cash Options (bills only) for purchase=================================
				if (purChoice == 'A' || purChoice == 'a')
				{	
				do
				{
					// user input for bill amounts
					cout << "\nEnter number of $100 bills (min: 0, max: 100): ";	// input for hundreds
			        cin >> hundreds;
			        
			        if (hundreds < 0 || hundreds > 100)
			        	cout << "\nERROR: Invalid input of $100 Bills. Try Again.\n"; 
				} while ( hundreds < 0 || hundreds > 100);
				
				do
				{
					cout << "Enter number of $50 bills (min: 0, max: 100): ";	// input for fifties
			        cin >> fifties;
			        
			        if (fifties < 0 || fifties > 100)
			        	cout << "\nERROR: Invalid input of $50 Bills. Try Again.\n"; 
				} while ( fifties < 0 || fifties > 100);
			
			    do
				{
					cout << "Enter number of $20 bills (min: 0, max: 100): ";	// input for twenties
			        cin >> twenties;
			        
			        if (twenties < 0 || twenties > 100)
			        	cout << "\nERROR: Invalid input of $20 Bills. Try Again.\n"; 
				} while ( twenties < 0 || twenties > 100); 
			
			    do
				{
					cout << "Enter number of $10 bills (min: 0, max: 100): ";	// input for tens
			        cin >> tens;
			        
			        if (tens < 0 || tens > 100)
			        	cout << "\nERROR: Invalid input of $10 Bills. Try Again.\n"; 
				} while ( tens < 0 || tens > 100); 
				
			    do
				{
					cout << "Enter number of $5 bills (min: 0, max: 100): ";	// input for fives
			        cin >> fives;
			        
			        if (fives < 0 || fives > 100)
			        	cout << "\nERROR: Invalid input of $5 Bills. Try Again.\n"; 
				} while ( fives < 0 || fives > 100); 
			
			    do
				{
					cout << "Enter number of $1 bills (min: 0, max: 100): ";	// input for ones
			        cin >> ones;
			        
			        if (ones < 0 || ones > 100)
			        	cout << "\nERROR: Invalid input of $1 Bills. Try Again.\n"; 
				} while ( ones < 0 || ones > 100); 
				
					int totalCash = (hundreds * 100) + (fifties * 50) + (twenties * 20) + (tens * 10) + (fives * 5) + (ones * 1);	//Total amount of bills used
					
					totalHundreds += hundreds;
					totalFifties += fifties;
					totalTwenties += twenties;
					totalTens += tens;
					totalFives += fives;
					totalOnes += ones;
					tokensPur = totalCash * TOKENS_PER_DOLLAR;
					
					int receiptStartBal = endingBal;
					endingBal += tokensPur;
					totalTokensPur += tokensPur;
								
				
					//==============cash receipt for tokens purchased with bills============================
					cout <<"\n\n-------Transaction Receipt-------" << endl;
					cout <<"Starting Tokens: \t" << receiptStartBal << endl;
					cout <<"Tokens Purchased: \t" << tokensPur << endl;
					cout <<"\nPayment Breakdown:" << endl;
					cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
					
					if (hundreds > 0)
					cout << right << setw(9) << hundreds << " x $100.00" << right << setw(6) << "$" << (hundreds * 100.00) << endl;
					if (fifties > 0)
					cout << right << setw(9) << fifties << " x $50.00" << right << setw(7) << "$" << (fifties * 50.00) << endl;
					if (twenties > 0)
					cout << right << setw(9) << twenties << " x $20.00" << right << setw(7) << "$" << (twenties * 20.00) << endl;
					if (tens > 0)
					cout << right << setw(9) << tens << " x $10.00" << right << setw(7) << "$" << (tens * 10.00) << endl;
					if (fives > 0)
					cout << right << setw(9) << fives << " x $5.00" << right << setw(8) << "$" << (fives * 5.00) << endl;
					if (ones > 0)
					cout << right << setw(9) << ones << " x $1.00" << right << setw(8) << "$" << (ones * 1.00) << endl;
					
					cout << "\nEnding Tokens: \t" << endingBal << endl;
					
					totalTrans++;
					
				} // ================================(bills only closing bracket)=========================================
			
				// +++++++++++++++++++++++++++++++++++Coin option menu for purchase++++++++++++++++++++++++++++++++++++++++++++++++++
				if (purChoice == 'B' || purChoice == 'b')
					{						
					do
					{
						cout << "\nEnter number of $0.25 coins (min: 0, max: 100): ";	// input and validate for quarters
				        cin >> quarters;
				        
				        if (quarters < 0 || quarters > 100)
				        	cout << "\nERROR: Invalid input of $0.25 Coins. Try Again.\n"; 
					} while ( quarters < 0 || quarters > 100); 
					
					do
					{
						cout << "Enter number of $0.10 coins (min: 0, max: 100): ";	// input and validate for dimes
				        cin >> dimes;
				        
				        if (dimes < 0 || dimes > 100)
				        	cout << "\nERROR: Invalid input of $0.10 Coins. Try Again.\n"; 
					} while ( dimes < 0 || dimes > 100); 
						
					do
					{
						cout << "Enter number of $0.05 coins (min: 0, max: 100): ";	// input and validate for nickels
				        cin >> nickels;
				        
				        if (nickels < 0 || nickels > 100)
				        	cout << "\nERROR: Invalid input of $0.05 Coins. Try Again.\n"; 
					} while ( nickels < 0 || nickels > 100); 
						
					do
					{
						cout << "Enter number of $0.01 coins (min: 0, max: 100): ";	// input and validate for pennies
				        cin >> pennies;
				        
				        if (pennies < 0 || pennies > 100)
				        	cout << "\nERROR: Invalid input of $0.01 Coins. Try Again.\n"; 
					} while ( pennies < 0 || pennies > 100); 
										
						double totalCoins = (quarters * QUARTER) + (dimes * DIME) + (nickels * NICKEL) + (pennies * PENNY);		// total for coins 
		
						int totalCents = (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1);
						tokensPur = (totalCents * TOKENS_PER_DOLLAR) / 100;
						
						int receiptStartBal = endingBal;
						endingBal += tokensPur;
						totalTokensPur += tokensPur;
						
						
						//==============receipt for tokens purchased with coins with formatting============================
						cout <<"\n\n-------Transaction Receipt-------" << endl;
						cout <<"Starting Tokens: \t" << receiptStartBal << endl;
						cout <<"Tokens Purchased: \t" << tokensPur << endl;
						cout <<"\nPayment Breakdown:" << endl;
						cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
						if (quarters > 0)
						cout << right << setw(9) << quarters << " x $0.25" << right << setw(11) << "$" << (quarters * 0.25) << endl;
						if (dimes > 0)
						cout << right << setw(9) << dimes << " x $0.10" << right << setw(11) << "$" << (dimes * 0.10) << endl;
						if (nickels > 0)
						cout << right << setw(9) << nickels << " x $0.05" << right << setw(11) << "$" << (nickels * 0.05) << endl;
						if (pennies > 0)
						cout << right << setw(9) << pennies << " x $0.01" << right << setw(11) << "$" << (pennies * 0.01) << endl;
											
						totalQuarters += quarters;
						totalDimes += dimes;
						totalNickels += nickels;
						totalPennies += pennies;
					
						cout << "\nEnding Tokens: \t" << endingBal << endl;
						
						totalTrans++;					
					} // ++++++++++(coin purchase menu closing bracket)+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				}
			// =============================REDEMPTION========================================
			
			else if (transChoice == 'B' || transChoice == 'b')
				{
					do 
					{
					    cout << "\nHow many tokens would you like to redeem? (max: " << endingBal << "): ";
					    cin >> tokensRed;
					
					    if (tokensRed <= 0 || tokensRed > endingBal)
					    {
					    	cout <<"\nERROR: Invalid redemption amount.\n";
						} 
					} while (tokensRed <= 0 || tokensRed > endingBal);
					
				        int remaining = tokensRed;
				
				        megaCount = remaining / MEGA; remaining %= MEGA;
				        superCount = remaining / SUPER; remaining %= SUPER;
				        largeCount = remaining / LARGE; remaining %= LARGE;
				        mediumCount = remaining / MEDIUM; remaining %= MEDIUM;
				        smallCount = remaining / SMALL; remaining %= SMALL;
				        miniCount = remaining / MINI; remaining %= MINI;
				        tinyCount = remaining / TINY; remaining %= TINY;
				        stickerCount = remaining / STICKER;
				        remaining %= STICKER;
				        candyCount = remaining / CANDY;

						megaCount += mega;
						superCount += super;
						largeCount += large;
						mediumCount += medium;
						smallCount += small;
						tinyCount += tiny;
						stickerCount += sticker;
						candyCount += candy;

						int receiptStartBal = endingBal;
				        endingBal -= tokensRed;
				        totalTokensRed += tokensRed;
				
				        singleRedem++;
				        totalRedem++;
				
				        cout << "\n------ Redemption Receipt ------\n";
				        cout << "Starting Tokens: " << receiptStartBal << endl;
				        cout << "Tokens Redeemed: " << tokensRed << "\n" << endl;
				        
				        if (megaCount > 0) 
							{
								cout << setw(8) << right << megaCount << setw(15) << left << " x Mega Prize" << setw(15) << right << "1000 Tokens" << endl; 
							}
							if (superCount > 0) 
							{
								cout << setw(8) << right << superCount << setw(15) << left << " x Super Prize" << setw(15) << right << "500 Tokens" << endl; 
							}
							if  (largeCount > 0) 
							{
								cout << setw(8) << right << largeCount << setw(15) << left << " x Large Prize" << setw(15) << right << "250 Tokens" << endl; 
							}
							if (mediumCount > 0) 
							{
								cout << setw(8) << right << mediumCount << setw(15) << left << " x Medium Prize" << setw(15) << right << "100 Tokens" << endl; 
							}
							if (smallCount > 0) 
							{
								cout << setw(8) << right << smallCount << setw(15) << left << " x Small Prize" << setw(15) << right << "50 Tokens" << endl; 
							}
							if (miniCount > 0) 
							{
								cout << setw(8) << right << miniCount << setw(15) << left << " x Mini Prize" << setw(15) << right << "25 Tokens" << endl; 
							}
							if (tinyCount > 0) 
							{
								cout << setw(8) << right << tinyCount << setw(15) << left << " x Tiny Prize" << setw(14) << right << "10 Tokens" << endl; 
							}
							if (stickerCount > 0) 
							{
								cout << setw(8) << right << stickerCount << setw(15) << left << " x Sticker Prize" << setw(15) << right << "5 Tokens" << endl;
							} 
							if (candyCount > 0) 
							{
								cout << setw(8) << right << candyCount << setw(15) << left << " x Candy Prize" << setw(15) << right << "1 Token" << endl; 
							}
							cout << "\n\tEnding Tokens: \t\t" << endingBal << endl;
							
							totalTrans++;
				}
			break;
		}
		
		case 'B':
		case 'b':
			{
				int hundreds = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, ones = 0;		// declare bill counters
				int quarters = 0, dimes = 0, nickels = 0, pennies = 0; 							// declare coins counters
				int multiTrans;
				
				do
				{
					cout <<"\nEnter number of transactions to generate (1-10): ";
					cin >> multiTrans;
					cout <<"\n--Generating " << multiTrans << " Random Transactions--" << endl;
					
					if (multiTrans < 1 || multiTrans > 10)
					{
						cout <<"\nERROR: Must be between 1 and 10.\n";
					}
				} while (multiTrans < 1 || multiTrans > 10);
				
				for (int i = 1; i <= multiTrans; i++)
				{					
					cout <<"\nTransaction #" << i << ":" << endl;
					
					int transType = rand() % 2;
					
			
					if (transType == 0)
						{
						    multiPur++;
							totalPur++;						
						
						    int payType = rand() % 2;

					    if (payType == 0)
					    {					
					        int rHundreds = (rand() % 5) + 1;
					        int rFifties = (rand() % 5) + 1;
					        int rTwenties = (rand() % 5) + 1;
					        int rTens = (rand() % 5) + 1;
					        int rFives = (rand() % 5) + 1;
					        int rOnes = (rand() % 5) + 1;
					        
					        totalHundreds += rHundreds;
							totalFifties += rFifties;
							totalTwenties += rTwenties;
							totalTens += rTens;
							totalFives += rFives;
							totalOnes += rOnes;
					
					        int totalCash =
					            (rHundreds * 100) +
					            (rFifties * 50) +
					            (rTwenties * 20) +
					            (rTens * 10) +
					            (rFives * 5) +
					            (rOnes * 1);
					
					        int simTokens = totalCash * TOKENS_PER_DOLLAR;
					        endingBal += simTokens;
					        
					        cout << "\tToken Purchase\n";
							cout << "\tPayment Breakdown:" << endl;
							cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
							
							if (rHundreds > 0)
							cout << right << setw(9) << rHundreds << " x $100.00" << right << setw(6) << "$" << (rHundreds * 100.00) << endl;
							if (rFifties > 0)
							cout << right << setw(9) << rFifties << " x $50.00" << right << setw(7) << "$" << (rFifties * 50.00) << endl;
							if (rTwenties > 0)
							cout << right << setw(9) << rTwenties << " x $20.00" << right << setw(7) << "$" << (rTwenties * 20.00) << endl;
							if (rTens > 0)
							cout << right << setw(9) << rTens << " x $10.00" << right << setw(7) << "$" << (rTens * 10.00) << endl;
							if (rFives > 0)
							cout << right << setw(9) << rFives << " x $5.00" << right << setw(8) << "$" << (rFives * 5.00) << endl;
							if (rOnes > 0)
							cout << right << setw(9) << rOnes << " x $1.00" << right << setw(8) << "$" << (rOnes * 1.00) << endl;
												
					        cout << "\n\tTokens Purchased: " << simTokens << endl;
					        totalTokensPur += simTokens;
					    }
					    else
						    {											
						        int rQuarters = rand() % 20;
						        int rDimes = rand() % 20;
						        int rNickels = rand() % 20;
						        int rPennies = rand() % 20;
						        
						        totalQuarters += rQuarters;
								totalDimes += rDimes;
								totalNickels += rNickels;
								totalPennies += rPennies;
						
						        int totalCents =
						            (rQuarters * 25) +
						            (rDimes * 10) +
						            (rNickels * 5) +
						            (rPennies * 1);
						
						        int simTokens = (totalCents * TOKENS_PER_DOLLAR) / 100;
						        endingBal += simTokens;
						        
						        cout << "\tToken Purchase\n";
								cout << "\tPayment Breakdown:" << endl;
								cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
						        
								if (rQuarters > 0)
								cout << right << setw(9) << rQuarters << " x $0.25" << right << setw(7) << "$" << (rQuarters * 0.25) << endl;
								if (rDimes > 0)
								cout << right << setw(9) << rDimes << " x $0.10" << right << setw(7) << "$" << (rDimes * 0.10) << endl;
								if (rNickels > 0)
								cout << right << setw(9) << rNickels << " x $0.05" << right << setw(7) << "$" << (rNickels * 0.05) << endl;
								if (rPennies > 0)
								cout << right << setw(9) << rPennies << " x $0.01" << right << setw(7) << "$" << (rPennies * 0.01) << endl;
							
								cout << "\n\tTokens Earned: " << simTokens << endl;
						        totalTokensPur += simTokens;
						    }
						    	
						}
						
						else
							{
							
							    multiRedem++;
							    totalRedem++;
	
							    int tokensUsed = rand() % (endingBal + 1);
							    
							    if (tokensUsed < 50) tokensUsed = 50;
							    if (tokensUsed > endingBal) tokensUsed = endingBal;
							    int tempTokens = tokensUsed;
													    
							    int mega = tempTokens / MEGA;      tempTokens %= MEGA;
							    int super = tempTokens / SUPER;     tempTokens %= SUPER;
							    int large = tempTokens / LARGE;     tempTokens %= LARGE;
							    int medium = tempTokens / MEDIUM;   tempTokens %= MEDIUM;
							    int small = tempTokens / SMALL;     tempTokens %= SMALL;
							    int mini = tempTokens / MINI;       tempTokens %= MINI;
							    int tiny = tempTokens / TINY;       tempTokens %= TINY;
							    int sticker = tempTokens / STICKER; tempTokens %= STICKER;
							    int candy = tempTokens / CANDY;
					
							    if (tokensUsed > endingBal)
							    tokensUsed = endingBal;
							
								totalTokensRed += tokensUsed;
								endingBal -= tokensUsed;
							    
							    cout << "\tPrize Redemption\n";
								cout << "\tPrize Breakdown:" << endl;
								cout << left << setw(19) << "\tCount" << right << setw(5) << "Token Value" << endl;
							
							    if (mega > 0) 
								{
									cout << setw(9) << right << mega << setw(15) << left << " x Mega Prize" << setw(15) << right << "1000 Tokens" << endl; 
								}
								if (super > 0) 
								{
									cout << setw(9) << right << super << setw(15) << left << " x Super Prize" << setw(15) << right << "500 Tokens" << endl; 
								}
								if  (large > 0) 
								{
									cout << setw(9) << right << large << setw(15) << left << " x Large Prize" << setw(15) << right << "250 Tokens" << endl; 
								}
								if (medium> 0) 
								{
									cout << setw(9) << right << medium << setw(15) << left << " x Medium Prize" << setw(15) << right << "100 Tokens" << endl; 
								}
								if (small > 0) 
								{
									cout << setw(9) << right << small << setw(15) << left << " x Small Prize" << setw(15) << right << "50 Tokens" << endl; 
								}
								if (mini > 0) 
								{
									cout << setw(9) << right << mini << setw(15) << left << " x Mini Prize" << setw(15) << right << "25 Tokens" << endl; 
								}
								if (tiny > 0) 
								{
									cout << setw(9) << right << tiny << setw(15) << left << " x Tiny Prize" << setw(15) << right << "10 Tokens" << endl; 
								}
								if (sticker > 0) 
								{
									cout << setw(9) << right << sticker << setw(15) << left << " x Sticker Prize" << setw(14) << right << "5 Tokens" << endl;
								} 
								if (candy > 0) 
								{
									cout << setw(9) << right << candy << setw(15) << left << " x Candy Prize" << setw(15) << right << "1 Token" << endl; 
								}
								cout << "\n\tTokens Redeemed: " << tokensUsed << endl;
							}
				totalTrans++;			
				}
			
			} break;
			
			case 'C':
			case 'c':
			{		
				cout << ": Total Transactions = " << totalTrans << endl;
					    
				cout << "\n\nThank you for visiting Cosmic Coins Arcade!\n\n\n";
			    
			    if (totalTrans == 0)
			    {
			    	cout << "\n--Current Token Balance--" << endl;
			    	cout << "\nPersonal Token Balance: \t\t" << endingBal << endl;
			    	cout << "\n\n-- All Transaction Report --\n" << endl;
					cout << "There were no transactions for this session." << endl;
				}
				
				else
				{
				cout << "\n--Current Token Balance--" << endl;
			    cout << "\nPersonal Token Balance: \t" << endingBal << endl;
			    cout << "\n--All Transaction Report--" << endl;
			    cout << "# of Transactions: \t" << setw(10) << right << totalTrans << endl;
			
			    cout << "\n# of Single Transactions: " << setw(8) << right << (singlePur + singleRedem) << endl;
			    cout << "\t# of Single Purchases:   " << singlePur << endl;
			    cout << "\t# of Single redemptions: " << singleRedem << endl;
			    
			    cout << "\n# of Generated Transactions: " << (multiPur + multiRedem) << endl;
				cout << "\t# of Generated Purchases: " << multiPur << endl;
				cout << "\t# of Generated Redemptions: " << multiRedem << endl;
				
				cout << "\n# of purchases: " << setw(17) << (multiPur + singlePur) << endl;
				cout << "# of redemptions: " << setw(15) << (multiRedem + singleRedem) << endl;
			
			    cout << "\nTotal Currency Tendered: " << endl;
			    
			    //------------------------Multi Trans Bills/Dollars---------------------------------------
			    if (totalHundreds > 0 || totalFifties > 0 || totalTwenties > 0 ||
		            totalTens > 0 || totalFives > 0 || totalOnes > 0)
		        {
		            cout << left << setw(19) << "\tCount" << right << setw(5) << "Amount" << endl;
		        }
			    
				if (totalHundreds  > 0)
					cout << right << setw(9) << totalHundreds  << " x $100.00" << right << setw(6) << "$" << (totalHundreds * 100.00) << endl;
				if (totalFifties  > 0)
					cout << right << setw(9) << totalFifties  << " x $50.00" << right << setw(7) << "$" << (totalFifties * 50.00) << endl;
				if (totalTwenties  > 0)
					cout << right << setw(9) << totalTwenties  << " x $20.00" << right << setw(7) << "$" << (totalTwenties  * 20.00) << endl;
				if (totalTens   > 0)
					cout << right << setw(9) << totalTens  << " x $10.00" << right << setw(7) << "$" << (totalTens  * 10.00) << endl;
				if (totalFives  > 0)
					cout << right << setw(9) << totalFives  << " x $5.00" << right << setw(8) << "$" << (totalFives  * 5.00) << endl;
				if (totalOnes  > 0)
					cout << right << setw(9) << totalOnes  << " x $1.00" << right << setw(8) << "$" << (totalOnes  * 1.00) << endl;
				
				if (totalQuarters > 0 || totalDimes > 0 || totalNickels > 0 ||
		            totalPennies > 0 )
		        {
		            cout << left << setw(19) << "\n\tCount" << right << setw(5) << "Amount" << endl;
		        }
		        
		        //==============================Multi Trans Coins============================================
				if (totalQuarters  > 0)
					cout << right << setw(9) << totalQuarters  << " x $0.25" << right << setw(7) << "$" << (totalQuarters * 0.25) << endl;
				if (totalDimes  > 0)
					cout << right << setw(9) << totalDimes  << " x $0.10" << right << setw(7) << "$" << (totalDimes * 0.10) << endl;
				if (totalNickels > 0)
					cout << right << setw(9) << totalNickels  << " x $0.05" << right << setw(7) << "$" << (totalNickels  * 0.05) << endl;
				if (totalPennies   > 0)
					cout << right << setw(9) << totalPennies  << " x $0.01" << right << setw(7) << "$" << (totalPennies  * 0.01) << endl;			
			    
				cout << "\n-- Prizes Redeemed Summary --" << endl;

				if (megaCount > 0)
				    cout << setw(8) << right << megaCount << setw(15) << left << " x Mega Prize" << setw(15) << right << "1000 Tokens" << endl;
				
				if (superCount > 0)
				    cout << setw(8) << right << superCount << setw(15) << left << " x Super Prize" << setw(15) << right << "500 Tokens" << endl;
				
				if (largeCount > 0)
				    cout << setw(8) << right << largeCount << setw(15) << left << " x Large Prize" << setw(15) << right << "250 Tokens" << endl;
				
				if (mediumCount > 0)
				    cout << setw(8) << right << mediumCount << setw(15) << left << " x Medium Prize" << setw(15) << right << "100 Tokens" << endl;
				
				if (smallCount > 0)
				    cout << setw(8) << right << smallCount << setw(15) << left << " x Small Prize" << setw(15) << right << "50 Tokens" << endl;
				
				if (miniCount > 0)
				    cout << setw(8) << right << miniCount << setw(15) << left << " x Mini Prize" << setw(15) << right << "25 Tokens" << endl;
				
				if (tinyCount > 0)
				    cout << setw(8) << right << tinyCount << setw(15) << left << " x Tiny Prize" << setw(15) << right << "10 Tokens" << endl;
				
				if (stickerCount > 0)
				    cout << setw(8) << right << stickerCount << setw(15) << left << " x Sticker Prize" << setw(14) << right << "5 Tokens" << endl;
				
				if (candyCount > 0)
				    cout << setw(8) << right << candyCount << setw(15) << left << " x Candy Prize" << setw(15) << right << "1 Token" << endl;
				
				cout << "\n# of Tokens Transacted: " << (totalTokensPur + totalTokensRed) << endl;
			    cout << "# of Tokens Purchased: " << totalTokensPur << endl;
			    cout << "# of Tokens Redeemed: " << totalTokensRed << endl;
				}
	
			    break;
				}
		} 
	} while (mainChoice != 'c' && mainChoice != 'C'); 		// (main menu and first do-while closing bracket)
}			// main closing bracket
