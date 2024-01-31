#include <iostream>
#include <string.h>
using namespace std;

class Product{
    private:
        string productName;
        int productPrice;
        int numberOfSales;
    
    public:
        //Constructor
        Product(string pName, int pPrice) : productName(pName), productPrice(pPrice) {}
        
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
    // Using the two parameter constructor
    Product laptop1("Dell XPS 13", 1400);
    cout<<"Laptop 1 -\n";
    cout << "Product Name: " << laptop1.getProductName() << ", Price: " << laptop1.getProductPrice() <<endl;

    // Using copy constructor
    Product laptop2 = laptop1;
    cout<<"Laptop 2 -\n";
    cout << "Product Name: " << laptop2.getProductName() << ", Price: " << laptop2.getProductPrice() <<endl;


    Product phone1("iPhone 15", 1000.0);
    cout<<"Phone 1-\n";
    cout << "Product Name: " << phone1.getProductName() << ", Price: " << phone1.getProductPrice() <<endl;

    // Using assignment operator
    Product phone2("Pixel 8", 900.0);
    phone2 = phone1;
    cout<<"Phone 2-\n";
    cout << "Product Name: " << phone2.getProductName() << ", Price: " << phone2.getProductPrice() <<endl;

    return 0;
}