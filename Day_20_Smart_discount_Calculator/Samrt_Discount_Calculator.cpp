#include <iostream>
#include <iomanip>
using namespace std;

void smartDiscountFinder() {
    char again;

    do {
        cout << "\n=====================================\n";
        cout << "        SMART DISCOUNT FINDER \n";
        cout << "=====================================\n";

        double originalPrice, discountPercent, taxPercent;

        cout << "Enter the original price: ";
        cin >> originalPrice;

        cout << "Enter the discount percentage: ";
        cin >> discountPercent;

        double discountedPrice = originalPrice - ((discountPercent / 100) * originalPrice);
        double amountSaved = (discountPercent / 100) * originalPrice;

        cout << fixed << setprecision(2);
        cout << "\n----------------------------------\n";
        cout << "Original Price: $" << originalPrice << endl;
        cout << "Discount: " << discountPercent << "%" << endl;
        cout << "You Saved: $" << amountSaved << endl;
        cout << "Price After Discount: $" << discountedPrice << endl;
        cout << "----------------------------------\n";

        cout << "\nDo you want to add tax? (y/n): ";
        char taxChoice;
        cin >> taxChoice;

        if (taxChoice == 'y' || taxChoice == 'Y') {
            cout << "Enter tax percentage: ";
            cin >> taxPercent;
            double finalPrice = discountedPrice + ((taxPercent / 100) * discountedPrice);
            cout << "\nFinal Price after tax: $" << finalPrice << endl;
            cout << "----------------------------------\n";
        }

        cout << "\nDo you want to calculate another discount? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for using Smart Discount Finder!\n";
    cout << "=====================================\n";
}

int main() {
    smartDiscountFinder();
    return 0;
}
