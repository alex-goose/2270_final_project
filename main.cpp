#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdio>
#include <algorithm>


struct Character {
    std::string name;
    std::string race;
    int health;
    int strength;
    int gold;
    int total_health_possible;
    int num_potions;
};

void printASCII(std::string filename) {
    std::string line = "";
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open()) {
        while(std::getline(inFile,line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "File failed to load." << std::endl;
    }
    inFile.close();
}

void pressEnter() {
    std::cout << "Press 'enter' to continue..." << std::endl;
    std::cin.get();
}

void slowPrint(std::string& text){
    for (int i = 0; i <text.length(); i++){
        char c = text[i];
        std::cout << c;
        std::cout.flush();  // Ensure the character is immediately displayed

        // Adjust the duration to control the speed of printing
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    std::cout << " " << std::endl;
}

void CharacterCreation(Character& player){

    bool characterCreated = false;
    bool exitCreation = false;
    while (!exitCreation) {
        std::string selection;
        system("clear");
        printASCII("ASCII_Art/castle.txt");
        std::string text = "Three races rule the land in Ervinia.";
        slowPrint(text);
        std::string text2 = "Which one will you choose...?";
        slowPrint(text2);
        std::cout << "(E) for Elf, (W) for Wizard, (M) for Minatour." << std::endl;
        std::cin >> selection;

        if (selection == "E"){
            while (!characterCreated) {
                system("clear");
                printASCII("ASCII_Art/elf.txt");
                //std::cout << " " << std::endl;
                std::cout << "\nElfs are the most populous creatures in the land." << std::endl;
                std::cout << "Initial Health: 10" <<std::endl;
                std::cout << "Strength: 5" <<std::endl;
                std::cout << "(B) to go back or (S) to select this race.\n" << std::endl;
                std::cin >> selection;
                if (selection == "B"){
                    break;
                }
                else if (selection == "S"){
                    player.health = 10;
                    player.strength = 5;
                    player.race = "Elf";
                    characterCreated = true;
                    exitCreation = true;
                    break;
                }
                else {
                    std::cout << "Invalid Input" << std::endl;
                }
            }

        }
        else if (selection == "W"){
            while (!characterCreated) {
                system("clear");
                printASCII("ASCII_Art/wizard.txt");
                //std::cout << " " << std::endl;
                std::cout << "\nWizards, while weak, are the best fighters around." << std::endl;
                std::cout << "Initial Health: 8" <<std::endl;
                std::cout << "Strength: 10" <<std::endl;
                std::cout << "(B) to go back or (S) to select this race.\n" << std::endl;
                std::cin >> selection;
                if (selection == "B"){
                    break;
                }
                else if (selection == "S"){
                    player.health = 8;
                    player.strength = 10;
                    player.race = "Wizard";
                    characterCreated = true;
                    exitCreation = true;
                    break;
                }
                else {
                    std::cout << "Invalid Input" << std::endl;
                }
            }
        }
        else if (selection == "M"){
            while (!characterCreated) {
                system("clear");
                printASCII("ASCII_Art/minatour.txt");
                //std::cout << " " << std::endl;
                std::cout << "\nMinatours may be strong, but they cannot use potions..." << std::endl;
                std::cout << "Initial Health: 12" <<std::endl;
                std::cout << "Strength: 15" <<std::endl;
                std::cout << "(B) to go back or (S) to select this race.\n" << std::endl;
                std::cin >> selection;
                if (selection == "B"){
                    break;
                }
                else if (selection == "S"){
                    player.health = 8;
                    player.strength = 10;
                    player.race = "Minatour";
                    characterCreated = true;
                    exitCreation = true;
                    break;
                }
                else {
                    std::cout << "Invalid Input" << std::endl;
                }
            }
        }
    }

    // Once character type is selected, confirm choice
    if (characterCreated == true){
        system("clear");
        std::cout << player.race << " selected. Good choice!" << std::endl;
        std::string con = "Continuing...";
        pressEnter();
        system("read");
        slowPrint(con);
        system("clear");

        // Get player's name.
        printASCII("ASCII_Art/opening.txt");
        std::string name;
        std::cin >> name;
        player.name = name;
        std::cout << "Hello " << player.name << "! Let's begin your story!" << std::endl;
        pressEnter();
    }
}

struct Node {
    std::string text;
    std::string text2;

    std::string choice;
    //std::string choice2;

    std::string art;
    //std::string art2;
    Node* left;
    Node* right;
};

void deleteTree(Node* root){
    if (root){
        deleteTree(root->left);
        deleteTree(root->right);
        std::cout << root << " deleted" << std::endl;
        delete root;
    }
}

void gameOver(Node* currNode, Node* root){
    deleteTree(root);
    currNode = nullptr;
    std::cout << "Woo hoo! All nodes deleted successfully!" << std::endl;
}

int main() {

    // Create Character
    Character player;
    player.gold = 0;
    player.health = 0;
    player.strength = 0;
    CharacterCreation(player);

    // Tree 1 - node declerations
    Node* Root = new Node;
    Node* left1 = new Node;
    Node* right1 = new Node;
    Node* left2 = new Node;
    Node* right2 = new Node;
    Node* left3 = new Node;
    Node* right3 = new Node;
    Node* left4 = new Node;
    Node* right4 = new Node; // DEAD
    Node* left6 = new Node;
    Node* right6 = new Node; // DEAD
    Node* right7 = new Node;

    //Trees 2 nd 3 roots
    Node* Root2 = new Node;
    Node* Root3 = new Node;

    Root->art = "ASCII_Art/man.txt";
    Root->text = "\nYou look up and see a strange man. \nDo you greet him or continue on?\n";
    Root->text2 = "(L) to greet, (R) to continue on your way.\n";
    Root->left = left1;
    Root->right = right1;
    
    // Root->left
    //Root->left = left1;
    left1->left = left2;
    left1->right = right2;
    left1->art = "ASCII_Art/strangeman.txt";
    left1->text = "\n'Ah, hello there. \n"
                "It's not often to meet someone out here wondering around alone at night.\n"
                "You look lost. There's a tavern nearby. I assume you need some money.\n"
                "Here's 10 gold. Go get yourself a warm meal'\n";
    player.gold += 10;
    left1->text2 = "(L) continue to tavern, (R) No thanks, I like wandering.";
    
    //Root->left->left
    left2->left = left4;
    left2->right = right4;
    left2->art = "ASCII_Art/house.txt";
    left2->text = "\n\nFinally, somewhere to relax and get some food.\n"
                "You step inside and take a seat at the counter.\n";
    left2->text2 = "\n\n'What can I do you for? Food and drink for ya?\n"
                "I can get ya filled up for 2 gold!'\n\n"
                "(L) for yes please! (R) for no thanks, I think I'll starve."; 

    //Root->left->right DEAD
    right2->art = "ASCII_Art/snow2.txt";
    right2->text = "Why would you do that?\n"
                "The cold is simply too much for you...";

    // Root->right
    //Root->right = right1;
    right1->left = left3;
    right1->right = right3;
    right1->art = "ASCII_Art/house.txt";
    right1->text = "\n~You stumble along until you find a tavern. Finally, somewhere to rest!~\n"
                "\n'What can I do you for? Food and drink for ya?\n"
                "I can get you filled up for 2 gold!\n"
                "Oh... I see you're broke. Tell ya what. I'll make this one on the house on one condition.\n"
                "Before eatin' would you be willin to clean the barn?'";
    right1->text2 = "\n(L) for yes, (R) for heck no!";

    // Root->right->left
    left3->left = left6;
    left3->right = right6;
    left3->art = "ASCII_Art/broom.txt";
    left3->text = "\nHere ya go. When you're done\n"
                "a warm meal will be waitin for ya!";
    left3->text2 = "\n(L) Ready to eat, (R) Eh, I'll starve.";

    // Root->right->right DEAD
    right3->art = "ASCII_Art/snow.txt";
    right3->text = "\n'Well if ya ain't gonna help, get outta here!'"
                "\nYou're thrown out into the cold, lost and hungry.";

    //Root->left->left->left   Brings to new tree Root3
    left4->left = Root3;
    left4->art = "ASCII_Art/food.txt";
    left4->text = "'Welp, it was good having ya. Hey... you should go North from here.\n"
                "I know you don't know your way around here, but if you find an elf,\n"
                "let them know Bradford sent ya....'\n";
    left4->text2 = "\n(L) To continue on your journey... (to the next tree!)";

    //Root->right->left->left
    left6->left = Root2;
    left6->right = right7;
    left6->art = "ASCII_Art/food.txt";
    left6->text = "Ha, don't eat too quickly!\n"
                "I'm glad you stopped in. You need a room for the night too?";
    left6->text2 = "\n(L) Yes I'll take a room! (R) No thanks.";

    // Root->left->left->right DEAD
    right4->art = "ASCII_Art/snow.txt";
    right4->text = "'Fine... suit yourself. Go on, get outta here!'";

    //Root->right->left->right DEAD
    right7->art = "ASCII_Art/snow.txt";
    right7->text = "'Suit yourself, have fun making it in the cold!'\n"
                "The cold is too much for you...\n";


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TREE 2!!
    Node* left2_1 = new Node;
    Node* right2_1 = new Node;
    Node* left2_2 = new Node;
    Node* right2_2 = new Node;
    Node* left2_3 = new Node;
    Node* right2_3 = new Node;
    Node* left2_4 = new Node;
    Node* right2_4 = new Node;
    Node* left2_5 = new Node;
    Node* right2_5 = new Node;
    Node* left2_6 = new Node;
    Node* right2_6 = new Node;

    Root2->left = left2_1;
    Root2->right = right2_1;
    Root2->art = "ASCII_Art/room.txt";
    Root2->text = "\n'Here's our finest room for ya.\n"
                "I know ya ain't got nothing to pay with\n"
                "but we can figure that out in the mornin'.\n";
    Root2->text2 = "(L) Go to Sleep (R) Lookaround the room";

    left2_1->left = left2_2;
    left2_1->right = right2_2;
    left2_1->art = "ASCII_Art/bed.txt";
    left2_1->text = "\nYou slowly drift away into a deep sleep...\n";
    left2_1->text2 = "Do you tend to have nightmares? (L) Yes (R) No";

    left2_2->left = left2_4;
    left2_2->right = right2_4;
    left2_2->art = "ASCII_Art/goblin.txt";
    left2_2->text = "\nYou have a terrible dream of a goblin!\n";
    left2_2->text2 = "(L) to wake up (R) to push through it";


    right2_1->left = left2_3;
    right2_1->right = right2_3;
    right2_1->art = "ASCII_Art/treasure.txt";
    right2_1->text = "\nWhoa! You found a treasure in the corner!\n"
                    "I wonder if there's gold inside...\n";
    right2_1->text2 = "Do you try and open it? (L) Yes (R) No";
    
    //Try to open chest
    left2_3->left = left2_6;
    left2_3->right = right2_6;
    left2_3->art = "ASCII_art/key.txt";
    left2_3->text = "\nYou feel something in your pocket.\n"
                    "Something that wasn't there before...\n"
                    "It's a key! It must be for the treasure!\n";
    left2_3->text2 = "(L) Open the chest (R) This doesn't feel right...";

    //Don't open chest
    right2_3->art = "ASCII_Art/unhappy.txt";
    right2_3->text = "\nThat was your only chance to pay for the room.\n"
                    "You realize the Inn Keeper was testing you, and you failed.\n\n"
                    "'Get outta here! And never come back!'\n";


    right2_4->art = "ASCII_Art/deathbed.txt";
    right2_4->text = "\nYour dream is so bad you cannot push through it\n"
                    "You end up never waking up!!\n";

    right2_2->left = right2_4;
    right2_2->art = "ASCII_Art/monster.txt";
    right2_2->text = "\nWhat's this?? A nightmare!?\nBut you never get nightmares!\n"
                    "(L) to see what happens next!";

    // wake up from dream
    left2_4->left = Root3;
    left2_4->art = "ASCII_Art/unhappy.txt";
    left2_4->text = "\nWell that sucked...\nLet's get out of here!!!\n"
                    "(L) to get the heck out of here!\n";

    // open the chest - dead
    left2_6->art = "ASCII_Art/monster.txt";
    left2_6->text = "\nOh no! There's a monster inside!!!\n";

    // don't use the key
    right2_6->art = "ASCII_Art/unhappy.txt";
    right2_6->text = "\nThat was your only chance to pay for the room.\n"
                    "You realize the Inn Keeper was testing you, and you failed.\n\n"
                    "'Get outta here! And never come back!'\n";






    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //Tree 3 !!
    Node* left3_1 = new Node;
    Node* right3_1 = new Node;
    Node* left3_2 = new Node;
    Node* right3_2 = new Node;
    Node* left3_3 = new Node;
    Node* right3_3 = new Node;

    Root3->left = left3_1;
    Root3->right = right3_1;
    Root3->art = "ASCII_Art/sunrise.txt";
    Root3->text = "\nYou set off North, towards the Norfin Mountain Range.\n"
                "The sunrise over the mountain begins to warm your skin.\n"
                "Eventually, you see a man off in the distance....\n"
                "As you get closer, it appears to be an elf!\n"
                "(L) to approach, (R) to avoid\n";


    left3_1->left = left3_2;
    left3_1->right = right3_2;
    left3_1->art = "ASCII_Art/elf2.txt";
    left3_1->text = "\nHello there, who are you? State your purpose.\n"
                    "(L) for I was told to find you\n"
                    "(R) for I bet I could take you!";
    
    left3_2->art  = "ASCII_Art/unhappy.txt";
    left3_2->text = "\nWhat!? Whoever told you to find me... grrr... I'll kill 'em!\n"
                    "But... YOU FIRST!!";

    right3_2->art = "ASCII_Art/deathbed.txt";
    right3_2->text = "\nHoly cow, you actually killed him....\n"
                    "YOU WIN!! CONGRATS! This is the only way to win!!!!!!!\n"
                    "(Ignore the YOU DIED below....)";

    right3_1->left = left3_3;
    right3_1->right = right3_3;
    right3_1->art = "ASCII_Art/mush_house.txt";
    right3_1->text = "\nWhoa, good choice. It's a mushroom house!\n"
                    "(L) to take a bite of it, (R) to inspect it\n";

    left3_3->art = "ASCII_Art/mushroom.txt";
    left3_3->text = "\nOh no, it was poisonous!\n";

    right3_3->art = "ASCII_Art/mushroom.txt";
    right3_3->text = "\nOh no! Poisonous spores got onto your face!!\n";





    // TREE TRAVERSAL MECHANISM
    Node* currNode = Root;

    while (currNode){
        system("clear");
        printASCII(currNode->art);
        slowPrint(currNode->text);

        if (currNode->left && currNode->right){
            std::cout << currNode->text2 << std::endl;
            std::cin >> currNode->choice;
            if (currNode->choice == "L"){
                currNode = currNode->left;
            }
            else if (currNode->choice == "R"){
                currNode = currNode->right;
            }
            else{
                std::cout << "Invalid choice, please choose again" << std::endl;
            }
        }
        else {
            if (currNode->left){
                // If only left is valid, we must be starting a new tre
                // include choices and traversal methods to begin new tree
                // currNode in this context is root of new tree
                std::cout << currNode->text2 << std::endl;
                std::cin >> currNode->choice;
                if (currNode->choice == "L"){
                    currNode = currNode->left;
                }
                else if (currNode->choice == "R"){
                    std::cout << "Check your traverses. You shouldn't be here!" << std::endl;
                    currNode = currNode->right;
                }
            }
            
            else if (currNode->right){
                std::cout << "Check your traverses. You shouldn't be here!" << std::endl;
                currNode = currNode->right;
            }
            else {
                std::cout << std::endl << player.name << " Died - Game Over..." << std::endl;
                std::string restart;
                std::cout << "\nDo you want to Restart (R) or Quit (Q)?" << std::endl;
                std::cin >> restart;

                if (restart == "R"){
                    currNode = Root;
                }
                else if (restart == "Q"){
                    gameOver(currNode, Root);
                    break;
                }
            }
        }
    }
    return 0;
};