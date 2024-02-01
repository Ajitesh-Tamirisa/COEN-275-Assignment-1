#include <iostream>
#include <string.h>
using namespace std;

class Product{
    private:
        string productName;
        int productPrice;
        int numberOfSales;
    
    public:
        //Three parameter constructor
        Product(string pName, int tRevenue, int noOfSales) : productName(pName), productPrice(tRevenue/noOfSales), numberOfSales(noOfSales) {}
        
        //Modified two parameter constructor        
        //automatically sets the number of sales to 10
        Product(string pName, int pPrice):Product(pName, pPrice*10, 10){}

        //Copy constructor
        Product(Product& p) : productName(p.getProductName()), productPrice(p.getProductPrice()), numberOfSales(p.getNumberOfSales()){
            cout<<"Copy constructor called\n";
        };
        
        void setProductName(string pName){
            productName = pName;
        }

        string getProductName(){
            return productName;
        }

        void setProductPrice(int pPrice){
            productPrice = pPrice;
        }

        int getProductPrice(){
            return productPrice;
        }

        void setNumberOfSales(int noOfSales){
            numberOfSales = noOfSales;
        }

        int getNumberOfSales(){
            return numberOfSales;
        }

        //Assignment operator
        Product& operator=(Product& p)
        {
            if (this != &p) {
                productName = p.getProductName();
                productPrice = p.getProductPrice();
                numberOfSales = p.getNumberOfSales();
                cout << "Assignment operator called for product: " << productName <<endl;
            }
            return *this;
        }

        //Destructor
        ~Product() {
            cout << "\nDestructor executed"; 
        }
};

int main() {
    // Using the modified two-parameter constructor which in turn calls the new three parameter constructor
    Product laptop1("Macbook Pro M2", 1600);
    
    cout << "Product Name: " << laptop1.getProductName() <<endl;
    cout << "Price: " << laptop1.getProductPrice() <<endl;
    cout << "Number of Sales: " << laptop1.getNumberOfSales() <<endl;

    return 0;
}