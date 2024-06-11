#include "Addons.h"

/* This function is used in the quick sort This makes one index the piviot of the array
And then it sorts the array such that the smaller ones are on the left of the piviot and
the bigger ones are on the right side of the piviot and then it returns the piviot */
int partition(vector<Prisoners *> &array, int first, int last)
{
    Prisoners *piviot = array[last];
    int j = first - 1;
    for (int i = first; i < last; i++)
    {
        /*yaar main ni khelta yaar ye kya chawal he mujh se ni hora ye code theek kya L he ye sara 😭😭😭😭😭😭😭*/
        if (array[i]->root->less_than(piviot->root))
        {
            j++;
            swap(array[j], array[i]);
        }
    }
    swap(array[j + 1], array[last]);
    piviot = nullptr;
    return j + 1;
}

void quick_sort(vector<Prisoners *> &array, int first, int last)
{
    if (first < last)
    {
        int mid = partition(array, first, last); // ye function hmeen mid point deta he
        quick_sort(array, first, mid - 1);       // mid se left pe recurse kro
        quick_sort(array, mid + 1, last);        // mid se right pe recurse kro
    }
}

// the peek function checks the next character in the file without extracting it.
// if teh peek is equal to the end of file character then that means there are no more characters to read.
// since we are checking the first character then that means there are no characters in the file at all.
bool is_it_empty(ifstream &pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

char *get_time()
{
    // current date and time on the current system
    time_t now = time(0);
    return ctime(&now);
}

vector<string> customSplit(string str, char separator)
{
    vector<string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++)
    {

        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size())
        {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}

bool fine_sentence(string data)
{
    if (data == "Life without parole"|| data == "life without parole"|| data == "forever"|| data == "Forever" || data == "N/A")
    {
        return false;
    }
    vector<string> split;
    if (data[0] == ' ')
        return true;
    {
        char seperator = ' ';
        split = customSplit(data, seperator);
    }
    if (split.size() <= 1 || split.size() > 2)
        return true;
        
    for (auto &&i : split[0])
    {
        if (!isdigit(i) && i != '.')
            return true;
    }

    if (split[1] != "month" && split[1] != "Month" && split[1] != "months" && split[1] != "Months" && split[1] != "year" && split[1] != "Year" && split[1] != "years" && split[1] != "Years")
        return true;
    return false;
}
