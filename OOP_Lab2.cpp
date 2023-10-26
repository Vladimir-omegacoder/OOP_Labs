#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Vector.h"
#include "Transform.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Convex.h"



#define RECTANGLES_PATH "file_source\\Rectangles.csv"
#define CIRCLES_PATH    "file_source\\Circles.csv"
#define CONVEXES_PATH   "file_source\\Convexes.csv"
#define OUTPUT_PATH     "file_source\\Output.csv"





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

void select_shape(Shape*& shape);

void print_shape(const Shape& shape);

void transform_shape(Shape& shape);





int main()
{

    Shape* shape = nullptr;


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
            select_shape(shape);
            break;
            

        case Menu_commands::PRINT_SHAPE:
            print_shape(*shape);
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



void select_shape(Shape*& shape)
{
    char choice, input;
    int position;
    std::cout << "Choose shape 1 - rectangle, 2 - circle, 3 - convex: ";
    std::cin >> choice;

    switch ((Menu_commands)choice)
    {

    case Menu_commands::RECTANGLE:
        delete shape;
        shape = new Rectangle();

        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if(input == '1')
        {
            std::cout << "Enter recatngle size and position: ";
            std::cin >> static_cast<Rectangle&>(*shape);
        }
        else if(input == '2')
        {
            std::cout << "Enter position in the file: ";
            std::cin >> position;

            std::ifstream file(RECTANGLES_PATH);
            std::string temp;
            for (size_t i = 0; i < position; ++i)
            {
                std::getline(file, temp);
            }
            std::ifstream(RECTANGLES_PATH) >> static_cast<Rectangle&>(*shape);
        }
        break;


    case Menu_commands::CIRCLE:
        delete shape;
        shape = new Circle();

        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if (input == '1')
        {
            std::cout << "Enter circle radius and position: ";
            std::cin >> static_cast<Circle&>(*shape);
        }
        else if (input == '2')
        {
            std::cout << "Enter position in the file: ";
            std::cin >> position;

            std::ifstream file(CIRCLES_PATH);
            std::string temp;
            for (size_t i = 0; i < position; ++i)
            {
                std::getline(file, temp);
            }
            std::ifstream(CIRCLES_PATH) >> static_cast<Circle&>(*shape);
        }
        break;


    case Menu_commands::CONVEX:
        int point_count;
        std::cout << "Enter point count: ";
        std::cin >> point_count;

        delete shape;
        shape = new Convex(point_count);

        std::cout << "Choose source 1 - console, 2 - file: ";
        std::cin >> input;
        if (input == '1')
        {
            std::cout << "Enter convex points: ";
            std::cin >> static_cast<Convex&>(*shape);
        }
        else if (input == '2')
        {
            std::cout << "Enter position in the file: ";
            std::cin >> position;

            std::ifstream file(CONVEXES_PATH);
            std::string temp;
            for (size_t i = 0; i < position; ++i)
            {
                std::getline(file, temp);
            }
            std::ifstream(CONVEXES_PATH) >> static_cast<Convex&>(*shape);
        }
        break;


    default:
        std::cout << "There is no such shape.\n";
        break;

    }

}

void print_shape(const Shape& shape)
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
    }
    else
    {
        return;
    }

    if (const Rectangle* temp1 = dynamic_cast<const Rectangle*>(&shape))
    {
        (*destination) << *temp1;
    }
    else if (const Circle* temp2 = dynamic_cast<const Circle*>(&shape))
    {
        (*destination) << *temp2;
    }
    else if (const Convex* temp3 = dynamic_cast<const Convex*>(&shape))
    {
        (*destination) << *temp3;
    }

    (*destination) << '\n';

    if(destination != &std::cout)
    {
        delete destination;
    }
}

void transform_shape(Shape& shape)
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
