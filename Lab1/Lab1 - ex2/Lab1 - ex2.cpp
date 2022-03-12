#include <iostream>

int main()
{
    int n=9999, i;

    std::cout << "The PIN codes are: \n";

    for (i = n; i >= 1000; i--)
    {
        if(i%10 != (i%100)/10 && i%10 != (i / 100) % 10 && i%10 != i/1000 && (i % 100) / 10 != (i / 100) % 10 && (i % 100) / 10 != i / 1000 && (i / 100) % 10 != i/1000)
            if ((i % 10 + (i % 100) / 10 + (i / 100) % 10 + i / 1000) == 24)
                std::cout << i << '\n';
    }

}
