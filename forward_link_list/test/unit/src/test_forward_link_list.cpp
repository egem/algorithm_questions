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

TEST(InsertAfterSuite, test_insertAfter_return_false_when_input_match_node_is_null)
{
    bool expectedOutput = false;

    LinkedList<int> l1(5), l2(7);

    bool ret = l1.insertAfter(NULL, &l2);

    ASSERT_EQ(expectedOutput, ret);
}

