/*
 * test_forward_link_list.h
 *
 *  Created on: Feb 28, 2019
 *      Author: z003xwaj
 */

#ifndef FORWARD_LINK_LIST_TEST_UNIT_INC_TEST_FORWARD_LINK_LIST_H_
#define FORWARD_LINK_LIST_TEST_UNIT_INC_TEST_FORWARD_LINK_LIST_H_

class InsertAfter_Input_Match_Node_Address_and_New_Node_Address : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertAfter_Input_Match_Node_Address_and_New_Node_Address() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertAfter_Input_Match_Node_Reference_and_New_Node_Reference() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class InsertAfter_Input_New_Node_Address : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertAfter_Input_New_Node_Address() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("LinkedList<T>* insertAfter(LinkedList<T>* newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class InsertAfter_Input_New_Node_Reference : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertAfter_Input_New_Node_Reference() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("LinkedList<T>* insertAfter(LinkedList<T>& newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class InsertBefore_Input_Match_Node_Address_and_New_Node_Address : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertBefore_Input_Match_Node_Address_and_New_Node_Address() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool insertBefore(LinkedList<T>* matchNode, LinkedList<T>* newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class InsertBefore_Input_Match_Node_Reference_and_New_Node_Reference : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    InsertBefore_Input_Match_Node_Reference_and_New_Node_Reference() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool insertBefore(LinkedList<T>& matchNode, LinkedList<T>& newNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class DeleteNode_Input_Match_Node_Address : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    DeleteNode_Input_Match_Node_Address() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool deleteNode(LinkedList<T>* matchNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};

class DeleteNode_Input_Match_Node_Reference : public ::testing::Test
{
    std::string m_ClassName;
    std::string m_FunctionName;
    std::stringstream m_TestInfo;

public:
    DeleteNode_Input_Match_Node_Reference() :
        m_ClassName("LinkedList<T>"),
        m_FunctionName("bool deleteNode(LinkedList<T>& matchNode)")
    {
        m_TestInfo          << "Class Name    : " << m_ClassName << std::endl
                            << "Function Name : " << m_FunctionName << std::endl;
    }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    std::string TestInfo()
    {
        return m_TestInfo.str();
    }
};
#endif /* FORWARD_LINK_LIST_TEST_UNIT_INC_TEST_FORWARD_LINK_LIST_H_ */
