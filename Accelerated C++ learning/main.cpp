#include <iostream>
#include <string>

//Standard library names used in this program
using std::cout;    using std::endl;
using std::cin;     using std::string;

int main()
{
    //Get persons name
    cout << "Please enter your first name: ";

    //read the name
    string name;
    cin >> name;

    //Build message we intend to write
    string greeting = "Hello, " + name + "!";

    //Ask user for the intended vertical and horizontal padding
    cout << "Enter the desired vertical padding: ";
    int padVertical;
    cin >> padVertical;
    cout << endl;
    cout << "Enter the desired horizontal padding: ";
    int padHorizontal;
    cin >> padHorizontal;
    cout << endl;

    //the number of rows and columns to write
    int rows = padVertical * 2 + 3;
    string::size_type cols = greeting.size() + padHorizontal * 2 + 2;

    //writes two blank lines to separate output from input
    cout << endl;
    cout << endl;

    //write rows rows of output
    //invariant: we have written r rows so far
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        //invariant: we have written c characters so far in the current row
        while (c != cols) {
            // is it time to write the greeting?
            if (r == padVertical + 1 && c == padHorizontal + 1) {
                cout << greeting;
                c += greeting.size();
            }
            //If we are on the row with the statement we only want to increment a few columns corresponding to the pad
            //When c == padHorizontal + 1, then we must execute the greeting command.
            else if (r == padVertical + 1 && c == 0){
                cout << "*" + string(padHorizontal, ' ');
                c += greeting.size() + 1;
            } else if (r == padVertical + 1 && c == 1 + padHorizontal + greeting.size()) {
                cout << (padHorizontal, ' ') + "*";
            } else {
                //are we on the border?
                if (r==0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }

    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cin.get();
    return 0;
}
