// Copyright 2018 Kovshov Andrey

#include <gtest/gtest.h>
#include "include/TreeOfSegments.h"

TEST(TreeOfSegmets, can_create_tree) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act & Assert
    ASSERT_NO_THROW(TreeOfSegmets<int> ts(n, a));
}

TEST(TreeOfSegments, can_not_create_tree_with_negative_size) {
    // Arrange
    int n = -1;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act & Assert
    ASSERT_ANY_THROW(TreeOfSegmets<int> ts(n, a));
}

TEST(TreeOfSegments, can_not_create_tree_with_too_big_size) {
    // Arrange
    int n = 1000000;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act & Assert
    ASSERT_ANY_THROW(TreeOfSegmets<int> ts(n, a));
}

TEST(TreeOfSegments, can_compare_trees) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);
    TreeOfSegmets<int> ts2(n, a);

    // Assert
    EXPECT_TRUE(ts1 == ts2);
}

TEST(TreeOfSegments, can_create_copy_tree) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_NO_THROW(TreeOfSegmets<int> ts2(ts1));
}

TEST(TreeOfSegments, can_create_copy_tree2) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);
    TreeOfSegmets<int> ts2(ts1);

    // Assert
    EXPECT_TRUE(ts1 == ts2);
}

TEST(TreeOfSegments, can_equate_trees) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;
    int* b = new int[3];
    b[0] = 1;
    b[1] = 2;
    b[2] = 1000;

    // Act
    TreeOfSegmets<int> ts1(n, a);
    TreeOfSegmets<int> ts2(n, b);

    // Assert
    ASSERT_NO_THROW(ts1 = ts2);
    EXPECT_TRUE(ts1 == ts2);
}

TEST(TreeOfSegments, can_equate_itself) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_NO_THROW(ts1 = ts1);
}

TEST(TreeOfSegments, can_find_sum) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    EXPECT_EQ(ts1.sum(0, 2), a[0] + a[1] + a[2]);
    EXPECT_EQ(ts1.sum(1, 2), a[1] + a[2]);
    EXPECT_EQ(ts1.sum(0, 1), a[0] + a[1]);
    EXPECT_EQ(ts1.sum(0, 0), a[0]);
    EXPECT_EQ(ts1.sum(1, 1), a[1]);
    EXPECT_EQ(ts1.sum(2, 2), a[2]);
}

TEST(TreeOfSegments, can_not_find_sum_with_negative_left) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_ANY_THROW(ts1.sum(-1, 2));
}

TEST(TreeOfSegments, can_not_find_sum_with_too_big_right) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_ANY_THROW(ts1.sum(0, 10));
}
TEST(TreeOfSegments, can_not_find_sum_with_right_less_left) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_ANY_THROW(ts1.sum(2, 0));
}

TEST(TreeOfSegments, can_update_tree) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_NO_THROW(ts1.update(1, 5));
}

TEST(TreeOfSegments, can_not_update_tree_with_negative_vertex) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_ANY_THROW(ts1.update(-1, 5));
}

TEST(TreeOfSegments, can_not_update_tree_with_to_big_vertex) {
    // Arrange
    int n = 3;
    int* a = new int[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 100;

    // Act
    TreeOfSegmets<int> ts1(n, a);

    // Assert
    ASSERT_ANY_THROW(ts1.update(-4, 5));
}
