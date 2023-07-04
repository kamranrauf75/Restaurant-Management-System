# Restaurant System

This project implements a restaurant system using structs and provides functionality for both customers and the owner. The program displays a main menu where users can choose between customer mode and owner mode, or exit the program.

## Customer Mode

In customer mode, the following options are available:

1. New Customer: Allows a new customer to enter their name and select a seat from the available seats in the restaurant. The customer menu is then displayed.
2. Current Customer: Allows a customer who is already seated to enter their name. If the customer is present in any of the seats, the customer menu is displayed.

### Customer Menu

The customer menu provides the following options:

1. View Food Menu: Displays the current menu of the restaurant, including dish names and prices.
2. Place Order: Allows the customer to place an order by entering the serial number of the desired food item.
3. View Order: Displays the name of the food item ordered by the customer.
4. Pay Bill: Enables the customer to pay the bill, removing their order from the list of current orders and adding the amount to the restaurant's earnings.
5. Leave: Allows the customer to leave if they have no amount due. The customer's seat is vacated after leaving.
6. Return to Main Menu: Takes the customer back to the main menu.

## Owner Mode

In owner mode, the following options are available:

1. Update Food Menu: Allows the owner to add new food items to the menu and adjust the price of existing items.
2. View Food Menu: Displays the current menu of the restaurant, including dish names and prices.
3. View Number of Customers Served: Shows the total number of customers served.
4. View Orders Received: Displays the orders of customers who have not yet paid for their food.
5. Amount Earned: Displays the total earnings of the restaurant.
6. Offer Discount: Enables the owner to enter a percentage amount for offering a discount on all items in the restaurant menu.
7. Return to Main Menu: Takes the owner back to the main menu.

Please note that the program initializes with a menu containing four food items. The customer seating follows specific criteria, ensuring social distancing rules are maintained.

## How to Run the Program

1. Clone the repository to your local machine.
2. Compile and run the source code files.
3. Follow the prompts in the console to interact with the restaurant system.

Enjoy managing your restaurant efficiently and serving your customers flawlessly with this restaurant system!
