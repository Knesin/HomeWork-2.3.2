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
        if(std::cin.peek() == '\n')
            std::cout << "Введите команду('+', '-', '=' или 'x') : ";
        std::cin >> answer;
        if (answer == '+') 
            my_count->up();
        else if (answer == '-') 
            my_count->down();
        else if (answer == '=') 
            my_count->print();
        else if (answer == 'x' || answer == 'х') {
            std::cout << "До свидания!";
            delete my_count;
            return 0;
        }
    }
}