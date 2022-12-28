# Pharmacy-Management-System-in-C++ with-MySQL

![image](https://user-images.githubusercontent.com/48853024/209747423-69ec1b71-7dd0-492d-b60a-53e55ec314e7.png)

This C++ program is a pharmacy management system can store the medicine information and create purchase and generate total amount of purchase.
![image](https://user-images.githubusercontent.com/48853024/209743135-084436a1-04e9-45d2-bb03-7eab70f73778.png)
Global variables used in Pharmacy Management System in C++ with MySQL


- qstate represent the state of the query. If 0 is successful 1 is failed.
- conn is the mysql connection variable.
- row is for getting the current row of the database.
- res is for getting all the values form the database.

![image](https://user-images.githubusercontent.com/48853024/209743295-c5aefbd7-774a-408b-9608-5552c4a4b7b3.png)


![image](https://user-images.githubusercontent.com/48853024/209743388-d56a5d78-27bf-42ae-95f6-e388f214446f.png)

# Class db_response

- This class contains connection of the database.
- mysql_init is the initializer of mysql_real_connect
- mysql_real_connect connects to the database. (MySql server should open while connecting)
- the if statement shows the successful or failed connection.

![image](https://user-images.githubusercontent.com/48853024/209743593-18e729d9-f718-4e39-920b-ccb5505fdfce.png)


![image](https://user-images.githubusercontent.com/48853024/209743661-9367a933-483d-4505-b6a3-dc6e8a59ff92.png)

# Function main Pharmacy Management System in C++ with MySQL
- Here firstly the clear screen command then the title command and the color command.
- db_response::ConnectionFunction() is create the connection to the database.
- The program features
  - Buy Medicine
  - Show Item List
  - Find Item From List
  - Add Item in Stock
  - Update Stock Item
  - Delete Stock Item


![image](https://user-images.githubusercontent.com/48853024/209744003-bc415be1-a731-43b6-a33c-c473fe34d953.png)
- The switch case is used for switching between this functions
   - BuyMedicine()
   - ShowItemList()
   - FindItemFromList()
   - AddIteminStock()
   - UpdateStockItem()
   - DeleteStockItem()


![image](https://user-images.githubusercontent.com/48853024/209744243-10d26713-c824-4bd0-87a0-90a322242f9a.png)
# Function BuyMedicine ()
- This function is for the customer in Pharmacy Management System
- If the customer wants to buy medicine the seller can easily make a list of medicine and create a total bill of the medicines.
- Here all the medicine in the list will showing in the console
- Seller can choose medicines more than ones
- Simple “Select” query get all the medicine from the list
- Then after validation of ids the total number of medicine will decrease after all purchase
- And update the database
- As well as show the total amount of purchased medicine

# Function ShowItemList ()
- Showing all the items in the database in Pharmacy Management System
- “Select” query will get all the data from the database
- And display in the console

![image](https://user-images.githubusercontent.com/48853024/209744837-6038a82f-9e29-48f1-96df-126913616d7f.png)
# Function FindItemFromList ()
- User can find item from the list in Pharmacy Management System
- Only with few characters of the name of the item the program can find all the similar product
- And display all the information in the console


![image](https://user-images.githubusercontent.com/48853024/209744944-32c9b5e3-4c51-4756-aabc-0f0db791647f.png)
# Function AddIteminStock ()
- User can add new medicine with this function
- “Insert” query is used for add item in the database
- User can fill all the information of the medicine
- Then the information’s are added in the database

![image](https://user-images.githubusercontent.com/48853024/209745083-ff5b846e-9a25-47a4-b21f-fbfefb678c25.png)

# Function UpdateStockItem ()
- If the user wants to update any information of the item in the list then this is the function
- “Update” query is used to update the database information.
- User can keep the old data in the database by typing simple keyword “xN”
- Then the database will update the information
- It can validate the given number and show proper message in the console

![image](https://user-images.githubusercontent.com/48853024/209745260-29e2ff0b-c050-48b7-afa6-7b5cdb502592.png)

# Database and Table Name used in Pharmacy Management System

Table: medicine_tb
Database: cpp_pharmacymanagementsystem

# Usage
# XAMPP Server, MySql Headers, MySql Libs

![image](https://user-images.githubusercontent.com/48853024/209745502-f8218e63-465c-4242-8a59-45dbe003539b.png)


