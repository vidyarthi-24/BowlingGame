#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include <string>

constexpr int MAX_NUM_FRAMES = 10;
constexpr int MAX_PINS = 10;

struct Frame
{
    unsigned int rollCount;
    unsigned int score;
    unsigned int numBonusRollsRemaining;
    unsigned int sumOfRolls;
};

class BowlingGame final
{
public:
    BowlingGame(const std::string& inPlayerName);
    void roll(int inPins);
    int calculateFrameScore(int previousFrameScore, int sumOfCurrFrameRolls);
    const Frame& getFrame(int idx)const;
private:
    void BowlingGame::fillFrame(int inPins);
    void BowlingGame::fillLastFrame(int inPins);
    void updateFrame(unsigned int nxtRoll, unsigned int frameIndex);

    Frame frames[MAX_NUM_FRAMES];
    unsigned int frameCount;
    int score;
    std::string playerName;
};

#endif // BOWLING_GAME_H