#include "FormTest.h"
#include <iostream>
#include <iomanip> // std::setw

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::setw;

void FormTest::Initialize()
{
    FormQuestion question;
    // question.Set<std::string>("Are you a hotdog?","");
    std::string questionn = "Are you a hotdog?";
    question.Set<float>(questionn,0);
    formData.emplace("1",question);
}
void FormTest::Content()
{
    // cout << formData["1"].GetQuestion() << endl;
    int num = 1;
    for(auto kv : formData){//kv.second.GetQuestion()
        cout << num << ". " << kv.second.GetQuestion() << setw(10) << std::right;
        kv.second.GetInput();
    }
}

void FormTest::AskForInput()
{
    float res = formData["1"].GetResponse<float>();
    // float res = std::get<float>(formData["1"].GetResponse2());
    cout << "the truth is - " << res << endl;
    formData["1"].PrintResponse();
}
