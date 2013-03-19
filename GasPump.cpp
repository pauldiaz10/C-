// Paul Williams Diaz
// pauldiaz@my.smcc.edu
// CIS 278 C++ Methods
// Project 4 GasPump
// 03/11/13

#include "GasPump.h"
#include <iostream>

using namespace std;

//loads all pumps with 50 gallons, low price 2.00, med price 2.25,
//high price 2.50
GasPump::GasPump()
{
    highOctane = 50;
    medOctane = 50;
    lowOctane = 50;
    
    pricehigh = 2.50;
    pricemed = 2.25;
    pricelow = 2.00;
}

//prices are 2.00, 2.25, 2.50
GasPump::GasPump(int l, int m, int h)
{
    setHighGal(h);
    setMedGal(m);
    setLowGal(l);
    
    pricehigh = 2.50;
    pricemed = 2.25;
    pricelow = 2.00;
}

//loads all pumps w/50 gallons
GasPump::GasPump(double prl, double prm, double prh)
{
    highOctane = 50;
    medOctane = 50;
    lowOctane = 50;
    
    pricehigh = prh;
    pricemed = prm;
    pricelow = prl;
}
//set the quantity of gas in the indicated tank to parameter value
void GasPump::setHighGal(int gallons)
{
    if(gallons >= 1)
    {
        highOctane = gallons;
    }
    
    else
    {
        std::cout << "set High gallons Invalid.\n";
    }
}

//set the quantity of gas in the indicated tank to parameter value
void GasPump::setMedGal(int gallons)
{
    if(gallons >= 1)
    {
        medOctane = gallons;
    }
    
    else
    {
        std::cout << "set med gallons Invalid.\n";
    }
}

//set the quantity of gas in the indicated tank to parameter value
void GasPump::setLowGal(int gallons)
{
    if(gallons >= 1)
    {
        lowOctane = gallons;
    }
    
    else
    {
        std::cout << "set low gallons Invalid.\n";
    }
}

//sets the price of gas in the indicated tank to parameter value
void GasPump::setHighPrice(double price)
{
    if(price > 0.0)
    {
        pricehigh = price;
    }
    
    else
    {
        std::cout << "set High Price Invalid.\n";
    }
}

//sets the price of gas in the indicated tank to parameter value
void GasPump::setMedPrice(double price)
{
    if(price > 0.0)
    {
        pricemed = price;
    }
    
    else
    {
        std::cout << "Set Med Price Invalid.\n";
    }
}

//sets the price of gas in the indicated tank to parameter value
void GasPump::setLowPrice(double price)
{
    if(price > 0.0)
    {
        pricelow = price;
    }
    
    else
    {
        std::cout << "set Low Price Invalid.\n";
    }
}

//returns # gallons of high octane
int GasPump::getHigh() const
{
    return highOctane;
}

//returns # gallons of med octane
int GasPump::getMed() const
{
    return medOctane;
}

//returns # gallons of low octane
int GasPump::getLow() const
{
    return lowOctane;
}

//returns price for high octane
double GasPump::getPriceHigh() const
{
    return pricehigh;
}

//returns price for med octane
double GasPump::getPriceMed() const
{
    return pricemed;
}

//returns price for low octane
double GasPump::getPriceLow() const
{
    return pricelow;
}

//checks if high pump is empty
bool GasPump::emptyHigh() const
{
    bool empty = true;
    
    if(getHigh() <= 0)
    {
        empty = true;
    }
    
    else
    {
        empty = false;
    }
    
    return empty;
}

//checks if med pump is empty
bool GasPump::emptyMed() const
{
    bool empty = true;
    
    if(getMed() <= 0)
    {
        empty = true;
    }
    
    else
    {
        empty = false;
    }
    
    return empty;
}

//checks if low pump is empty
bool GasPump::emptyLow() const
{
    bool empty = true;
    
    if(getLow() <= 0)
    {
        empty = true;
    }
    
    else
    {
        empty = false;
    }
    
    return empty;
}

//purchase gal gallons of high octane, cost of this purchase is returned
double GasPump::salePriceHigh(int gal)
{
    std::cout.setf(ios::fixed);
    std::cout.setf(ios::showpoint);
    std::cout.precision(2);
    
    double costHigh;
    highOctane = getHigh() - gal;
    costHigh = gal * pricehigh;
    totalHigh = totalHigh + costHigh;
    
    return costHigh;
}

//purchase gal gallons of med octane, cost of this purchase is returned
double GasPump::salePriceMed(int gal)
{
    std::cout.setf(ios::fixed);
    std::cout.setf(ios::showpoint);
    std::cout.precision(2);
    
    double costMed;
    medOctane = getMed() - gal;
    costMed = gal * pricemed;
    totalMed = pricemed + costMed;
    
    return costMed;
}

//purchase gal gallons of low octane, cost of this purchase is returned
double GasPump::salePriceLow(int gal)
{
    std::cout.setf(ios::fixed);
    std::cout.setf(ios::showpoint);
    std::cout.precision(2);
    
    double costLow;
    lowOctane = getLow() - gal;
    costLow = gal * pricelow;
    totalLow = getLow() + costLow;
    
    return costLow;
}

//returns total earned so far for high octane
double GasPump::earnedHigh()
{
    return totalHigh;
}

//returns total earned so far for med octane
double GasPump::earnedMed()
{
    return totalMed;
}

//returns total earned so far for low octane
double GasPump::earnedLow()
{
    return totalLow;
}

// prints the amount of gas which remains in each of the three tanks, plus the
//amount of cash earned for low, medium and high grades respectively.
void GasPump::display(ostream& out) const
{
    out << "Gas Left           Total "
    << "\nHigh Octane: " << getHigh() << " gallons"
    << "\nMedium Octane: " << getMed() << " gallons"
    << "\nLow Octane: "<<  getLow() << " gallons" << endl;
}