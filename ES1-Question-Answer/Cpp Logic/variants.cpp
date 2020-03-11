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

    
    for(int deviceNumber = 1; deviceNumber < variants.size(); deviceNumber++) { 
        for(int attributeNumber = 1; attributeNumber < variants[("device" + to_string(deviceNumber))]["attributes"].size(); attributeNumber++) {
            for (int attributeinarray = 0; attributeinarray < variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))].size(); attributeinarray++) {
                // for (int questionNumber = 1; questionNumber < answers.size(); questionNumber++) { 
                // if (variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))][attributeinarray] == answers[("question" + to_string(questionNumber))]["choosedAnswer"]) {
                //     variants[("device" + to_string(deviceNumber))]["matchquestion"][(to_string(attributeNumber))] = "true";
                    //    cout << variants[deviceNumberStr]["matchquestion"].dump(4) << endl;
                    if (variants[("device" + to_string(deviceNumber))]["attributes"][(to_string(attributeNumber))][attributeinarray] == answers[("question" + to_string(attributeNumber))]["choosedAnswer"] && variants[("device" + to_string(deviceNumber))]["skip"] != "true") {
                    variants[("device" + to_string(deviceNumber))]["matchquestion"][(to_string(attributeNumber))] = "true";

                }
            // }
           }
       }
    }   
       
        std::vector<unsigned long int> topdevicescore;
        std::vector<string> topdevicestring;
        for (int deviceNumber = 1; deviceNumber < variants.size(); deviceNumber++) {
            topdevicescore.push_back(variants[("device" + to_string(deviceNumber))]["matchquestion"].size());
            topdevicestring.push_back(variants[("device" + to_string(deviceNumber))]["0.devicename"]);
        }
        // for ( int n : topdevicescore ) {
        // std::cout << n << '\n';
        // }

        std::vector<unsigned long int>::iterator it = std::find(topdevicescore.begin(), topdevicescore.end(), *max_element(topdevicescore.begin(), topdevicescore.end()));
        unsigned long int index = std::distance(topdevicescore.begin(), it);
        cout << "Congratulations! The best choice for you was generated. Here are the results: " << endl << endl << topdevicestring[index] << endl;


    
return 0;


}
