//
//  ESQuestion.h
//  ES1-Question-Answer
//
//  Created by Moris on 11/03/2020.
//  Copyright © 2020 Moris. All rights reserved.
//

#ifndef ESQuestion_h
#define ESQuestion_h

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
// using std::ostringstream;
using std::to_string;
using std::count;
using std::setw;



class ESQuestion {
    
public:
    
    ESQuestion();
    
    ~ESQuestion()
    {
        
    }
    
    void mainCompute();
    
    void saveAnswers();
    
    void setChoosedAnswer(int answer);
    
    json getQuestions();
    int getQuestionNumber();
    int getIterAnswerNumber();
    std::string testGet();
    
private:
    
    ifstream questionsfile;
    json questions; //
    
    int questionNumber; //
    string questionStr;
    string AnswerStr;
    int choosedAnswer;
    string skipquestioniter;
    
    int iterAnswersNumber; //
    
};

#endif /* ESQuestion_h */
