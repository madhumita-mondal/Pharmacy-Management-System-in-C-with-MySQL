// Pharmacy Management System System CodeWithC

#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
using namespace std;

// Global Variable
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
// Global Variable End

class db_response
{
public:
    static void ConnectionFunction()
    {
        conn = mysql_init(0);
        if (conn)
        {
            cout << "Database Connected" << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
        conn = mysql_real_connect(conn, "localhost", "root", "", "cpp_pharmacymanagementsystem", 0, NULL, 0);
        if (conn)
        {
            cout << "Database Connected To MySql" << conn << endl;
            cout << "Press any key to continue..." << endl;
            // getch();
            system("cls");
        }
        else
            cout << "Failed To Connect!" << mysql_errno(conn) << endl;
    }
};

// Extra Functions CodeWithC
void Welcome() {
    cout << "Welcome To Pharmacy Management System" << endl << endl;
    cout << "Menu" << endl;
}

// Fucntions
void BuyMedicine();
void ShowItemList();
void FindItemFromList();
void AddIteminStock();
void UpdateStockItem();
void DeleteStockItem();

int main()
{
    // Initial Load
    system("cls");
    system("title Music Store Management Program");
    system("color 0f");
    // Initial Load End

    // Call Methods
    db_response::ConnectionFunction();
    // Call Methods End

    // Variables
    int chooseOneFromMenu = 0;
    char exitSurity;
    int num = 1;
    int fin = 0;
    // Variables End

    Welcome();
    for (int i = 0; i < 1; i++) {
        fin = num;
        cout << fin << ". Buy Medicine" << endl;
        fin += num;
        cout << fin << ". Show Item List" << endl;
        fin += num;
        cout << fin << ". Find Item From List" << endl;
        fin += num;
        cout << fin << ". Add Item in Stock" << endl;
        fin += num;
        cout << fin << ". Update Stock Item" << endl;
        fin += num;
        cout << fin << ". Delete Stock Item" << endl;
        fin += num;
        cout << fin << ". Exit" << endl;
        cout << "Choose One: ";
    }
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        BuyMedicine();
        break;
    case 2:
        ShowItemList();
        break;
    case 3:
        FindItemFromList();
        break;
    case 4:
        AddIteminStock();
        break;
    case 5:
        UpdateStockItem();
        break;
    case 6:
        DeleteStockItem();
        break;
    case 7:
        ExitProgram:
        cout << "Program terminating. Are you sure? (y/N): ";
        cin >> exitSurity;
        if (exitSurity == 'y' || exitSurity == 'Y') {
            return 0;
        }else if (exitSurity == 'n' || exitSurity == 'N') {
            system("cls");
            main();
        }else {
            cout << "Next time choose after read the corresponding line." << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 7. Press Enter To Continue...";
        getch();
        system("cls");
        main();
        break;
    }
    return 0;
}

// Function Implementation CodeWithC
void BuyMedicine() {
    system("cls");

    // Variables
    char choose;
    string getId = "";
    string itemId[5000];
    string itemName[5000];
    char chooseEditOrBuy;
    int itemIndex = 0;
    float totalPrice = 0.0;
    bool purchase, itemFalse = false;

    string storeid[5000];
    string storename[5000];
    string storecompany[5000];
    string storearrival_date[5000];
    string storeexpire_date[5000];
    string storeprice[5000];
    string storequantity[5000];
    int storeIndex = 0, storeIndexN = 0;
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from medicine_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", "Column Id", "Name", "Company", "Arrival Date", "Expire Date", "Price", "Quantity");
        printf("---------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            if (atoi(row[6]) > 0)
            {
                printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-5s | %-8s |\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);

                storeid[storeIndex] = row[0];
                storename[storeIndex] = row[1];
                storecompany[storeIndex] = row[2];
                storearrival_date[storeIndex] = row[3];
                storeexpire_date[storeIndex] = row[4];
                storeprice[storeIndex] = row[5];
                storequantity[storeIndex] = row[6];
                storeIndex++;
            }
        }
        printf("---------------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    for (itemIndex = 0;;itemIndex++)
    {
        cout << "Enter a Column ID's (q to exit): ";
        cin >> getId;
        if (getId == "q")
        {
            break;
        }
        else
        {
            for(int i = 0; i < storeIndex; i++)
            {
                if (getId == storeid[i])
                {
                    itemId[itemIndex] = getId;
                    itemFalse = false;
                    break;
                }
                else
                {
                    itemFalse = true;
                }
            }
            if (itemFalse == true)
            {
                cout << "Enter a valid number." << endl;
                itemIndex--;
                itemFalse = false;
            }
        }
    }

    cout << "You choose this item id's: ";
    for (int i = 0; i < itemIndex; i++)
    {
        cout << itemId[i] << " ";
    }

    CHOOSEEDITORBUY:
    cout << endl << "Do you want to edit items(e) or buy this items(b): ";
    cin >> chooseEditOrBuy;

    if (chooseEditOrBuy == 'e')
    {
        for (int i = 0;;i++)
        {
            cout << "Remove item id's (q to exit): ";
            cin >> getId;
            if (getId == "q")
            {
                break;
            }
            else
            {
                for (int j = 0;j < itemIndex;j++)
                {
                    if (itemId[j] == getId)
                    {
                        for (int k = j; k < itemIndex; k++)
                        {
                            itemId[k] = itemId[k+1];
                        }
                        itemId[itemIndex--] = "\0";
                    }
                }
            }
        }

        cout << "You choose this song id's: ";
        for (int i = 0; i < itemIndex; i++)
        {
            cout << itemId[i] << " ";
        }

        goto CHOOSEEDITORBUY;
    }
    else if (chooseEditOrBuy == 'b')
    {
        for (int i = 0; i < itemIndex; i++)
        {
            for (int j = 0; j < storeIndex; j++)
            {
                if (itemId[i] == storeid[j])
                {
                    qstate = mysql_query(conn, "select quantity from medicine_tb");
                    if (!qstate)
                    {
                        res = mysql_store_result(conn);
                        while ((row = mysql_fetch_row(res)))
                        {
                            if (atoi(row[0]) > 0)
                            {
                                storequantity[storeIndexN] = row[0];
                                storeIndexN++;
                            }
                        }
                        storeIndexN = 0;
                    }
                    else
                    {
                        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
                    }

                    totalPrice += strtof((storeprice[j]).c_str(), 0);

                    float quan1 = strtof((storequantity[j]).c_str(), 0);
                    quan1 -= 1;
                    float quan2 = strtof((storequantity[j]).c_str(), 0);
                    float quan = quan2 - quan1;
                    string getResult;
                    stringstream strquan;
                    strquan << quan;
                    strquan >> getResult;

                    string getQuan1;
                    stringstream strquan1;
                    strquan1 << quan1;
                    strquan1 >> getQuan1;

                    purchase = true;

                    string update_query = "update medicine_tb set quantity = '"+getQuan1+"' where id = '"+storeid[j]+"'";
                    const char* qu = update_query.c_str();
                    //cout << update_query << endl;

                    qstate = mysql_query(conn, qu);

                    if (qstate)
                    {
                        cout << "Failed To Update!" << mysql_errno(conn) << endl;
                    }
                }
            }
        }

        if(purchase == true)
        {
            cout << endl << "Purchase Successfully Done." << endl;
            cout << endl << "Total Price: " << totalPrice << endl;
        }
    }

    // Exit Code
    cout << endl << "Press 'm' to Menu, 'a' to purchase again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        BuyMedicine();
    }
    else
    {
        exit(0);
    }
}
void ShowItemList() {
    system("cls");

    // Variables
    char choose;
    string input;
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from medicine_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Name", "Company", "Arrival Date", "Expire Date", "Price", "Quantity");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else
    {
        exit(0);
    }
}
void FindItemFromList() {
     // Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string input = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Medicine Name: ";
    getline(cin, input);
    string findbyname_query = "select * from medicine_tb where name like '%"+input+"%'";
    const char* qn = findbyname_query.c_str();
    qstate = mysql_query(conn, qn);

    cout << endl;
    if (!qstate)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << "ID: " << row[0] << "Medicine Name: " << row[1] << "\nCompany Name: " << row[2] << "\nArrival Date: " << row[3] << "\nExpire Date: " << row[4] << "\nPrice: " << row[5] << "\nQuantity: " << row[6] << endl << endl;
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'm' to Menu, 'a' to Search again and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        FindItemFromList();
    }
    else
    {
        exit(0);
    }
}
void AddIteminStock(){
// Initial Load
    system("cls");
    // Initial Load End

    // Variables
    string name = "";
    string company = "";
    string arrival_date = "";
    string expire_date = "";
    string price = "";
    string quantity = "";
    char choose;
    // Variables End

    Welcome();
    cin.ignore(1, '\n');
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Company: ";
    getline(cin, company);
    cout << "Enter Arrival Date (dd-mm-yyyy): ";
    getline(cin, arrival_date);
    cout << "Enter Expire Date (dd-mm-yyyy): ";
    getline(cin, expire_date);
    cout << "Enter Price: ";
    getline(cin, price);
    cout << "Enter Quantity: ";
    getline(cin, quantity);

    string insert_query = "insert into medicine_tb (name, company, arrival_date, expire_date, price, quantity) values ('"+name+"','"+company+"',STR_TO_DATE('"+arrival_date+"', '%d-%m-%Y'),STR_TO_DATE('"+expire_date+"', '%d-%m-%Y'),'"+price+"','"+quantity+"')";

    const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

    qstate = mysql_query(conn, q);

    if (!qstate)
    {
        cout << endl << "Successfully added in database." << endl;
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    // Exit Code
    cout << "Press 'm' to Menu and 'a' to Insert Again Or Any Other key to exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'a' || choose == 'A')
    {
        AddIteminStock();
    }
    else
    {
        exit(0);
    }
}
void UpdateStockItem() {
system("cls");

    // Variables
    string name = "";
    string company = "";
    string arrival_date = "";
    string expire_date = "";
    string price = "";
    string quantity = "";
    string items[5000];
    char choose;
    int itemId;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForId = 0;

    // Store Variables
    string storeid = "";
    string storename = "";
    string storecompany = "";
    string storearrival_date = "";
    string storeexpire_date = "";
    string storeprice = "";
    string storequantity = "";
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from medicine_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-----------------------------------------------------------------------\n");
        printf("| %-10s | %-20s | %-10s | %-10s | %-5s |\n", "Column Id", "Name", "Arr. Date", "Exp. Date", "Price", "quantity");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-20s | %-10s | %-10s | %-5s |\n", row[0], row[1], row[3], row[4], row[5], row[6]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("-----------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string findbyid_query = "select * from medicine_tb where id = '"+strid+"'";
            const char* qi = findbyid_query.c_str();
            qstate = mysql_query(conn, qi);

            if (!qstate)
            {
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << "Column ID: " << row[0]
                         << "\nName: " << row[1]
                         << "\nCompany: " << row[2]
                         << "\nArrival Date: " << row[3]
                         << "\nExpire Date: " << row[4]
                         << "\nPrice: " << row[5]
                         << "\nQuantity: " << row[6]
                         << endl << endl;

                    storeid = row[0];
                    storename = row[1];
                    storecompany = row[2];
                    storearrival_date = row[3];
                    storeexpire_date = row[4];
                    storeprice = row[5];
                    storequantity = row[6];

                }
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
            }

            cin.ignore(1, '\n');
            string defaultString = "xN";
            cout << "Enter Name (" << defaultString << "  to not change): ";
            getline(cin, name);
            if (name == defaultString)
            {
                name = storename;
            }
            cout << "Enter Company (" << defaultString << "  to not change): ";
            getline(cin, company);
            if (company == defaultString)
            {
                company = storecompany;
            }
            cout << "Enter Arrival Date (" << defaultString << "  to not change) (yyyy-mm-dd): ";
            getline(cin, arrival_date);
            if (arrival_date == defaultString)
            {
                arrival_date = storearrival_date;
            }
            cout << "Enter Expire Date (" << defaultString << "  to not change) (yyyy-mm-dd): ";
            getline(cin, expire_date);
            if (expire_date == defaultString)
            {
                expire_date = storeexpire_date;
            }
            cout << "Enter Price (" << defaultString << "  to not change): ";
            getline(cin, price);
            if (price == defaultString)
            {
                price = storeprice;
            }
            cout << "Enter Quantity (" << defaultString << "  to not change): ";
            cin >> quantity;
            if (quantity == defaultString)
            {
                 quantity = storequantity;
            }

            string update_query = "update medicine_tb set name = '"+name+"', company = '"+company+"', arrival_date = '"+arrival_date+"', expire_date = '"+expire_date+"', price = '"+price+"', quantity = '"+quantity+"' where id = '"+strid+"'";
            const char* qu = update_query.c_str();
            qstate = mysql_query(conn, qu);

            if (!qstate)
            {
                cout << endl << "Successfully Updated." << endl;
            }
            else
            {
                cout << "Failed To Update!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    ExitMenu:
    cout << "Press 'm' to Menu, 'e' to edit another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'e' || choose == 'E')
    {
        UpdateStockItem();
    }
    else
    {
        exit(0);
    }
}
void DeleteStockItem() {
    system("cls");

    // Variables
    char choose;
    int itemId;
    string items[5000];
    int indexForId = 0;
    bool HaveException = false, NotInDatabase = false;
    // Variables End

    Welcome();
    qstate = mysql_query(conn, "select * from medicine_tb");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("----------------------------------------------------------\n");
        printf("| %-10s | %-15s | %-10s | %-10s |\n", "Column Id", "Name", "Price", "Quantity");
        printf("----------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-10s | %-15s | %-10s | %-10s |\n", row[0], row[1], row[5], row[6]);
            items[indexForId] = row[0];
            indexForId++;
        }
        printf("----------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    try
    {
        cout << endl;
        cout << "Enter Item ID: ";
        cin >> itemId;
        cout << endl;
    }
    catch (exception e)
    {
        cout << "Please Enter a valid NUMBER." << endl;
        HaveException = true;
        goto ExitMenu;
    }

    if (HaveException == false)
    {
        stringstream streamid;
        string strid;
        streamid << itemId;
        streamid >> strid;

        for (int i = 0; i < indexForId; i++)
        {
            if (strid != items[i])
            {
                NotInDatabase = true;
            }else
            {
                NotInDatabase = false;
                break;
            }
        }

        if (NotInDatabase == false)
        {
            string delete_query = "delete from medicine_tb where id = '"+strid+"'";
            const char* qd = delete_query.c_str();
            qstate = mysql_query(conn, qd);

            if (!qstate)
            {
                cout << "Successfully Deleted." << endl;
            }
            else
            {
                cout << "Failed To Delete!" << mysql_errno(conn) << endl;
            }

        }
        else
        {
            cout << "Item Not Found in database." << endl;
        }
    }

    // Exit Code
    ExitMenu:
    cout << "Press 'm' to Menu, 'd' to delete another item and any other key to Exit: ";
    cin >> choose;
    if (choose == 'm' || choose == 'M')
    {
        main();
    }
    else if (choose == 'd' || choose == 'D')
    {
        DeleteStockItem();
    }
    else
    {
        exit(0);
    }
}


















