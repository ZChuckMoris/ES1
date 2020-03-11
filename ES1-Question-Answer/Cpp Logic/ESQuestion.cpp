//
//  ESQuestion.cpp
//  ES1-Question-Answer
//
//  Created by Moris on 11/03/2020.
//  Copyright © 2020 Moris. All rights reserved.
//

#include "ESQuestion.h"

#pragma mark - Constructor

ESQuestion::ESQuestion():
questionsfile("questions.json"), questionNumber(1), questionStr(""), AnswerStr(""), choosedAnswer(0), skipquestioniter(""), iterAnswersNumber(0)
{
    questionsfile >> questions;
    
#pragma mark - here we erase values "skip" and "choosedAnswer" under any question to prevent mistakes.
        for (int iterquestionnumber = 1; iterquestionnumber != (int)questions.size(); iterquestionnumber++) {
            questionStr = "question" + to_string(iterquestionnumber);
            questions[questionStr].erase("skip");
            questions[questionStr].erase("choosedAnswer");
            // cout << "erasing 'skip' in " << questionStr << endl;
        }
    
        questionNumber = 1;
        questionStr = "question" + to_string(questionNumber);
}

#pragma mark - mainCompute
void ESQuestion::mainCompute()
{
    // AnswerStr = "answer";
    if (questions[questionStr]["skip"] == true) {
        cout << questionNumber;
        questionNumber = questionNumber + 1;
        questionStr = "question" + to_string(questionNumber);
        // cout << "questionStr: " << questionStr << endl;
    } else {
        // cout << "questionStr: " << questionStr << endl;
        cout << questions[questionStr]["0.questionName"] << endl;
        for (iterAnswersNumber = 0; iterAnswersNumber != (int)questions[questionStr]["answers"].size(); iterAnswersNumber++) {
            // cout << iterAnswersNumber << endl;
            // AnswerStr = "answer" + std::to_string(iterAnswersNumber);
            // AnswerStr = '"' + std::to_string(iterAnswersNumber);
            cout << "[" << iterAnswersNumber << "] "<< questions[questionStr]["answers"][std::to_string(iterAnswersNumber)] << endl;
        }
        cin >> choosedAnswer;
        // while (true)
        // {
        //     getline(cin, choosedAnswer);
        //     std::stringstream answerstream(choosedAnswer);
        //     if (answerstream >> choosedAnswer)
        //         break;
        //     cout << "Invalid number, please try again\n";
        // }
        // while (true) {
        //     if (std::cin.get() == '\n') {
        //         std::cout<<"ENTER WAS PRESSED"<<std::endl;
        //     }
        // }
        questions[questionStr]["choosedAnswer"] = choosedAnswer;
        questionNumber = (int)questions[questionStr]["goto"][std::to_string(choosedAnswer)];
        for (json::iterator arrayiterator = questions[questionStr]["noAsk"][std::to_string(choosedAnswer)].begin(); arrayiterator != questions[questionStr]["noAsk"][std::to_string(choosedAnswer)].end(); ++arrayiterator) {
            skipquestioniter = "question" + to_string(*arrayiterator);
            questions[skipquestioniter]["skip"] = true;
        }
        // if (questions[questionStr][answerGotoStr][2] = 0) {
        // }
        // questionNumber = (int)questions[questionStr][answerGotoStr];
        questionStr = "question" + to_string(questionNumber);
    }
}

#pragma mark - saveAnswers
void ESQuestion::saveAnswers()
{
    if (remove("answers.json") == 0)
        printf("Previous JSON file deleted successfully \n");
        else
        printf("Unable to delete previous JSON file \n");
    
        for (int iterquestionnumber = 1; iterquestionnumber != (int)questions.size(); iterquestionnumber++) {
            questionStr = "question" + to_string(iterquestionnumber);
            questions[questionStr].erase("goto");
            questions[questionStr].erase("noAsk");
            // cout << "erasing 'skip' in " << questionStr << endl;
        }
    
        std::ofstream answerssave("answers.json");
        answerssave << setw(4) << questions << std::endl;
    
        cout << "New JSON file was saved successfully" << endl;
}

#pragma mark - Getters and Setters

void ESQuestion::setChoosedAnswer(int answer) {
    choosedAnswer = answer;
}

std::string ESQuestion::testGet()
{
    return questions[questionStr]["0.questionName"];
}

json ESQuestion::getQuestions()
{
    return questions;
}
int ESQuestion::getQuestionNumber()
{
    return questionNumber;
}
int ESQuestion::getIterAnswerNumber()
{
    return iterAnswersNumber;
}
