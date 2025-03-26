#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>
#include <string>
#include "BowlingGameConstants.h"
#include "BowlingFrame.h"

namespace BG
{
    class BowlingGame final
    {
    public:
        BowlingGame(const std::string& inPlayerName);
        void roll(int inPins);
        inline int calculateFrameScore(unsigned int previousFrameScore, unsigned int sumOfCurrFrameRolls);
        const Frame& getFrame(int idx)const;
    private:
        void fillFrame(int inPins);
        void fillLastFrame(int inPins);
        inline void updateFrame(unsigned int nxtRoll, unsigned int frameIndex);

        Frame frames[BowlingGameConstants::MAX_NUM_FRAMES];
        unsigned int frameCount;
        unsigned int score;
        std::string playerName;
    };
} // namespace BG
#endif // BOWLING_GAME_H
