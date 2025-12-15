
#include<iostream>
#include<vector>
using namespace std;

struct Appointment {
    double start;
    double end;
};

void optimizeSchedule(vector<Appointment>& appointments){
    int n = appointments.size();
    
    for (int i = 0 ; i < n-1 ; i++){
        for (int j = 0 ; j < n-i-1; j++){
            if (appointments[j].end > appointments[j+1].end){
                Appointment temp = appointments[j];
                appointments[j] = appointments[j+1];
                appointments[j+1] = temp;
            }
        }
    }

    vector<Appointment> selected;

   
    if (!appointments.empty()){
        selected.push_back(appointments[0]);
    }

  
    if (!selected.empty()) {
        double last_end_time = selected[0].end;

        for (int i = 1 ; i < appointments.size(); i++){
            if (appointments[i].start >= last_end_time){
                selected.push_back(appointments[i]);
                last_end_time = appointments[i].end;
            }
        }
    }

 
    cout << "Selected Schedule: [";
    for (size_t i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].start << ", " << selected[i].end << ")";
        if (i < selected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout <<" TOTAL patients that can be treated: " << selected.size() << endl;   
}

int main()
{
    vector<Appointment> appointments = {
        {10.5, 11.0},
        {9.0, 10.0},
        {9.5, 11.0},
        {10.0, 10.5},
        {11.0, 12.0},
        
    };
    optimizeSchedule(appointments);
    return 0;
}