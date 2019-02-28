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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
 * Function under test : bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode)
 */

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


/*
 * Function under test : bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode)
 */

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

TEST_F(InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL)
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


/*
 * Function under test : bool insertAfter(LinkedList<T>* newNode)
 */

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

TEST_F(InsertAfter_Input_New_Node_Address, test_RETURN_NEW_NODE_ADDRESS_when_NEW_NODE_NOT_NULL)
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

TEST_F(InsertAfter_Input_New_Node_Address, test_RETURN_NEW_NODE_TAIL_ADDRESS_when_NEW_NODE_HAS_NEXT)
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

/*
 * Function under test : bool insertAfter(LinkedList<T>& newNode)
 */

TEST_F(InsertAfter_Input_New_Node_Reference, test_RETURN_NEW_NODE_REFERENCE_when_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    LinkedList<int>* expectedOutput = &l2;
    LinkedList<int>* output;

    /************************** Act **************************/
    output = &(l1.insertAfter(l2));

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)           << TestInfo();
    EXPECT_EQ(&l2, l1.next())                   << TestInfo();
}

TEST_F(InsertAfter_Input_New_Node_Reference, test_RETURN_NEW_NODE_TAIL_REFERENCE_when_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    LinkedList<int>* expectedOutput = &l4;
    LinkedList<int>* output;

    l1.insertAfter(l2).insertAfter(l5);
    l3.insertAfter(l4);

    /************************** Act **************************/
    output = &(l2.insertAfter(l3));

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}


/*
 * Function under test : bool insertBefore(LinkedList<T>* matchNode, LinkedList<T>* newNode)
 */

TEST_F(InsertBefore_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertBefore(NULL, &l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_NEW_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertBefore(&l1, NULL);

    /************************** Assert **************************/
    ASSERT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertBefore(&l2, &l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(nullptr, l3.next())      << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l2.insertBefore(&l2, &l1);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(&l2, l1.next())           << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Address_and_New_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l5.insertBefore(&l5, &l2);
    l2.insertBefore(&l2, &l1);
    l4.insertBefore(&l4, &l3);

    /************************** Act **************************/
    output = l1.insertBefore(&l5, &l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}


/*
 * Function under test : bool insertBefore(LinkedList<T>& matchNode, LinkedList<T>& newNode)
 */

TEST_F(InsertBefore_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.insertBefore(l2, l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(nullptr, l3.next())      << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_NOT_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    /************************** Act **************************/
    bool output = l2.insertBefore(l2, l1);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(&l2, l1.next())           << TestInfo();
}

TEST_F(InsertBefore_Input_Match_Node_Reference_and_New_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l5.insertBefore(l5, l2);
    l2.insertBefore(l2, l1);
    l4.insertBefore(l4, l3);

    /************************** Act **************************/
    output = l1.insertBefore(l5, l3);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(&l5, l4.next())               << TestInfo();
}


/*
 * Function under test : bool deleteNode(LinkedList<T>* matchNode);
 */

TEST_F(DeleteNode_Input_Match_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NULL)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.deleteNode(NULL);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Address, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.deleteNode(&l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_ITSELF)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    l1.insertAfter(&l2);

    /************************** Act **************************/
    bool output = l1.deleteNode(&l1);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(nullptr, l1.next())           << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    l1.insertAfter(&l2);

    /************************** Act **************************/
    bool output = l1.deleteNode(&l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(nullptr, l1.next())           << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Address, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l1.insertAfter(l2).insertAfter(l3).insertAfter(l5).insertAfter(l4);

    /************************** Act **************************/
    output = l1.deleteNode(&l5);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(nullptr, l4.next())               << TestInfo();
}


/*
 * Function under test : bool deleteNode(LinkedList<T>& matchNode);
 */

TEST_F(DeleteNode_Input_Match_Node_Reference, test_RETURN_FALSE_when_MATCH_NODE_NOT_FOUND)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = false;

    /************************** Act **************************/
    bool output = l1.deleteNode(l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_ITSELF)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    l1.insertAfter(l2);

    /************************** Act **************************/
    bool output = l1.deleteNode(l1);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(nullptr, l1.next())           << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7);
    bool expectedOutput = true;

    l1.insertAfter(l2);

    /************************** Act **************************/
    bool output = l1.deleteNode(l2);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)   << TestInfo();
    EXPECT_EQ(nullptr, l1.next())           << TestInfo();
}

TEST_F(DeleteNode_Input_Match_Node_Reference, test_RETURN_TRUE_when_MATCH_NODE_FOUND_and_NEW_NODE_HAS_NEXT)
{
    /************************** Arrange **************************/
    LinkedList<int> l1(5), l2(7), l3(9), l4(11), l5(13);
    bool expectedOutput = true;
    bool output;

    l1.insertAfter(l2).insertAfter(l3).insertAfter(l5).insertAfter(l4);

    /************************** Act **************************/
    output = l1.deleteNode(l5);

    /************************** Assert **************************/
    EXPECT_EQ(expectedOutput, output)       << TestInfo();
    EXPECT_EQ(&l2, l1.next())               << TestInfo();
    EXPECT_EQ(&l3, l2.next())               << TestInfo();
    EXPECT_EQ(&l4, l3.next())               << TestInfo();
    EXPECT_EQ(nullptr, l4.next())               << TestInfo();
}


