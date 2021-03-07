#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    string str, temp;
    string current_word = "";
    string answer = "";
    int repetitions;
    set <string> word_list;

    getline(cin, str);

    cin >> repetitions;
    for (int i = 0; i < repetitions; i++){
        cin >> temp;
        word_list.insert(temp);
    }
    
    for (int j = 0; j < str.size(); j++){
        if (str[j] != ' '){
            current_word += str[j];
        }
        else {
            if ((word_list.find(current_word) != word_list.end()) && (repetitions > 0)){
                temp = "/*" + current_word + "*/ ";
                answer += temp;
                repetitions--;
                current_word = "";
            } else {
                answer += current_word + " ";
                current_word = "";
            }
        }
    }
    if ((word_list.find(current_word) != word_list.end()) && (repetitions > 0)){
        temp = "/*" + current_word + "*/ ";
        answer += temp;
        repetitions--;
    } else {
        answer += current_word + " ";
    }

   

  cout << answer;
}