class Bank {
private:
    vector<long long> accountBalances;  
    int totalAccounts;                  
  
public:
    
    Bank(vector<long long>& balance) {
        accountBalances = balance;
        totalAccounts = balance.size();
    }
  
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > totalAccounts || 
            account2 < 1 || account2 > totalAccounts || 
            accountBalances[account1 - 1] < money) {
            return false;
        }
      
        accountBalances[account1 - 1] -= money;
        accountBalances[account2 - 1] += money;
        return true;
    }
  
   
    bool deposit(int account, long long money) {
        if (account < 1 || account > totalAccounts) {
            return false;
        }
      
        accountBalances[account - 1] += money;
        return true;
    }
  
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > totalAccounts || 
            accountBalances[account - 1] < money) {
            return false;
        }
      
        accountBalances[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */