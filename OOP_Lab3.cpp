﻿#include <iostream>
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
    RECTANGLE = '1',
    CIRCLE = '2',
    CONVEX = '3',

    PRINT_SHAPE = 'p',

    TRANSFORM_SHAPE = 't',
};



void print_command_info();

void select_shape(Smart_ptr<Convex> shape);

void print_shape(Smart_ptr<Convex> shape);

void transform_shape(Convex& shape);





int main()
{

    Smart_ptr<Convex> shape(new Convex(1));

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
            select_shape(std::move(shape));
            break;
            

        case Menu_commands::PRINT_SHAPE:
            print_shape(std::move(shape));
            break;


        case Menu_commands::TRANSFORM_SHAPE:
            transform_shape(*shape);
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

        << "\'" << (char)Menu_commands::PRINT_SHAPE << "\' - print shape\n"

        << "\'" << (char)Menu_commands::TRANSFORM_SHAPE << "\' - transform shape\n"

        << "\n\n";

}



void select_shape(Smart_ptr<Convex> shape)
{

    char choice, input;
    int position;
    std::cout << "Choose shape 1 - rectangle, 2 - circle, 3 - convex: ";
    std::cin >> choice;

    Convex_reshape reshape(*shape);

    switch ((Menu_commands)choice)
    {

    case Menu_commands::RECTANGLE:
        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if(input == '1')
        {
            Rectangle temp;
            std::cout << "Enter recatngle size and position: ";
            std::cin >> temp;
            reshape = temp;
        }
        else if(input == '2')
        {
            std::cout << "Enter position in the file: ";
            std::cin >> position;

            std::ifstream file(RECTANGLES_PATH);
            if (!file.is_open())
            {
                throw;
            }

            for (int i = 0; i < position; ++i)
            {
                while (file.peek() != '\n') file.ignore(1);
                file.ignore(1);
            }

            Rectangle temp;
            file >> temp;
            reshape = temp;
        }
        break;


    case Menu_commands::CIRCLE:
        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if (input == '1')
        {
            Circle temp;
            std::cout << "Enter circle radius and position: ";
            std::cin >> temp;
            reshape = temp;
        }
        else if (input == '2')
        {
            std::cout << "Enter position in the file: ";
            std::cin >> position;

            std::ifstream file(CIRCLES_PATH);
            if(!file.is_open())
            {
                throw;
            }

            for (int i = 0; i < position; ++i)
            {
                while (file.peek() != '\n') file.ignore(1);
                file.ignore(1);
            }

            Circle temp;
            file >> temp;
            reshape = temp;
        }
        break;


    case Menu_commands::CONVEX:
        int point_count;
        std::cout << "Enter point count: ";
        std::cin >> point_count;

        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if (input == '1')
        {
            std::cout << "Enter convex points: ";
            std::cin >> *shape;
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
            file >> *shape;
        }
        break;


    default:
        std::cout << "There is no such shape.\n";
        break;

    }

}



void print_shape(Smart_ptr<Convex> shape)
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

    (*destination) << *shape;

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

    Convex convex(5);
    convex[0] = Vector2f(10, 10);
    convex[1] = Vector2f(30, 20);
    convex[2] = Vector2f(45, 20);
    convex[3] = Vector2f(25, 15);
    convex[4] = Vector2f(15, 15);

    Convex temp(3);
    temp[0] = Vector2f(40, 20);
    temp[1] = Vector2f(60, 40);
    temp[2] = Vector2f(70, 30);

    std::cout << convex << '\n';

    convex(1, 2) = temp;

    std::cout << convex << '\n';

}


