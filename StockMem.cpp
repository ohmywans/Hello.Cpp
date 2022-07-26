#include "Stock.h"

void Stock::acquire(string co, int n, float pr) { 

    name = co;
    shares = n;
    share_val = pr;
    set_total();

} 
void Stock::buy(int n, float pr) { 

    shares -= n;
    share_val = pr;
    set_total();

}
void Stock::sell(int n, float pr) {

    shares -= n;
    share_val = pr;
    set_total();

}
void Stock::update(float pr) { 

    share_val = pr;
    set_total();

}

void Stock::show() { 
    cout << "회사 명 : " << name << endl;
    cout << "주식 수 : " << shares << endl;
    cout << "주가 : " << share_val << endl;
    cout << "주식 총 가치 : " << total_val << endl;
}
    Stock();
    ~Stock();
    
Stock::Stock() 
{
}

Stock::~Stock()
{
}
