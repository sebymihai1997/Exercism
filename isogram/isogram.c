/*
 The function takes a string and return a boolean value indicating whether the phrase is isogram or not.
 An isogram is a word or a phrase in which no letter occurs more than once.
*/
#include "isogram.h"

bool is_isogram(const char phrase[])
{
    int i,j,len;
    bool isogram=true;
    char phraseLocal[50];

    //Check if the input phrase is not null and copies the content of the phrase into the phraseLocal and determines the length of phraseLocal.
    if(phrase!=NULL)
    {
        strcpy(phraseLocal,phrase);

        len=strlen(phraseLocal);
        //Convert all characters into lowercase.
        for(i=0;i<len;i++)
        {
            phraseLocal[i]=tolower(phraseLocal[i]);
        }
        //Check if the phraseLocal contains any duplicate characters excluding spaces and hyphens.
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(phraseLocal[i]==phraseLocal[j]&&phraseLocal[i]!='-'&&phraseLocal[i]!=' ')
                 {
                    isogram=false;
                    break;
                 }
//                else
//                    isogram=true;
            }
            if(isogram==false)
                break;
        }
    }
    else
            isogram=false;


    return isogram;
}
