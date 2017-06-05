#include <iostream>

#include "FSObject.h"
#include "File.h"
#include "Directory.h"

int main()
{
    File HobbitPart1("Hobbit: An Unexpected Journey", "mkv", 4287);
    File HobbitPart2("Hobbit: The Desolation of Smaug", "mkv", 3894);
    File HobbitPart3("Hobbit: The Battle of the Five Armies", "mkv", 4402);

    File HobbitPart1Srt("HaUJ_subtitles", "srt", 0.1);
    File HobbitPart2Srt("HDoS_subtitles", "srt", 0.08);
    File HobbitPart3Srt("HBoFA_subtitles", "srt", 0.2);

    //add files to directory
    Directory HobbitTrilogy("Hobbit: Trilogy");
    HobbitTrilogy.addElement(HobbitPart1);
    HobbitTrilogy.addElement(HobbitPart2);
    HobbitTrilogy.addElement(HobbitPart3);
    HobbitTrilogy.addElement(HobbitPart1Srt);
    HobbitTrilogy.addElement(HobbitPart2Srt);
    HobbitTrilogy.addElement(HobbitPart3Srt);


    File FightClub("Fight Club", "avi", 1446);
    File FightClubSrt("FC_subtitles", "srt", 0.07);

    Directory FightClubMovie("Fight Club");
    FightClubMovie.addElement(FightClub);
    FightClubMovie.addElement(FightClubSrt);


    //add to directory 2 others directories and a file
    Directory Films("Films");
    Films.addElement(HobbitTrilogy);
    Films.addElement(FightClubMovie);
    Films.addElement(File("John Wick: Chapter 2", "mkv", 3978));

    std::cout<<"Space taken by "<<Films.getName()<<": "<<Films.getSize()<<" MB"<<std::endl;
    Films.print();
    return 0;
}
