#include "FormTest.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void FormTest::Initialize()
{
    FormQuestion question;
    question.Set<std::string>("Are you a hotdog?","");
    formData.emplace("1",question);

    question.Set<float>("what hotdog # are you?",0);
    formData.emplace("2",question);
}
void FormTest::Content()
{
    // cout << formData["1"].GetQuestion() << endl;
    int num = 1;
    for(auto& kv : formData){//kv.second.GetQuestion()
        cout << num << ". " << kv.second.GetQuestion() << "\t";
        kv.second.GetInput();
        num++;
    }
}

void FormTest::AskForInput()
{
    std::string res = formData["1"].GetResponse<std::string>();
    // float res = std::get<float>(formData["1"].GetResponse2());
    cout << "the truth is - " << res << endl;

    float res2 = formData["2"].GetResponse<float>();
    // float res = std::get<float>(formData["1"].GetResponse2());
    cout << "the hotdog # is - " << res2 << endl;
}
