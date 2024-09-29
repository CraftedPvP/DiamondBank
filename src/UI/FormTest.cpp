#include "FormTest.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

void FormTest::Initialize()
{
    FormQuestion question;
    question.Set<std::string>("Are you a hotdog","");
    formData.emplace("1",question);

    question.Set<int>("what hotdog # are you",0);
    formData.emplace("2",question);

    question.Set<float>("how much are you",0.f);
    formData.emplace("3",question);
}
void FormTest::Content()
{
    int num = 1;
    for(auto& kv : formData){
        cout << num << ". " << kv.second.GetQuestion() << "\t";
        kv.second.GetInput();
        num++;
    }
}

void FormTest::ProcessInput()
{
    cout << endl;

    std::string res = formData["1"].GetResponse<std::string>();
    cout << "the truth is - " << res << endl;

    int res2 = formData["2"].GetResponse<int>();
    cout << "you are #" << res2 << endl;

    float res3 = formData["3"].GetResponse<float>();
    cout << "price is - $" << res3 << endl;
}
