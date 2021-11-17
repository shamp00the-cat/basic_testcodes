/*
Author: Casey Roosma
Date: 11/16/2021
This program helps the user pick a food to eat based on input
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
string shuffleFood();
void play();
string vegetarian[] = {"Sliced carrots, cucumber and hummus", "Oatmeal with fruit", "Grilled cheese with tomato slice and spinach", "Vegatable fried rice", "Tofu pad thai", "Jackfruit barbecue sandwich", "Vegetable sushi", "Sweet potato salad", "Tomato basil bisque", "Black bean burrito"};
string lowCarb[] = {"Stuffed peppers", "Chicken lettuce wraps", "Salmon fillet with asparagus", "Vegetable Omelette", "Kale Salad", "Steak and broccoli", "Eggs and bacon", "Shrimp fried 'rice' with cauliflower rice", "Ratatouille", "Greek yogurt with berries"};
string cheap[] = {"Instant ramen", "Rice and beans", "Tuna salad sandwich", "Peanut butter and jelly", "Instant Oatmeal", "Eggs and toast", "Dumplings", "Baked potato", "Spaghetti", "Baked Chicken"};
string extravagant[] = {"Sushi", "Duck", "Surf and turf", "Escargot", "Caviar", "Bacon wrapped filet mignon", "Paella", "Charcuterie", "Crab legs", "Lobster tail"};


string shuffleFood()
{
    srand(time(0)); // seed for the random integer
    //get a random integer between 1 and 5 to choose which array of foods to choose from
    //get another random integer
    int randomint, index;
    randomint = rand() % 4 + 1;
    index = rand() % 9;
    switch(randomint) {
          case 1 :
            return vegetarian[index];
             break;
          case 2 :
            return lowCarb[index];
            break;
          case 3 :
            return cheap[index];
             break;
          case 4 :
            return extravagant[index];
             break;
          default :
             return "Error";
       }
    system("pause");
}

void play()
{
    int choice;
    int num;
    cout << "Let's narrow this down some more." << "\n" <<  "Would you rather have something cheap, something fancy, something vegetarian, or maybe you are doing a low carb diet (such as keto)?" << endl;
    cout << "We'll make this easy for you: " << endl;
    cout << "Type 1 for a random Vegetarian dish." << "\n" << "Type 2 for a random Low Carb or 'keto' dish." << "\n" << "Type 3 for a random Low Cost dish." << "\n" << "Type 4 for a random Extravagant dish and TREAT yourself." << endl;
    cin >> choice;
    if(choice >= 1 || choice <= 4){
        cout << "Great! Now type your favorite number between 1 and 10." << endl;
        cin >> num;
        cout << "Try this... " << endl;
        switch(choice) {
              case 1 :
                cout << vegetarian[num];
                 break;
              case 2 :
                cout << lowCarb[num];
                break;
              case 3 :
                cout << cheap[num];
                 break;
              case 4 :
                cout << extravagant[num];
                 break;
           }
    }
    else {
        cout << "Error! You didn't enter an integer between 1 and 4. Try again..." << endl;
        play();
    }
    cout <<"\n";
}

void printCute()
{
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20 - i; j++){
            if(j % 2 == 0){
                cout << "*";
            }
            else {
                cout << "~";
            }
        }
        if(i % 3 == 0){
            cout << "*" << endl;
        }
    }
    cout << "\n";
}

int main()
{
    char selection;
    cout << "Welcome to food suggestor app!" << endl;
    cout << "Lets get started!" << endl;
    printCute();
    cout << "Do you want to pick a random food, or answer some questions to narrow the possible suggestions?" << endl;
    cout << "Type 'R' for an instant, random suggestion. Type 'A' to answer a couple of questions and narrow it down a bit more." << endl;
    cin >> selection;
    if(selection == 'R' || selection == 'r')
    {
        string x = shuffleFood();
        cout << "Try this: " << x << endl;
    }
    if(selection == 'A' || selection == 'a')
    {
        play();
    }
    else {
        cout << "Error: You didn't enter 'R' or 'A'" << endl;
    }
    cout << "Play again? \n type 'Y' for yes or 'X' to exit." << endl;
    char x;
    cin >> x;
    if(x == 'y' || x == 'Y')
    {
        main();
    }
    else {
        cout << "Thank you for playing! Next time you can't think of what to eat, let the food suggester app choose for you." << endl;
        printCute();
    }
    
}
