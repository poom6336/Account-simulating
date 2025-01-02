#include <iostream>
#include <vector>
#include <string>

class Account {
public:
    Account(std::string accountName, double initialBalance)
        : accountName(accountName), balance(initialBalance) {}

    std::string getAccountName() const { return accountName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " to account " << accountName << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from account " << accountName << std::endl;
        } else {
            std::cout << "Invalid withdraw amount." << std::endl;
        }
    }

    void displayBalance() const {
        std::cout << "Account: " << accountName << ", Balance: " << balance << std::endl;
    }

private:
    std::string accountName;
    double balance;
};

class Bank {
public:
    void createAccount(const std::string& accountName, double initialBalance) {
        accounts.emplace_back(accountName, initialBalance);
        std::cout << "Account created: " << accountName << std::endl;
    }

    void depositToAccount(const std::string& accountName, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountName() == accountName) {
                account.deposit(amount);
                return;
            }
        }
        std::cout << "Account not found." << std::endl;
    }

    void withdrawFromAccount(const std::string& accountName, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountName() == accountName) {
                account.withdraw(amount);
                return;
            }
        }
        std::cout << "Account not found." << std::endl;
    }

    void displayAccountBalance(const std::string& accountName) const {
        for (const auto& account : accounts) {
            if (account.getAccountName() == accountName) {
                account.displayBalance();
                return;
            }
        }
        std::cout << "Account not found." << std::endl;
    }

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account.displayBalance();
        }
    }

private:
    std::vector<Account> accounts;
};

int main() {
    Bank bank;
    int choice;

    do {
        std::cout << "\nBank Management System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Display Account Balance\n";
        std::cout << "5. Display All Accounts\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string accountName;
                double initialBalance;
                std::cout << "Enter account name: ";
                std::cin >> accountName;
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                bank.createAccount(accountName, initialBalance);
                break;
            }
            case 2: {
                std::string accountName;
                double amount;
                std::cout << "Enter account name: ";
                std::cin >> accountName;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.depositToAccount(accountName, amount);
                break;
            }
            case 3: {
                std::string accountName;
                double amount;
                std::cout << "Enter account name: ";
                std::cin >> accountName;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdrawFromAccount(accountName, amount);
                break;
            }
            case 4: {
                std::string accountName;
                std::cout << "Enter account name: ";
                std::cin >> accountName;
                bank.displayAccountBalance(accountName);
                break;
            }
            case 5: {
                bank.displayAllAccounts();
                break;
            }
            case 6: {
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
