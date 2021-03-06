/*
 * One version of a program that manipulates bank accounts.  This
 * exercise is inspired by Walter Savitch, Problem Solving with C++,
 * 10th edition, Chapter 10.  I've taken the bank account example and
 * choice of representations as well as some operations from Savitch.
 * I also added a data member for the account holder name and added
 * deposit and with withdraw functions.  
 *
 * We're doing this with structs rather than classes, but classes are
 * coming! 
 *
 * Mark A. Sheldon, Tufts University, Fall 2018
 */
#include <iostream>
#include <cmath>

using namespace std;

/**************************************************************************/
/*                             Bank Accounts                              */
/**************************************************************************/

/*
 * Representation 1 for bank accounts.
 * Clients should not manipulate the struct members at all.
 * They should use the functions below.
 */
struct BankAccount {
        string owner;
        int    accountNumber;
        int    balanceDollars;
        int    balanceCents;
        float  interestFraction;
};

/**************************************************************************/
/*                   Bank Account Function Interface                      */
/**************************************************************************/

BankAccount *BankAccount_new    (string owner, int acct_num, 
                                 int balance_dollars, int balance_cents,
                                 float interest_rate); 
void   BankAccount_destroy      (BankAccount **accountpp);
void   BankAccount_print        (BankAccount *accountp);
float  BankAccount_balance      (BankAccount *accountp);
string BankAccount_owner        (BankAccount *accountp);
void   BankAccount_applyInterest(BankAccount *accountp);
void   BankAccount_deposit      (BankAccount *accountp, int dollars, int cents);
void   BankAccount_withdraw     (BankAccount *accountp, int dollars, int cents);


/**************************************************************************/
/*                            Bank Account Client                         */
/*                         Nothing here is modified                       */
/**************************************************************************/

const int MAX_ACCOUNTS = 5;

int readAccountInfo(BankAccount *accounts[], int max_len);
void printAccounts(BankAccount *accts[], int numAccts);
void destroyAccounts(BankAccount *accts[], int numAccts);
void doSomeTransactions(BankAccount *accts[], int numAccts);
void applyInterest(BankAccount *accts[], int numAccts);

int main() {
        BankAccount *accounts[MAX_ACCOUNTS];
        int         num_accounts = 0;

        num_accounts = readAccountInfo(accounts, MAX_ACCOUNTS);
        printAccounts(accounts, num_accounts);

        doSomeTransactions(accounts, num_accounts);
        printAccounts(accounts, num_accounts);
        
        applyInterest(accounts, num_accounts);
        printAccounts(accounts, num_accounts);
        
        destroyAccounts(accounts, num_accounts);
        return 0;
}

/*
 * Read account information from cin up to maxLen accounts
 */
int readAccountInfo(BankAccount *accounts[], int maxLen) {
        int    accountNum = 0;
        string name;
        int    initialDollars;
        int    initialCents;
        float  interest;

        cin >> name >> initialDollars >> initialCents >> interest;
        while (not cin.fail() and accountNum < maxLen) {
                accounts[accountNum] = BankAccount_new(name, accountNum,
                                                       initialDollars,
                                                       initialCents,
                                                       interest);
                cin >> name >> initialDollars >> initialCents >> interest;
                ++accountNum;
        }
        return accountNum;
}

/*
 * Print information about all bank accounts on cout
 */
void printAccounts(BankAccount *accts[], int numAccts) {
        for (int i = 0; i < numAccts; ++i) {
                BankAccount_print(accts[i]);
        }
}

bool isEven(int n) {
        return n % 2 == 0;
}

/*
 * A few transactions, assuming there are some accounts.
 * This is not thorough testing, just some examples of using the
 * interface. 
 */
void doSomeTransactions(BankAccount *accts[], int numAccts) {
        int dollars = 100;
        
        for (int i = 0; i < numAccts; ++i) {
                if (isEven(i)) {
                        cout << "Depositing " << dollars << " for "
                             << BankAccount_owner(accts[i]) << endl;
                        BankAccount_deposit(accts[i], dollars, 0);
                } else {
                        cout << "Withdrawing " << dollars << " from "
                             << BankAccount_owner(accts[i]) << endl;
                        BankAccount_withdraw(accts[i], dollars, 0);
                }
                dollars += 20;
        }
}

/*
 * Apply interest to all accounts
 */
void applyInterest(BankAccount *accts[], int numAccts) {
        for (int i = 0; i < numAccts; ++ i) {
                cout << "Applying intest for " 
                     << BankAccount_owner(accts[i])
                     << endl;
                BankAccount_applyInterest(accts[i]);
        }
}

/*
 * Recycle storage associated with all accounts
 */
void destroyAccounts(BankAccount *accts[], int numAccts) {
        for (int i = 0; i < numAccts; ++i) {
                BankAccount_destroy(&accts[i]);
        }
}

/**************************************************************************/
/*                 Bank Account Function Implementation                   */
/**************************************************************************/

/**************************************************************************/
/*                     FUNCTIONS FOR YOU TO WORK ON                       */
/**************************************************************************/


/*
 * Return a pointer to a newly initialized BankAccount
 * Note, interest rate is a percentage, e. g. 3.5 for 3.5% interest
 */
BankAccount *BankAccount_new(string owner, int accountNum, 
                             int balanceDollars, int balanceCents, 
                             float interestRate) {
        BankAccount *account_ptr = new BankAccount;
    
        account_ptr->owner            = owner;
        account_ptr->accountNumber    = accountNum;
        account_ptr->balanceDollars   = balanceDollars;
        account_ptr->balanceCents     = balanceCents;
        account_ptr->interestFraction = interestRate / 100.0;
        
        return account_ptr;
}
/*
 * Recycle the storage associated with the indicated BankAccount
 */
void BankAccount_destroy(BankAccount **accountpp) {
        if (accountpp != nullptr) {
                delete (*accountpp);
                (*accountpp) = nullptr;
        }
}

/*
 * Return the account balance as a floating point number
 */
float BankAccount_balance(BankAccount *accountp) {
        return accountp == nullptr ? -1 : 
                       (accountp->balanceDollars + 
                        0.01 * accountp->balanceCents);
}

/*
 * Update the balance of given BankAccount with by depositing given
 * amount
 */
void BankAccount_deposit(BankAccount *accountp, int dollars, int cents) {
        if (accountp != nullptr) {
        accountp->balanceDollars += dollars + cents / 100;
        accountp->balanceCents   += cents % 100;
    }
}

/*
 * Update the balance of given BankAccount with by withdrawing given
 * amount.  Not checking for overdraft.
 * If there's an overdraft, only dollars goes negative (assuming
 * starting balance is positive).
 */
void BankAccount_withdraw(BankAccount *accountp, int dollars, int cents) {
        if (accountp != nullptr) {
        accountp->balanceDollars -= dollars + cents / 100;
        accountp->balanceCents   -= cents % 100;
    }
}

/**************************************************************************/
/*                END OF FUNCTIONS FOR YOU TO WORK ON                     */
/**************************************************************************/

/*
 * Return owner of given account
 */
string BankAccount_owner(BankAccount *accountp) {
        return accountp->owner;
}

/*
 * Update the balance of given BankAccount according to its interest rate
 * Note:  interest rate is stored as a percentage
 */
void BankAccount_applyInterest(BankAccount *accountp) {
        int scaledBalance = accountp->balanceDollars * 100
                            + accountp->balanceCents;
        int payment = round(scaledBalance * accountp->interestFraction);

        accountp->balanceDollars += payment / 100;
        accountp->balanceCents   += payment % 100;
}

/*
 * Print the information about the BankAccount on cout
 */
void BankAccount_print(BankAccount *accountp) {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        
        cout << "BankAccount:  " << endl
             << "  { owner    = " << BankAccount_owner(accountp)   << ",\n"
             << "    number   = " << accountp->accountNumber       << ",\n"
             << "    balance  = " << BankAccount_balance(accountp) << ",\n"
             << "    interest = " << accountp->interestFraction * 100.0 << "\n"
             << "  }"
             << endl;
}