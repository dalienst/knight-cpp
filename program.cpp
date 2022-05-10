#include "splashkit.h"
#include<string>

using namespace std;

struct knight_data
{
    string name;
    int age;
    string month;
    string state;
};


//returns a string of the input from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//to read an integer from the user
int read_integer(string prompt) 
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

knight_data read_knight()
{
    knight_data result;
    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.month = read_string("Enter you month of birth: ");
    result.state = read_string("Enter your State: ");

    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello " + knight.name + " aged " + to_string(knight.age));
    write_line("I was born in the month of " + knight.month + " and I live in " + knight.state + " state.");
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_MONTH,
    UPDATE_STATE,
    FINISH_UPDATE
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update month");
    write_line("4: Update status");
    write_line("5: Finish update");
    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result - 1);

}

void update_knight(knight_data &knight)
{
    int option;

    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();
        

        switch (option)
        {
        case UPDATE_NAME:
            knight.name = read_string("Enter new name: ");
            break;
        
        case UPDATE_AGE:
            knight.age = read_integer("Enter new age: ");

        case UPDATE_MONTH:
            knight.month = read_string("Enter new month: ");

        case UPDATE_STATE:
            knight.state = read_string("Enter new state: ");

        case FINISH_UPDATE:
            break;
        
        default:
            write_line("Please select a valid option");
        }
    } while ( option != FINISH_UPDATE);
    
}

int main()
{
    knight_data my_knight;

    my_knight = read_knight();
    write_knight(my_knight);

    update_knight(my_knight);
    write_line("After update... back in main");
    write_knight(my_knight);
    

    return 0;
}