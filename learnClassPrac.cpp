#include "Stock.h"
#include <iostream>

int main() {

    Stock temp;
    temp.acquire("Wans Company ", 100, 1000);
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();

    return 0;
}
