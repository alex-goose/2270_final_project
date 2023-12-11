# 2270_final_project
Final project for 2270, choose your own adventure game.

Welcome to my final project for CSPB 2270!

Running this project is extremely easy, as it is only a main file as well as a folder of images.
Simply compile main.cpp in the terminal and run it and the game will start. All decisions which
require the user to enter an input must be done in caps. 

This project is an expansion on the use of binary trees by using them to
maximize readability and effeciency within a choose your own adventure game. The issue with most
of these games as a coding project is they rely on deeply nested if/else statements. By using
binary trees, it is possible to only include a handful of if/else statements in the traversal
function, which only relies on them to go left or right as well as replay or quit. 

While the plan was to have a large amount of trees, this project uses only a handful as I decided
to focus on creating a functional story line to make the project engaging as opposed to a shallow
experience with more trees. There are many, many ways to 'die' in the game and only one path will lead
the user to winning. A forest of trees was used as a method to keep track of each part of the game,
as well as to create distinct branches. In the future, I'd like to add more. For example, I want the user
to be able to select 'visit store', and if they choose to do so, the left child of that node will be a 
pointer to the root node of the 'store' tree where a user can purchase goods such as food and potions.

The traversal function is the "engine" of the game as it checks if a node has both children.
There are three options here:
    1. If both children, there is a choice to make. Once the user makes a selection,
    currNode moves either left or right.
    2. If the currNode only has a left child, the child is the root of a new tree. currNode is
    moved to become this new tree. 
    3. If currNode has no children, this is a dead end. One final picture and string will
    be displayed. Then, the user is informed that they have died and they are given the option to restart.
    4. While there are technically 3 options, the use of the currNode only having a right 
    child has been left as a test case. If currNode follows this path, it is made clear
    that something has gone wrong.

Each node is initiated all at once for each tree so that children can be assaigned without
errors. These nodes then have art and two strings attached to them. Using the traversal function,
the choices made decide which child to move to. Many children lead to dead ends, and the most fun
sounding choice does not always lead to the most enjoyable story line.

At the very end of the game, if the user chooses to quit the game, each node created is deleted
and cout statements are used to make sure each node is deleted. This way I can count each cout
statement to make sure it matches up with how many nodes were created. If it is successful,
this is followed by a confirmation message that all nodes have been deleted.

It is important to note that this project does not rely on shared pointers or using namespace std;
Throughout this course I have used these, and in doing so I have almost forgotten the function of
a pointer. By making this harder on myself, I was able to better understand how a bianry tree
functions as well as pointers and the purpose of namespaces.

All ASCII art was derived from asciiart.eu, which has a large database of images. Without the 
contributions of the artist who's art is listed there, this project would have felt dry and
incomplete, so I give many thanks to them.