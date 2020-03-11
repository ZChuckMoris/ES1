//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <sstream>
//#include <iomanip>
//// #include <typeinfo>
//#include "json.hpp"
//
//
//using json = nlohmann::json;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::vector;
//using std::ifstream;
//// using std::ostringstream;
//using std::to_string;
//using std::count;
//using std::setw;

//int main (){
//
//
//    ifstream questionsfile("questions.json");
//    json questions;
//    questionsfile >> questions;
//
//
//    int questionNumber = 1;
//    string questionStr;
//    string AnswerStr = "";
////    int answerGotoInt = 0;
//    int choosedAnswer = 0;
//    string skipquestioniter = "";
//
//    // cout << (int)questions.size();
//
//#pragma mark - here we erase values "skip" and "choosedAnswer" under any question to prevent mistakes.
//    for (int iterquestionnumber = 1; iterquestionnumber != (int)questions.size(); iterquestionnumber++) {
//        questionStr = "question" + to_string(iterquestionnumber);
//        questions[questionStr].erase("skip");
//        questions[questionStr].erase("choosedAnswer");
//        // cout << "erasing 'skip' in " << questionStr << endl;
//    }
//
//    questionNumber = 1;
//    questionStr = "question" + to_string(questionNumber);
//
//    // std::ofstream questionssave("questions.json");
//    // questionssave << setw(4) << questions << std::endl;
//
//    // cout << "erased 'skip' and 'choosedAnswer'. " << endl;
//    // cout << "New JSON file was saved successfully" << endl;
//
//    cout << "Enter number of your desired answer." << endl;
//    while (questionNumber > 0 && questionNumber < (int)questions.size()) {
//        // AnswerStr = "answer";
//        if (questions[questionStr]["skip"] == true) {
//            cout << questionNumber;
//            questionNumber = questionNumber + 1;
//            questionStr = "question" + to_string(questionNumber);
//            // cout << "questionStr: " << questionStr << endl;
//        } else {
//            // cout << "questionStr: " << questionStr << endl;
//            cout << questions[questionStr]["0.questionName"] << endl;
//            for (int iterAnswersNumber = 0; iterAnswersNumber != (int)questions[questionStr]["answers"].size(); iterAnswersNumber++) {
//                // cout << iterAnswersNumber << endl;
//                // AnswerStr = "answer" + std::to_string(iterAnswersNumber);
//                // AnswerStr = '"' + std::to_string(iterAnswersNumber);
//                cout << "[" << iterAnswersNumber << "] "<< questions[questionStr]["answers"][std::to_string(iterAnswersNumber)] << endl;
//            }
//            cin >> choosedAnswer;
//            // while (true)
//            // {
//            //     getline(cin, choosedAnswer);
//            //     std::stringstream answerstream(choosedAnswer);
//            //     if (answerstream >> choosedAnswer)
//            //         break;
//            //     cout << "Invalid number, please try again\n";
//            // }
//            // while (true) {
//            //     if (std::cin.get() == '\n') {
//            //         std::cout<<"ENTER WAS PRESSED"<<std::endl;
//            //     }
//            // }
//            questions[questionStr]["choosedAnswer"] = choosedAnswer;
//            questionNumber = (int)questions[questionStr]["goto"][std::to_string(choosedAnswer)];
//            for (json::iterator arrayiterator = questions[questionStr]["noAsk"][std::to_string(choosedAnswer)].begin(); arrayiterator != questions[questionStr]["noAsk"][std::to_string(choosedAnswer)].end(); ++arrayiterator) {
//                skipquestioniter = "question" + to_string(*arrayiterator);
//                questions[skipquestioniter]["skip"] = true;
//            }
//            // if (questions[questionStr][answerGotoStr][2] = 0) {
//            // }
//            // questionNumber = (int)questions[questionStr][answerGotoStr];
//            questionStr = "question" + to_string(questionNumber);
//        }
//
//    }
//
//
//    // questionStr = "questions10";
//    // for (json::iterator answersiterator = questions[questionStr]["goto"].begin(); answersiterator != questions[questionStr]["goto"].end(); ++answersiterator) {
//    //     std::cout << *answersiterator << '\n';
//    // }
//
//
//    // for (auto& element : questions) {
//    //     std::cout << element << '\n';
//    // }
//
//    if (remove("answers.json") == 0)
//    printf("Previous JSON file deleted successfully \n");
//    else
//    printf("Unable to delete previous JSON file \n");
//
//    for (int iterquestionnumber = 1; iterquestionnumber != (int)questions.size(); iterquestionnumber++) {
//        questionStr = "question" + to_string(iterquestionnumber);
//        questions[questionStr].erase("goto");
//        questions[questionStr].erase("noAsk");
//        // cout << "erasing 'skip' in " << questionStr << endl;
//    }
//
//    std::ofstream answerssave("answers.json");
//    answerssave << setw(4) << questions << std::endl;
//
//    cout << "New JSON file was saved successfully" << endl;
//
//    return 0;
//}

