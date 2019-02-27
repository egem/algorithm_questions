/*
 * test_forward_link_list.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: z003xwaj
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_FALSE_when_MATCH_NODE_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(NULL, &l2);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_FALSE_when_NEW_NODE_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l1, NULL);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l2, &l3);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(nullptr, l1.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l1, &l2);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(&l2, l1.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l1.insertAfter(&l1, &l2);
    l1.insertAfter(&l2, &l5);
    l3.insertAfter(&l3, &l4);

    /************************** Act **************************/
    output = l1.insertAfter(&l2, &l3);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(&l2, l1.next());
    ASSERT_EQ(&l3, l2.next());
    ASSERT_EQ(&l4, l3.next());
    ASSERT_EQ(&l5, l4.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL_passed_by_reference)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(l2, l3);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(nullptr, l1.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL_passed_by_reference)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l1.insertAfter(l1, l2);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(&l2, l1.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_FOUND_passed_by_reference)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l1.insertAfter(l1, l2);
    l1.insertAfter(l2, l5);

    l3.insertAfter(l3, l4);

    /************************** Act **************************/
    output = l1.insertAfter(l2, l3);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(&l2, l1.next());
    ASSERT_EQ(&l3, l2.next());
    ASSERT_EQ(&l4, l3.next());
    ASSERT_EQ(&l5, l4.next());
}

/*
 * Test
 *      class  : LinkedList
 *      method : LinkedList<T>* insertAfter(LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_NULL_when_NEW_NODE_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    LinkedList<int>* expectedOutput = nullptr;
    LinkedList<int>* output;

    /************************** Act **************************/
    output = l1.insertAfter(nullptr);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
}

/*
 * Test
 *      class  : LinkedList
 *      method : LinkedList<T>* insertAfter(LinkedList<T>* newNode);
 */
TEST(InsertAfterSuite, test_insertAfter_RETURN_NEW_NODE_when_NEW_NODE_NOT_NULL_passed_by_address)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    LinkedList<int>* expectedOutput = &l2;
    LinkedList<int>* output;

    /************************** Act **************************/
    output = l1.insertAfter(&l2);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output);
    ASSERT_EQ(&l2, l1.next());
}

