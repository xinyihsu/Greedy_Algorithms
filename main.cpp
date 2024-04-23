#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Lecture {
    int startTime;
    int endTime;
    int num;
};

bool sortCompare(const Lecture&, const Lecture&);
void printLectures(const vector<Lecture>& lectures);
void printRooms(const vector<vector<Lecture>>& rooms);

int main()
{
    vector<int> roomFT;
    vector<vector<Lecture>> roomQueue;
    int lecturesNum = 20;
    vector<Lecture> lectures = {
        {900, 1000}, {1100, 1600}, {1230, 1330}, {1030, 1600}, {930, 1400},
        {1030, 1300}, {1130, 1530}, {1230, 1630}, {1100, 1200}, {930, 1400},
        {1130, 1700}, {930, 1530}, {1200, 1730}, {1130, 1400}, {1230, 1500},
        {1100, 1600}, {1200, 1700}, {1530, 1630}, {1630, 1730}, {900, 1600}
    };

    for (int i = 0; i < lecturesNum; i++) {
        lectures[i].num = i + 1;
    }

    //sort by starting time
    sort(lectures.begin(), lectures.end(), sortCompare);
    printLectures(lectures);


    for (int i = 0; i < lecturesNum; i++) {
        bool ifAdd = false;
        for (int roomIndex = 0; roomIndex < roomFT.size(); i++) {
            if (lectures[i].startTime >= roomFT[roomIndex]) {
                roomFT[roomIndex] = lectures[i].endTime;
                roomQueue[roomIndex].push_back(lectures[i]);
                cout << i << " " << roomIndex << " " << roomFT[roomIndex] << endl;
                ifAdd = true;
                break;
            }
        }
        if (!ifAdd) {
            roomFT.push_back(lectures[i].endTime);
            vector<Lecture> newRoom = {lectures[i]};
            roomQueue.push_back(newRoom);            
            cout << "add";
        }
    }
    cout << roomFT.size() << endl;
    printRooms(roomQueue);
    cout << "end";
}

bool sortCompare(const Lecture& second, const Lecture& first) {
    return second.startTime < first.startTime;
}

void printLectures(const vector<Lecture>& lectures) {
    for (int i = 0; i < lectures.size(); i++) {
        cout << lectures[i].num << " " << lectures[i].startTime << " " << lectures[i].endTime << endl;
    }
}

void printRooms(const vector<vector<Lecture>>& rooms) {
    int index = 1;
    for (const vector<Lecture>& room : rooms) {
        cout << "room:" << index;
        for (const Lecture& lecture : room) {
            cout << lecture.num << " " << lecture.startTime << " " << lecture.endTime << endl;
        }
        index++;
        cout << endl;
    }
}