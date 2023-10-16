#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }
// Map 1
    map<string, TwitterData> XMap;
    for (size_t i = 0; i < 5; i++)
    {
        XMap.insert(pair<string, TwitterData>(twitter_data[i].getUserName[i][0], twitter_data));
    }
    cout << "Print SearchByName Map:" << endl;
    for (std::map<std::string, TwitterData>::iterator Num = XMap.begin();Num != XMap.end(); Num++)
    {
        cout << "Username: " << Num->first << "Value: " << Num->first << "," << Num->second.getActualName() << "," <<Num->second.getEmail() << "," << Num->second.getNumTweets() << "," << Num->second.getCategory() << endl;
    }

    XMap.find("savage1"); // find savage1
    if (Xmap.find("savage1") != nullptr) //see if its ture if so delete
    {
        for (std::map<std::string, TwitterData>::iterator Num = XMap.begin();Num != XMap.end(); Num++)
        {
            if(Num->first == "savage1")
            {
             cout<< "savage1 found" << endl;
             cout << "Username: " << Num->first << "Value: " << Num->first << "," << Num->second.getActualName() << "," <<Num->second.getEmail() << "," << Num->second.getNumTweets() << "," << Num->second.getCategory() << endl;
             XMap.earse(num);
             cout << "This entry has been deleted" << endl;
            }
        }
    }
    
// Map 2
     map<string, TwitterData> XMap2;
    for (size_t i = 0; i < 5; i++)
    {
        XMap2.insert(pair<string, TwitterData>(twitter_data[i].getUserName[i][0], twitter_data));
    }
    cout << "Print SearchByName Email:" << endl;
    for (std::map<std::string, TwitterData>::iterator Num = XMap.begin();Num != XMap.end(); Num++)
    {
        cout << "Username: " << Num->second.getEmail() << "Value: " << Num->first << "," << Num->second.getActualName() << "," <<Num->second.getEmail() << "," << Num->second.getNumTweets() << "," << Num->second.getCategory() << endl;
    }
    
    for (std::map<std::string, TwitterData>::iterator Num = XMap.begin();Num != XMap.end(); Num++)
    {
        if(XMap2.find("kat@gmail.com") != nullptr)
        {
            if(Num->second.getEmail() == "kat@gmail.com")
            {
                cout<< "Kat@gmail.com found" << endl;
                cout << "Username: " << Num->second.getEmail() << "Value: " << Num->first << "," << Num->second.getActualName() << "," <<Num->second.getEmail() << "," << Num->second.getNumTweets() << "," << Num->second.getCategory() << endl;
                XMap2.erase(Num);
                cout << "This entry has been deleted" << endl;
            }
        }
    }
    

    return 0;
}
