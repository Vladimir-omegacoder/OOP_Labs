#include <iostream>
#include "Customer.h"
#include "Cash_register.h"


void PrintHelp()
{
    std::cout << "\t\t------Команды------";
    std::cout << "\nВведите A - Если хотите ввести данный с клавиатуры";
    std::cout << "\nВведите B - Если хотите ввести данный из файла";
    std::cout << "\nВведите V - Если хотите вывести информацию про кассу на консоль";
    std::cout << "\nВведите v - Если хотите вывести информацию про вторую кассу на консоль";
    std::cout << "\nВведите P - Если хотите вывести информацию про кассу в файл";
    std::cout << "\nВведите R - Если хотите сделать кассу копией второй кассы";
    std::cout << "\nВведите T - Если хотите протестировать задание 20";
    std::cout << "\nВведите E - Если хотите окончить работу с программой";

    std::cout << std::endl << std::endl;
}



int main()
{
    setlocale(LC_ALL, "ru");

    Cash_register D;
    Cash_register E(4, 600);

    E.push(Customer("Tu"));
    E.push(Customer("Y"));
    E.push(Customer("Mu"));

    char action;

    switch (action)
    {
    case('A'):
    {
        std::cout << "Введiть максимальну довжину Черги 1 та час обслуговування покупця через кому: ";
        std::cin >> D;
        std::cout << "\n\n";

        break;
    }

    case('V'):
    {
        std::cout << "----- Каса 1 -----\n" << D << "\n\n";

        break;
    }

    case('v'):
    {
        std::cout << "----- Каса 2 -----\n" << E << "\n\n";

        break;
    }


    case('R'):
    {
        std::cout << "До\n";
        std::cout << "----- Каса 1 -----\n" << D << "\n\n";
        std::cout << "----- Каса 2 -----\n" << E << "\n\n";


        D = E;

        std::cout << "Пiсля\n";
        std::cout << "----- Каса 1 -----\n" << D << "\n\n";

        break;
    }

    default:
        break;
    }












    long worktime, elapsed_time = 0, customer_time;

    std::cout << "Введiть час роботи(1000 = 1 секю): ";
    std::cin >> worktime;
    worktime += 1;
    std::cout <<"\n\n";

    std::cout << "Введiть iнтервал через який будуть приходити покупцi(1000 = 1 секю): ";
    std::cin >> customer_time;
    std::cout << "\n\n";



    Cash_register A;
    std::cout << "Введiть максимальну довжину Черги 1 та час обслуговування покупця через кому: ";
    std::cin >> A;
    std::cout << "\n\n";


    Cash_register B;
    std::cout << "Введiть максимальну довжину Черги 2 та час обслуговування покупця через кому: ";
    std::cin >> B;
    std::cout << "\n\n";

    Cash_register C;
    std::cout << "Введiть максимальну довжину Черги 3 та час обслуговування покупця через кому: ";
    std::cin >> C;
    std::cout << "\n\n";


    int clients1 = 0, clients2 = 0, clients3 = 0, clients4 = 0;

    int time1 = 0, time2 = 0, time3 = 0, time4 = 0;

    int ctime1 = 0, ctime2 = 0, ctime3 = 0;

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;



    std::cout << "------------------------------------------------------------------------------------\n\n";


    int c = clock();

    while (elapsed_time < worktime)
    {

        time1 = (ctime1 / A.getTime()) - clients1;
        time2 = (ctime2 / B.getTime()) - clients2;
        time3 = (ctime3 / C.getTime()) - clients3;


        if (time1 > 0)
        {
            for (int i = 0; i < time1; i++)
            {
                if (A.getSize() != 0)
                {
                    std::cout << "Time: " << elapsed_time << "\n";

                    A.pop();
                    ++clients1;
                    std::cout << "Покупця з Черги 1 обслуговано!\n" << "Розмiр черги тепер: " << A.getSize() << " / " << A.getMaxSize() << std::endl << std::endl;
                }
            }
        }
        if (time2 > 0)
        {
            for (int i = 0; i < time2; i++)
            {
                if (B.getSize() != 0)
                {
                    std::cout << "Time: " << elapsed_time << "\n";

                    B.pop();
                    ++clients2;
                    std::cout << "Покупця з Черги 2 обслуговано!\n" << "Розмiр черги тепер: " << B.getSize() << " / " << B.getMaxSize() << std::endl << std::endl;
                }
            }
        }
        if (time3 > 0)
        {
            for (int i = 0; i < time3; i++)
            {
                if (C.getSize() != 0)
                {
                    std::cout << "Time: " << elapsed_time << "\n";

                    C.pop();
                    ++clients3;
                    std::cout << "Покупця з Черги 3 обслуговано!\n" << "Розмiр черги тепер: " << C.getSize() << " / " << C.getMaxSize() << std::endl << std::endl;
                }
            }
        }



        if (A.getSize() == A.getMaxSize() && B.getSize() == B.getMaxSize() && C.getSize() == C.getMaxSize())
        {
        }

        else
        {
            time4 = (elapsed_time / customer_time) - clients4;

            if (time4 > 0)
            {
                std::cout << "Time: " << elapsed_time << "\n";

                for (int i = 0; i < time4; i++)
                {
                    if (A.getSize() <= B.getSize() && A.getSize() <= C.getSize() && A.getSize() != A.getMaxSize())
                    {
                        A.push(Customer());
                        std::cout << "Додано клiєнта до Черги 1\nРозмiр черги тепер: " << A.getSize() << " / " << A.getMaxSize() << std::endl << std::endl;
                    }
                    else if (B.getSize() <= A.getSize() && B.getSize() <= C.getSize() && B.getSize() != B.getMaxSize())
                    {
                        B.push(Customer());
                        std::cout << "Додано клiєнта до Черги 2\nРозмiр черги тепер: " << B.getSize() << " / " << B.getMaxSize() << std::endl << std::endl;
                    }
                    else if (C.getSize() <= A.getSize() && C.getSize() <= B.getSize() && C.getSize() != C.getMaxSize())
                    {                     
                        C.push(Customer());
                        std::cout << "Додано клiєнта до Черги 3\nРозмiр черги тепер: " << C.getSize() << " / " << C.getMaxSize() << std::endl << std::endl;
                    }

                    ++clients4;
                }
            } 
        }


        int c2 = clock() - elapsed_time - c;
        elapsed_time += c2;

        if (A.getSize() != 0) { ctime1 += c2; }
        if (B.getSize() != 0) { ctime2 += c2; }
        if (C.getSize() != 0) { ctime3 += c2; }
    }

        
    std::cout << "------------------------------------------------------------------------------------\n\n";


    std::cout << "Всього прийшло клiєнтiв: " << clients4 << "\n";
    std::cout << "Всього обслуговано клiєнтiв: " << clients1 + clients2 + clients3 << "\n\n";


    res1 = customer_time - A.getTime();
    res2 = customer_time - B.getTime();
    res3 = customer_time - C.getTime();
    res4 = ((customer_time - A.getTime()) + (customer_time - B.getTime()) + (customer_time - C.getTime())) / 3;


    if (res1 < 0) { res1 *= -1; }

    if (res2 < 0) { res2 *= -1; }

    if (res3 < 0) { res3 *= -1; }

    if (res4 < 0) { res4 *= -1;}


    std::cout << "Середнiй час вiд приходу до обслуговування Черги 1: " << res1 << "\n";
    std::cout << "Середнiй час вiд приходу до обслуговування Черги 2: " << res2 << "\n";
    std::cout << "Середнiй час вiд приходу до обслуговування Черги 3: " << res3 << "\n";
    std::cout << "Спiльний середнiй час вiд приходу до обслуговування: " << res4 << "\n\n";

}

