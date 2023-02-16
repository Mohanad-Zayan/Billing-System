//
// Created by 20121 on 2/11/2023.
//

#ifndef BS_SHOPPING_H
#define BS_SHOPPING_H
#include <iostream>
using namespace std ;
class Shopping{
    private:
        int parCode ;
        float price ;
        float discount ;
        string productName ;
    public:
        void menu() ;

    [[noreturn]] void administrator() ;

    [[noreturn]] void buyer() ;
        void add() ;
        void edit() ;
        void rem() ;
        void list() ;
        void receipt() ;

};
#endif //BS_SHOPPING_H
