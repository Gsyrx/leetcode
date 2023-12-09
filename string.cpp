#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// palindrome or not
bool isPalindrome(std::string str)
{
  int left = 0, right = str.length() - 1;
  while (left < right)
  {
    if (str[left] != str[right])
    {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

// Subsequence or not
bool isSubSequence(string str1, string str2)
{
  int i = 0;
  int j = 0;

  while (i < str1.length() && j < str2.length())
  {
    if (str1[i] == str2[j])
    {
      j++;
    }
    i++;
  }

  return j == str2.length();
}

// Check for Anagram

bool isAnagram(string str1, string str2)
{
  int n1 = str1.length();
  int n2 = str2.length();

  if (n1 != n2)
  {
    return false;
  }

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  return str1 == str2;
}

// 2nd soln.

bool isAnagram(string str1, string str2)
{
  int n1 = str1.length();
  int n2 = str2.length();

  if (n1 != n2)
  {
    return false;
  }

  int count[256] = {0};

  for (int i = 0; i < str1.length(); i++)
  {
    count[str1[i]]++;
    count[str2[i]]--;
  }

  for (int i = 0; i < 256; i++)
  {
    if (count[i] != 0)
    {
      return false;
    }
  }

  return true;
}

// Leftmost Repeating Character

int leftmostRepeatingCharacter(string s)
{
  int n = s.length();

  int count[256] = {0};

  for (int i = 0; i < n; i++)
  {
    count[s[i]]++;
  }

  for (int i = 0; i < 256; i++)
  {
    if (count[s[i]] > 1)
    {
      return i;
    }
  }
  return -1;
}

// 2nd soln.

int leftmostRepeatingCharacter(string str)
{
  bool visited[256];
  fill(visited, visited + 256, false);
  int res = -1;
  for (int i = str.length() - 1; i >= 0; i--)
  {
    if (visited[str[i]])
      res = i;
    else
      visited[str[i]] = true;
  }

  return res;
}

// Leftmost Non-repeating Element

const int CHAR = 256;
int nonRep(string &str)
{
  int count[CHAR] = {0};
  for (int i = 0; i < str.length(); i++)
  {
    count[str[i]]++;
  }
  for (int i = 0; i < str.length(); i++)
  {
    if (count[str[i]] == 1)
      return i;
  }
  return -1;
}

// reverse word in string

void reverse(char str[], int low, int high)
{
  while (low <= high)
  {
    swap(str[low], str[high]);
    low++;
    high--;
  }
}

void reverseWords(char str[], int n)
{
  int start = 0;
  for (int end = 0; end < n; end++)
  {
    if (str[end] == ' ')
    {
      reverse(str, start, end - 1);
      start = end + 1;
    }
  }
  reverse(str, start, n - 1);
  reverse(str, 0, n - 1);
}

// Naive Pattern Searching
void naivePatternSearch(const std::string &text, const std::string &pattern)
{
  int textLength = text.length();
  int patternLength = pattern.length();

  for (int i = 0; i <= textLength - patternLength;)
  {
    int j;

    // Check for pattern match at the current position in the text
    for (j = 0; j < patternLength; ++j)
    {
      if (text[i + j] != pattern[j])
      {
        break;
      }
    }

    // If the inner loop completed without breaking, the pattern is found
    if (j == patternLength)
    {
      std::cout << "Pattern found at index " << i << std::endl;
    }
    // making it more efficient
    if (j == 0)
    {
      i++;
    }
    else
    {
      i = (i + j);
    }
  }

  // for (int i = 0; i <= textLength - patternLength; ++i)
  // {
  //   int j;

  //   // Check for pattern match at the current position in the text
  //   for (j = 0; j < patternLength; ++j)
  //   {
  //     if (text[i + j] != pattern[j])
  //     {
  //       break;
  //     }
  //   }

  //   // If the inner loop completed without breaking, the pattern is found
  //   if (j == patternLength)
  //   {
  //     std::cout << "Pattern found at index " << i << std::endl;
  //   }
  // }
}

// check if strings are rotation are not

bool arerotations(string s1, string s2)
{
  if (s1.length() != s2.length())
  {
    return false;
  }
  string temp = s1 + s1;
  return temp.find(s2) != string::npos;
}

// areAnagram or not

const int CHAR = 256;
bool areAnagram(string &pat, string &txt, int i)
{
  int count[CHAR] = {0};
  for (int j = 0; j < pat.length(); j++)
  {
    count[pat[j]]++;
    count[txt[i + j]]--;
  }
  for (int j = 0; j < CHAR; j++)
  {
    if (count[j] != 0)
      return false;
  }
  return true;
}

bool isPresent(string &txt, string &pat)
{
  int n = txt.length();
  int m = pat.length();
  for (int i = 0; i <= n - m; i++)
  {
    if (areAnagram(pat, txt, i))
      return true;
  }
  return false;
}

// Lexicographic Rank of a String

const int CHAR = 256;
int fact(int n)
{
  return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexRank(string &str)
{
  int res = 1;
  int n = str.length();
  int mul = fact(n);
  int count[CHAR] = {0};
  for (int i = 0; i < n; i++)
    count[str[i]]++;
  for (int i = 1; i < CHAR; i++)
    count[i] += count[i - 1];
  for (int i = 0; i < n - 1; i++)
  {
    mul = mul / (n - i);
    res = res + count[str[i] - 1] * mul;
    for (int j = str[i]; j < CHAR; j++)
      count[j]--;
  }
  return res;
}

// Longest Substring with Distinct Characters
// order(n2)
int longestDistinct(string str)
{
  int n = str.size();
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    vector<bool> visited(256);
    for (int j = i; j < n; j++)
    {
      if (visited[str[j]] == true)
      {
        break;
      }
      else
      {
        res = max(res, j - i + 1);
        visited[str[j]] = true;
      }
    }
  }
  return res;
}

// order(n)
int longestDistinct(string str)
{
  int n = str.length();
  int res = 0;
  vector<int> prev(256, -1);
  int i = 0;
  for (int j = 0; j < n; j++)
  {
    i = max(i, prev[str[j]] + 1);
    int maxEnd = j - i + 1;
    res = max(res, maxEnd);
    prev[str[j]] = j;
  }
  return res;
}

// Remove common characters and concatenate
std::string removeCommonAndConcatenate(const std::string &str1, const std::string &str2)
{
  std::unordered_set<char> set1(str1.begin(), str1.end());
  std::unordered_set<char> set2(str2.begin(), str2.end());

  std::string result;

  for (char ch : str1)
  {
    if (set2.find(ch) == set2.end())
    {
      // Character is not in str2, so add it to the result
      result += ch;
    }
  }

  for (char ch : str2)
  {
    if (set1.find(ch) == set1.end())
    {
      // Character is not in str1, so add it to the result
      result += ch;
    }
  }

  return result;
}

// 2nd sol
class Solution
{
public:
  // Function which concatenate two strings
  // after removing common characters
  string concatenatedString(string s1, string s2)
  {
    string s = "";
    int hash1[26] = {0};
    int hash2[26] = {0};
    for (int i = 0; i < s1.length(); i++)
      hash1[s1[i] - 'a']++;
    for (int i = 0; i < s2.length(); i++)
      hash2[s2[i] - 'a']++;
    for (int i = 0; i < s1.length(); i++)
    {
      if (hash2[s1[i] - 'a'] == 0)
        s += s1[i];
    }
    for (int i = 0; i < s2.length(); i++)
    {
      if (hash1[s2[i] - 'a'] == 0)
        s += s2[i];
    }
    if (!s.length())
      return "-1";
    return s;
  }
};

// Check if string is rotated by two places

bool isRotatedByTwoPlaces(const std::string &str1, const std::string &str2)
{
  if (str1.length() != str2.length())
  {
    return false; // Strings must be of the same length for rotation
  }

  // Rotate the original string to the left by two places
  std::string rotatedStrLeft = str1.substr(2) + str1.substr(0, 2);

  // Rotate the original string to the right by two places
  std::string rotatedStrRight = str1.substr(str1.length() - 2) + str1.substr(0, str1.length() - 2);

  // Check if either of the rotated strings matches str2
  return rotatedStrLeft == str2 || rotatedStrRight == str2;
}

// Panagram Checking

bool isPangram(const std::string &str)
{
  std::unordered_set<char> letters;

  for (char ch : str)
  {
    if (std::isalpha(ch))
    {
      // Convert the character to lowercase before adding to the set
      letters.insert(std::tolower(ch));
    }
  }

  // Check if the set of letters contains all the alphabets
  return letters.size() == 26;
}