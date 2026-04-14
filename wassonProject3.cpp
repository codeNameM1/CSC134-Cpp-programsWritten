#include <iostream>		// header file needed for console input / output
#include <iomanip> 		// header file used for formatting output
#include <cstdlib>		// header file used for rand and srand
#include <ctime>		// header file used for time
#include <string>		// header file used for library string class
using namespace std;  	// uses standard namespace for C++ keywords

// ============================== Function prototypes==========================
string getMainMenuChoice();
string getTransactionMenuChoice(int tokenBalance);
string getPaymentMenuChoice();
long getValidatedInput(string prompt, long minVal, long maxVal);
void displayFormattedToken(long tokens);
void displayCurrencyBreakdown(string type, long hundred, long fifty, long twenty, long ten, long five, long one, long quarter, long dime, long nickel, long penny, long startingBalance, long tokensPurchased, long tokenBalance);
void displayPrizeBreakdown(string type, long mega, long super, long large, long medium, long small, long mini, long tiny, long sticker, long candy);
void displaySessionReport(int startingBal, int endingBal, long totalTrans, long singlePur, long singleRedem, long multiPur, long multiRedem, long totalTokensPur, long totalTokensRed, long totalHundreds, long totalFifties, long totalTwenties, long totalTens, long totalFives, long totalOnes, long totalQuarters, long totalDimes, long totalNickels, long totalPennies, long megaCount, long superCount, long largeCount, long mediumCount, long smallCount, long miniCount, long tinyCount, long stickerCount, long candyCount);

// =============================== Global constants============================
	// Bill values
const double HUNDRED = 100.00;
const double FIFTY = 50.00;
const double TWENTY = 20.00; 
const double TEN = 10.00;
const double FIVE = 5.00;
const double ONE = 1.00;

	// Coin values
const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;
const double PENNY = 0.01;

const int TOKENS_PER_DOLLAR = 10;
const int LOW_BALANCE_THRESHOLD = 50;
const int MEGA_PRIZE_VALUE = 1000;
const int SUPER_PRIZE_VALUE = 500;
const int LARGE_PRIZE_VALUE = 250;
const int MEDIUM_PRIZE_VALUE = 100;
const int SMALL_PRIZE_VALUE = 50;
const int MINI_PRIZE_VALUE = 25;
const int TINY_PRIZE_VALUE = 10;
const int STICKER_PRIZE_VALUE = 5;
const int CANDY_PRIZE_VALUE = 1;

//******************************* Main Function********************************
int main() 
{
	srand(time(0));
	
	cout << fixed << setprecision(2);
	
	// ============ Local tracking variables  ============
	int startingBal = (rand() % 49901) + 100;
	int tokenBalance = startingBal;
	
	// Bill/coin tracking
	long totalHundreds = 0, totalFifties = 0, totalTwenties = 0, totalTens = 0, totalFives = 0, totalOnes = 0;
	long totalQuarters = 0, totalDimes = 0, totalNickels = 0, totalPennies = 0;
	
	// Prize tracking
	long megaCount = 0, superCount = 0, largeCount = 0, mediumCount = 0, smallCount = 0;
	long miniCount = 0, tinyCount = 0, stickerCount = 0, candyCount = 0;
	
	// Transaction tracking
	long totalTrans = 0, singlePur = 0, singleRedem = 0, multiPur = 0, multiRedem = 0;
	long totalTokensPur = 0, totalTokensRed = 0;
	
	string mainChoice;
	do 
	{
		mainChoice = getMainMenuChoice();
		
		if (mainChoice == "A" || mainChoice == "a")
		{
			string transChoice = getTransactionMenuChoice(tokenBalance);
			
			if (transChoice == "A" || transChoice == "a")
			{
				string payChoice = getPaymentMenuChoice();
				
				long hundred = 0, fifty = 0, twenty = 0, ten = 0, five = 0, one = 0;
				long quarter = 0, dime = 0, nickel = 0, penny = 0;
				
				if (payChoice == "A" || payChoice == "a")
				{
					//*************** Bills ***************
					hundred = getValidatedInput("Enter the number of $100 bills (min: 0, max: 100): ", 0, 100);
					fifty = getValidatedInput("Enter the number of $50 bill (min: 0, max: 100): ", 0, 100);
					twenty = getValidatedInput("Enter the number of $20 bill (min: 0, max: 100): ", 0, 100);
					ten = getValidatedInput("Enter the number of $10 bill (min: 0, max: 100): ", 0, 100);
					five = getValidatedInput("Enter the number of $5 bill (min: 0, max: 100): ", 0, 100);
					one = getValidatedInput("Enter the number of $1 bill (min: 0, max: 100): ", 0, 100);
				}
				else
				{
					//*************** Coins *******************
					quarter = getValidatedInput("Enter number of Quarters $0.25 (min: 0, max: 100): ", 0, 100);
					dime = getValidatedInput("Enter number of Dimes $0.10 (min: 0, max: 100): ", 0, 100);
					nickel = getValidatedInput("Enter number of Nickels $0.05 (min: 0, max: 100): ", 0, 100);
					penny = getValidatedInput("Enter number of Pennies $0.01 (min: 0, max: 100): ", 0, 100);
				}
				
				// ======= Calculate Tokens ============
				double totalCash = (hundred * 100) + (fifty * 50) + (twenty * 20) + (ten * 10) + (five * 5) + (one * 1);
				double totalCoin = (quarter * 0.25) + (dime * 0.10) + (nickel * 0.05) + (penny * 0.01);
				
				int tokensPurchased = (int)((totalCash + totalCoin) * TOKENS_PER_DOLLAR);
				
				int startingBalance = tokenBalance;
				tokenBalance += tokensPurchased;
				
				// Accumulate tracking
				totalHundreds += hundred;
				totalFifties += fifty;
				totalTwenties += twenty;
				totalTens += ten;
				totalFives += five;
				totalOnes += one;
				totalQuarters += quarter;
				totalDimes += dime;
				totalNickels += nickel;
				totalPennies += penny;
				totalTokensPur += tokensPurchased;
				singlePur++;
				totalTrans++;
				
				//^^^^^^^^^^^^^^^ Receipt ^^^^^^^^^^^^^^^^^
				
				cout << "Starting Tokens: ";
				displayFormattedToken(startingBalance);
				cout << "\nTokens Purchased: ";
				displayFormattedToken(tokensPurchased);
				cout << endl;
				
				displayCurrencyBreakdown("P", hundred, fifty, twenty, ten, five, one, quarter, dime, nickel, penny, startingBalance, tokensPurchased, tokenBalance);
				
				cout << "Ending Tokens: ";
				displayFormattedToken(tokenBalance);
				cout << endl;
			}
			
			else if (transChoice == "B" || transChoice == "b")
			
			{
				long mega = 0, super = 0, large = 0, medium = 0, small = 0, mini = 0, tiny = 0, sticker = 0, candy = 0;
				
				cout << "How many tokens would you like to redeem? (max: " <<  tokenBalance << "): ";
				long tokensUsed = getValidatedInput("", 0, tokenBalance);
				
				if (tokensUsed == 0)
				{
					cout << "\nNo Tokens redeemed.\n";
				}
				else
				{
					long remaining = tokensUsed;

					mega = remaining / MEGA_PRIZE_VALUE;      remaining %= MEGA_PRIZE_VALUE;
					super = remaining / SUPER_PRIZE_VALUE;     remaining %= SUPER_PRIZE_VALUE;
					large = remaining / LARGE_PRIZE_VALUE;     remaining %= LARGE_PRIZE_VALUE;
					medium = remaining / MEDIUM_PRIZE_VALUE;   remaining %= MEDIUM_PRIZE_VALUE;
					small = remaining / SMALL_PRIZE_VALUE;     remaining %= SMALL_PRIZE_VALUE;
					mini = remaining / MINI_PRIZE_VALUE;       remaining %= MINI_PRIZE_VALUE;
					tiny = remaining / TINY_PRIZE_VALUE;       remaining %= TINY_PRIZE_VALUE;
					sticker = remaining / STICKER_PRIZE_VALUE; remaining %= STICKER_PRIZE_VALUE;
					candy = remaining;

					// Accumulate tracking
					megaCount += mega;
					superCount += super;
					largeCount += large;
					mediumCount += medium;
					smallCount += small;
					miniCount += mini;
					tinyCount += tiny;
					stickerCount += sticker;
					candyCount += candy;

					totalTokensRed += tokensUsed;
					tokenBalance -= tokensUsed;
					singleRedem++;
					totalTrans++;
				}
			
				displayPrizeBreakdown("R", mega, super, large, medium, small, mini, tiny, sticker, candy);
				
				cout << "Remaining Tokens: ";
				displayFormattedToken(tokenBalance);
				cout << endl;
			}
		}  // Close the if (mainChoice == "A"...)
		
		//************** MultiTransaction Menu *************
		else if (mainChoice == "B" || mainChoice == "b")
		{
		    int multiTrans = getValidatedInput(
		        "Enter number of transactions (1-10): ", 1, 10);
		        
		    // Used for Simulation balance Only under Multi-Transaction mode	
		    int simBalance = tokenBalance;
		    
	
		    cout << "\n--Generating " << multiTrans << " Random Transactions--\n";
		
		    for (int i = 1; i <= multiTrans; i++)
		    {
		        cout << "\nTransaction #" << i << ":\n";
		
		        int transType = rand() % 2;
		        totalTrans++;
		
		        // ================= PURCHASE =================
		        if (transType == 0)
		        {
		            multiPur++;
		
		            int payType = rand() % 2;
		
		            long rHundreds = 0, rFifties = 0, rTwenties = 0, rTens = 0, rFives = 0, rOnes = 0;
		            long rQuarters = 0, rDimes = 0, rNickels = 0, rPennies = 0;
		
		            double totalCash = 0;
		
		            if (payType == 0)
		            {
		                rHundreds = (rand() % 5) + 1;
		                rFifties = (rand() % 5) + 1;
		                rTwenties = (rand() % 5) + 1;
		                rTens = (rand() % 5) + 1;
		                rFives = (rand() % 5) + 1;
		                rOnes = (rand() % 5) + 1;
		
		                totalCash =
		                    (rHundreds * HUNDRED) +
		                    (rFifties * FIFTY) +
		                    (rTwenties * TWENTY) +
		                    (rTens * TEN) +
		                    (rFives * FIVE) +
		                    (rOnes * ONE);
		            }
		            else
		            {
		                rQuarters = rand() % 20;
		                rDimes = rand() % 20;
		                rNickels = rand() % 20;
		                rPennies = rand() % 20;
		
		                totalCash =
		                    (rQuarters * QUARTER) +
		                    (rDimes * DIME) +
		                    (rNickels * NICKEL) +
		                    (rPennies * PENNY);
		            }
		
		            int simTokens = (int)(totalCash * TOKENS_PER_DOLLAR);
		
				    // For multiTranaction Sim Only 
				    simBalance += simTokens;
		            
		            // Global Tracking
					totalTokensPur += simTokens;
		
		            totalHundreds += rHundreds;
		            totalFifties += rFifties;
		            totalTwenties += rTwenties;
		            totalTens += rTens;
		            totalFives += rFives;
		            totalOnes += rOnes;
		
		            totalQuarters += rQuarters;
		            totalDimes += rDimes;
		            totalNickels += rNickels;
		            totalPennies += rPennies;
		
		            cout << "\tToken Purchase\n";
		
		            displayCurrencyBreakdown("G",rHundreds, rFifties, rTwenties, rTens, rFives, rOnes,rQuarters, rDimes, rNickels, rPennies,0, simTokens, simBalance);
		
		            cout << "\tTokens Purchased: ";
		            displayFormattedToken(simTokens);
		            cout << endl;
		        }
		
		        // ================= REDEMPTION =================
		        else
		        {
		            multiRedem++;
		
		            long tokensUsed = rand() % (simBalance + 1);
		       
		       		// update simBalance Only 
					simBalance -= tokensUsed;

				    int tempTokens = tokensUsed;
		
		            int mega = tempTokens / MEGA_PRIZE_VALUE;      tempTokens %= MEGA_PRIZE_VALUE;
		            int super = tempTokens / SUPER_PRIZE_VALUE;    tempTokens %= SUPER_PRIZE_VALUE;
		            int large = tempTokens / LARGE_PRIZE_VALUE;    tempTokens %= LARGE_PRIZE_VALUE;
		            int medium = tempTokens / MEDIUM_PRIZE_VALUE;  tempTokens %= MEDIUM_PRIZE_VALUE;
		            int small = tempTokens / SMALL_PRIZE_VALUE;    tempTokens %= SMALL_PRIZE_VALUE;
		            int mini = tempTokens / MINI_PRIZE_VALUE;      tempTokens %= MINI_PRIZE_VALUE;
		            int tiny = tempTokens / TINY_PRIZE_VALUE;      tempTokens %= TINY_PRIZE_VALUE;
		            int sticker = tempTokens / STICKER_PRIZE_VALUE;tempTokens %= STICKER_PRIZE_VALUE;
		            int candy = tempTokens;
		
		            megaCount += mega;
		            superCount += super;
		            largeCount += large;
		            mediumCount += medium;
		            smallCount += small;
		            miniCount += mini;
		            tinyCount += tiny;
		            stickerCount += sticker;
		            candyCount += candy;
		
		            totalTokensRed += tokensUsed;
		          
		
		            cout << "\tPrize Redemption\n";
		
		            displayPrizeBreakdown("G",mega, super, large, medium, small, mini, tiny, sticker, candy);
		
		            cout << "\tTokens Redeemed: " << tokensUsed << endl;
		        }
		    }
		    
		}
		
	} while (mainChoice != "C" && mainChoice != "c");
	
	// Display final session report
	displaySessionReport(startingBal, tokenBalance, totalTrans, singlePur, singleRedem, multiPur, multiRedem,
					totalTokensPur, totalTokensRed, totalHundreds, totalFifties, totalTwenties, totalTens,
					totalFives, totalOnes, totalQuarters, totalDimes, totalNickels, totalPennies,
					megaCount, superCount, largeCount, mediumCount, smallCount, miniCount, tinyCount, stickerCount, candyCount);
	
	cout << "\nThank you for using Cosmic Coins!\n";
	return 0;	
}

//******************************* Main Menu Function **************************
// Purpose: Displays main menu and gets validated user choice
// Parameters: None
// Return:    string - validated menu choice (A, B, or C)
//////////////////////////////////////////////////////////////////////////////
string getMainMenuChoice() 
{
	string choice;
	
	do
	{
		cout <<"\n\t\t --Main Menu--\n";
		cout <<"Choose from one of the following:\n";
		cout <<"\tA - Single Transaction\n";
		cout <<"\tB - Generate Multiple Transactions\n";
		cout <<"\tC - Exit\n";
		cout <<"\nEnter your choice (A, B, or C): ";
		getline(cin, choice);
		
	} while (choice != "A" && choice != "B" && choice != "C" && 
			 choice != "a" && choice != "b" && choice != "c");
			 
	return choice;
}

//******************************* Validate Input Function **********************
// Purpose: Prompts user for numeric input and validates within range
// Parameters: string prompt - the prompt message to display
//             long minVal - minimum acceptable value
//             long maxVal - maximum acceptable value
// Return:    long - validated numeric input within the specified range
//////////////////////////////////////////////////////////////////////////////
long getValidatedInput(string prompt, long minVal, long maxVal)
{
	long value;
	
	do
	{
		cout << prompt;
		cin >> value;
		
		if (value < minVal || value > maxVal)
		{
			cout << "Error: Invalid input. Try Again.\n";
		}
	} while (value < minVal || value > maxVal);
	
	cin.ignore(1000, '\n');
	
	return value;
}

//******************************* Payment Menu Function ************************
// Purpose: Displays payment type menu and gets validated user choice
// Parameters: None
// Return:    string - validated payment method choice (A or B)
//////////////////////////////////////////////////////////////////////////////
string getPaymentMenuChoice()
{
	string choice;
	
	do
	{
		cout << "How would you like to pay?" << endl;
		cout << "\n\tA - Cash Only (Bills)\n";
		cout << "\tB - Coins Only\n";
		cout << "Enter your choice (A or B): ";
		getline(cin,choice);
		
	} while (choice != "A" && choice != "B" && 
			 choice != "a" && choice != "b");
	
	return choice;
}

//******************************* Transaction Menu Function ********************
// Purpose: Displays transaction menu with low balance warning and validates choice
// Parameters: int tokenBalance - current token balance (used for balance check)
// Return:    string - validated transaction choice (A or B)
//////////////////////////////////////////////////////////////////////////////
string getTransactionMenuChoice(int tokenBalance)
{
	string choice;
	
	if (tokenBalance < LOW_BALANCE_THRESHOLD)
		{
			cout <<"\nWARNING LOW TOKEN BALANCE. PLEASE MAKE A PURCHASE.\n";
			return "A";
		}

			do
			{
				cout << "\n\t--Single Transaction Menu--\n";
				cout << "\nYour Current Token Balance is: " << tokenBalance << " tokens\n";
				cout << "\nWhat would you like to do today?\n";
	            cout << "\tA - Purchase Tokens" << endl;
	            cout << "\tB - Redeem Tokens for prizes" << endl;
	            cout << "Enter choice (A or B): ";
	            getline(cin, choice);
	            
	            if (choice != "A" && choice != "a" &&
        			choice != "B" && choice != "b")
        			{
        				cout << "\nERROR: Invalid choice.\n";
					}
			} while (choice != "A" && choice != "a" &&
         			 choice != "B" && choice != "b");
         	
			return choice;
}

//******************************* Display Formatted Token **********************
// Purpose: Displays token value with formatting
// Parameters: long tokens - the number of tokens to display
// Return:    void - displays output to console
//////////////////////////////////////////////////////////////////////////////
void displayFormattedToken(long tokens)
{
	cout << tokens;
}

//******************************* Currency Breakdown ***************************
// Purpose: Displays payment breakdown for purchase transaction
// Parameters: string type - transaction format type (P/R/G/F)
//             long hundred through penny - denomination counts
//             long startingBalance - starting token balance for receipt
//             long tokensPurchased - tokens purchased in transaction
//             long tokenBalance - ending token balance
// Return:    void - displays formatted currency breakdown to console
//////////////////////////////////////////////////////////////////////////////
void displayCurrencyBreakdown(string  type, long hundred, long fifty, long twenty, long ten, long five, long one, long quarter, long dime, long nickel, long penny, long startingBalance, long tokensPurchased, long tokenBalance)
{
	// Format based on receipt type
	if (type == "P" || type == "p")
	{
		// P = Purchase receipt - standard format
		cout << "\n-------Transaction Receipt (Purchase)-------" << endl;
		cout << "Starting Tokens: \t" << startingBalance << endl;
		cout << "Tokens Purchased: \t" << tokensPurchased << endl;
		cout << "\nPayment Breakdown:" << endl;
		cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
		
		if (hundred > 0)
			cout << right << setw(9) << hundred << " x $100.00" << right << setw(6) << "$" << (hundred * 100.00) << endl;
		if (fifty > 0)
			cout << right << setw(9) << fifty << " x $50.00" << right << setw(7) << "$" << (fifty * 50.00) << endl;
		if (twenty > 0)
			cout << right << setw(9) << twenty << " x $20.00" << right << setw(7) << "$" << (twenty * 20.00) << endl;
		if (ten > 0)
			cout << right << setw(9) << ten << " x $10.00" << right << setw(7) << "$" << (ten * 10.00) << endl;
		if (five > 0)
			cout << right << setw(9) << five << " x $5.00" << right << setw(8) << "$" << (five * 5.00) << endl;
		if (one > 0)
			cout << right << setw(9) << one << " x $1.00" << right << setw(8) << "$" << (one * 1.00) << endl;
		
		if (quarter > 0)
			cout << right << setw(9) << quarter << " x $0.25" << right << setw(6) << "$" << (quarter * 0.25) << endl;
		if (dime > 0)
			cout << right << setw(9) << dime << " x $0.10" << right << setw(6) << "$" << (dime * 0.10) << endl;
		if (nickel > 0)
			cout << right << setw(9) << nickel << " x $0.05" << right << setw(6) << "$" << (nickel * 0.05) << endl;
		if (penny > 0)
			cout << right << setw(9) << penny << " x $0.01" << right << setw(6) << "$" << (penny * 0.01) << endl;
		
		cout << "\nEnding Tokens: \t" << tokenBalance << endl;
	}
	else if (type == "G" || type == "g")
	{
		// G = Generated transaction - compact format
		cout << "\tPayment Breakdown:" << endl;
		cout << left << setw(19) << "\tCount" << right << setw(5) << "Value" << endl;
		
		if (hundred > 0)
			cout << right << setw(9) << hundred << " x $100.00" << right << setw(6) << "$" << (hundred * 100.00) << endl;
		if (fifty > 0)
			cout << right << setw(9) << fifty << " x $50.00" << right << setw(7) << "$" << (fifty * 50.00) << endl;
		if (twenty > 0)
			cout << right << setw(9) << twenty << " x $20.00" << right << setw(7) << "$" << (twenty * 20.00) << endl;
		if (ten > 0)
			cout << right << setw(9) << ten << " x $10.00" << right << setw(7) << "$" << (ten * 10.00) << endl;
		if (five > 0)
			cout << right << setw(9) << five << " x $5.00" << right << setw(8) << "$" << (five * 5.00) << endl;
		if (one > 0)
			cout << right << setw(9) << one << " x $1.00" << right << setw(8) << "$" << (one * 1.00) << endl;
		
		if (quarter > 0)
			cout << right << setw(9) << quarter << " x $0.25" << right << setw(6) << "$" << (quarter * 0.25) << endl;
		if (dime > 0)
			cout << right << setw(9) << dime << " x $0.10" << right << setw(6) << "$" << (dime * 0.10) << endl;
		if (nickel > 0)
			cout << right << setw(9) << nickel << " x $0.05" << right << setw(6) << "$" << (nickel * 0.05) << endl;
		if (penny > 0)
			cout << right << setw(9) << penny << " x $0.01" << right << setw(6) << "$" << (penny * 0.01) << endl;
	}
}

//******************************* Prize Breakdown ******************************
// Purpose: Displays prize distribution for redemption transaction
// Parameters: string type - transaction format type (R/G/F)
//             long mega through candy - prize counts for each denomination
// Return:    void - displays formatted prize breakdown to console
//////////////////////////////////////////////////////////////////////////////
void displayPrizeBreakdown(string type, long mega, long super, long large, long medium, long small, long mini, long tiny, long sticker, long candy)
{
	if (type == "R" || type == "r")
	{
		// R = Redemption receipt
		cout << "\n-------Prize Breakdown (Redemption)-------" << endl;
		cout << left << setw(24) << "Count" << right << setw(10) << "Value" << endl;
		
		if (mega > 0)
			cout << right << setw(9) << mega << " x Mega Prize(s)" << right << setw(10) << (mega * 1000) << " tokens" << endl;
		if (super > 0)
			cout << right << setw(9) << super << " x Super Prize(s)" << right << setw(9) << (super * 500) << " tokens" << endl;
		if (large > 0)
			cout << right << setw(9) << large << " x Large Prize(s)" << right << setw(10) << (large * 250) << " tokens" << endl;
		if (medium > 0)
			cout << right << setw(9) << medium << " x Medium Prize(s)" << right << setw(10) << (medium * 100) << " tokens" << endl;
		if (small > 0)
			cout << right << setw(9) << small << " x Small Prize(s)" << right << setw(8) << (small * 50) << " tokens" << endl;
		if (mini > 0)
			cout << right << setw(9) << mini << " x Mini Prize(s)" << right << setw(8) << (mini * 25) << " tokens" << endl;
		if (tiny > 0)
			cout << right << setw(9) << tiny << " x Tiny Prize(s)" << right << setw(8) << (tiny * 10) << " tokens" << endl;
		if (sticker > 0)
			cout << right << setw(9) << sticker << " x Sticker Prize(s)" << right << setw(6) << (sticker * 5) << " tokens" << endl;
		if (candy > 0)
			cout << right << setw(9) << candy << " x Candy Prize(s)" << right << setw(6) << (candy * 1) << " tokens" << endl;
	}
	else if (type == "G" || type == "g")
	{
		// G = Generated transaction - compact format
		cout << "\tPrize Breakdown:" << endl;
		
		if (mega > 0)
			cout << "\t" << mega << " x Mega Prize(s)" << right << setw(10) << (mega * 1000) << " tokens" << endl;
		if (super > 0)
			cout << "\t" << super << " x Super Prize(s)" << right << setw(10) << (super * 500) << " tokens" << endl;
		if (large > 0)
			cout << "\t" << large << " x Large Prize(s)" << right << setw(10) << (large * 250) << " tokens" << endl;
		if (medium > 0)
			cout << "\t" << medium  << " x Medium Prize(s)" << right << setw(10) << (medium * 100) << " tokens" << endl;
		if (small > 0)
			cout << "\t" << small << " x Small Prize(s)" << right << setw(10) << (small * 50) << " tokens" << endl;
		if (mini > 0)
			cout << "\t" << mini << " x Mini Prize(s)" << right << setw(10) << (mini * 25) << " tokens" << endl;
		if (tiny > 0)
			cout << "\t" << tiny << " x Tiny Prize(s)" << right << setw(10) << (tiny * 10) << " tokens" << endl;
		if (sticker > 0)
			cout << "\t" << sticker << " x Sticker Prize(s)" << right << setw(10) << (sticker * 5) << " tokens" << endl;
		if (candy > 0)
			cout << "\t" << candy << " x Candy Prize(s)" << right << setw(10) << (candy * 1) << " tokens" << endl;
	}
}



//******************************* Session Report Function **********************
// Purpose: Displays comprehensive session summary including all transactions,
//          currency breakdown, and prizes redeemed
// Parameters: int startingBal, endingBal - session token balances
//             long totalTrans, singlePur, singleRedem, multiPur, multiRedem - transaction counts
//             long totalTokensPur, totalTokensRed - total tokens purchased/redeemed
//             long totalHundreds through totalPennies - accumulated currency counts
//             long megaCount through candyCount - accumulated prize counts
// Return:    void - displays final session report to console
//////////////////////////////////////////////////////////////////////////////
void displaySessionReport(int startingBal, int endingBal, long totalTrans, long singlePur, long singleRedem, long multiPur, long multiRedem, 
						long totalTokensPur, long totalTokensRed, long totalHundreds, long totalFifties, long totalTwenties, long totalTens, 
						long totalFives, long totalOnes, long totalQuarters, long totalDimes, long totalNickels, long totalPennies,
						long megaCount, long superCount, long largeCount, long mediumCount, long smallCount, long miniCount, long tinyCount, long stickerCount, long candyCount)
{
	cout << "\nThank you for visiting Cosmic Coins Arcade!\n";
	
	if (totalTrans == 0)
	{
		cout << "\n--Current Token Balance--" << endl;
		cout << "\nPersonal Token Balance: \t\t" << startingBal << endl;
		cout << "\n\n-- All Transaction Report --\n" << endl;
		cout << "There were no transactions for this session." << endl;
	}
	else
	{
		cout << "\n--Current Token Balance--" << endl;
		cout << "\nPersonal Token Balance: " << startingBal << endl;
		cout << "Ending Token Balance: \t" << endingBal << endl;
		
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
}

