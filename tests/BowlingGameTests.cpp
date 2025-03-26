#include "../BowlingGame.h"
#include <gtest/gtest.h>

TEST(BowlingGameTest, TestInitialScore) {
    BowlingGame game("Player1");
    EXPECT_EQ(game.getFrame(0).score, 0);
}

TEST(BowlingGameTest, TestSingleRoll) {
    BowlingGame game("Player1");
    game.roll(5);
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 5);
    EXPECT_EQ(game.getFrame(0).score, 5);
}

TEST(BowlingGameTest, TestSpare) {
    BowlingGame game("Player1");
    game.roll(5);
    game.roll(5); // Spare
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 10);
    EXPECT_EQ(game.getFrame(0).score, 10); // 10 + 0 bonus

    game.roll(3);
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 13);
    EXPECT_EQ(game.getFrame(0).score, 13); // 10 + 3 bonus
    EXPECT_EQ(game.getFrame(1).sumOfRolls, 3);
    EXPECT_EQ(game.getFrame(1).score, 16);

    game.roll(4);
    EXPECT_EQ(game.getFrame(1).sumOfRolls, 7);
    EXPECT_EQ(game.getFrame(1).score, 20); // 13 + 4
}

TEST(BowlingGameTest, TestStrike) {
    BowlingGame game("Player1");
    game.roll(10); // Strike
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 10);
    EXPECT_EQ(game.getFrame(0).score, 10); // 10 + 0 bonus

    game.roll(3);
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 13);
    EXPECT_EQ(game.getFrame(0).score, 13);
    EXPECT_EQ(game.getFrame(1).sumOfRolls, 3);
    EXPECT_EQ(game.getFrame(1).score, 16);

    game.roll(4);
    EXPECT_EQ(game.getFrame(0).sumOfRolls, 17);
    EXPECT_EQ(game.getFrame(0).score, 17); // 10 + 3 + 4 bonus
    EXPECT_EQ(game.getFrame(1).sumOfRolls, 7);
    EXPECT_EQ(game.getFrame(1).score, 24); // 17 + 7
}

TEST(BowlingGameTest, TestPerfectGame) {
    BowlingGame game("Player1");
    for (int i = 0; i < 12; ++i) {
        game.roll(10); // 12 strikes
    }
    EXPECT_EQ(game.getFrame(9).sumOfRolls, 30);
    EXPECT_EQ(game.getFrame(9).score, 300);
}

TEST(BowlingGameTest, TestAllSpares) {
    BowlingGame game("Player1");
    for (int i = 0; i < 21; ++i) {
        game.roll(5); // 21 rolls of 5 pins
    }
    EXPECT_EQ(game.getFrame(9).sumOfRolls, 15);
    EXPECT_EQ(game.getFrame(9).score, 150);
}

TEST(BowlingGameTest, TestMixedGame) {
    BowlingGame game("Player1");
    game.roll(10); // Strike
    game.roll(7);
    game.roll(3); // Spare
    game.roll(9);
    game.roll(0);
    game.roll(10); // Strike
    game.roll(0);
    game.roll(8);
    game.roll(8);
    game.roll(2); // Spare
    game.roll(0);
    game.roll(6);
    game.roll(10); // Strike
    game.roll(10); // Strike
    game.roll(10); // Strike
    game.roll(8);
    game.roll(1);
    EXPECT_EQ(game.getFrame(9).sumOfRolls, 19);
    EXPECT_EQ(game.getFrame(9).score, 167);
}