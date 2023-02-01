#include <iostream>
#include <string>

class Counter {
public:
    void up() { ++count; }
    void down() { --count; }
    void print() { std::cout << count <<std::endl; }
    Counter(int tmp) { count = tmp; }
    Counter() { count = 1; }
private:
    int count;
};


int main()
{
    system("chcp 1251");

    
    int initial = 1;
    Counter* my_count;

    std::cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет : ";
    while(true)
    {
        std::string answer;
        std::cin >> answer;
        if (answer == "да") {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> initial;
            break;
        }
        else if (answer == "нет")
            break;
        else
            std::cout << "Введите да или нет : ";
    }
    if (initial != 1)
        my_count = new Counter(initial);
    else
        my_count = new Counter();

    while (true){
        char answer;
        std::cout << "Введите команду('+', '-', '=' или 'x') : ";
        std::cin >> answer;
        switch(answer)
        {
            case '+':
                my_count->up();
                break;
            case '-':
                my_count->down();
                break;
            case '=':
                my_count->print();
                break;
            case 'x':
            case 'х':
                std::cout << "До свидания!";
                delete my_count;
                return 0;
            default:
                break;
        }
    }
}