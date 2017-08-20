// Paul Williams Diaz
// pauldiaz@my.smcc.edu
// CIS 278 C++ Methods
// Project 4 GasPump
// 03/11/13

#include <iostream>
using namespace std;

class GasPump
{
private:
    int highOctane, medOctane, lowOctane;
    double pricehigh, pricemed, pricelow;
    double totalHigh, totalMed, totalLow;
    
public:
    //loads all pumps with 50 gallons, low price 2.00, med price 2.25,
    //high price 2.50
    GasPump();
    //prices are 2.00, 2.25, 2.50
    GasPump(int l = 100, int m = 100, int h = 100);
    //loads all pumps w/50 gallons
    GasPump(double prl, double prm, double prh);
    
    //set the quantity of gas in the indicated tank to parameter value
    void setHighGal(int gallons);
    //set the quantity of gas in the indicated tank to parameter value
    void setMedGal(int gallons);    
    //set the quantity of gas in the indicated tank to parameter value
    void setLowGal(int gallons);
    
    //sets the price of gas in the indicated tank to parameter value
    void setHighPrice(double price);
    //sets the price of gas in the indicated tank to parameter value
    void setMedPrice(double price);
    //sets the price of gas in the indicated tank to parameter value
    void setLowPrice(double price);
    
    //returns # gallons of high octane
    int getHigh() const;
    //returns  # gallons of med octane
    int getMed() const;
    //returns  # gallons of low octane
    int getLow() const;
    
    //returns price for high octane
    double getPriceHigh() const;
    //returns price for med octane
    double getPriceMed() const;
    //returns price for low octane
    double getPriceLow() const;
    
    //is high octane empty?
    bool emptyHigh() const;
    //is medium octane empty?
    bool emptyMed() const;
    //is low octane empty?
    bool emptyLow() const;
    
    //purchase gal gallons of high octane, cost of this purchase is returned
    double salePriceHigh(int gal);
    //purchase gal gallons of medium octane, cost of this purchase is returned
    double salePriceMed(int gal);
    //purchase gal gallons of low octane, cost of this purchase is returned
    double salePriceLow(int gal);
    
    // returns total earned so far for high octane
    double earnedHigh();
    // returns total earned so far for med octane
    double earnedMed();
    // returns total earned so far for low octane
    double earnedLow();
    
    // prints the amount of gas which remains in each of the three tanks, plus the
    //amount of cash earned for low, medium and high grades respectively.
    void display(ostream& out) const;
};