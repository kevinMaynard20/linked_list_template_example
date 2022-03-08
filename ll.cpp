#include <iostream>
using namespace std;

struct career_struct
{
    int prev_number; //
    string prev_team;
    struct career_struct *next;
};
struct player_struct
{
    string name;
    struct career_struct *c_head;
    // I decided the current data for the player will just be the
    // last element of its sublist. eg. to find current number would be
    //  player_struct k; do{ k = k->next; }while(k->next) print("Number is: %d" , k->prev_number);
    struct player_struct *next; // Pointer to next Element
}

template <typename T, typename S>
bool inList(T struct, S data); // forward declaration of the class inList() that will take ANY two types



//I dont know if you're going to have like the teams intialized or the leagues or the players instantiated first
//but i would make a method like this one for all of the structs 
//also same thing as inList() im going to declare it above and define it below 
//overloading is typically an exception to this convention so thats why those methods are up here

void makePlayer(player_struct *node, string name, string team, int number);




// here I am overriding the == operator so we can call if(T==S) regardless of the types
friend bool operator==(const &player_struct a, const &string name)
{
    string tempA = tolower(a->name); // Good habit to always set a string to either upper or lower for comparison
    string tempB = tolower(name);    // you have to assign the lowercase val to new string since a & name are constant
    return (tempA.compare(tempB) == 0);
}
// same thing here but i also made a method that allows you to compare a career to a prev team meaning you can call
//  career_struct == (int)  && career_struct == (string)
friend bool operator==(const &career_struct a, const &int number)
{
    return (a->prev_number == number);
}

friend bool operator==(const &career_struct a, const &string name)
{
    return (a->prev_number name);
}



int main(int argc char **argv)
{
    player_struct* head = new player_struct; //This is now allocated on the heap;
    makePlayer(head,"Kareem","Pistons",5);
    player_struct* second = new player_struct; //This is now allocated on the heap;
    makePlayer(second,"James","Heat",23);
    head->next=second;
}

template <typename T, typename S>
bool inList(T L_list, S data)
{
    while (L_list->next)
    { // we are able to do this because both career_struct & player_struct have a next field.
        if (L_list == data)
            return 1;
        L_list = L_list->next;
    }
    return (L_list == data);
}

void makePlayer(player_struct *node, string name, string team, int number){
    career_struct *head = new career_struct; //keep in mind you are allocating this to the heap by using the keyword 'new'
    head->prev_number = number; // meaning you will need to free it before you finish the program
    head->prev_team=team; // i probably wont write that for this little program but lmk if you need help with it
    node->c_head = head;
    node->name = name;
}