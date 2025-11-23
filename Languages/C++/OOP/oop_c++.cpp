//BASIC EXAMPLE FOR REFERENCE

#include <iostream>
#include <string>
#include <cmath> // For mathematical operations like sqrt()

/**
 * @file oop_comprehensive_example.cpp
 * @brief Demonstrates comprehensive OOP concepts in C++ with detailed explanations
 */

/**
 * @class BankAccount
 * @brief Represents a bank account with basic banking operations
 * 
 * Demonstrates:
 * - Encapsulation (private data, public interface)
 * - Constructor without default values
 * - Basic member functions
 * - Error handling
 * - Function composition (functions calling other functions)
 */
class BankAccount {
public:
    /**
     * @brief Constructor that requires all parameters (no defaults)
     * @param accountHolder Name of the account holder
     * @param accountNumber Unique account identifier
     * @param initialBalance Starting balance (must be >= 0)
     * @throws std::invalid_argument if initialBalance is negative
     */
    BankAccount(const std::string& accountHolder, 
                const std::string& accountNumber, 
                double initialBalance)
        : accountHolder_(accountHolder),    // Initialize member variables
          accountNumber_(accountNumber),    // using member initializer list
          balance_(initialBalance) {
        
        // Validate input parameters
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative");
        }
    }

    // ========== BASIC MEMBER FUNCTIONS ========== //

    /**
     * @brief Deposits money into the account
     * @param amount The amount to deposit (must be positive)
     * @throws std::invalid_argument if amount is not positive
     */
    void deposit(double amount) {
        // Input validation
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        
        // Modify account state
        balance_ += amount;
        
        // Record the transaction
        logTransaction("Deposit", amount);
    }

    /**
     * @brief Withdraws money from the account
     * @param amount The amount to withdraw (must be positive and <= balance)
     * @throws std::invalid_argument if amount is not positive
     * @throws std::runtime_error if insufficient funds
     */
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (amount > balance_) {
            throw std::runtime_error("Insufficient funds");
        }
        
        balance_ -= amount;
        logTransaction("Withdrawal", amount);
    }

    /**
     * @brief Transfers money to another account
     * @param toAccount The destination account
     * @param amount The amount to transfer
     * @note Uses withdraw() and deposit() to perform the operation
     */
    void transfer(BankAccount& toAccount, double amount) {
        // First withdraw from this account
        withdraw(amount);  // Could throw exceptions
        
        // Then deposit to the other account
        toAccount.deposit(amount);
        
        logTransaction("Transfer to " + toAccount.getAccountNumber(), amount);
    }

    // ========== GETTER FUNCTIONS ========== //
    // Provide read-only access to private members

    std::string getAccountHolder() const { return accountHolder_; }
    std::string getAccountNumber() const { return accountNumber_; }
    double getBalance() const { return balance_; }

    /**
     * @brief Displays account information
     * @note Uses getter functions to access private data
     */
    void displayAccountInfo() const {
        std::cout << "=== Account Information ===\n"
                  << "Holder: " << getAccountHolder() << "\n"
                  << "Number: " << getAccountNumber() << "\n"
                  << "Balance: $" << getBalance() << "\n"
                  << "==========================\n";
    }

private:
    // ========== PRIVATE DATA MEMBERS ========== //
    std::string accountHolder_;  // Name of account owner
    std::string accountNumber_; // Unique account ID
    double balance_;            // Current account balance

    /**
     * @brief Helper function to log transactions
     * @param type The type of transaction (Deposit/Withdrawal/Transfer)
     * @param amount The transaction amount
     * @note Private because it's an implementation detail
     */
    void logTransaction(const std::string& type, double amount) {
        std::cout << "[Transaction] " << type << " of $" << amount 
                  << " | New Balance: $" << balance_ << "\n";
    }
};

/**
 * @class Vector2D
 * @brief Represents a 2D vector with mathematical operations
 * 
 * Demonstrates:
 * - Mathematical operations as member functions
 * - Const-correctness
 * - Object composition through operations
 */
class Vector2D {
public:
    /**
     * @brief Constructor that requires both coordinates
     * @param x X-coordinate
     * @param y Y-coordinate
     */
    Vector2D(double x, double y) : x_(x), y_(y) {} //assigning the parameters

    // ========== VECTOR OPERATIONS ========== //

    /**
     * @brief Calculates the vector's magnitude (length)
     * @return The magnitude as a double
     * @note Marked const because it doesn't modify the object
     */
    double magnitude() const {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    /**
     * @brief Adds another vector to this one
     * @param other The vector to add
     * @return A new Vector2D representing the sum
     * @note Returns by value (new object)
     */
    Vector2D add(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    /**
     * @brief Scales the vector by a scalar value
     * @param scalar The scaling factor
     * @return A new scaled Vector2D
     */
    Vector2D scale(double scalar) const {
        return Vector2D(x_ * scalar, y_ * scalar);
    }

    /**
     * @brief Calculates the dot product with another vector
     * @param other The other vector
     * @return The dot product value
     */
    double dotProduct(const Vector2D& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }

    /**
     * @brief Displays vector information
     * @note Uses magnitude() to show vector length
     */
    void display() const {
        std::cout << "Vector (" << x_ << ", " << y_ << ")\n"
                  << "Magnitude: " << magnitude() << "\n";
    }

private:
    double x_; // X-coordinate
    double y_; // Y-coordinate
};

int main() {
    try {
        // ========== BANK ACCOUNT DEMONSTRATION ========== //
        std::cout << "==== BANK ACCOUNT EXAMPLE ====\n\n";
        
        // Create accounts with required parameters (no defaults)
        BankAccount aliceAccount("Alice Smith", "ACC123456", 1000.0);
        BankAccount bobAccount("Bob Johnson", "ACC654321", 500.0);

        // Demonstrate basic operations
        std::cout << "Initial operations:\n";
        aliceAccount.deposit(200.0);    // Adds to balance
        aliceAccount.withdraw(150.0);    // Subtracts from balance
        aliceAccount.transfer(bobAccount, 300.0); // Moves money between accounts

        // Show final state
        std::cout << "\nFinal Account Status:\n";
        aliceAccount.displayAccountInfo();
        bobAccount.displayAccountInfo();

        // ========== VECTOR DEMONSTRATION ========== //
        std::cout << "\n==== VECTOR EXAMPLE ====\n\n";
        
        // Create vectors with required coordinates
        Vector2D v1(3.0, 4.0);  // 3 units right, 4 units up
        Vector2D v2(1.0, 2.0);  // 1 unit right, 2 units up

        // Perform vector operations
        Vector2D v3 = v1.add(v2);    // Vector addition
        Vector2D v4 = v1.scale(2.0); // Scalar multiplication
        double dot = v1.dotProduct(v2); // Dot product

        // Display results
        std::cout << "Original vectors:\n";
        v1.display();
        v2.display();
        
        std::cout << "\nAfter addition:\n";
        v3.display();
        
        std::cout << "\nAfter scaling v1 by 2:\n";
        v4.display();
        
        std::cout << "\nDot product of v1 and v2: " << dot << "\n";

    } catch (const std::exception& e) {
        // Handle any exceptions thrown by our classes
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}