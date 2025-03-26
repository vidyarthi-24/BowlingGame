#include "BowlingGame.h" // Ensure this file exists in the same directory as this source file

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
    if(frameCount == MAX_NUM_FRAMES-1)//last frame
    {
        fillLastFrame(inPins);
    }
    else
    {
        if(currFrame.rollCount < 2)
        {
            currFrame.sumOfRolls += inPins;
            currFrame.score = calculateFrameScore(currFrame.sumOfRolls, frameCount);//dynamicallly updates score
            currFrame.rollCount++;
    
            if(currFrame.sumOfRolls == MAX_PINS)
            {
                if(currFrame.rollCount == 1)//isStrike
                {
                    currFrame.numBonusRollsRemaining = 2;
                }
                else //isSpare
                {
                    currFrame.numBonusRollsRemaining = 1;
                }
            }
            if((currFrame.sumOfRolls == MAX_PINS)||(currFrame.rollCount == 2))
            {      
                frameCount++;
            }
        }        
    }
}

void BowlingGame::roll(int inPins)
{
    if(frameCount < MAX_NUM_FRAMES)
    {
        int numPreviousFramesEligibleForBonus = frameCount>1?2:(frameCount>0?1:0);
        for(int i = frameCount-numPreviousFramesEligibleForBonus; i<frameCount; i++)
        {
            updateFrame(inPins, i);
        }
        
        // if(frameCount>1)//two frames ago
        // {
        //     updateFrame(inPins, frameCount-2);

        // }

        // if(frameCount>0)// one frame ago
        // {
        //     updateFrame(inPins, frameCount-1);
        // }

        fillFrame(inPins);
    }
}

 int BowlingGame::calculateFrameScore( int sumOfCurrFrameRolls, int frameIndex)
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
    if(currFrame.numBonusRollsRemaining>0)
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
