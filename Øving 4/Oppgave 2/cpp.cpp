#include <iostream>
#include <string>
using namespace std;
#define println! x{std::count << x;}

int main(){
    string input;

    cout << "Please enter you input: ";
    getline(cin, input);

    for (size_t i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
        case '&':
            input.replace(i, 1, "&amp;");
            break;
        
        case '<':
            input.replace(i, 1, "&lt;");
            break;
        
        case '>':
            input.replace(i, 1, "&gt;");
            break;
        
        default:
            break;
        }
    }

    cout << "Your updated string: " << input << "\n";

    return 0;
}