// Paul Williams Diaz
// pauldiaz@my.smcc.edu
// CIS 278 C++ Methods
// Project 4 GasPump
// 03/11/13

#include <iostream>
#include "GasPump.h"
using namespace std;

int main()
{
    GasPump  gas;
    int set, gas1, gas2 = 0;
    double gas1P, gas2P, gas3P = 0;
    int gasNum1, gasNum2, gasNum3 = 0;
    int choice, case3Choice = 0;
    int galPurchase = 0;
    
    do
    {
        std::cout << "Enter 1 to set initial gallons."
                  << "\nEnter 2 to set the price: "
                  << "\nEnter 0 to proceed further: ";
        std::cin >> set;
        
        switch(set)
        {
            case 1:
                std::cout << "\nEnter 1 for High Octane."
                          << "\nEnter 2 for Medium Octane"
                          << "\nEnter 3 for Low Octane: ";
                std::cin >> gas1;
                
                if(gas1 == 1)
                {
                    std::cout << "\nEnter amount of gas to fill in for High Octane (in gallons): ";
                    std::cin >> gasNum1;
                    gas.setHighGal(gasNum1);
                    std::cout << "\n";
                }
                if(gas1 == 2)
                {
                    std::cout << "\nEnter amount of gas to fill in for Medium Octane (in gallons): ";
                    std::cin >> gasNum2;
                    gas.setMedGal(gasNum2);
                    std::cout << "\n";
                }
                if(gas1 == 3)
                {
                    std::cout << "\nEnter amount of gas to fill in for Low Octane (in gallons): ";
                    std::cin >> gasNum3;
                    gas.setLowGal(gasNum3);
                    std::cout << "\n";
                }
            
            break;
                
            case 2:
                std::cout << "\nEnter 1 for High Octane."
                << "\nEnter 2 for Medium Octane"
                << "\nEnter 3 for Low Octane: ";
                std::cin >> gas2;
                
                if(gas2 == 1)
                {
                    std::cout << "\nEnter new price for High Octane: $";
                    std::cin >> gas1P;
                    gas.setHighPrice(gas1P);
                    std::cout << "\n";
                    
                }
                
                if(gas2 == 2)
                {
                    std::cout << "\nEnter new price for Medium Octane: $";
                    std::cin >> gas2P;
                    gas.setMedPrice(gas2P);
                    std::cout << "\n";
                }
                
                if(gas2 == 3)
                {
                    std::cout << "\nEnter new price for Low Octane: $";
                    std::cin >> gas3P;
                    gas.setLowPrice(gas3P);
                    std::cout << "\n";
                }
                break;
                
            default:
                std::cout << "\n";
                break;
        }
        
    }while(set != 0);
    
    
    do{
        std::cout << "Enter 1 to purchase a gas.\n"
                  << "Enter 2 to check how much gas left.\n"
                  << "Enter 3 to check cash earned.\n"
                  << "Enter 0 to exit:  ";
        std::cin >> choice;
    
        switch(choice)
        {
            
            case 1:
                std::cout << "\nEnter 1 for high octane.\n"
                          << "Enter 2 for medium octane.\n"
                          << "Enter 3 for low octane: ";
                std::cin >> case3Choice;
            
                if(case3Choice == 1)
                {
                    std::cout << "\nPrice for High Octane: $" << gas.getPriceHigh() << endl;
                    
                    std::cout << "\nEnter number of gallons to be purchased: ";
                    std::cin >> galPurchase;
                
                    if(gas.emptyHigh())
                    {
                        std::cout << "\nSorry, High octane is empty.\n"
                                  << "\n";
                    }
                    
                    else if(galPurchase > gas.getHigh())
                    {
                        std::cout << "\nNumber of gallons you entered is higher than the gas available.\n";
                        std::cout << "Machine will dispense " << gas.getHigh() << " gallons - gas available\n";
                        std::cout << "\nTotal cost - High Octane: $" << gas.salePriceHigh(gas.getHigh())
                                  << "\n" << endl;
                    }
                    else
                    {
                        std::cout << "Total cost - High Octane: $" << gas.salePriceHigh(galPurchase)<< endl;
                        std::cout << "\n";
                    }
                }
            
                if(case3Choice == 2)
                {
                    std::cout << "\nPrice for Medium Octane: $" << gas.getPriceMed() << endl;
                    
                    std::cout << "\nEnter number of gallons to be purchased: ";
                    std::cin >> galPurchase;
                    
                    if(gas.emptyMed())
                    {
                        std::cout << "\nSorry, Medium Octane is empty.\n"
                                  << "\n";
                    }
                    
                    else if(galPurchase > gas.getMed())
                    {
                        std::cout << "\nNumber of gallons you entered is higher than the gas available.\n";
                        std::cout << "Machine will dispense " << gas.getMed() << " gallons - gas available\n";
                        std::cout << "Total cost - Medium Octane: $" << gas.salePriceMed(gas.getMed())<< endl;
                        std::cout << "\n";
                    }
                    
                    else
                    {
                        std::cout << "Total cost - Medium Octane: $" << gas.salePriceMed(galPurchase)<< endl;
                        std::cout << "\n";
                    }
                }
            
                if(case3Choice == 3)
                {
                    std::cout << "\nPrice for Low Octane: $" << gas.getPriceLow() << endl;
                    
                    std::cout << "\nEnter number of gallons to be purchased: ";
                    std::cin >> galPurchase;
                    
                    if(gas.emptyLow())
                    {
                        std::cout << "\nSorry, Low Octane is empty.\n"
                                  << "\n";
                    }
                    
                    else if(galPurchase > gas.getLow())
                    {
                        std::cout << "\nNumber of gallons you entered is higher than the gas available.\n";
                        std::cout << "Machine will dispense " << gas.getLow() << " gallons - gas available\n";
                        std::cout << "Total cost - Low Octane: $" << gas.salePriceLow(gas.getLow())<< endl;
                        std::cout << "\n";
                    }
                    
                    else
                    {
                        std::cout << "Total cost - Low Octane: $" << gas.salePriceLow(galPurchase)<< endl;
                        std::cout << "\n";
                    }
                
                }
                break;
            
            case 2:
                std::cout << "\n                Gas Left\n";
                std::cout << "\nGas left for High Octane: "<< gas.getHigh() << " gallons";
                std::cout << "\nGas left for Med Octane:  "<< gas.getMed() << " gallons";
                std::cout << "\nGas left for Low Octane:  "<< gas.getLow() << " gallons";
                std::cout << "\n\n";
                break;
            
            case 3:
                gas.display(cout);
                break;
            }
        
        }while(choice != 0);
    
    //std::cout <<
    std::cout << "\nThank you.\nProgrammed by: Paul Diaz";
  
    return 0;
}

