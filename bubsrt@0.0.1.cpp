#include <iostream>
#include <sstream>

using namespace std;

bool input(float * &elements, int num)
{
    float *tmp_elements;
    string str;

    getline(cin, str);

    tmp_elements = new float [num];

    for (string str; getline(cin, str); ) {
        std::istringstream stream(str);
        for (unsigned int j = 0; j < num; ++j) {
            if(!(stream >> tmp_elements[j])) {
                return false;
            }
        }
        break;
    }
    elements = tmp_elements;
    return true;
}

void bubsort(float *elements, int num)
{
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (elements[j] > elements[j + 1]) {
                swap(elements[j], elements[j + 1]);
            }
        }
    }
}

int main() {
    float *elements;
    int num;

    if(!(cin>>num)||(num < 0))
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    if(!(input(elements,num)))
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    bubsort(elements, num);
    for (int i = 0; i < num; i++) cout << elements[i]<<' ';
    
    delete[] elements;
    return 0;
}
