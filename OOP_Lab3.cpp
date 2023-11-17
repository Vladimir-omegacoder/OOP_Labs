#include <iostream>
#include <fstream>
#include "Basic_graphics.hpp"
#include "Smart_ptr.h"



#define RECTANGLES_PATH "file_source\\Rectangles.txt"
#define CIRCLES_PATH    "file_source\\Circles.txt"
#define CONVEXES_PATH   "file_source\\Convexes.txt"
#define OUTPUT_PATH     "file_source\\Output.txt"





enum class Menu_commands
{

    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    SELECT_SHAPE = 's',
    SELECT_TEMP = 'a',

    PRINT_SHAPE = 'p',
    PRINT_TEMP = 'y',

    TRANSFORM_SHAPE = 't',

    INSERT_SHAPE = 'i',

};



void print_command_info();

void select_shape(Convex& shape);

void print_shape(Convex& shape);

void transform_shape(Convex& shape);

void insert_shape(Convex& shape1, const Convex& shape2);





int main()
{

    Smart_ptr<Convex> shape(new Convex(1));
    Smart_ptr<Convex> temp(new Convex(1));

    char command;
    bool run = true;
    print_command_info();

    while (run)
    {

        std::cout << "----- MAIN MENU -----\n" << "Enter command: ";
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch ((Menu_commands)command)
        {

        case Menu_commands::CLEAR_CONSOLE:
            system("cls");
            break;


        case Menu_commands::PRINT_HELP:
            print_command_info();
            break;


        case Menu_commands::QUIT_PROGRAM:
            run = false;
            break;


        case Menu_commands::SELECT_SHAPE:
            select_shape(*shape);
            break;
            

        case Menu_commands::SELECT_TEMP:
            select_shape(*temp);
            break;


        case Menu_commands::PRINT_SHAPE:
            print_shape(*shape);
            break;


        case Menu_commands::PRINT_TEMP:
            print_shape(*temp);
            break;


        case Menu_commands::TRANSFORM_SHAPE:
            transform_shape(*shape);
            break;


        case Menu_commands::INSERT_SHAPE:
            insert_shape(*shape, *temp);
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

        std::cout << '\n';

    }

    return 0;

}





void print_command_info()
{

    std::cout << "Commands list:\n"
          
        << "\'" << (char)Menu_commands::PRINT_HELP << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM << "\' - quit program\n"

        << "\'" << (char)Menu_commands::SELECT_SHAPE << "\' - select shape\n"
        << "\'" << (char)Menu_commands::SELECT_TEMP << "\' - select temp\n"

        << "\'" << (char)Menu_commands::PRINT_SHAPE << "\' - print shape\n"
        << "\'" << (char)Menu_commands::PRINT_TEMP << "\' - print temp\n"

        << "\'" << (char)Menu_commands::TRANSFORM_SHAPE << "\' - transform shape\n"

        << "\'" << (char)Menu_commands::INSERT_SHAPE << "\' - insert shape\n"

        << "\n\n";

}



void select_shape(Convex& shape)
{

    char input;
    int position;

    int point_count;
    std::cout << "Enter point count: ";
    std::cin >> point_count;

    shape = Convex(point_count);

    std::cout << "Choose source 1 - console, 2 - file: ";
    std::cin >> input;
    if (input == '1')
    {
        std::cout << "Enter convex points: ";
        std::cin >> shape;
    }
    else if (input == '2')
    {
        std::cout << "Enter position in the file: ";
        std::cin >> position;

        std::ifstream file(CONVEXES_PATH);
        if (!file.is_open())
        {
            throw;
        }

        for (int i = 0; i < position; ++i)
        {
            while (file.peek() != '\n') file.ignore(1);
            file.ignore(1);
        }
        file >> shape;
    }

}



void print_shape(Convex& shape)
{

    char choice;
    std::cout << "Choose destination(1 - console, 2 - file): ";
    std::cin >> choice;

    std::ostream* destination;

    if (choice == '1')
    {
        destination = &std::cout;
    }
    else if (choice == '2')
    {
        destination = new std::ofstream(OUTPUT_PATH, std::ios::app);
        if(!static_cast<std::ofstream*>(destination)->is_open())
        {
            delete destination;
            throw;
        }
    }
    else
    {
        return;
    }

    (*destination) << shape;

    (*destination) << '\n';

    if(destination != &std::cout)
    {
        delete destination;
    }

}



void transform_shape(Convex& shape)
{

    char choice;

    float angle;
    Vector2f scale, offset;
    Transform transform;

    bool run = true;

    while (run) 
    {

        std::cout << "Choose transformation to add(1 - rotate, 2 - scale, 3 - move, a - to apply): ";
        std::cin >> choice;

        switch (choice)
        {

        case '1':
            std::cout << "Enter angle: ";
            std::cin >> angle;
            transform.rotate(angle);
            break;


        case '2':
            std::cout << "Enter scale: ";
            std::cin >> scale;
            transform.scale(scale);
            break;


        case '3':
            std::cout << "Enter offset: ";
            std::cin >> offset;
            transform.move(offset);
            break;


        case 'a':
            run = false;
            break;


        default:
            std::cout << "There is no such transformation.\n";
            break;

        }

    }

    shape.apply_transform(transform);

}

void insert_shape(Convex& shape1, const Convex& shape2)
{

    size_t begin, length;

    std::cout << "Enter begin index: ";
    std::cin >> begin;
    std::cout << "Enter length: ";
    std::cin >> length;

    shape1(begin, length) = shape2;

}


