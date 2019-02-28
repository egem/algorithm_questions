/*
 * test_forward_link_list.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: z003xwaj
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
#include <cstring>
#include <sstream>
#include "LinkedList.h"
#include "test_forward_link_list.h"


using namespace std;

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(InsertAfter_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(NULL, &l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_NEW_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l1, NULL);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l2, &l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(nullptr, l1.next())      << TestInfo();
}


TEST_F(InsertAfter_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l1.insertAfter(&l1, &l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(&l2, l1.next())           << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT)
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
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertAfter(l2, l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(nullptr, l1.next())           << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference, test_insertAfter_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL_passed_by_reference)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l1.insertAfter(l1, l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
}

TEST_F(InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_FOUND)
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
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}

TEST_F(InsertAfter_Input_New_Node_Address, test_RETURN_NULL_when_NEW_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    LinkedList<int>* expectedOutput = nullptr;
    LinkedList<int>* output;

    /************************** Act **************************/
    output = l1.insertAfter(nullptr);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output)           << TestInfo();
}

TEST_F(InsertAfter_Input_New_Node_Address, test_RETURN_NEW_NODE_when_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    LinkedList<int>* expectedOutput = &l2;
    LinkedList<int>* output;

    /************************** Act **************************/
    output = l1.insertAfter(&l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)           << TestInfo();
    EXPECT_EQ(&l2, l1.next())                   << TestInfo();
}

TEST_F(InsertAfter_Input_New_Node_Address, test_RETURN_NEW_NODE_TAIL_when_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    LinkedList<int>* expectedOutput = &l4;
    LinkedList<int>* output;

    l1.insertAfter(&l2)->insertAfter(&l5);
    l3.insertAfter(&l4);

    /************************** Act **************************/
    output = l2.insertAfter(&l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}
