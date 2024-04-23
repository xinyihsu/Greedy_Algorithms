#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int roomNum = 1;
    vector<float> roomFT = {0};
    vector<vector<int>> roomQueue;
    int lecturesNum = 10;
    // vector<pair<float, float>> lecturesTime = {{9, 10}, {11, 16}, {12.5, 13.5}, 
    //     {10.5, 16}, {9.5, 14}, {10.5, 13}, {11.5, 15.5}, {12.5, 16.5}, {11, 12}, 
    //     {9.5, 14}, {11.5, 17}, {9.5, 15.5}, {12, 17.5}, {11.5, 14}, {12.5, 15}, 
    //     {11, 16}, {12, 17}, {15.5, 16.5}, {16.5, 17.5}, {9, 16}};
    vector<pair<float, float>> lecturesTime = {{9, 10}, {9.5, 14}, 
        {10.5, 16}, {10.5, 13}, {11, 16}, {11, 12}, {11.5, 15.5}, {12.5, 16.5}, {12.5, 13.5}, {16.5, 17.5}};
    
    //sort by starting time
    // int index = 0;
    // for (int i = 0; i < lecturesNum; i++) {
    //     int min = 0;
    //     //if (lecturesTime[])
    // }
    cout << 1111111;
    for (int i = 0; i < lecturesNum; i++) {
        bool ifAdd = false;
        for (int roomIndex = 0; roomIndex < roomNum; i++) {
            if (lecturesTime[i].first >= roomFT[roomIndex]) {
                roomQueue[roomIndex].push_back(i + 1);
                roomFT[roomIndex] = lecturesTime[i].second;
                ifAdd = true;
                break;
            }
        }
        if (!ifAdd) {
            roomNum++;
            vector<int> newRoom = {i + 1};
            roomQueue.push_back(newRoom);            
            roomFT.push_back(lecturesTime[i].second);
        }
    }
    cout << roomNum;
    // for (int i = 0; i < roomNum; i++) {
    //     cout << "room" << i << endl;
    //     for (int j = 0; j < roomQueue[i].size(); j++) {
    //         int index = roomQueue[i][j];
    //         cout << index << " : " << lecturesTime[index].first << " " << lecturesTime[index].second << endl;
    //     }
    //     cout << endl;
    // }
}