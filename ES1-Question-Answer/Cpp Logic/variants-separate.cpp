#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
// #include <typeinfo>
#include "json.hpp"


using json = nlohmann::json;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::setw;
using std::to_string;

int main (){


    ifstream variantsfile("variants.json");
    json variants;
    variantsfile >> variants;

    ifstream answersfile("answers.json");
    json answers;
    answersfile >> answers;
    int choosedAnswer;
    string answermean;
    int attributeNumbertest = 2;
    // choosedAnswer = answers[("question5")]["choosedAnswer"];
    // cout << choosedAnswer << endl;
    // cout << answers[("question5")]["answers"][to_string(choosedAnswer)] << endl;

    for(int deviceNumber = 1; deviceNumber < variants.size(); deviceNumber++) { 
        for(int attributeNumber = 1; attributeNumber < variants[("device" + to_string(deviceNumber))]["attributes"].size(); attributeNumber++) {
            for (int attributeinarray = 0; attributeinarray < variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))].size(); attributeinarray++) {
                // for (int questionNumber = 1; questionNumber < answers.size(); questionNumber++) { 
                // if (variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))][attributeinarray] == answers[("question" + to_string(questionNumber))]["choosedAnswer"]) {
                //     variants[("device" + to_string(deviceNumber))]["matchquestion"][(to_string(attributeNumber))] = "true";
                    //    cout << variants[deviceNumberStr]["matchquestion"].dump(4) << endl;
                    // if (answers["question" + to_string(attributeNumber)]["skip"] != "true" && answers[("question" + to_string(attributeNumber))]["choosedAnswer"] != "null") {
                    //     cout << answers[("question" + to_string(attributeNumber))]["choosedAnswer"];
                    // }
                    // answermean = answers[("question" + to_string(attributeNumber))]["answers"][to_string(choosedAnswer)];
                    if (variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))][attributeinarray] == answers[("question" + to_string(attributeNumber))]["choosedAnswer"] && variants[("device" + to_string(deviceNumber))]["skip"] != "true" && to_string(answers["question" + to_string(attributeNumber)]["skip"]) != "true") {
                    variants[("device" + to_string(deviceNumber))]["matchquestion"][(to_string(attributeNumber))] = "true";
                    // if (variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))][attributeinarray] == answers[("question" + to_string(attributeNumber))]["choosedAnswer"] && variants[("device" + to_string(deviceNumber))]["skip"] != "true") {
                    // variants[("device" + to_string(deviceNumber))]["matchquestion"][(to_string(attributeNumber))] = "true";

                }
            // }
           }
       }
    }   
       
        std::vector<int> topdevicescore;
        std::vector<string> topdevicestring;
        for (int deviceNumber = 1; deviceNumber < variants.size(); deviceNumber++) {
            topdevicescore.push_back(variants[("device" + to_string(deviceNumber))]["matchquestion"].size());
            topdevicestring.push_back(variants[("device" + to_string(deviceNumber))]["0.devicename"]);
            // cout << variants[("device" + to_string(deviceNumber))]["0.devicename"] << " = " << variants[("device" + to_string(deviceNumber))]["matchquestion"].size() << endl;
        }
        // for ( int n : topdevicescore ) {
        // std::cout << n << '\n';
        // }

        std::vector<int>::iterator it = std::find(topdevicescore.begin(), topdevicescore.end(), *max_element(topdevicescore.begin(), topdevicescore.end()));
        int index = std::distance(topdevicescore.begin(), it);
        cout << "Congratulations! The best choice for you was generated. Here are the results: " << endl << endl << topdevicestring[index] << endl;


    
return 0;


}
