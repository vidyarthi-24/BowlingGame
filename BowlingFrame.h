#ifndef BOWLING_FRAME_H
#define BOWLING_FRAME_H

namespace BG
{
    struct Frame
    {
        unsigned int rollCount;
        unsigned int score;
        unsigned int numBonusRollsRemaining;
        unsigned int sumOfRolls;
    };

} // namespace BG
#endif // BOWLING_FRAME_H
