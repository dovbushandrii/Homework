#pragma once

#include "Date.h"
#include "DestinationENUM.h"
#include "../saveTo/textFile/SaveConstants.h"

class Train {
public:
    string number;
    string optionalName;
    Destination destination;
    Date arrive = Date(0, 0, 0, 0, 1804);
    Date departure = Date(0, 0, 0, 0, 1804);
    double rate;

    Train(string number, string optionalName, Destination destination, Date arrive, Date departure, double rate) {
        if (number.length() != 4) {
            throw invalid_argument("incorrect Train number");
        }

        for (int i = 0; i < number.length(); i++) {
            if (number[i] < '0' || number[i] > '9') {
                throw invalid_argument("incorrect Train number");
            }
        }

        this->number = number;
        this->optionalName = optionalName;
        this->destination = destination;
        this->arrive = arrive;
        this->departure = departure;
        this->rate = rate;
    }

    string getTextToSave() {
        string textToSave = NUMBER + this->number + "\n" +
                            OPTIONAL_NAME + this->optionalName + "\n" +
                            DESTINATION + to_string(this->destination) + "\n" +
                            ARRIVE + this->arrive.getTextToSave() + "\n" +
                            DEPARTURE + this->departure.getTextToSave() + "\n" +
                            RATE + to_string(this->rate) + "\n";
        return textToSave;
    }
};
