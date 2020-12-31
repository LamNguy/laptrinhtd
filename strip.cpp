// find the longest substring with k unique
// characters in a given string
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX_CHARS 26
using namespace std;


bool isValid(int count[], int k)
{
    int val = 0;
    for (int i=0; i<MAX_CHARS; i++)
        if (count[i] > 0)
            val++;

    // Return true if k is greater than or equal to val
    return (k >= val);
}

// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
    int u = 0; // number of unique characters
    int n = s.length();

    // Associative array to store the count of characters
    int count[MAX_CHARS];
    memset(count, 0, sizeof(count));

    // Traverse the string, Fills the associative array
    // count[] and count number of unique characters
    for (int i=0; i<n; i++)
    {
        if (count[s[i]-'1']==0)
            u++;
        count[s[i]-'1']++;
    }

    // If there are not enough unique characters, show
    // an error message.
    if (u < k)
    {
        cout << 1 << " " << n;
        return;
    }

    // Otherwise take a window with first element in it.
    // start and end variables.
    int curr_start = 0, curr_end = 0;

    // Also initialize values for result longest window
    int max_window_size = 1, max_window_start = 0;

    // Initialize associative array count[] with zero
    memset(count, 0, sizeof(count));

    count[s[0]-'1']++;  // put the first character

    // Start from the second character and add
    // characters in window according to above
    // explanation
    for (int i=1; i<n; i++)
    {
        // Add the character 's[i]' to current window
        count[s[i]-'1']++;
        curr_end++;

        // If there are more than k unique characters in
        // current window, remove from left side
        while (!isValid(count, k))
        {
            count[s[curr_start]-'1']--;
            curr_start++;
        }

        // Update the max window size if required
        if (curr_end-curr_start+1 > max_window_size)
        {
            max_window_size = curr_end-curr_start+1;
            max_window_start = curr_start;
        }
    }

    cout << max_window_start+1 << " " <<max_window_size << endl;
}

// Driver function
int main()
{
    int N;
    cin >> N;
    int s[N];
    for(int i=0; i<N; i++){
        cin >> s[i];
    }

    string str;
    for(int i=0; i<N; i++){
        string c = std::to_string(s[i]);
        str += c;
    }

    kUniques(str, 2);

    return 0;
}
