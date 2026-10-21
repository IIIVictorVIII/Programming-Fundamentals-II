//Victor Villarreal
//in this program it initializes with the original values given. The user can enter a menu choice
//that can add,delete, or edit items.  
//Last changes: 10/20/2026


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Define the struct with at least five members
struct inventory_item {
    string name;         // 1. Name of the item
    int id;              // 2. Unique ID number
    int quantity;        // 3. Current stock level
    double price;        // 4. Unit price
    string category;     // 5. Product category
};



void projectStartingItems(ofstream& outfile);

int get_menu_choice();
void changePrice(inventory_item list[],int itemnums);
void deleteItem(inventory_item list[], int& itemnums);
void changestock(inventory_item list[], int itemnums);
void addNewItem(inventory_item list[], int& itemnums);
void readinfile(inventory_item list[], ifstream& infile, int& itemnum);
void printitems(inventory_item list[], int itemnums);


int main(){

    ifstream infile;
    ofstream outfile;
    inventory_item items[100] = {};

    int choice;
    int itemnum = 0;


    cout << fixed << setprecision(2);

    //initialize file with starting values.
    outfile.open("C:\\Users\\Owner\\OneDrive\\Desktop\\records1.txt");
    projectStartingItems(outfile);
    
    infile.open("C:\\Users\\Owner\\OneDrive\\Desktop\\records1.txt");
    readinfile(items, infile, itemnum);
    
    cout << "--- Inventory Records ---\n\n";
    printitems(items, itemnum);
    choice = get_menu_choice();

    while (choice != 5) {

        if (choice == 1)
            changePrice(items, itemnum);

        else if (choice == 2)
            changestock(items, itemnum);

        else if (choice == 3)
            deleteItem(items, itemnum);

        else if (choice == 4)
            addNewItem(items, itemnum);

        
        cout << "--- Inventory Records ---\n\n";
        printitems(items, itemnum);
        choice = get_menu_choice();
    }
    return 0;
}


void readinfile(inventory_item list[], ifstream& infile, int& itemnum) {
    
    string line;
    itemnum = 0;

    while (itemnum < 100 && getline(infile, list[itemnum].name)) {
       
        getline(infile, line);
        list[itemnum].id = stoi(line);

        getline(infile, list[itemnum].category);

        getline(infile, line);
        list[itemnum].quantity = stoi(line);

        getline(infile, line);
        list[itemnum].price = stod(line);

        getline(infile, line);

        itemnum++;
    }
    infile.close();
}
void printitems(inventory_item list[],int itemnums) {

    
    for (int i = 0; i < itemnums; i++) {

        cout << "Item "<<i+1<< ": " << list[i].name << "\n";
        cout << "ID: " << list[i].id << " | Category: " << list[i].category << "\n";
        cout << "Quantity: " << list[i].quantity << " | Price: $" << list[i].price << "\n\n";
        
    }

}

// going to intialize the file with items given from assignment
// will be able to delete these later. 
void projectStartingItems(ofstream& outfile) {


    // Create three records based on the inventory_item structure
    inventory_item item1 = { "Potting Soil (Bag)", 101, 50, 6.99, "Gardening Item" };
    inventory_item item2 = { "Drill", 102, 15, 89.50, "Power Tools" };
    inventory_item item3 = { "Nails (Box)", 103, 200, 5.25, "Hardware" };

    // Set formatting for decimal prices
    outfile << fixed << setprecision(2);

    // Output data from each structure to the screen
    

    // Item 1
    outfile << item1.name << "\n";
    outfile << item1.id << "\n";
    outfile << item1.category << "\n";
    outfile << item1.quantity << "\n";
    outfile << item1.price << "\n\n";

    // Item 2
    outfile << item2.name << "\n";
    outfile << item2.id << "\n";
    outfile << item2.category << "\n";
    outfile << item2.quantity << "\n";
    outfile << item2.price << "\n\n";

    // Item 3
    outfile << item3.name << "\n";
    outfile << item3.id << "\n";
    outfile << item3.category << "\n";
    outfile << item3.quantity << "\n";
    outfile << item3.price << "\n\n";

    outfile.close();

}

int get_menu_choice() {

    int userChoice;

    cout << "--------main-menu--------" << endl;
    cout << "(1) Change item Price" << endl;
    cout << "(2) Change item stock level" << endl;
    cout << "(3) Delete item from inventory" << endl;
    cout << "(4) Add new item to inventory" << endl;
    cout << "(5) quit" << endl;

    cout << "Enter menu Choice: ";
    cin >> userChoice;  

    while (userChoice < 1 || userChoice > 5 ) {

        cout << "Invalid choice" << endl;
        cout << "Enter new choice: ";
        cin >> userChoice;
       
    
    }

    return userChoice;
}

void changePrice(inventory_item list[], int itemnums) {

    int listnumber;
    double itemprice;
    cout<<"Enter item  number to change: ";
    cin >> listnumber;
    
    
    while (listnumber > itemnums || listnumber < 1){
        cout << "out of bounds" << endl;
        cout << "enter new item number: ";
        cin >> listnumber ;
    }
    
    cout << "Enter new price for "<<list[listnumber - 1].name<<": ";
    cin >> itemprice;

    list[listnumber-1].price = itemprice;
    cout << endl;
    cout << endl;


}

void changestock(inventory_item list[], int itemnums) {
    
    int listnumber;
    int itemstock;
    cout << "Enter item number to change: ";
    cin >> listnumber;


    while (listnumber > itemnums || listnumber < 1) {
        cout << "out of bounds" << endl;
        cout << "enter new item number: ";
        cin >> listnumber;
    }

    
    cout << "Enter updated stock level: ";
    cin >> itemstock;

    while (itemstock < 0) {
        cout << "negatives not allowed" << endl;
        cout << "Enter updated stock level: ";
        cin >> itemstock;
    }

    list[listnumber - 1].quantity = itemstock;

}
void deleteItem(inventory_item list[], int& itemnums){

    int listnumber;
    char response;
    cout << "Enter item list number to delete: ";
    cin >> listnumber;

    while (listnumber > itemnums || listnumber < 1) {
        cout << "out of bounds" << endl;
        cout << "enter new list number: ";
        cin >> listnumber;
    }

    cout << "are you sure?: ";
    cin >> response;
    
    if (response == 'y' || response == 'Y') {

        cout << "deleting...\n";
        for (int i = listnumber - 1; i < itemnums - 1; i++)
            list[i] = list[i + 1];

        itemnums--;
    }
    else
        cout << "did not delete.\n";
    
}
void addNewItem(inventory_item list[], int& itemnums){


    int id;
    int quantity;
    double price;
    char response = 'y';
    
    while (response == 'y' || response == 'Y'){
        cout << "-------Enter information for new item------- " << endl;

        cin.ignore();
        cout << "item name: ";
        getline(cin, list[itemnums].name);
        cout << endl;
        
        
        cout << "item id: ";
        cin >> id;
        cout << endl;
        while (id < 0) {
            cout << "invalid id number" << endl;
            cout << "Enter valid id: ";
            cin >> id;
            cout << endl;
        }
        list[itemnums ].id = id;

        cout << "item stock level: ";
        cin >> quantity;
        cout << endl;
        while (quantity < 0) {
            cout << "invalid stock level" << endl;
            cout << "Enter valid stock level: ";
            cin >> quantity;
            cout << endl;
        }
        list[itemnums].quantity = quantity;

        cout << "item price: ";
        cin >> price;
        cout << endl;
        while (price < 0) {
            cout << "invalid price" << endl;
            cout << "Enter valid item price: ";
            cin >> price;
            cout << endl;
        }
        list[itemnums].price = price;

        cin.ignore();
        cout << "item category: ";
        getline(cin, list[itemnums].category);
        cout << endl;
        

        itemnums++;

        cout << "would you like to add additional items? (y/n): ";
        cin >> response;
    }
    cout << "new entries added!\n";
}
