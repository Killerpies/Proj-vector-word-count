**327 Project 2**

**Assignment**

Write a word count application which does the following;

1.  Opens an input file for reading.

2.  Reads all the words from the file, count the number of times each
    word occurs and records this data to a vector.

3.  Sorts the vector

4.  Writes the sorted vector to an output file.

**Where to start:**

Define all the functions in array_functions.cpp, and fileio.cpp, just
enough to get it to compile, then run it. You will then see the output
of running all tests plus your grade. Then begin filling in the
implementation for each function.

Note:Notice that content in array_functions.h is in namespace KP and all
constants are in namespace constants.

**Helpful Bits**

**ONLY MAKE CHANGES TO** array_functions.cpp and fileio.cpp. THESE ARE
THE ONLY FILES OF YOURS THAT I WILL TEST

-   [See the starter project]{.ul} . I have given you quite a bit of
    code. Use the declarations in the includes folder as a guide to what
    you need to implement.

-   To turn a std::string into a const std::string use c_str() method of
    string.

-   Make sure you call strip_unwanted_chars to get rid of rubbish chars
    in a token

-   [Use stringstream to parse each line.]{.ul} Here is a bit of code
    that may help:

> :
>
> #include \<sstream>
>
> **void** **extractTokensFromLine**(std::vector\<constants::entry>
> &entries,std::string &myString) {
>
> stringstream ss(myString);
>
> string tempToken;
>
> **while** (**getline**(ss, tempToken, constants::CHAR_TO_SEARCH_FOR))
> {
>
> processToken(entries, tempToken);
>
> }
>
> }
>
> This function takes myString and searches for tokens separated by
> constants::CHAR_TO_SEARCH_FOR (which is a space). This constant is
> defined in the file constants.h.

-   Please use the struct in constants to hold token information .

    **Testing and Verification**

This project has a built in tester which runs various tests on
[your]{.ul} code and will use the test results to calculate your grade.

**Sample Run**

See ./data folder in the sample project. testdata_full contains some
words, testdata_full_processed is correct output after running
project2.cpp's test_file function with no sorting.

**How I will grade**

I am going to take your implementation of array_functions.cpp and
fileio.cpp and drop them in the appropriate place in a cloned project
repo on my machine. I will not use any additional files in your repo.
Please do not change any of the other completed .cpp or .h files I give
you, or add any files that your array_functions.cpp or fileio.cpp depend
on.

**Scary parts**

I'm using a templates in testing.cpp . Its sorta like a Java generic,
Don't worry about it. Its there to condense code.

I'm also using popen in testing.cpp as a way to run another process, in
this case some linux cleanup code and a diff tool. The diff tool that I
am using is the standard one from a linux install. I've noted its
details in the code.

**Grading**

**Points awarded as per project output (as long as functions
attempted).**
