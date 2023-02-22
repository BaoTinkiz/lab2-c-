#include <iostream>
using namespace std;

double inputValidate(double);
char userChoice(char);
double calculateTotalCharges(double, double);
double calculateTotalCharges(double, double, double, double);

int main()
{
    char user_choice; // 1 or 2

    double days_spent,
           daily_rate,
           med_charges,
           services_charge,
           total_charges;

    cout <<"Benh nhan la noi tru hay ngoai tru "<<endl
    	 <<"Bam 1 neu la noi tru hoac 2 neu la ngoai tru : ";
     
    user_choice = userChoice(user_choice);

    if (user_choice == '1')
    {
        cout << "Number of days spent in the hospital: ";
        days_spent = inputValidate(days_spent);

        cout << "Daily rate: $";
        daily_rate = inputValidate(daily_rate);

        cout << "Hospital medication charges: $";
        med_charges = inputValidate(med_charges);

        cout << "Charges for hospital services\n"
            << "(lab tests, etc.): $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(days_spent,
                                              daily_rate,
                                              med_charges,
                                              services_charge);
                        
        cout << "total_charges = $" 
            << total_charges
            << endl;
    }
    else
    {
        cout << "Hospital medication charges: $";
        med_charges = inputValidate(med_charges);

        cout << "Charges for hospital services\n"
            << "(lab tests, etc.): $";
        services_charge = inputValidate(services_charge);

        total_charges = calculateTotalCharges(med_charges,
                                              services_charge);

        cout << "total_charges = $" 
               << total_charges
               << endl;
    }
    

    return 0;
}

char userChoice(char letter)
{
    cin >> letter;
    // Error check algorithim
    while (!((letter == '1') || (letter == '2')))
    {
        // Explain error
        cout << "ERROR: enter 1 or 2: ";
        // Clear input stream
        cin.clear();
        // Discard previous input
     //   cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Receive input again
        cin >> letter;
    }
    return letter;
}

double inputValidate(double num)
{

    while(!(cin >> num) || num < 0)
    {
        cout << " Loi. So nhap vao khong duoc am.";
        cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>> num;
    }

    return num;
}

double calculateTotalCharges(double med_charges, 
                             double services_charge)
{
     return med_charges + services_charge;
}

double calculateTotalCharges(double days_spent, 
                             double daily_rate, 
                             double med_charges, 
                             double services_charge)
{
     return (days_spent * daily_rate) + med_charges + services_charge;
}
