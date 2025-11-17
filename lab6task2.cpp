#include <iostream>
#include <vector>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

void activitySelection(vector<Activity>& activities) {
    int n = activities.size();
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(activities[j].finish > activities[j + 1].finish) {
                Activity temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }
    
    vector<int> selected;
    selected.push_back(activities[0].id);
    int lastFinishTime = activities[0].finish;
    
    for(int i = 1; i < n; i++) {
        if(activities[i].start >= lastFinishTime) {
            selected.push_back(activities[i].id);
            lastFinishTime = activities[i].finish;
        }
    }
    
    cout << "Selected Activities: ";
    for(int i = 0; i < selected.size(); i++) {
        cout << selected[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "welcome to the world of analysis of algorithm with umar ahad usmani (sap:60199)" << endl;
    
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    vector<Activity> activities(n);
    
    for(int i = 0; i < n; i++) {
        activities[i].id = i + 1;
        cout << "Enter start and finish time for activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }
    
    activitySelection(activities);
    
    return 0;
}
