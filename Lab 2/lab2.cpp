#include <iostream>
#include <string>

using namespace std;

class BankAccount {

private:

    string name,iban,address;
    double sum;


public:

    BankAccount(string nm, string ib, string ad, double mon) {
        name = nm;
        iban = ib;
        address = ad;
        sum = mon;
    }
    BankAccount() {}

    void displayBalance() {

        cout << "Current Bank Account Balance: " << sum << "$\n";
    }

    void displayOwner() {
        cout << "Name: " << name << ", IBAN: " << iban << " , Address: " << address << "\n";
    }

    void withdraw(double amount) {

        if (sum < amount) {
            cout << "Insufficient Balance To Withdraw: " << amount << "$\n";
            return;
        }
        sum -= amount;
        cout << "Successful Withdrawal: " << amount << "$\n";
    }

    void deposit(double amount) {

        sum += amount;
        cout << "Successfully Deposited: " << amount << "$\n";
    }

};

class Point {

private:

    int coordX, coordY;

public:

    Point() {}
    Point(int x, int y) {

        coordX = x;
        coordY = y;
    }

    void reset(string pointName) {
        cout << "Resetting " << pointName  << " to (0,0)\n";
        coordX = coordY = 0;
    }

    int getX() {
        return coordX;
    }
    int getY() {
        return coordY;
    }

    void moveX(int x) {
        cout << "Moving point on x-axis  " << x << " units\n";
        coordX += x;
    }

    void moveY(int y) {
        cout << "Moving point on y-axis " << y << " units\n";
        coordY += y;
    }

    void moveXY(int x, int y) {

        cout << "Moving point  (" << x << ", " << y << ") units\n";

        coordX += x;
        coordY += y;
    }

    void display(string pointName) {

        cout << "Displaying " << pointName << ": (" << coordX << ", " << coordY << ")\n";
    }
    ~Point() {

    }
};

class Complex {

private: 

    double re;
    double im;

public:
    Complex() {}

    Complex(double reN, double imN) {
        re = reN;
        im = imN;
    }
    void displayNum() {

        if (im == 0 && re == 0) {

            cout << "0 \n";
        }
        else if (im == 1 && re == 0) {

            cout << "i\n";
        }
        else if (im == -1 && re == 0) {

            cout << "-i\n";

        }
        else if (im == 1 && re != 0) {

            cout << re << " + i\n";
        }
        else if (im == -1 && re != 0) {

            cout << re << " -i\n";
        }
        else if (im == 0 && re != 0) {
            cout << re << "\n";
        }
        else {

            cout << re << " + " << im << "i" << "\n";
        }
    }
    void addNum(Complex n2) {

        re = re + n2.getRe();
        im = im + n2.getIm();

    }

    double getRe() {

        return re;
    }

    double getIm() {

        return im;
    }

    void multNum(Complex n2) {

        double re2 = n2.getRe();
        double im2 = n2.getIm();
        double re1 = re;
        double im1 = im;

        re = (re1 * re2) - (im1 * im2);
        im = (im1 * re2) + (re1 * im2);

    }

    void conjugate() {

        im = im * -1;
    }

    ~Complex()
    {
        //dtor
    }
};

bool isLeap(int y) {
    
    if (y % 400 == 0) {
        return true;
    }
    
    else if (y % 100 == 0) {
        return false;
    }
    
    else if (y % 4 == 0) {
        return true;
    }
    
    else {
        return false;
    }
}

struct Date {

    int day;
    int month;
    int year;

    void display() {

        cout << day << "/" << month << "/" << year << "\n";
    }

    void isValid() {

        if (year <= 0) {
            cout << "It is not a valid date.\n";
            return;
        }

        if (month == 2) {
            if (isLeap(year) && day <= 29) {
                cout << "It is a valid date\n";
            }
            else if (!isLeap(year) && day >= 29) {
                cout << "It isn't a valid date\n";
            }
            else if (isLeap(year) && day > 29) {
                cout << "It is not a valid date\n";
            }
            else {
                cout << "It is a valid date\n";
            }
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {

            if (day > 31 || day <= 0) {
                cout << "It is not a valid date.\n";

            }
            else {
                cout << "It is a valid date.\n";
            }

        }
        else {

            if (day > 30 || day <= 0) {
                cout << "It is not a valid date.\n";
            }
            else {
                cout << "It is a valid date.\n";
            }
        }
    }

};

void exercise1() {

    

    Date d1;
    cout << "Enter a date [DD MM YYYY]";
    cin >> d1.day >> d1.month >> d1.year;

    d1.display();
    d1.isValid();
    
}

void exercise2() {

  

    Complex num3(9, 0);
    cout << "Displaying Complex Number 3: ";
    num3.multNum(Complex(1.0, 1.0));
    num3.displayNum();


    cout << "Conjugating num3:";
    num3.conjugate();
    num3.displayNum();

    cout << "Result of:  (2 + 3i) x (4 + 2i)\n";

    Complex num4(2, 3);
    Complex num5(4, 2);

    num4.multNum(num5);
    num4.displayNum();
}

void exercise3() {

    Point p1(1,3);
    
    p1.display("Point 1");

    p1.moveXY(4, 6);
    p1.display("Point 1");

    
    p1.moveX(8);
    p1.display("Point 1");

   
    p1.moveY(0);
    p1.display("Point 1");

   
    p1.reset("Point 1");
    p1.display("Point 1");
}

void extraExercise() {
    BankAccount account1("Mario","BTRO03134123", "Strada Alexandru Vlahuta nr 4", 9500.);

    account1.displayOwner();

    account1.withdraw(8000.0);
    account1.displayBalance();
    account1.deposit(1000);
    account1.displayBalance();
    account1.withdraw(4000.4);
    account1.displayBalance();
   
}

int main()
{

    cout << "\nEXERCISE 1:\n";
    exercise1();

    cout << "\nEXERCISE 2:\n";
    exercise2();

    cout << "\nEXERCISE 3:\n";
    exercise3();


    cout << "\nEXTRA EXERCISE:\n";
    extraExercise();
   
} 