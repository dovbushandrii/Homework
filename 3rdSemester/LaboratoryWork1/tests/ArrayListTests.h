#include <gtest/gtest.h>
#include <climits>

/**
 * First of first include implementation which you wont to use,
 * in this case it is {@code class ArrayList : List {...}}
 */
#include "../list_implementation/ArrayList.h"

/**
 * Also include external functions for yout data type (in example it is int)
 * to check object condition and convert it in text format
 */
#include "../data/Int.h"

TEST(ArrayList, sizeZeroTest) {
    List<int> *list = new ArrayList<int>();
    ASSERT_EQ(0, list->size());
}

TEST(ArrayList, addTest) {
    List<int> *list = new ArrayList<int>();
    list->add(0);
    list->add(1);
    list->add(-1);
    list->add(INT_MIN);
    list->add(INT_MAX);
}

TEST(ArrayList, sizeTest) {
    List<int> *list = new ArrayList<int>();
    for (int i = 1; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(ArrayList, addWithResizeTest) {
    List<int> *list = new ArrayList<int>();
    for (int i = 1; i < 100; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->size());
    }
}

TEST(ArrayList, getByIndexTest) {
    List<int> *list = new ArrayList<int>();
    for (int i = 0; i < 10; ++i) {
        list->add(i);
        ASSERT_EQ(i, list->get(i));
    }
}

TEST(ArrayList, getByNotExistingIndexTest) {
    List<int> *list = new ArrayList<int>();
    ASSERT_THROW(list->get(100), std::exception);
    ASSERT_THROW(list->get(0), std::exception);
    list->add(99);
    ASSERT_THROW(list->get(1), std::exception);
    ASSERT_THROW(list->get(-1), std::exception);
}

TEST(ArrayList, getIndexWhereConditionTest) {
    List<int> *list = new ArrayList<int>();
    list->add(1);
    ASSERT_THROW(list->getIndexWhereCondition(isCondition), std::exception);
    list->add(5);
    ASSERT_EQ(1, list->getIndexWhereCondition(isCondition));
}

TEST(ArrayList, toStringTest) {
    List<int> *list = new ArrayList<int>();
    ASSERT_EQ("[]", list->toString(toStringInt));
    list->add(1);
    ASSERT_EQ("[1]", list->toString(toStringInt));
    list->add(2);
    ASSERT_EQ("[1, 2]", list->toString(toStringInt));
}
