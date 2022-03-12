#include <iostream>
#include "Car.h"
#include "Electric.h"
#include "Diesel.h"
#include "UI.h"
#include "Tests.h"


using namespace std;

int main()
{
    

    TestAll();
    UI ui;
    ui.run();

    return 0;
}