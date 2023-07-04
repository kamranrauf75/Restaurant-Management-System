#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct food_item
{
public:
    int serial_no;
    string dish_name;
    float price;

    food_item()
    {
        serial_no = 0;
        dish_name = " ";
        price = 0;
    }

    void set(int serial_no, string dish_name, float price)
    {
        this->serial_no = serial_no;
        this->dish_name = dish_name;
        this->price = price;
    }

    void food_menu(food_item items[])
    {

    	int done;

        cout << "\t \t" << "Menu" << endl;
        //system("cls");
        for (int i = 0; i < 10; i++)
        {
        	
            if (items[i].dish_name != " ")
            {
            	
                cout << "\t" << items[i].serial_no << "\t" << items[i].dish_name << "\t" << items[i].price << endl;
            }

        }
        //cout<<"Press 1 to continue"<<endl;
        //cin>>done;

    }
};

struct customer
{
public:
    int customer_status;
    string name;
    float amount_paid;
    int orders;
    double AmountOwed;
    string dish_ordered;
    float dish_price;
    int seat_choice;


    customer()
    {
        name = " ";
        amount_paid = 0;

        AmountOwed = 0.0;
        dish_ordered = " ";
        dish_price = 0;
        seat_choice = 0;

        //seats[]={'w','w','o','o','o','w','w','w','w','w'};
    }

    customer(string name, float amount_paid, string order, string dish_ordered)
    {
        this->name = name;
        this->amount_paid = 0;
        this->dish_ordered = " ";
        //this->order = " ";

    }

    void select_seat(string name, char seats[], string name_register[])
    {


        for (int i = 0; i < 10; i++)
            cout << seats[i] << " , ";
        cout << endl;
        bool flag = 0;
        do {
            cin >> seat_choice;
            seat_choice--;
            if(seat_choice != 0 && seat_choice!=9)
            {
            	//cout<<"here1"<<endl;

            if (seats[seat_choice - 1] == 'o' && seats[seat_choice + 1] == 'o' && seats[seat_choice] == 'o')
            {
                seats[seat_choice] = 'x';
                name_register[seat_choice] = name;
                flag = 1;
            }

            else {
                cout << "Error: seat taken, choose another seat" << endl;
                cin.clear();
                cin.ignore();
            }

        	}
            else if(seat_choice == 0)
            	{
            		//cout<<"here2"<<endl;
            		 if (seats[seat_choice + 1] == 'o' && seats[seat_choice] == 'o')
            			{
                			seats[seat_choice] = 'x';
                			name_register[seat_choice] = name;
                			flag = 1;
            			}

            		else{
                			cout << "Error: seat taken, choose another seat" << endl;
                			cin.clear();
                			cin.ignore();
            	 		}

            	 }

            else if(seat_choice == 9)
            {
            	 //cout<<"here3"<<endl;
            	 if (seats[seat_choice - 1] == 'o' && seats[seat_choice] == 'o')
            	 {
                seats[seat_choice] = 'x';
                name_register[seat_choice] = name;
                flag = 1;
            	 }

            else {
                cout << "Error: seat taken, choose another seat" << endl;
                cin.clear();
                cin.ignore();
            	 }
            }
        	

        } while (flag == 0);
    }

 
};

struct owner
{
public:

    string name;
    float amount_earned;
    int customers_served;
    food_item items;
    int total_orders;
    float p_discount;

    owner()
    {
        name = " ";
        amount_earned = 0;
        customers_served = 0;
        total_orders = 0;
        p_discount = 0;
    }
    void update_foodmenu(food_item items[])
    {
        food_item a;

        int initial_items = a.serial_no;
        //food_item f;
        int answer = 0;
        cout << "Press 1 if you want to add more items?" << endl;
        cout << "Press 2 if you want to change price of any item?" << endl;
        cin >> answer;
        if (answer == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                if (items[i].serial_no == 0)
                {
                    cout << "Enter serial no" << endl;
                    cin >> a.serial_no;
                    cout << "Enter dish name" << endl;
                    cin >> a.dish_name;
                    cout << "Enter price" << endl;
                    cin >> a.price;
                    items[i].set(a.serial_no, a.dish_name, a.price);
                    break;
                }
            }



        }
        else if (answer == 2)
        {
            cout << "Enter serial_no of the item you want to change price of." << endl;
            cin >> a.serial_no;
            for (int i = 0; i < 10; i++)
            {
                if (items[i].serial_no == a.serial_no)
                {

                    cout << "Enter new price" << endl;
                    cin >> items[i].price;//gtfrdfghjuhytgrfd
                    //items[a.serial_no].set(a.serial_no, a.dish_name, a.price);
                }

            }

        }
    }

    void offer_discount(food_item items[])
    {
        cout << "How much percent discount do you want to give?" << endl;
        cin >> p_discount;
        int s = 0;
        while (items[s].price != 0)
        {
            items[s].price = items[s].price * (1 - (p_discount / 100));
            s++;
        }


    }

};

int Main_Menu()
{
	//system("cls");
    int choice;
    cout << "Press 1 for customer mode" << endl;
    cout << "Press 2 for owner mode" << endl;
    cout << "Press 3 to exit program" << endl;
    cin >> choice;
    return choice;
}

int customer_menu()
{
    int choice;
    //system("cls");
    cout << "\n\t\t\t\t****";
    cout << "\n\t\t\t\tRESTAURANT MANAGEMENT ";
    cout << "\n\t\t\t\t* CUSTOMER MENU *";
    cout << "\n\t\t\t\t****";
    cout << "\n\n\n\t\t\tPress 1 to View food menu";
    cout << "\n\t\t\tPress 2 to Place order";
    cout << "\n\t\t\tPress 3 to View order";
    cout << "\n\t\t\tPress 4 to Pay bill";
    cout << "\n\t\t\tPress 5 to Leave";
    cout << "\n\t\t\tPress 6 to Return to Main menu";
    cout << "\n\n\t\t\tEnter Your Choice: ";
    cin >> choice;

    return choice;

}

int owner_menu()
{
    //system("cls");
    int choice;
    cout << "\n\t\t\t\t****";
    cout << "\n\t\t\t\t 	RESTAURANT MANAGEMENT ";
    cout << "\n\t\t\t\t      * OWNER MENU *";
    cout << "\n\t\t\t\t****";
    cout << "\n\n\n\t\t\tPress 1 to Update food menu";
    cout << "\n\t\t\tPress 2 to View food menu";
    cout << "\n\t\t\tPress 3 to View no of Customers served";
    cout << "\n\t\t\tPress 4 to View orders recieved";
    cout << "\n\t\t\tPress 5 to Amount Earned";
    cout << "\n\t\t\tPress 6 to Offered Discount";
    cout << "\n\t\t\tPress 7 to Return to Main menu";
    cout << "\n\n\t\t\tEnter Your Choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    string* name_register = new string[10];
    char* seats = new char[10];

    for (int i = 0; i < 10; i++)
    {
        *(name_register + i) = " ";
    }

    for (int i = 0; i < 10; i++)
    {
        *(seats + i) = 'o';
    }
    
    food_item f;
    food_item items[10];
    int initial_items = 4;
 
    items[0].set(1, "Apple Pie", 11);
    items[1].set(2, "French Fries", 8);
    items[2].set(3, "Lasagna	", 24);
    items[3].set(4, "Chop suey", 15);

    customer c[10];
    owner O;

    int first_choice = 0;
    do {
        
       // cout << "gyufcdxvhjbhkgtfuycjhfhxcjdthASDGFTFDRFCGHV\n";

        first_choice = Main_Menu();

        if (first_choice == 1) // Customer Mode
        {
            int second_choice = 0;
            do {
            	//

            	//system("cls");
                cout << "Press 1 if you are a new customer" << endl;
                cout << "Press 2 if you are a current customer" << endl;
                cout << "Press 3 to Exit" << endl;
                cin >> second_choice;

                if (second_choice == 1) // New or current
                {
                    bool flag = 0;
                    string name_check;
                    cout << "Kindly enter your name" << endl;
                    cin >> name_check;

                    for (int i = 0; i < 10; i++)
                    {
                        if (c[i].name == name_check)
                        {
                            flag = 1;
                            cout << "Person with this name is already sitting in the restaurant" << endl;
                            break;
                        }

                    }

                    if (flag == 0)
                    {
                        int x = 0;
                        for (x = 0; x < 10; x++)
                        {
                            if (c[x].name == " ")
                            {
                                break;
                            }
                           // cout << "No seat left" << endl;
                        }
                        if (x != 10)
                        {
                            c[x].name = name_check;
                            c[x].select_seat(c[x].name, seats, name_register);

                            int choice_2 = 0;
                            do
                            {
                                choice_2 = customer_menu();
                                if (choice_2 == 1) // View Food Menu
                                {

                                    f.food_menu(items);

                                }

                                else if (choice_2 == 2) // Place Order
                                {

                                    //cout<<c[x].dish_ordered<<endl;//whyyyyyyy
                                    /*for(int j = 0; j<10; j++)
                                    {
                                        if(c[j].dish_ordered == " ")
                                        {
                                            break;
                                        }

                                    }*/

                                    if (c[x].dish_ordered == " ")
                                    {
                                        cout << "enter serial number of the dish that you want to order" << endl;
                                        cin >> f.serial_no;

                                        for (int i = 0; i < 10; i++)
                                        {
                                            if (f.serial_no == items[i].serial_no)
                                            {
                                                c[x].dish_ordered = items[i].dish_name;
                                                c[x].dish_price = items[i].price;
                                                O.total_orders++;
                                                c[x].customer_status = 1;
                                                c[x].AmountOwed = c[x].dish_price;
                                            }
                                        }

                                    }
                                    else { cout << "your order is already placed"; }

                                }

                                else if (choice_2 == 3) // View Order
                                {
                                    cout << c[x].dish_ordered << "\t" << c[x].dish_price << endl;

                                }

                                else if (choice_2 == 4) // Pay Bill
                                {
                                    cout << c[x].dish_price;
                                    cout << "Please enter your bill amount" << endl;
                                    cin >> c[x].amount_paid;

                                    c[x].AmountOwed = c[x].AmountOwed - c[x].amount_paid;
                                    if (c[x].AmountOwed < 0 || c[x].AmountOwed == 0)
                                    {
                                        //c[x].AmountOwed=0;
                                        cout << " BIll paid successfully" << endl;
                                        O.amount_earned = O.amount_earned + (c[x].amount_paid) + (c[x].AmountOwed);
                                        cout << "Your left over money= " << abs(c[x].AmountOwed);
                                        O.customers_served++;

                                    }

                                }

                                else if (choice_2 == 5) // Leave
                                {

                                    if (c[x].AmountOwed == 0 || c[x].AmountOwed < 0)
                                    {
                                        seats[c[x].seat_choice] = 'o';
                                        //vacate seat
                                        break;
                                    }
                                    else
                                    {
                                        do {
                                            cout << " Kindly pay the remaining dues" << endl;
                                            cin >> c[x].amount_paid;
                                            c[x].AmountOwed = c[x].AmountOwed - c[x].amount_paid;

                                            if (c[x].AmountOwed < 0 || c[x].AmountOwed == 0)
                                            {
                                                //c[x].AmountOwed=0;
                                                cout << " BIll paid successfully" << endl;
                                                cout << "Your left over money= " << abs(c[x].AmountOwed);
                                                O.customers_served++;
                                                O.amount_earned = O.amount_earned + (c[x].amount_paid) + (c[x].AmountOwed);

                                            }
                                        } while (c[x].AmountOwed != 0);

                                    }
                                }


                            } while (choice_2 != 6);
                            /*for(int i = 0;i<10;i++)
                            {
                                cin >> c[0].name;//"""manage customers"""""
                                string name=c[0].name;
                                c[0].select_seat(name,seats,name_register);
                            }*/

                            //c[0].select_seat(name, seats, name_register);
                        }
                    }
                }
                
                else if (second_choice == 2)
                {
                        int x = 0;
                        bool flag_i=0;
                        string name_check;
                        cout << "Kindly enter your name" << endl;
                        cin >> name_check;
                        
                        for (x = 0; x < 10; x++)
                        {
                            if (c[x].name == name_check)
                            {

                                cout << "Entry successful" << endl;
                                flag_i =1;
                                break;
                            }
                             
                        }
                        if (flag_i==1)
                        {
                        int choice_2 = 0;
                        do
                        {
                            choice_2 = customer_menu();
                            if (choice_2 == 1) // View Food Menu
                            {
                                f.food_menu(items);

                            }

                            else if (choice_2 == 2) // Place Order
                            {

                                //cout<<c[x].dish_ordered<<endl;//whyyyyyyy
                                /*for(int j = 0; j<10; j++)
                                {
                                    if(c[j].dish_ordered == " ")
                                    {
                                        break;
                                    }

                                }*/

                                if (c[x].dish_ordered == " ")
                                {
                                    cout << "enter serial number of the dish that you want to order" << endl;
                                    cin >> f.serial_no;

                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (f.serial_no == items[i].serial_no)
                                        {
                                            c[x].dish_ordered = items[i].dish_name;
                                            c[x].dish_price = items[i].price;
                                            O.total_orders++;
                                            c[x].customer_status = 1;
                                            c[x].AmountOwed = c[x].dish_price;
                                        }
                                    }

                                }
                                else { cout << "your order is already placed"; }

                            }

                            else if (choice_2 == 3) // View Order
                            {
                                cout << c[x].dish_ordered << "\t" << c[x].dish_price << endl;

                            }

                            else if (choice_2 == 4) // Pay Bill
                            {
                                cout << c[x].dish_price;
                                cout << "Please enter your bill amount" << endl;
                                cin >> c[x].amount_paid;

                                c[x].AmountOwed = c[x].AmountOwed - c[x].amount_paid;
                                if (c[x].AmountOwed < 0 || c[x].AmountOwed == 0)
                                {
                                    //c[x].AmountOwed=0;
                                    cout << " BIll paid successfully" << endl;
                                    O.amount_earned = O.amount_earned + (c[x].amount_paid) + (c[x].AmountOwed);
                                    cout << "Your left over money= " << abs(c[x].AmountOwed);
                                    O.customers_served++;
                                }

                            }

                            else if (choice_2 == 5) // Leave
                            {

                                if (c[x].AmountOwed == 0 || c[x].AmountOwed < 0)
                                {
                                    seats[c[x].seat_choice] = 'o';
                                    //vacate seat
                                    break;
                                }
                                else
                                {
                                    do {
                                        cout << " Kindly pay the remaining dues" << endl;
                                        cin >> c[x].amount_paid;
                                        c[x].AmountOwed = c[x].AmountOwed - c[x].amount_paid;

                                        if (c[x].AmountOwed < 0 || c[x].AmountOwed == 0)
                                        {
                                            //c[x].AmountOwed=0;
                                            cout << " BIll paid successfully" << endl;
                                            cout << "Your left over money= " << abs(c[x].AmountOwed);
                                            O.customers_served++;
                                            O.amount_earned = O.amount_earned + (c[x].amount_paid) + (c[x].AmountOwed);

                                        }
                                    } while (c[x].AmountOwed != 0);

                                }
                            }

                       } while (choice_2 != 6);
                   }
                   else{cout<<"There is no person with this name in the restaurant. So, please try again."<<endl;
                        //menu is displayed
                                 //ccc
                   }
                }//this for flag(0)

            	} while (second_choice != 1 && second_choice != 2);
        }

        if (first_choice == 2) // Owner Mode
        {
            int second_choice = 0;

            while (second_choice != 7)
            {
                second_choice = owner_menu();

                if (second_choice == 1) // Update Food Menu
                {
                    O.update_foodmenu(items);
                }

                if (second_choice == 2) //  View Food Menu
                {
                    f.food_menu(items);
                }

                if (second_choice == 3) // View no of Customers served
                {
                    cout << O.customers_served << endl;
                }

                if (second_choice == 4) // View orders recieved
                {
                    cout << O.total_orders << endl;
                }

                if (second_choice == 5) // Amount earned
                {
                    cout << O.amount_earned;
                }

                if (second_choice == 6) // Offered Discount
                {
                    O.offer_discount(items);
                }

                if (second_choice == 7) // Exit
                {
                    break;
                }
            }
        }

        if (first_choice == 3) // EXIT
        {
            break;
        }

    } while (first_choice != 3);

    delete[] name_register;
    delete[] seats;

    return 0;
}