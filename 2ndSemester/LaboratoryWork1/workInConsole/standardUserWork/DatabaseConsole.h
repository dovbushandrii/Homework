#pragma once

#include "../../dataStructures/Train.h"
#include "GetTrain.h"

using namespace std;

class DatabaseConsole {
public:
    static void save__(void saveTrain(Train)) {
        saveTrain(getTrainFromConsole());
    }

    static void print__(string getTrains()) {
        cout << getTrains();
    }

    static void clear__(void clearTrains()) {
        clearTrains();
    }

    static void change__(string getTrainsWith(), void changeTrain(int, Train)) {
        int id = 0;
        while (true) {
            try {
                cout << getTrainsWith();
                cout << "Witch id changeTrain?" << endl << "id = ";
                cin >> id;
                changeTrain(id, getTrainFromConsole());
                break;
            }
            catch (const std::invalid_argument &ia) {
                continue;
            }
        }
    }

    static void delete__(string getTrainsWithID(), void deleteTrain(int)) {
        int id = 0;
        while (true) {
            try {
                cout << getTrainsWithID();
                cout << "Witch id delete?" << endl << "id = ";
                cin >> id;
                deleteTrain(id);
                break;
            }
            catch (const std::invalid_argument &ia) {
                continue;
            }
        }
    }

    static void task1__(vector<Train> task1(string)) {
        vector<Train> taskResult;
        string lastFragmentOfName;
        cout << "Last fragment of name: ";
        cin >> lastFragmentOfName;
        taskResult = task1(lastFragmentOfName);
        for (int i = 0; i < taskResult.size(); ++i) {
            cout << taskResult[i].getInText() << endl;
        }
    }

    static void task2__(vector<Train> task2(Destination, string, string)) {
        vector<Train> taskResult;
        Destination destination;
        string destinationString;
        string number1;
        string number2;
        do {
            cout << "Destination: " << endl;
            for (int i = 0; i < DestinationMap.size(); ++i) {
                cout << "\"" << to_string(i + 1) << "\" - " << DestinationMap[i] << endl;
            }
            cout << "Destination: ";
            cin >> destinationString;
        } while (destinationString.length() != 1 ||
                 (destinationString[0] <= '0' || destinationString[0] > '4'));
        destination = static_cast<Destination>(stoi(destinationString) - 1);

        do {
            cout << "Number 1 (\"nnnn\"): ";
            cin >> number1;
        } while (number1.length() != 4 || !isItInt(number1));

        do {
            cout << "Number 2 (\"nnnn\"): ";
            cin >> number2;
        } while (number2.length() != 4 || !isItInt(number2));

        if (stoi(number1) > stoi(number2)) {
            taskResult = task2(destination, number2, number1);
        } else {
            taskResult = task2(destination, number1, number2);
        }
        for (int i = 0; i < taskResult.size(); ++i) {
            cout << taskResult[i].getInText() << endl;
        }
    }

    static void task3__(vector<Train> task3(Date)) {
        vector<Train> taskResult;
        string departureHourString;
        string departureMinuteString;
        string departureDayString;
        string departureMonthString;
        string departureYearString;
        Date departure;
        string lastFragmentOfName;
        while (true) {
            do {
                cout << "Departure date (\"h m d m y\"): ";
                cin >> departureHourString >> departureMinuteString >> departureDayString >> departureMonthString
                    >> departureYearString;
            } while (!isItInt(departureHourString) || !isItInt(departureMinuteString) || !isItInt(departureDayString) ||
                     !isItInt(departureMonthString) || !isItInt(departureYearString));
            try {
                departure = Date(stoi(departureHourString), stoi(departureMinuteString), stoi(departureDayString),
                                 stoi(departureMonthString), stoi(departureYearString));
                break;
            }
            catch (const std::invalid_argument &ia) {
                continue;
            }
        }
        taskResult = task3(departure);
        for (int i = 0; i < taskResult.size(); ++i) {
            cout << taskResult[i].getInText() << endl;
        }
    }
};
