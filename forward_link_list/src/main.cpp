/*
 * main.cpp
 *
 *  Created on: Feb 23, 2019
 *      Author: Ahmet Ege Mahlec
 */

#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> l1(7), l2(9), l3(11), l4(13), l5(15), l6(17);

    l1.setNext(l3).setNext(l5).setNext(l6);
    l1.insertBefore(l3, l2);

    l1.print(cout);

    LinkedList<int>* reverse_l1 = l1.reverse();

    reverse_l1->print(cout);
}
