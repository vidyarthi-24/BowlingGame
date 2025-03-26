#include "BowlingGame.h" // Ensure this file exists in the same directory as this source file
namespace BG
{
BowlingGame::BowlingGame(const std::string& inPlayerName) : frames{},
frameCount{}, playerName{inPlayerName}, score{0} {}

void BowlingGame::fillLastFrame(int inPins)
{
    Frame& lastFrame = frames[frameCount];
    if(lastFrame.rollCount < 3)
    {
        lastFrame.rollCount++;
        lastFrame.sumOfRolls += inPins;
        lastFrame.score = calculateFrameScore(lastFrame.sumOfRolls, frameCount); 
       
        if(lastFrame.rollCount == 3)
        {
            frameCount++; 
        }
    }
}

void BowlingGame::fillFrame(int inPins)
{
    Frame& currFrame = frames[frameCount];
        if(currFrame.rollCount < 2)
        {
            currFrame.sumOfRolls += inPins;
            currFrame.score = calculateFrameScore(currFrame.sumOfRolls, frameCount);//dynamicallly updates score
            currFrame.rollCount++;
    
            if(currFrame.sumOfRolls == BowlingGameConstants::MAX_PINS)
            {
                if(currFrame.rollCount == 1)//isStrike
                {
                    currFrame.numBonusRollsRemaining = BowlingGameConstants::STRIKE_BONUS_ROLLS;
                }
                else //isSpare
                {
                    currFrame.numBonusRollsRemaining = BowlingGameConstants::SPARE_BONUS_ROLLS;
                }
            }
            if((currFrame.sumOfRolls == BowlingGameConstants::MAX_PINS)||(currFrame.rollCount == 2))
            {      
                frameCount++;
            }
        }        
}

void BowlingGame::roll(int inPins)
{
    if(frameCount < BowlingGameConstants::MAX_NUM_FRAMES)
    {
        unsigned int numPreviousFramesEligibleForBonus = frameCount>1?2:(frameCount>0?1:0);
        for(unsigned int i = frameCount-numPreviousFramesEligibleForBonus; i<frameCount; i++)
        {
            updateFrame(inPins, i);
        }
        
        if(frameCount == BowlingGameConstants::MAX_NUM_FRAMES-1)//last frame
        {
            fillLastFrame(inPins);
        }
        else
        {
            fillFrame(inPins);
        }
    }
}

 int BowlingGame::calculateFrameScore(unsigned int sumOfCurrFrameRolls,unsigned int frameIndex)
 {
    if(frameIndex>0)
    {
        score = frames[frameIndex-1].score + sumOfCurrFrameRolls;
    }
    else
    {
        score = sumOfCurrFrameRolls;
    }
    return score;
 }

  void BowlingGame::updateFrame(unsigned int nxtRoll, unsigned int frameIndex)
  {
    Frame& currFrame = frames[frameIndex];
    if(currFrame.numBonusRollsRemaining > 0)
    {
        currFrame.sumOfRolls += nxtRoll;
        currFrame.numBonusRollsRemaining--;
        currFrame.score = calculateFrameScore(currFrame.sumOfRolls, frameIndex);
    }
  }

  const Frame& BowlingGame::getFrame(int idx)const
  {
        return frames[idx];
  }
} // namespace BG